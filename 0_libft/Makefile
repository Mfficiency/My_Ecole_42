# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    oldMakefile                                        :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmeersma <mmeersma@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/19 10:32:22 by slosey            #+#    #+#              #
#    Updated: 2021/11/07 15:55:15 by mmeersma         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		= libft.a

SRCS 		= ft_isalnum.c 		\
				ft_isalpha.c 		\
				ft_isdigit.c	\
				ft_isascii.c	\
				ft_isprint.c	\
				ft_strlen.c	\
				ft_memset.c	\
				ft_bzero.c	\
				ft_memcpy.c	\
				ft_memmove.c	\
				ft_strlcpy.c	\
				ft_strlcat.c	\
				ft_toupper.c	\
				ft_tolower.c	\
				ft_strchr.c	\
				ft_strrchr.c	\
				ft_strncmp.c	\
				ft_memchr.c	\
				ft_memcmp.c	\
				ft_strnstr.c	\
				ft_calloc.c	\
				ft_strdup.c	\
				ft_substr.c	\
				ft_strjoin.c	\
				ft_strtrim.c	\
				ft_split.c	\
				ft_itoa.c	\
				ft_strmapi.c	\
				ft_striteri.c	\
				ft_putchar_fd.c	\
				ft_putstr_fd.c	\
				ft_putendl_fd.c	\
				ft_putnbr_fd.c	\
				ft_atoi.c	
INCLUDES	= libft.h 
OBJS		= ${SRCS:.c=.o}
CC			= gcc
AR			= ar rc
NORM_BIN	= norminette
NORM_FLAGS	= -RCheckForbiddenSourceHeader -RCheckDefine
RM 			= rm -f
CFLAGS 		= -Wall -Wextra -Werror -I./${INCLUDES} 

TINCLUDES	= libft.h ./tests/testlib.h
CTFLAGS 	= -Wall -Wextra -Werror -I./${TINCLUDES} 
TESTDIR		= tests
TESTFILES	= ${TESTDIR}/ft_main.test.c
TESTNAME	= testfile

${NAME} : 	${OBJS}
			${AR} ${NAME} ${OBJS} 

all : 		${NAME}

clean :
			${RM} ${OBJS}

fclean: 	clean
			${RM} ${NAME}

re : 		fclean all

test :		${NAME}
			${CC} ${CTFLAGS} ${TESTFILES} -L. -lft 

.PHONY:		all clean fclean re test