#    Makefile - Desarrollo de Aplicaciones en Red Servidor, Cliente UDP
#    all	- Compilar todo
#    clean	- Limpiar archivos compilados
#    server	- Compilar server
#    client	- Compilar cliente

BIN = ../bin
EXECUTABLES = server
# Agregar cabeceras .h
INCLUDES = 
#Usar gcc
GCC = gcc 
#Bibliotecas
LIBS = -lm -lpthread
#FLAGS =  -std=c99
CFLAGS = -I.

#'make all' creará todos los ejecutables
all: 	$(EXECUTABLES)

#'make clean' eleminar archivos objetos
clean:
	rm -f $(BIN)/server $(BIN)/client  *.o

# Compilar los archivos .c
%.o:%.c $(INCLUDES) 
	$(GCC) $(FLAGS) $(CFLAGS) -c $<

# Generar ejecutables individuales
server: server.o
	$(GCC) $(FLAGS) $(CFLAGS) -o $(BIN)/server server.o $(LIBS)

