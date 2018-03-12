#Compilador a usar
CC=gcc

#Flags
#(-I.) Buscar en este directorio las dependencias
CFLAGS=-I.

#Dependencias (archivo.h)
DEPS =

#Objetos (archivo.o)
OBJ = main.o

#Compila todos los archivos objeto
%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

#Linkea todos los archivos objeto
main: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

#Borra los archivos objeto
clean:
	rm -f *.o
