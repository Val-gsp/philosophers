CFLAGS = -Wall -Werror -Wextra -I ft_printf
CC = gcc
NAME = philo

PRINTF_DIR = ft_printf
PRINTF_LIB = $(PRINTF_DIR)/libftprintf.a

SRC = check.c init.c main.c life.c utils.c
OBJ_DIR = obj
OBJS = $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))

GRAY = \033[37m
GREEN = \033[32m
RESET = \033[0m

all: $(OBJ_DIR) $(PRINTF_LIB) $(NAME)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)
	@echo " "
	@echo "$(GRAY)Dossier obj créé.$(RESET)"

$(PRINTF_LIB):
	@$(MAKE) -C $(PRINTF_DIR)
	@echo "$(GRAY)ft_printf compilé.$(RESET)"

$(NAME): $(OBJS) $(PRINTF_LIB)
	@$(CC) $(CFLAGS) $(OBJS) $(PRINTF_LIB) -o $(NAME)
	@echo " "
	@echo "$(GREEN)Compilation terminée -> $(NAME)$(RESET)"
	@echo " "
	@echo "$(GREEN)1 -> ./philo <Nombre de philo> <Temps avant qu'un philo meure de faim> <Temps pour manger> <Temps pour dormir> <Objectif repas>$(RESET)"
	@echo "$(GREEN)Exemple -> ./philo 4 410 200 200 5$(RESET)"
	@echo " "

$(OBJ_DIR)/%.o: %.c | $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@ 
	@echo "$(GRAY)Fichier $@ compilé.$(RESET)"

clean:
	@rm -rf $(OBJ_DIR)
	@$(MAKE) -C $(PRINTF_DIR) clean
	@echo "$(GRAY)Dossier obj et fichiers objets supprimés.$(RESET)"

fclean: clean
	@rm -rf $(NAME)
	@$(MAKE) -C $(PRINTF_DIR) fclean
	@echo "$(GRAY)Exécutable et ft_printf supprimés.$(RESET)"

re: fclean all

.PHONY: all clean fclean re
