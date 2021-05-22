/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeskim <jaeskim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 21:06:12 by yjung             #+#    #+#             */
/*   Updated: 2021/05/22 18:21:53 by jaeskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_bonus.h"

int	ft_echo(t_list *args)
{
	t_list	*curr;
	int		status;

	status = 0;
	if (!args)
	{
		ft_putstr_fd("\n", STDOUT_FILENO);
		return (0);
	}
	curr = args;
	if (ft_strcmp(curr->content, "-n") == 0)
	{
		status = 1;
		curr = curr->next;
	}
	while (curr)
	{
		ft_putstr_fd(curr->content, STDOUT_FILENO);
		curr = curr->next;
		if (curr)
			ft_putstr_fd(" ", STDOUT_FILENO);
	}
	if (status != 1)
		ft_putstr_fd("\n", STDOUT_FILENO);
	return (0);
}
