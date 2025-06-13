# Makefile for lab04, exercise 1

# Nombre del ejecutable
EXEC = main

# Archivos fuente
SRC = main.c

# Compilador
CC = gcc

# Flags de compilación (añadí -Wall para mostrar advertencias, podés sumar -g para debug)
CFLAGS = -Wall -std=c99

# Regla por defecto
all: $(EXEC)

# # Run target
run: $(EXEC)
	./$(EXEC)
# Cómo compilar el ejecutable
$(EXEC): $(SRC)
	$(CC) $(CFLAGS) -o $(EXEC) $(SRC)

# Regla para limpiar archivos generados
clean:
	rm -f $(EXEC)