/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeskim <jaeskim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 15:45:57 by yjung             #+#    #+#             */
/*   Updated: 2021/05/22 22:35:51 by jaeskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_bonus.h"

int	builtin_cmd_set(t_cmd *cmds, t_check *g)
{
	int	status;

	status = ft_redir_connect(g, 1);
	if (status < 0)
	{
		ft_redir_close(g);
		return (status);
	}
	status = ft_cmd_exec(cmds, g);
	ft_redir_close(g);
	return (status);
}

int	builtin_pipe_set(t_cmd *cmds, t_check *g)
{
	pid_t	pid;
	int		status;

	status = 0;
	pid = fork();
	if (pid < 0)
		ft_error_print("fail fork", NULL, strerror(errno));
	else if (pid == 0)
	{
		ft_pipe_connect(&status, g);
		if (status < 0)
			return (status);
		status = ft_redir_connect(g, 0);
		if (status < 0)
			return (status);
		status = ft_cmd_exec(cmds, g);
		exit(status);
	}
	g_sh.pid = pid;
	waitpid(pid, &status, WUNTRACED);
	g_sh.pid = 0;
	g_sh.status = handle_status(status);
	ft_redir_close(g);
	ft_pipe_close(g);
	return (g_sh.status);
}

int	ft_cmd_set(t_cmd *cmds, t_check *g)
{
	pid_t	pid;
	int		status;

	status = 0;
	pid = fork();
	if (pid < 0)
		ft_error_print("fail fork", NULL, strerror(errno));
	if (pid == 0)
	{
		ft_pipe_connect(&status, g);
		if (status < 0)
			exit(status);
		status = ft_redir_connect(g, 0);
		if (status < 0)
			exit(status);
		status = ft_make_cmd(cmds->cmd, cmds->args);
		exit(status);
	}
	g_sh.pid = pid;
	waitpid(pid, &status, WUNTRACED);
	g_sh.pid = 0;
	g_sh.status = handle_status(status);
	ft_redir_close(g);
	ft_pipe_close(g);
	return (g_sh.status);
}
