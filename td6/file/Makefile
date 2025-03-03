# Compilateur C
CC = gcc

# Drapeaux de compilation
CFLAGS = -Wall -Wextra -Werror

# Nom de l'exécutable
TARGET = file

# Fichiers source
SRCS = main.c file.c

# Fichiers objet
OBJS = $(SRCS:.c=.o)

# Règle par défautmake
all: $(TARGET)

# Règle pour créer l'exécutable
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

# Règle pour créer les fichiers objet
%.o: %.c file.h
	$(CC) $(CFLAGS) -c $< -o $@

# Règle pour nettoyer les fichiers générés
clean:
	rm -f $(OBJS) $(TARGET)

# Règle pour supprimer tous les fichiers générés
fclean: clean
	rm -f *~

# Règle pour recompiler le programme
re: fclean all

# Règle pour afficher les règles disponibles
.PHONY: all clean fclean re
