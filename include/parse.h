/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeskim <jaeskim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 13:41:05 by jaeskim           #+#    #+#             */
/*   Updated: 2021/05/08 23:54:43 by jaeskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

# include "minishell.h"

# define PARSE_ERROR_COUNT	4
# define PARSE_MALLOC		0
# define PARSE_MALLOC_MSG	"Memory allocation failure\n"
# define PARSE_INVAILD		1
# define PARSE_INVAILD_MSG	"invaild command\n"
# define PARSE_UNEXPECT		2
# define PARSE_UNEXPECT_MSG	"syntax error near unexpected token\n"
# define PARSE_NOTTHING		3

t_list	*parse_line(char *line);
char	*parse_cmd(char *cmd, t_list *envp);
t_list	*parse_arg(char *arg, t_list *envp);

void	print_parse_err(t_list *err);
void	free_AST(void *data);
void	free_REDIRECT(t_redirect *redirect);
void	free_CTR_OP(t_ctr_op *ctr);
void	free_PIPE(t_pipe *pipe);
void	free_CMD(t_cmd *cmd);

#endif
