#Compilador a usar
CC=gcc

#Flags
#(-I.) Buscar en este directorio las dependencias
CFLAGS=-I. -lm

#Objetivo
TARGET=Maintest

#Dependencias (archivo.h)
DEPS = Benchmark.h Cost.h Datacreator.h TUI.h Algorithm.h Dataorganizer.h Lucky.h

#Objetos (archivo.o)
OBJ = $(TARGET).o Benchmark.o Cost.o Datacreator.o TUI.o Algorithm.o Dataorganizer.o Lucky.o


#Compila todos los archivos objeto
%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

#Linkea todos los archivos objeto
$(TARGET): $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

#Borra los archivos objeto
clean:
	rm -f *.o
