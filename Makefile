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

SRC = 	main.c \
		eval_expr/do_op.c \
		eval_expr/eval_expr_calcul.c \
		eval_expr/eval_expr.c \
		eval_expr/handle_minus.c \
		eval_expr/fix_min.c \
		eval_expr/my_strtol.c \
		eval_expr/util.c \
		infin_add/add.c \
		infin_add/infin_add.c \
		infin_add/min.c \
		infin_add/util_infin_add.c \
		multiplication/multiplication.c \
		multiplication/util_multiplication.c \
		division/main_div.c \
		division/div_add_method.c \
		division/div_hand_method.c \
		modulo/main_modulo.c \
		modulo/modulo_add_method.c \
		modulo/modulo_hand_method.c \

SRC_TESTS =	eval_expr/do_op.c \
			eval_expr/eval_expr_calcul.c \
			eval_expr/eval_expr.c \
			eval_expr/handle_minus.c \
			eval_expr/fix_min.c \
			eval_expr/my_strtol.c \
			eval_expr/util.c \
			infin_add/add.c \
			infin_add/infin_add.c \
			infin_add/min.c \
			infin_add/util_infin_add.c \
			multiplication/multiplication.c \
			multiplication/util_multiplication.c \
			division/main_div.c \
			division/div_add_method.c \
			division/div_hand_method.c \
			modulo/main_modulo.c \
			modulo/modulo_add_method.c \
			modulo/modulo_hand_method.c \

TESTS = tests/test_project_div.c \
		tests/test_project_mod.c \
		tests/test_project_add.c \
		tests/test_project_min.c \
		tests/test_project_mul.c \

OBJ = $(SRCLIB:.c=.o)

INC = -I./include

LIB = -L./lib -lmy

NAME = calc

CFLAGS = -Wall -Wextra

tests_run: re
		gcc $(INC) -o unit_tests $(SRC_TESTS) $(LIB) $(TESTS) --coverage -lcriterion
		./unit_tests

all: $(NAME)

$(NAME):
	@make all -s -C ./lib/my/
	@$(info ${YELLOW}Compilation avec gcc !${RESET})
	@gcc $(INC) -o $(NAME) $(SRC) $(LIB) $(CFLAGS) -g3
	@$(info ${GREEN}Compilation réussie !${RESET})

clean:
	@$(info ${YELLOW}Clean en cours !${RESET})
	@rm -f *.gcda
	@rm -f *.gcno
	@make clean -s -C ./lib/my/
	@$(info ${GREEN}Fait !${RESET})

fclean:	clean
	@make fclean -s -C ./lib/my/
	@$(info ${YELLOW}FClean en cours !${RESET})
	@rm -f $(NAME)
	@rm -f unit_tests
	@$(info ${GREEN}Fait !${RESET})

re:	clean fclean all