/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeskim <jaeskim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/08 23:02:36 by jaeskim           #+#    #+#             */
/*   Updated: 2021/05/22 22:12:45 by jaeskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTIN_H
# define BUILTIN_H

# include "minishell.h"

int		ft_echo(t_list *args);
int		ft_cd(t_list *args);
int		ft_export(t_list *args);
int		compare(t_list *a, t_list *b);
int		ft_unset(t_list *args);
int		ft_env(void);
int		ft_pwd(void);
int		ft_exit(t_list *args);

#endif
