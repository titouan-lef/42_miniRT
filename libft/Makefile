# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pchalmin <pchalmin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/07 17:32:00 by pchalmin          #+#    #+#              #
#    Updated: 2025/01/07 18:21:19 by pchalmin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SOURCES = ft_isalpha.c \
			ft_isdigit.c \
			ft_isalnum.c \
			ft_isascii.c \
			ft_isprint.c \
			ft_is_white_space.c \
			ft_strlen.c \
			ft_memset.c \
			ft_bzero.c \
			ft_memcpy.c \
			ft_memmove.c \
			ft_strlcpy.c \
			ft_strlcat.c \
			ft_toupper.c \
			ft_tolower.c \
			ft_strchr.c \
			ft_strrchr.c \
			ft_strncmp.c \
			ft_memchr.c \
			ft_memcmp.c \
			ft_strnstr.c \
			ft_atoi.c \
			ft_atol.c \
			ft_calloc.c \
			ft_strdup.c \
			ft_substr.c \
			ft_strjoin.c \
			ft_strtrim.c \
			ft_split.c \
			ft_itoa.c \
			ft_putchar_fd.c \
			ft_putstr_fd.c \
			ft_putendl_fd.c \
			ft_putnbr_fd.c \
			ft_strmapi.c \
			ft_striteri.c \
			ft_printf.c \
			ft_putchar.c \
			ft_putstr.c \
			ft_putptr.c \
			ft_puthex.c \
			ft_putnbr.c \
			ft_lstnew_bonus.c \
			ft_lstadd_front_bonus.c \
			ft_lstsize_bonus.c \
			ft_lstlast_bonus.c \
			ft_lstadd_back_bonus.c \
			ft_lstdelone_bonus.c \
			ft_lstclear_bonus.c \
			ft_lstiter_bonus.c \
			ft_lstmap_bonus.c \
			get_next_line_bonus.c \
			get_next_line_utils_bonus.c
			
OBJDIR = object
DEPDIR = build

OBJECTS = $(addprefix $(OBJDIR)/, $(SOURCES:.c=.o))
CDEP = $(addprefix $(DEPDIR)/, $(SOURCES:.c=.d))

RM = rm -rf

CFLAGS = -Wall -Wextra -Werror -g

CC = cc

all : $(NAME)

$(NAME): $(OBJECTS)
	@ar -rcs $(NAME) $(OBJECTS)

$(OBJDIR) $(DEPDIR):
	@mkdir -p $@

$(OBJDIR)/%.o: %.c | $(OBJDIR)
	@$(CC) $(CFLAGS) -c $< -o $@

$(DEPDIR)/%.d: %.c | $(DEPDIR)
	@$(CC) $(CFLAGS) -MM -MP -c $< -o $@

clean :
	@$(RM) $(OBJECTS) $(CDEP)
	@$(RM) $(OBJDIR) $(DEPDIR) 

fclean : clean
	@$(RM) $(NAME)

re : fclean all

.PHONY : all clean fclean re

-include $(CDEP)
