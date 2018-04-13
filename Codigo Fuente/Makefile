#Compilador a usar
CC=gcc

#Flags
CFLAGS=-lm -std=c99 -pedantic-errors -Wall

#Objetivo
TARGET=main

#Dependencias (archivo.h)
DEPS = Benchmark.h Datacreator.h TUI.h Algorithm.h Dataorganizer.h

#Objetos (archivo.o)
OBJ = Benchmark.o Datacreator.o TUI.o Algorithm.o Dataorganizer.o $(TARGET).o


#Compila todos los archivos objeto
%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

#Linkea todos los archivos objeto
$(TARGET): $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

#Borra los archivos objeto
clean:
	rm -f *.o
