CFLAGS = -Wall -Werror -Wextra -I ft_printf
CC = gcc
NAME = philo

# Chemins vers ft_printf
PRINTF_DIR = ft_printf
PRINTF_LIB = $(PRINTF_DIR)/libftprintf.a

# Fichiers sources
SRC = check.c init.c main.c life.c utils.c
OBJ_DIR = obj
OBJS = $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))

# Couleurs pour les messages
GRAY = \033[37m
GREEN = \033[32m
RESET = \033[0m

# Compilation du projet principal
all: $(OBJ_DIR) $(PRINTF_LIB) $(NAME)

# Création du répertoire obj
$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)
	@echo " "
	@echo "$(GRAY)Dossier obj créé.$(RESET)"

# Compilation de ft_printf
$(PRINTF_LIB):
	@$(MAKE) -C $(PRINTF_DIR)
	@echo "$(GRAY)ft_printf compilé.$(RESET)"

# Compilation de philo
$(NAME): $(OBJS) $(PRINTF_LIB)
	@$(CC) $(CFLAGS) $(OBJS) $(PRINTF_LIB) -o $(NAME)
	@echo " "
	@echo "$(GREEN)Compilation terminée -> $(NAME)$(RESET)"
	@echo " "
	@echo "$(GREEN)1 -> ./philo <Nombre de philo> <Temps avant qu'un philo meure de faim> <Temps pour manger> <Temps pour dormir> <Objectif repas>$(RESET)"
	@echo "$(GREEN)Exemple -> ./philo 4 410 200 200 5$(RESET)"
	@echo " "

# Compilation des fichiers objets
$(OBJ_DIR)/%.o: %.c | $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@ 
	@echo "$(GRAY)Fichier $@ compilé.$(RESET)"

# Nettoyage des objets
clean:
	@rm -rf $(OBJ_DIR)
	@$(MAKE) -C $(PRINTF_DIR) clean
	@echo "$(GRAY)Dossier obj et fichiers objets supprimés.$(RESET)"

# Nettoyage complet (objets + exécutable)
fclean: clean
	@rm -rf $(NAME)
	@$(MAKE) -C $(PRINTF_DIR) fclean
	@echo "$(GRAY)Exécutable et ft_printf supprimés.$(RESET)"

# Recompilation complète
re: fclean all

.PHONY: all clean fclean re
