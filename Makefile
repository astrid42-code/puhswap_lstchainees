# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asgaulti <asgaulti@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/24 13:51:00 by asgaulti@st       #+#    #+#              #
#    Updated: 2021/06/20 14:19:10 by asgaulti         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	push_swap

SRCS	=	ft_create.c ft_utils.c main.c ft_pushswap.c ft_swap.c ft_lst_utils.c \
			ft_rotate.c ft_reverse_rotate.c ft_push.c ft_sort_onehundred.c \
			ft_sort_fivehundred.c

PATH_SRCS = srcs/

OBJS	=	${addprefix ${PATH_SRCS}, ${SRCS:.c=.o}}

CC		=	clang
RM		=	rm -f
CFLAGS	=	-Wall -Werror -Wextra 
#-fsanitize=address -g3

INCL	=	include

.c.o:
			${CC} ${CFLAGS} -I${INCL} -g -c $< -o ${<:.c=.o}

# avec graph : git clone --recurse-submodules https://github.com/forfungg/push_swap.git; cd push_swap; make
# sans graph : git clone --recurse-submodules https://github.com/forfungg/push_swap.git; cd push_swap; make nograph

$(NAME):	${OBJS}
			${CC} ${CFLAGS} ${LFLAGS} ${OBJS} -o ${NAME}

all:		${NAME}

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}
					
re:			fclean all

.PHONY:		all clean fclean re