/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjung <yjung@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 22:30:59 by jaeskim           #+#    #+#             */
/*   Updated: 2021/04/07 22:29:10 by yjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include "libft.h"

# define CD_NOTEXIST		("No such file or directory.")
# define CD_NOTDIR			("Error opening directory.")
# define CD_NOPERM			("Permission denied.")
# define ASSIGNMENT_FAIL	("assignment failed.")
// # define MALLCHECK(x)		if (!x) return (-1);

char	**g_envp;

#endif
