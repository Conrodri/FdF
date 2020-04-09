# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: vicaster <vicaster@student.le-101.fr>      +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2018/12/11 14:16:36 by vicaster     #+#   ##    ##    #+#        #
#    Updated: 2019/05/27 20:33:22 by vicaster    ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

#	Rappel des variables automatiques:
#	$@ : produit (ou but) de la règle
#	$< : nom de la première dépendance (ou source)
#	$? : toutes les dépendances plus récentes que le but
#	$^ : toutes les dépendances
#	$+ : idem mais chaque dépendance apparait autant de fois qu'elle est cité
#	et l'ordre d'apparition est conservé.

##############################################################################
##								COULEURS									##
##############################################################################

DEFAULT =\033[0m
HIGHLIGHT =\033[1m
UNDERLINE =\033[4m
BLINK =\033[5m
BLACK =\033[30m
RED =\033[31m
GREEN =\033[32m
YELLOW =\033[33m
BLUE =\033[34m
PURPLE =\033[35m
CYAN =\033[36m
WHITE =\033[37m

##############################################################################

NAME = libft.a
CC = gcc
CFLAGS = -Wextra -Werror -Wall
SRC = ft_atoi.c ft_isdigit.c ft_memalloc.c ft_push_back.c ft_puttab.c ft_strdel.c ft_strmapi.c\
		ft_strrealloc.c ft_bzero.c ft_isprint.c ft_memccpy.c ft_putchar.c ft_strcat.c ft_strdup.c\
		ft_strncat.c ft_strrev.c ft_count_int.c ft_itoa.c ft_memchr.c ft_putchar_fd.c ft_strccpy.c\
		ft_strequ.c ft_strncmp.c ft_strsplit.c ft_count_letter.c ft_lstadd.c ft_memcmp.c ft_putendl.c\
		ft_strcdup.c ft_striter.c ft_strncpy.c ft_strstr.c ft_count_words.c ft_lstdel.c ft_memcpy.c\
		ft_putendl_fd.c ft_strchr.c ft_striteri.c ft_strndup.c ft_strsub.c ft_creat_elem.c ft_lstdelone.c\
		ft_memdel.c ft_putnbr.c ft_strclr.c ft_strjoin.c ft_strnequ.c ft_strtrim.c ft_isalnum.c ft_lstiter.c\
		ft_memmove.c ft_putnbr_fd.c ft_strcmp.c ft_strlcat.c ft_strnew.c ft_tolower.c ft_isalpha.c ft_lstmap.c\
		ft_memset.c ft_putstr.c ft_strcpy.c ft_strlen.c ft_strnstr.c ft_toupper.c ft_isascii.c ft_lstnew.c ft_print_tab.c\
		ft_putstr_fd.c ft_strcspn.c ft_strmap.c ft_strrchr.c get_next_line.c ft_str_is_numeric.c ft_strupcase.c ft_strlowcase.c\
		ft_print_tab_int.c ft_abs.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@echo "${YELLOW}Wait..${DEFAULT}"
	@$(CC) $(CFLAGS) -c $(SRC)
	@ar rc $(NAME) $(OBJ)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all

rc: re
	@make clean
