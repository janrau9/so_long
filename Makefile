# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jberay <jberay@student.hive.fi>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/07 11:38:23 by jberay            #+#    #+#              #
#    Updated: 2024/02/08 11:41:56 by jberay           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Colors

DEF_COLOR = \033[0;39m
GRAY = \033[0;90m
RED = \033[0;91m
GREEN = \033[0;92m
YELLOW = \033[0;93m
BLUE = \033[0;94m
MAGENTA = \033[0;95m
CYAN = \033[0;96m
WHITE = \033[0;97m

NAME			=	so_long

CC				=	cc
CFLAGS			=	-Wall -Wextra -Werror 
RM				=	rm -rf

SRCS 			=	main.c \
					so_errors.c \
					so_delete.c \
					so_check_map.c \
					so_check_args.c \
					so_load_img.c \
					so_draw.c \
					so_utils.c \
					so_move.c
						
OBJS			=	$(SRCS:%.c=%.o)

LIBFT_PATH		=	./libft
LIBFT			=	$(LIBFT_PATH)/libft.a

all:				$(NAME)

$(NAME):			$(LIBFT) $(OBJS)
					@$(CC) $(CFLAGS) libmlx42.a $(OBJS) $(LIBFT) -Iinclude -lglfw -L"/Users/jberay/.brew/opt/glfw/lib/" -o $(NAME) 
					@echo "$(GREEN)So_long compiled!$(DEF_COLOR)"	
					
%.o:%.c
					@$(CC) $(CFLAGS) -c $< -o $@		
							
$(LIBFT):
					@make -C $(LIBFT_PATH) all bonus

clean:
					@make -C $(LIBFT_PATH) clean
					@$(RM) $(OBJS)

fclean:				clean
					@make -C $(LIBFT_PATH) fclean
					@$(RM) $(NAME)
					
re:					fclean all

.PHONY:				all bonus clean fclean re libft