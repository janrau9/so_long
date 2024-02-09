# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jberay <jberay@student.hive.fi>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/07 11:38:23 by jberay            #+#    #+#              #
#    Updated: 2024/02/08 14:54:52 by jberay           ###   ########.fr        #
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

NAME			=	so_long

CC				=	cc
CFLAGS			=	-Wall -Wextra -Werror 
MLX_FLAGS		=	-Iinclude -lglfw -L"/Users/jberay/.brew/opt/glfw/lib/"
RM				=	rm -rf

LIBFT_PATH		=	./libft
LIBFT			=	$(LIBFT_PATH)/libft.a
MLX_PATH		=	./MLX42
MLX42			=	$(MLX_PATH)/build/libmlx42.a

all:				$(NAME)

$(NAME):			$(LIBFT) $(OBJS) $(MLX42)
					@$(CC) $(CFLAGS) $(MLX42) $(OBJS) $(LIBFT) $(MLX_FLAGS) -o $(NAME) 
					@echo "$(GREEN)So_long compiled!$(DEF_COLOR)"	
					
%.o:%.c
					@$(CC) $(CFLAGS) -c $< -o $@		
							
$(MLX42):
					cmake $(MLX_PATH) -B $(MLX_PATH)/build && make -C $(MLX_PATH)/build -j4

$(LIBFT):
					@make -C $(LIBFT_PATH) all bonus

clean:
					@make -C $(LIBFT_PATH) clean
					@$(RM) $(OBJS)
					@rm -rf $(MLX_PATH)/build
					@echo "$(GREEN)$(NAME) objects cleaned!$(DEF_COLOR)"	

fclean:				clean
					@make -C $(LIBFT_PATH) fclean
					@$(RM) $(NAME)
					
re:					fclean all

.PHONY:				all bonus clean fclean re