/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeskim <jaeskim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/15 19:21:46 by jaeskim           #+#    #+#             */
/*   Updated: 2021/05/22 18:22:05 by jaeskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_bonus.h"

static int	exit_with_arg(t_list *arg)
{
	char	*str;
	int		exit_code;

	exit_code = 0;
	str = arg->content;
	while (*str && ft_isdigit(*str))
		exit_code = (exit_code * 10) + *str++ - '0';
	if (*str)
	{
		ft_putstr_fd("minishell: exit: ", STDERR_FILENO);
		ft_putstr_fd(arg->content, STDERR_FILENO);
		ft_putstr_fd(": numeric argument required\n", STDERR_FILENO);
		exit(255);
	}
	if (arg->next)
	{
		ft_putstr_fd("minishell: exit: too many arguments\n", 2);
		return (1);
	}
	exit(exit_code);
	return (0);
}

int	ft_exit(t_list *args)
{
	ft_putendl_fd("exit", STDERR_FILENO);
	if (args)
		return (exit_with_arg(args));
	exit(0);
	return (0);
}
