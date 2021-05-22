/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_status_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeskim <jaeskim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/22 16:57:57 by jaeskim           #+#    #+#             */
/*   Updated: 2021/05/22 18:24:29 by jaeskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_bonus.h"

int	handle_status(int status)
{
	int		sig;

	if (WIFEXITED(status))
		return (WEXITSTATUS(status));
	if (WIFSIGNALED(status))
	{
		sig = WTERMSIG(status);
		if (sig == SIGINT)
			return (130);
		if (sig == SIGQUIT)
		{
			ft_putstr_fd("Quit: 3\n", 1);
			return (131);
		}
		return (128 + sig);
	}
	return (1);
}
