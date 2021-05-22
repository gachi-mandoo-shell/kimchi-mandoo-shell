/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envp_bonus.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeskim <jaeskim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 12:23:37 by jaeskim           #+#    #+#             */
/*   Updated: 2021/05/22 18:16:19 by jaeskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENVP_BONUS_H
# define ENVP_BONUS_H

# include "minishell_bonus.h"

t_list	*get_envp(char *name, t_list *envp);
char	*get_envp_value(char *name);
int		set_envp(char *env);
int		remove_envp(char *value);

#endif
