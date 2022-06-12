##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## Makefile
##

# Colors
BLACK        := $(shell tput -Txterm setaf 0)
RED          := $(shell tput -Txterm setaf 1)
GREEN        := $(shell tput -Txterm setaf 2)
YELLOW       := $(shell tput -Txterm setaf 3)
LIGHTPURPLE  := $(shell tput -Txterm setaf 4)
PURPLE       := $(shell tput -Txterm setaf 5)
BLUE         := $(shell tput -Txterm setaf 6)
WHITE        := $(shell tput -Txterm setaf 7)
RESET := $(shell tput -Txterm sgr0)

SRC = 	my_putchar.c \
		my_sort_int_array.c \
		my_str_isnum.c \
		my_strstr.c \
		my_compute_power_rec.c \
		my_putnbr_base.c \
		my_strcapitalize.c \
		my_str_isprintable.c \
		my_str_to_word_array.c \
		my_compute_square_root.c \
		my_put_nbr.c \
		my_strcat.c \
		my_str_isupper.c \
		my_strupcase.c \
		my_find_prime_sup.c \
		my_putstr.c \
		my_strcmp.c \
		my_strlen.c \
		my_swap.c \
		my_getnbr.c \
		my_revstr.c \
		my_strcpy.c \
		my_strlowcase.c \
		my_showmem.c \
		my_strdup.c \
		my_strncat.c \
		my_isneg.c \
		my_showstr.c \
		my_str_isalpha.c \
		my_strncmp.c \
		my_is_prime.c \
		my_show_word_array.c \
		my_str_islower.c \
		my_strncpy.c \

OBJ = $(SRC:.c=.o)

INC = my.h

NAME = libmy.a

all: $(NAME)

$(NAME): $(OBJ)
	@$(info ${YELLOW}Création de mylib.a !${RESET})
	@ar rc $(NAME) $(OBJ)
	@$(info ${GREEN}Fait !${RESET})
	@$(info ${YELLOW}CP et MV des fichiers !${RESET})
	@cp $(NAME) ../
	@cp ./$(INC) ../../include
	@$(info ${GREEN}Fait !${RESET})

clean:
	@$(info ${YELLOW}Clean LIB en cours !${RESET})
	@rm -f $(OBJ)
	@$(info ${GREEN}Fait !${RESET})

fclean:
	@$(info ${YELLOW}Fclean LIB en cours !${RESET})
	@rm -f $(NAME)
	@rm -f ../$(NAME)
	@rm -f ../../include/$(INC)
	@$(info ${GREEN}Fait !${RESET})

re: clean fclean all
