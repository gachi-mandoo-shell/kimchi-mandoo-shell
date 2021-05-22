/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cursor_ctrl_left_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeskim <jaeskim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/15 22:17:57 by jaeskim           #+#    #+#             */
/*   Updated: 2021/05/22 18:22:38 by jaeskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_bonus.h"

void	cursor_ctrl_left(void)
{
	while (g_sh.cmd_i > 0 && g_sh.line[g_sh.cmd_i - 1] == ' ')
	{
		cursor_left();
		--g_sh.cmd_i;
	}
	while (g_sh.cmd_i > 0 && g_sh.line[g_sh.cmd_i - 1] != ' ')
	{
		cursor_left();
		--g_sh.cmd_i;
	}
}
