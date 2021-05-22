# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jaeskim <jaeskim@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/06 21:07:58 by jaeskim           #+#    #+#              #
#    Updated: 2021/05/22 18:34:16 by jaeskim          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

CC = gcc
CFLAGS = -Wall -Wextra -Werror
CLIBFLAGS = -lncurses
# CFLAGS += -g3 -fsanitize=address
ifeq ($(DEBUG),true)
	CFLAGS += -g
endif

RM = rm
RMFLAGS = -rf

INC_DIR = include
SRC_DIR = src
OBJ_DIR = obj

# libft
LIBFT = libft.a
LIBFT_DIR = lib/libft
LIBFT_FILE = $(LIBFT_DIR)/$(LIBFT)
LIBFT_INC_DIR = $(LIBFT_DIR)/include
LIBFT_FLAGS = -L./$(LIBFT_DIR) -lft
CFLAGS += -I $(LIBFT_INC_DIR)

HEADERS = $(addprefix $(INC_DIR)/, \
	builtin.h \
	cursor.h  \
	envp.h  \
	exec.h  \
	minishell.h \
	minishell_type.h  \
	parse.h \
	parse_util.h  \
	util.h	\
)

UTIL_DIR = $(SRC_DIR)/util
UTIL_SRC = $(addprefix $(UTIL_DIR)/, \
	get_line.c  \
	getch.c \
	handle_history.c  \
	handle_key_input.c  \
	handle_signal.c \
	is_util.c \
	print_PS.c  \
	print_PS1.c \
	print_PS2.c \
)

CURSOR_DIR = $(SRC_DIR)/cursor
CURSOR_SRC = $(addprefix $(CURSOR_DIR)/, \
	clear_line.c  \
	cursor_ctrl_left.c  \
	cursor_ctrl_right.c \
	cursor_left.c \
	cursor_right.c  \
	delete_char.c \
	delete_line.c \
	putchar_tc.c  \
)

PARSE_DIR = $(SRC_DIR)/parse
PARSE_SRC = $(addprefix $(PARSE_DIR)/,	\
	free_AST.c  \
	is_wildcard.c \
	lexical_analyzer.c  \
	normalize.c \
	parse_arg.c \
	parse_cmd.c \
	parse_line.c  \
	parse_util.c  \
	print_AST.c \
	syntax_AST.c  \
	syntax_analyzer.c \
	syntax_cmd.c  \
	tokenizer.c \
)

EXEC_DIR = $(SRC_DIR)/exec
EXEC_SRC = $(addprefix $(EXEC_DIR)/,	\
	builtin_parser.c  \
	exec_cmd.c  \
	exec_tree_parser.c  \
	fork.c  \
	free_exec.c \
	ft_cmd.c  \
	ft_error.c  \
	handle_status.c \
	heredoc.c \
	make_cmd.c  \
	parse_t_cmd.c \
	pipe.c  \
	redirection.c \
)

ENVP_DIR = $(SRC_DIR)/envp
ENVP_SRC = $(addprefix $(ENVP_DIR)/, \
	get_envp.c  \
	get_evnp_value.c  \
	remove_envp.c \
	set_envp.c  \
)

BUILTIN_DIR = $(SRC_DIR)/builtin
BUILTIN_SRC = $(addprefix $(BUILTIN_DIR)/,	\
	export_sort.c \
	ft_cd.c \
	ft_echo.c \
	ft_env.c  \
	ft_exit.c \
	ft_export.c \
	ft_pwd.c  \
	ft_unset.c  \
)

ROOT_SRCS = $(addprefix $(SRC_DIR)/,	\
	exit_minshell.c \
	init.c  \
	minishell.c \
)

SRCS = \
	$(ROOT_SRCS)	\
	$(PARSE_SRC)	\
	$(EXEC_SRC)	\
	$(UTIL_SRC)	\
	$(CURSOR_SRC)	\
	$(ENVP_SRC)	\
	$(BUILTIN_SRC)

vpath %.c \
	$(SRC_DIR)	\
	$(PARSE_DIR)	\
	$(EXEC_DIR)	\
	$(UTIL_DIR)	\
	$(CURSOR_DIR)	\
	$(ENVP_DIR)	\
	$(BUILTIN_DIR) \


OBJS = $(addprefix $(OBJ_DIR)/, $(notdir $(SRCS:.c=.o)))

# ============================================================================ #
#                                 BONUS_PART                                   #
# ============================================================================ #

INC_DIR_BONUS = ./include_bonus
SRC_DIR_BONUS = ./src_bonus

HEADERS_BONUS = $(addprefix $(INC_DIR_BONUS)/, \
	builtin_bonus.h \
	cursor_bonus.h  \
	envp_bonus.h  \
	exec_bonus.h  \
	minishell_bonus.h \
	minishell_type_bonus.h  \
	parse_bonus.h \
	parse_util_bonus.h  \
	util_bonus.h	\
)

UTIL_DIR_BONUS = $(SRC_DIR_BONUS)/util
UTIL_SRC_BONUS = $(addprefix $(UTIL_DIR_BONUS)/, \
	get_line_bonus.c  \
	getch_bonus.c \
	handle_history_bonus.c  \
	handle_key_input_bonus.c  \
	handle_signal_bonus.c \
	is_util_bonus.c \
	print_PS_bonus.c  \
	print_PS1_bonus.c \
	print_PS2_bonus.c \
)

CURSOR_DIR_BONUS = $(SRC_DIR_BONUS)/cursor
CURSOR_SRC_BONUS = $(addprefix $(CURSOR_DIR_BONUS)/, \
	clear_line_bonus.c  \
	cursor_ctrl_left_bonus.c  \
	cursor_ctrl_right_bonus.c \
	cursor_left_bonus.c \
	cursor_right_bonus.c  \
	delete_char_bonus.c \
	delete_line_bonus.c \
	putchar_tc_bonus.c  \
)

PARSE_DIR_BONUS = $(SRC_DIR_BONUS)/parse
PARSE_SRC_BONUS = $(addprefix $(PARSE_DIR_BONUS)/,	\
	free_AST_bonus.c  \
	is_wildcard_bonus.c \
	lexical_analyzer_bonus.c  \
	normalize_bonus.c \
	parse_arg_bonus.c \
	parse_cmd_bonus.c \
	parse_line_bonus.c  \
	parse_util_bonus.c  \
	print_AST_bonus.c \
	syntax_AST_bonus.c  \
	syntax_analyzer_bonus.c \
	syntax_cmd_bonus.c  \
	tokenizer_bonus.c \
)

EXEC_DIR_BONUS = $(SRC_DIR_BONUS)/exec
EXEC_SRC_BONUS = $(addprefix $(EXEC_DIR_BONUS)/,	\
	builtin_parser_bonus.c  \
	exec_cmd_bonus.c  \
	exec_tree_parser_bonus.c  \
	fork_bonus.c  \
	free_exec_bonus.c \
	ft_cmd_bonus.c  \
	ft_error_bonus.c  \
	handle_status_bonus.c \
	heredoc_bonus.c \
	make_cmd_bonus.c  \
	parse_t_cmd_bonus.c \
	pipe_bonus.c  \
	redirection_bonus.c \
)

ENVP_DIR_BONUS = $(SRC_DIR_BONUS)/envp
ENVP_SRC_BONUS = $(addprefix $(ENVP_DIR_BONUS)/, \
	get_envp_bonus.c  \
	get_evnp_value_bonus.c  \
	remove_envp_bonus.c \
	set_envp_bonus.c  \
)

BUILTIN_DIR_BONUS = $(SRC_DIR_BONUS)/builtin
BUILTIN_SRC_BONUS = $(addprefix $(BUILTIN_DIR_BONUS)/,	\
	export_sort_bonus.c \
	ft_cd_bonus.c \
	ft_echo_bonus.c \
	ft_env_bonus.c  \
	ft_exit_bonus.c \
	ft_export_bonus.c \
	ft_pwd_bonus.c  \
	ft_unset_bonus.c  \
)

ROOT_SRCS_BONUS = $(addprefix $(SRC_DIR_BONUS)/,	\
	exit_minshell_bonus.c \
	init_bonus.c  \
	minishell_bonus.c \
)

SRCS_BONUS = \
	$(ROOT_SRCS_BONUS)	\
	$(PARSE_SRC_BONUS)	\
	$(EXEC_SRC_BONUS)	\
	$(UTIL_SRC_BONUS)	\
	$(CURSOR_SRC_BONUS)	\
	$(ENVP_SRC_BONUS)	\
	$(BUILTIN_SRC_BONUS)

vpath %.c \
	$(SRC_DIR_BONUS)	\
	$(PARSE_DIR_BONUS)	\
	$(EXEC_DIR_BONUS)	\
	$(UTIL_DIR_BONUS)	\
	$(CURSOR_DIR_BONUS)	\
	$(ENVP_DIR_BONUS)	\
	$(BUILTIN_DIR_BONUS) \

OBJS_BONUS = $(addprefix $(OBJ_DIR)/, $(notdir $(SRCS_BONUS:.c=.o)))

# ============================================================================ #

# Color
CL_BOLD	 = \e[1m
CL_DIM	= \e[2m
CL_UDLINE = \e[4m

NO_COLOR = \e[0m

BG_TEXT = \e[48;2;45;55;72m
BG_BLACK = \e[48;2;30;31;33m

FG_WHITE = $(NO_COLOR)\e[0;37m
FG_TEXT = $(NO_COLOR)\e[38;2;189;147;249m
FG_TEXT_PRIMARY = $(NO_COLOR)$(CL_BOLD)\e[38;2;255;121;198m

LF = \e[1K\r$(NO_COLOR)
CRLF= \n$(LF)

all : $(NAME)

clean :
	@$(RM) $(RMFLAGS) $(OBJ_DIR)
	@printf "$(LF)🧹 $(FG_TEXT)Cleaning $(FG_TEXT_PRIMARY)$(NAME)'s Object files...\n"

fclean : clean
	@$(RM) $(RMFLAGS) $(NAME)
	@printf "$(LF)🧹 $(FG_TEXT)Cleaning $(FG_TEXT_PRIMARY)$(NAME)\n"

re : fclean all

$(OBJ_DIR) :
	@mkdir $(OBJ_DIR)

$(OBJ_DIR)/%.o : %.c $(LIBFT_FILE) | $(OBJ_DIR)
	@$(CC) $(CFLAGS) -I $(INC_DIR) -I $(INC_DIR_BONUS) -c $< -o $@
	@printf "$(LF)🚧 $(FG_TEXT)Create $(FG_TEXT_PRIMARY)$@ $(FG_TEXT)from $(FG_TEXT_PRIMARY)$<"

$(NAME) : $(LIBFT_FILE) $(HEADERS) $(OBJS)
	@printf "$(LF)🚀 $(FG_TEXT)Successfully Created $(FG_TEXT_PRIMARY)$@'s Object files $(FG_TEXT)!"
	@printf "$(CRLF)📚 $(FG_TEXT)Create $(FG_TEXT_PRIMARY)$@$(FG_TEXT)!\n"
	@$(CC) $(CFLAGS) -I $(INC_DIR) $(CLIBFLAGS) $(LIBFT_FLAGS) $(OBJS) -o $@
	@printf "$(LF)🎉 $(FG_TEXT)Successfully Created $(FG_TEXT_PRIMARY)$@ $(FG_TEXT)!\n$(NO_COLOR)"

bonus : $(LIBFT_FILE) $(HEADERS_BONUS) $(OBJS_BONUS)
	@printf "$(LF)🚀 $(FG_TEXT)Successfully Created $(FG_TEXT_PRIMARY)$@'s Object files $(FG_TEXT)!"
	@printf "$(CRLF)📚 $(FG_TEXT)Create $(FG_TEXT_PRIMARY)$@$(FG_TEXT)!\n"
	@$(CC) $(CFLAGS) -I $(INC_DIR_BONUS) $(CLIBFLAGS) $(LIBFT_FLAGS) $(OBJS_BONUS) -o $(NAME)
	@printf "$(LF)🎉 $(FG_TEXT)Successfully Created $(FG_TEXT_PRIMARY)$@ $(FG_TEXT)!\n$(NO_COLOR)"

# lib
lib : libft
lib_fclean : libft_fclean
lib_re : lib_fclean lib

# libft
libft : $(LIBFT_FILE)

$(LIBFT_FILE) :
	@make --no-print-directory -C $(LIBFT_DIR)

libft_re :
	@make --no-print-directory -C $(LIBFT_DIR) re

libft_clean :
	@make --no-print-directory -C $(LIBFT_DIR) clean

libft_fclean :
	@make --no-print-directory -C $(LIBFT_DIR) fclean


.PHONY: all clean fclean re bonus \
	lib lib_re	\
	libft libft_clean libft_fclean
