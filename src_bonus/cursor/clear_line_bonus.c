/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_line_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeskim <jaeskim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 16:26:23 by jaeskim           #+#    #+#             */
/*   Updated: 2021/05/22 18:22:33 by jaeskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_bonus.h"

void	clear_line(void)
{
	tputs(tgetstr("cl", NULL), 1, putchar_tc);
	print_PS1();
	ft_putstr_fd(g_sh.line, 1);
}
