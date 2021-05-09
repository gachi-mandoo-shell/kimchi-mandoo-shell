/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_util.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjung <yjung@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 12:58:07 by yjung             #+#    #+#             */
/*   Updated: 2021/05/09 17:16:29 by yjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_tree_parser(t_AST *cmds, t_check *g)
{
	int		status;

	status = 0;
	if (cmds->type == FT_CMD)
	{
		if (g->pipe_cnt > 0)
			status = ft_cmd_pipe_set(cmds->data, g);
		else
			status = ft_cmd_exec(cmds->data, g);
	}
	else if (cmds->type == FT_PIPE)
		status = ft_pipe_exec(cmds->data, g);
	else if (cmds->type == FT_REDIRECT)
		status = ft_redir_exec(cmds->data, g);
	else if (cmds->type == FT_CTR_OP)
		status = ft_ctr_op_exec(cmds->data, g);
	if (status != 0)
		return (status);
	return (status);
}

int	ft_ctr_op_exec(t_ctr_op *ctr, t_check *g)
{
	int		status;

	status = 0;
	status = ft_tree_parser(ctr->left, g);
	if (ctr->type == 2 && status != 0)
		return (status);
	status = ft_tree_parser(ctr->right, g);
	return (status);
}

// quotes 처리...
// $ 치환...
// link_list 연결 후 free
int	ft_make_cmd(char *cmd, t_list *lst)
{
	int		status;
	int		cnt;
	t_list	*curr;
	char	**args;

	status = 0;
	if (!ft_malloc((void **)&args, sizeof(char *) * (ft_lstsize(lst) + 2)))
		// TODO: 예외처리 필요
		return (-1);
	cnt = 0;
	// // malloc fail -> PARSE_MALLOC;
	// // command not found -> PARSE_CMD_NONE;
	// parse_cmd(cmd);
	// PARSE_CMD_NONE
	// TODO: ls -> /bin/ls 등 경로 치환 필요
	args[cnt++] = parse_cmd(normalize(cmd, NORMALIZE_CMD));
	curr = lst;
	while (curr)
	{
		// TODO: args 환경변수로 치환 -> 따로 parse_arg함수 만들어서 할 예정(*처리 위해)
		args[cnt++] = normalize(curr->content, NORMALIZE_CMD);
		curr = curr->next;
	}
	args[cnt] = NULL;
	status = execve(args[0], args, (char **)ft_lst_to_array(g_sh.envp));
	ft_lstclear(&lst, ft_free);
	exit(status);
	return (status);
}

int	ft_cmd_fork_set(t_cmd *cmds, t_check *g)
{
	pid_t	pid;
	int		status;

	status = 0;
	pid = fork();
	if (pid < 0)
		ft_error_print("fail fork", strerror(errno));
	if (pid == 0)
	{
		ft_pipe_connect(&status, g);
		if (status < 0)
			return (status);
		status = ft_redir_parser(g);
		if (status < 0)
			return (status);
		status = ft_make_cmd(cmds->cmd, cmds->args);
		if (status < 0)
			return (status);
		status = ft_redir_parser(g);
		exit(status);
	}
	// else if (pid > 0)
	else
	{
		wait(&pid);
		// ft_pipe_connect(&status, g);
		// if (status < 0)
		// 	return (status);
		// status = ft_redir_parser(g);
	}
	// else
	// 	ft_error_print("fail fork", strerror(errno));
	return (status);
}