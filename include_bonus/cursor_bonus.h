/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cursor_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeskim <jaeskim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 15:29:48 by jaeskim           #+#    #+#             */
/*   Updated: 2021/05/22 18:16:02 by jaeskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURSOR_BONUS_H
# define CURSOR_BONUS_H

# include "minishell_bonus.h"

int		putchar_tc(int tc);
void	delete_line(void);
void	delete_char(void);
void	cursor_left(void);
void	cursor_right(void);
void	cursor_ctrl_left(void);
void	cursor_ctrl_right(void);
void	clear_line(void);

#endif
