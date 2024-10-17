CFLAGS = -Wall -Werror -Wextra
CC = gcc
NAME = philo

SRC = check.c init.c main.c life.c start_routine.c utils.c
OBJ_DIR = obj
OBJS = $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))

GRAY = \033[37m
GREEN = \033[32m
RESET = \033[0m

all: $(OBJ_DIR) $(NAME)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)
	@echo " "
	@echo "$(GRAY)Dossier obj créé.$(RESET)"

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
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
	@echo "$(GRAY)Dossier obj et fichiers objets supprimés.$(RESET)"

fclean: clean
	@rm -rf $(NAME)
	@echo "$(GRAY)Exécutable supprimé.$(RESET)"

re: fclean all

.PHONY: all clean fclean re
