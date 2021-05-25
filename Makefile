# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asgaulti@student.42.fr <asgaulti>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/24 13:51:00 by asgaulti@st       #+#    #+#              #
#    Updated: 2021/05/25 17:37:18 by asgaulti@st      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	push_swap

SRCS	=	ft_create.c ft_utils.c main.c ft_pushswap.c ft_swap.c ft_lst_utils.c \
			ft_rotate.c 

PATH_SRCS = srcs/

OBJS	=	${addprefix ${PATH_SRCS}, ${SRCS:.c=.o}}

CC		=	clang
RM		=	rm -f
CFLAGS	=	-Wall -Werror -Wextra

LIBFT	=	Libft

LIBFT_LIB = Libft/libft.a

INCL	=	include

LFLAGS = -L ${LIBFT}

.c.o:
			${CC} ${CFLAGS} -I${LIBFT} -I${INCL} -g -c $< -o ${<:.c=.o}

# avec graph : git clone --recurse-submodules https://github.com/forfungg/push_swap.git; cd push_swap; make
# sans graph : git clone --recurse-submodules https://github.com/forfungg/push_swap.git; cd push_swap; make nograph

$(NAME):	${OBJS}
			make -C ${LIBFT}
			${CC} ${CFLAGS} ${LFLAGS} ${OBJS} -o ${NAME} ${LIBFT_LIB}

all:		${NAME}

clean:
			${RM} ${OBJS}
			make clean -C ${LIBFT}

fclean:		clean
			${RM} ${NAME} ${LIBFT_LIB}
					
re:			fclean all

.PHONY:		all clean fclean re