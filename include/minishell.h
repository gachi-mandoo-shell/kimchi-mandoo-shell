/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjung <yjung@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 22:30:59 by jaeskim           #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2021/04/14 13:44:33 by jaeskim          ###   ########.fr       */
=======
/*   Updated: 2021/04/14 00:11:29 by yjung            ###   ########.fr       */
>>>>>>> fe249061a7c6c27fd8cbfd71068508a129cf2724
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>

# include <libft.h>
# include "minishell_type.h"

# include "parse.h"
# include "exec.h"

# define CD_NOTEXIST		("No such file or directory.")
# define CD_NOTDIR			("Error opening directory.")
# define CD_NOPERM			("Permission denied.")
# define ASSIGNMENT_FAIL	("assignment failed.")
// # define MALLCHECK(x)		if (!x) return (-1);

char	**g_envp;

#endif
