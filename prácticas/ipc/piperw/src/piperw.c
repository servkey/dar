/*
	Abrir conducto y hacer fork a un proceso hijo
	El hijo hace la lectura
	El padre hace la escritura
*/
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <fcntl.h>
#include <limits.h>

#define BUFSZ PIPE_BUF

int main(int argc, char *argv[]){
	int fd[2]; //Matriz de descripciones de archivos
	int fdin;
	char buf[BUFSZ];
	int len;
	pid_t child;

	//Crear conducto o tubería sin nombre
	if ((pipe(fd)) < 0){
		perror("error- pipe()\n");
	}

	//Crear proceso con fork y cerrar descriptores apropiados
	if ((child = fork()) == -1)
	{
		perror("fork()\n");
	}
	else if (child == 0){
		printf("En proceso hijo...\n");
		//Estamos en el hijo
		close(fd[1]); //Cerrar escritura
		while((len = read(fd[0], buf, BUFSZ)) > 0)
			write(STDOUT_FILENO, buf, len); //Mostrar en salida estándar el contenido de buf
		close(fd[0]); //Cerrar lectura
		
	}else
	{		
		printf("En proceso padre...\n");
		//Estamos en el padre
		close(fd[0]); //Cerar lectura
		if ((fdin = open(argv[1], O_RDONLY)) < 0)
		{
			perror("open()");
			//Enviar algo al conducto aunque no se haya podido abrir la entrada
			write(fd[1], "123\n",4);	
		}else{
			while((len = read(fdin, buf, BUFSZ)) > 0)
				write(fd[1], buf, len);
			close(fdin);
		}
		//Cerrar el descriptor de escritura del padre
	}
	//Recoger el estado de la salida
	waitpid(child, NULL, 0);
	exit(EXIT_SUCCESS);
}
