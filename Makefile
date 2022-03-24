# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lleveque <lleveque@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/21 17:19:21 by arudy             #+#    #+#              #
#    Updated: 2022/03/24 17:10:16 by lleveque         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = ${SRCS_PARSING} ${SRCS_LEXER} ${SRCS_LIBFT} ${SRCS_BUILTINS} srcs/main.c

SRCS_PARSING = $(addprefix srcs/parsing/, get_full_path.c)

SRCS_LEXER = $(addprefix srcs/lexer/, lexer.c check_quotes.c \
				char_to_token.c)

SRCS_LIBFT = $(addprefix srcs/libft/, ft_putstr_fd.c ft_strlen.c \
				ft_strncmp.c ft_substr.c ft_split.c free_strs.c ft_strsjoin.c \
				ft_strdup.c ft_strncmp.c ft_substr.c ft_split.c free_strs.c \
				ft_is_whitespace.c ft_lst_addback.c ft_lst_last.c \
				ft_free_lst.c)

SRCS_BUILTINS = $(addprefix srcs/builtins/, echo.c)

SRCS_UTILS = $(addprefix srcs/utils/, env_utils.c)

OBJS = ${SRCS:.c=.o}

NAME = minishell

CC = clang

CFLAGS = -Wall -Werror -Wextra

RM = rm -f

all: ${NAME}

${NAME}:	${OBJS}
		${CC} ${CFLAGS} ${OBJS} -lreadline -o ${NAME}

.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

clean:
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re
