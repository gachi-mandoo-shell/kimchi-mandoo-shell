/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_signal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeskim <jaeskim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 04:27:38 by jaeskim           #+#    #+#             */
/*   Updated: 2021/05/22 17:18:23 by jaeskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	handle_sigint(int sig)
{
	g_sh.signal = sig;
	ft_putchar_fd('\n', 1);
	if (!g_sh.pid)
	{
		ft_free(g_sh.line);
		g_sh.line = NULL;
		if (!g_sh.isps2)
			print_PS1();
	}
	if (g_sh.read_fd > 0)
	{
		close(g_sh.read_fd);
		g_sh.read_fd = -1;
	}
}

static void	handle_sigquit(int sig)
{
	g_sh.signal = sig;
}

void	set_handle_signal(void)
{
	signal(SIGINT, handle_sigint);
	signal(SIGQUIT, handle_sigquit);
}
