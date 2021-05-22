/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_line_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeskim <jaeskim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 13:39:46 by jaeskim           #+#    #+#             */
/*   Updated: 2021/05/22 18:25:21 by jaeskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_bonus.h"
#include "parse_util_bonus.h"

t_list	*parse_line(char *line)
{
	t_list	*result;

	result = lexical_analyzer(line);
	if (result < (t_list *)PARSE_ERROR_COUNT)
		return (result);
	result = syntax_analyzer(result);
	return (result);
}
