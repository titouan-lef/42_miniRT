# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pchalmin <pchalmin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/17 10:15:36 by pchalmin          #+#    #+#              #
#    Updated: 2025/03/17 17:13:27 by pchalmin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := so_long
HEADERS_DIR := headers
SOURCES_DIR := sources
OBJ_DIR := object

SOURCES := 


OBJS := $(addprefix $(OBJ_DIR)/, $(notdir $(SOURCES:%.c=%.o)))

LIBFT_DIR := libft
LIBFT_INCLUDES := $(LIBFT_DIR)/headers
LIBFT := $(LIBFT_DIR)/libft.a

MLX_DIR := MacroLibX
MLX_INCLUDES := $(MLX_DIR)/includes 
MLX_LIB := $(MLX_DIR)/libmlx.so

CC := cc
CFLAGS := -Wall -Wextra -Werror -g
IFLAGS := -I $(HEADERS_DIR) -I $(MLX_INCLUDES) -I $(LIBFT_INCLUDES)
RM = rm -rf
DIR_DUP = mkdir -p $(@D)

all: $(NAME) $(OBJS)
 
$(NAME) : $(OBJS) $(MLX_LIB) $(LIBFT)  
	@$(CC) $(CFLAGS) $(IFLAGS) $^ -o $@ -lm -lSDL2

$(LIBFT) :
	@$(MAKE) -C $(LIBFT_DIR) --no-print-directory -j

$(MLX_LIB) :
	@$(MAKE) -C $(MLX_DIR) --no-print-directory -j

$(OBJ_DIR)/%.o: $(SOURCES_DIR)/%.c
	@$(DIR_DUP)
	@$(RM) $(OBJ_DIR)

$(OBJ_DIR)/%.o: $(SOURCES_DIR)/%.c
	@$(DIR_DUP)
	@$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@

bonus: $(NAME_BONUS) $(OBJS)
 
$(NAME) : $(OBJS) $(MLX_LIB) $(LIBFT)  
	@$(CC) $(CFLAGS) $(IFLAGS) $^ -o $@ -lm -lSDL2

$(LIBFT) :
	@$(MAKE) -C $(LIBFT_DIR) --no-print-directory -j

$(MLX_LIB) :
	@$(MAKE) -C $(MLX_DIR) --no-print-directory -j

$(OBJ_DIR)/%.o: $(SOURCES_DIR)/%.c
	@$(DIR_DUP)
	@$(RM) $(OBJ_DIR)

$(OBJ_DIR)/%.o: $(SOURCES_DIR)/%.c
	@$(DIR_DUP)
	@$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@

clean:
	@$(RM) $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@$(MAKE) -C $(MLX_DIR) fclean

re: fclean all

.PHONY : all clean flcean re bonus