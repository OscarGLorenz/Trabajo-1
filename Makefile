#Compilador a usar
CC=gcc

#Flags
#(-I.) Buscar en este directorio las dependencias
CFLAGS=-I. -lm -std=c99

#Dependencias (archivo.h)
DEPS = Benchmark.h Cost.h Datacreator.h TUI.h

#Objetos (archivo.o)
OBJ = main.o Benchmark.o Cost.o Datacreator.o TUI.o

#Compila todos los archivos objeto
%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

#Linkea todos los archivos objeto
main: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

#Borra los archivos objeto
clean:
	rm -f *.o
