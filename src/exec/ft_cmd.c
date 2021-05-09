/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cmd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjung <yjung@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 22:26:53 by yjung             #+#    #+#             */
/*   Updated: 2021/05/09 16:21:51 by yjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_cmd_pipe_set(t_cmd *cmds, t_check *g)
{
	pid_t	pid;
	int		status;

	status = 0;
	pid = fork();
	if (pid < 0)
		ft_error_print("fail fork", strerror(errno));
	else if (pid == 0)
	{
		ft_pipe_connect(&status, g);
		if (status < 0)
			return (status);
		status = ft_redir_parser(g);
		if (status < 0)
			return (status);
		status = ft_cmd_exec(cmds, g);
		if (status < 0)
			return (status);
		status = ft_redir_parser(g);
		exit(status);
	}
	else
	{
		wait(&pid);
		// ft_pipe_connect(&status, g);
		// if (status < 0)
		// 	return (status);
		// status = ft_redir_parser(g);
	}
	return (status);
}

int	ft_cmd_exec(t_cmd *cmds, t_check *g)
{
	int	 status;

	status = 0;
	if (ft_strcmp(cmds->cmd, "cd") == 0)
		status = ft_cd(g, cmds->args);
	else if (ft_strcmp(cmds->cmd, "echo") == 0)
		status = ft_echo(g, cmds->args);
	else if (ft_strcmp(cmds->cmd, "pwd") == 0)
		ft_pwd(g);
	else if (ft_strcmp(cmds->cmd, "env") == 0)
		status = ft_env();
	else if (ft_strcmp(cmds->cmd, "export") == 0)
		status = ft_export(cmds->args);
	else if (ft_strcmp(cmds->cmd, "unset") == 0)
		status = ft_unset(g, cmds->args);
	else if (ft_strcmp(cmds->cmd, "exit") == 0)
	{
		// status = ft_exit(cmds->args);
		if (status != -1)
			exit(status);
	}
	else if (cmds)
		status = ft_cmd_fork_set(cmds, g);
	return (status);
}