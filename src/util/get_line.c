/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_line.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeskim <jaeskim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 18:19:08 by jaeskim           #+#    #+#             */
/*   Updated: 2021/05/22 22:33:44 by jaeskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*append_char_malloc(char *line, char c)
{
	char	*result;

	if (line == NULL)
		return (ft_strndup(&c, 1));
	if (g_sh.cmd_i == g_sh.cmd_s)
		return (ft_strappendc(line, c));
	result = ft_strndup(line, g_sh.cmd_i);
	if (result == NULL)
	{
		ft_free(line);
		return (NULL);
	}
	result = ft_strappendc(result, c);
	if (result == NULL)
	{
		ft_free(line);
		return (NULL);
	}
	result = ft_strjoin_free(result, line + g_sh.cmd_i, 1);
	ft_free(line);
	if (result == NULL)
		return (0);
	return (result);
}

static char	*append_char(char *line, char c)
{
	int		i;
	char	*result;

	result = append_char_malloc(line, c);
	if (result == NULL)
		return (NULL);
	ft_putstr_fd(result + g_sh.cmd_i, 1);
	i = g_sh.cmd_s - g_sh.cmd_i;
	while (i--)
		cursor_left();
	(++g_sh.cmd_i && ++g_sh.cmd_s);
	return (result);
}

void	setup_line(void)
{
	t_history	*history;

	if (g_sh.cmd && g_sh.cmd->cmd == NULL)
	{
		g_sh.cmd->cmd = g_sh.line;
		g_sh.history = g_sh.cmd;
		return ;
	}
	if (!ft_malloc((void **)&history, sizeof(t_history)))
	{
		ft_putstr_fd(strerror(errno), 2);
		ft_free(g_sh.line);
		exit_minishell(1);
	}
	history->cmd = g_sh.line;
	if (g_sh.cmd == NULL)
		g_sh.cmd = history;
	else
	{
		g_sh.cmd->next = history;
		history->prev = g_sh.cmd;
		g_sh.cmd = history;
	}
	g_sh.history = g_sh.cmd;
}

static int	check_EOF(int keycode)
{
	if (is_eof(keycode) && (g_sh.line == NULL || !*g_sh.line))
	{
		g_sh.eof = 1;
		ft_free(g_sh.line);
		if (g_sh.isps2)
			return (1);
		ft_putstr_fd("exit\n", 2);
		exit_minishell(0);
	}
	return (0);
}

void	get_line(void)
{
	int		c;

	(!(c = 0) && !(g_sh.line = 0) && !(g_sh.cmd_i = 0) && \
	!(g_sh.cmd_s = 0) && !(g_sh.eof = 0) && (c = getch()));
	while (c != (int) '\n')
	{
		if (check_EOF(c) || (g_sh.signal == SIGINT && g_sh.isps2))
			break ;
		if (is_special_key(c))
			handle_key_input(c);
		else if (ft_isprint(c))
		{
			g_sh.line = append_char(g_sh.line, c);
			if (g_sh.line == NULL)
			{
				ft_putstr_fd(strerror(errno), 2);
				exit_minishell(1);
			}
		}
		c = getch();
	}
	ft_putchar_fd('\n', 1);
	setup_line();
}
