#    Makefile - Desarrollo de Aplicaciones en Red Servidor
#    all	- Compilar todo
#    clean	- Limpiar archivos compilados
#    ssh_login	- Compilar main

BIN = ../../bin_unix
EXECUTABLES = ssh_login
# Agregar cabeceras .h
INCLUDES = 
#Usar gcc
GCC = gcc 
#Bibliotecas
LIBS = -lm -lssh -lpthread 
#FLAGS =  -std=c99
CFLAGS =  -Wdeprecated-declarations -I /usr/include/libssh/ -I .


#'make all' creará todos los ejecutables
all: 	$(EXECUTABLES)

#'make clean' eleminar archivos objetos
clean:
	rm -f $(BIN)/ssh_login *.o

# Compilar los archivos .c
%.o:%.c $(INCLUDES) 
	$(GCC) $(FLAGS) $(CFLAGS) -c $<

# Generar ejecutables individuales
ssh_login: ssh_login.o
	$(GCC) $(FLAGS) $(CFLAGS) -o $(BIN)/ssh_login ssh_login.o $(LIBS)

