# Makefile para Proyecto 3: Implementación de Estructuras de Datos Básicas

# Definición del compilador y banderas de compilación
CC = gcc
CFLAGS = -Wall -Wextra -O2 -std=c11

# Definición de directorios
SRCDIR = src
TESTDIR = tests
SCRIPTDIR = scripts
RESULTDIR = results

# Definición de archivos fuente
SRC_FILES = $(SRCDIR)/main.c \
            $(SRCDIR)/linked_list.c \
            $(SRCDIR)/doubly_linked_list.c \
            $(SRCDIR)/stack_list.c \
            $(SRCDIR)/stack_array.c \
            $(SRCDIR)/queue_list.c \
            $(SRCDIR)/queue_array.c \
            $(SRCDIR)/bst.c \
            $(SRCDIR)/timing.c \
            $(SRCDIR)/utils.c

# Generación de archivos objeto a partir de los archivos fuente
OBJ_FILES = $(SRC_FILES:.c=.o)

# Definición de ejecutables
EXEC = data_structures
TEST_EXEC = test_data_structures

# Definición de scripts y resultados
PLOT_SCRIPT = $(SCRIPTDIR)/plot_data_structures.gnuplot
RESULT_DATA = $(RESULTDIR)/data_structures_results.dat
RESULT_PLOT = $(RESULTDIR)/data_structures_plot.png

# Regla por defecto: compilar el ejecutable principal y generar gráficos
all: $(EXEC) plot

# Regla para compilar el ejecutable principal
$(EXEC): $(OBJ_FILES)
	$(CC) $(CFLAGS) -o $@ $^

# Regla para compilar archivos objeto
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Regla para ejecutar el programa principal y generar los datos de resultados
$(RESULT_DATA): $(EXEC)
	@mkdir -p $(RESULTDIR)
	./$(EXEC) > /dev/null

# Regla para generar el gráfico utilizando GNUplot
plot: $(RESULT_DATA) $(PLOT_SCRIPT)
	gnuplot $(PLOT_SCRIPT)

# Regla para compilar y ejecutar las pruebas unitarias
test: $(TEST_EXEC)
	./$(TEST_EXEC)

# Regla para compilar el ejecutable de pruebas unitarias
$(TEST_EXEC): $(OBJ_FILES) $(TESTDIR)/test_data_structures.c
	$(CC) $(CFLAGS) -o $@ $(OBJ_FILES) $(TESTDIR)/test_data_structures.c

# Regla para limpiar archivos compilados y resultados
clean:
	rm -f $(SRCDIR)/*.o $(EXEC) $(TEST_EXEC) $(RESULT_DATA) $(RESULT_PLOT)

# Regla para limpiar sólo archivos objeto
clean-objects:
	rm -f $(SRCDIR)/*.o

# Regla para limpiar sólo ejecutables
clean-execs:
	rm -f $(EXEC) $(TEST_EXEC)

# Regla para limpiar sólo resultados
clean-results:
	rm -f $(RESULT_DATA) $(RESULT_PLOT)

# Indica que ciertas reglas no son archivos
.PHONY: all clean test plot clean-objects clean-execs clean-results

