/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_evnp_value_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeskim <jaeskim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 12:51:06 by jaeskim           #+#    #+#             */
/*   Updated: 2021/05/22 18:23:40 by jaeskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_bonus.h"

char	*get_envp_value(char *name)
{
	char	*result;
	t_list	*env;

	env = get_envp(name, g_sh.envp);
	if (!env || !ft_strchr(env->content, '='))
		result = ft_strdup("");
	else
		result = ft_strdup(env->content + ft_strlen(name) + 1);
	return (result);
}
