/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_exec.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeskim <jaeskim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 19:59:36 by yjung             #+#    #+#             */
/*   Updated: 2021/05/22 18:58:00 by jaeskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_free_cmd(t_cmd *new_cmd, int ret)
{
	if (new_cmd)
	{
		ft_free(new_cmd->cmd);
		if (new_cmd->args > (t_list *)PARSE_ERROR_COUNT)
			ft_lstclear(&new_cmd->args, ft_free);
		free(new_cmd);
	}
	return (ret);
}

void	free_g(t_check *g)
{
	if (g->pipe_fd)
		free_pipe(g->pipe_fd);
}

void	free_pipe(void *data)
{
	t_pi_fd	*pipe;

	pipe = data;
	if (pipe)
		ft_free(pipe);
}
