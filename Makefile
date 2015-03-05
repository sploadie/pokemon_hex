# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tgauvrit <tgauvrit@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/20 16:35:37 by tgauvrit          #+#    #+#              #
#    Updated: 2015/03/05 17:06:10 by tgauvrit         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =			pokemon_hex

CC =			gcc

FLAGS =			-Wall -Werror -Wextra -g

HEADER =		pokemon_hex.h

HEADER_DIR =	-I ./includes/ -I $(FT_LIB_DIR)

MLX_LIBS =		-L./minilibx_macos -lmlx -I./minilibx_macos -framework OpenGL -framework AppKit
				#-L/usr/X11/lib -lmlx -lXext -lX11

LIBRARIES =		-L$(FT_LIB_DIR) -l$(FT_LIB_NAME) $(MLX_LIBS)

FT_LIB_NAME =	ft

FT_LIB =		$(FT_LIB_DIR)lib$(FT_LIB_NAME).a

FT_LIB_DIR =	./libft/

SRC_DIR =		./srcs/

SRC_COMPILED =	main.o \
				gen_view.o \
				new_img.o \
				throw_error.o \
				check_malloc.o \
				gen_mlx_window.o \
				gen_default_camera.o \
				hex_expose_hook.o \
				hex_key_hook.o \
				hex_mouse_hook.o \
				hex_loop_hook.o \
				clear_img.o \
				pokemon_data.o \
				gen_sprite_bank.o \
				gen_sprite_data.o \
				gen_map.o \
				gen_entities.o \
				tile_distance.o \
				fetch_tile.o

COMPILED =		$(SRC_COMPILED)

all: $(NAME)

$(NAME): $(FT_LIB) $(SRC_COMPILED)
	$(CC) -o $(NAME) $(FLAGS) $(LIBRARIES) $(HEADER_DIR) $(SRC_COMPILED)

$(SRC_COMPILED): %.o: $(SRC_DIR)%.c
	$(CC) -c $(FLAGS) $(HEADER_DIR) $< -o $@

$(FT_LIB):
	@make -C $(FT_LIB_DIR);

clean:
	@make clean -C $(FT_LIB_DIR);
	-/bin/rm -f $(COMPILED)

fclean: clean
	-/bin/rm -f $(FT_LIB)
	-/bin/rm -f $(NAME)

re: fclean all
