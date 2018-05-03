# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nsikora <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/23 16:56:40 by nsikora           #+#    #+#              #
#    Updated: 2018/05/01 11:33:23 by nsikora          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	fractol

CC		=	/usr/bin/gcc

CFLAGS	=	-Wall -Wextra -Werror 

OBJS	=	$(addprefix $(SRCDIR)/, $(SRCS:.c=.o))

RM		=	/bin/rm -f

SRCDIR	=	src

SRCS	=	main.c 					\
			key_event.c				\
			declare_data.c			\
			display_info.c			\
			display_window.c        \
			mandelbrot.c			\
			julia.c					\
			match.c					\
			burning_ship.c			\

INCLUDE =	-I includes -I mlx -I libft

LIBFT = libft/libft.a
MLX = mlx/libmlx.a

all: $(LIBFT) $(MLX) $(NAME)

$(NAME): $(OBJS)
	$(CC) -o $(NAME) $(OBJS) $(INCLUDE) -L ./libft -lft -L mlx -l mlx -framework OpenGl -framework Appkit

$(LIBFT):
	make -C libft
	
$(MLX):
	make -C mlx

%.o: %.c
	$(CC) -o $@ -c $< $(INCLUDE) $(CFLAGS)

clean:
	make clean -C libft
	$(RM) $(OBJS)

fclean: clean
	make fclean -C libft
	make clean -C mlx
	$(RM) $(NAME)

re:	fclean all

.PHONY: all re clean fclean
