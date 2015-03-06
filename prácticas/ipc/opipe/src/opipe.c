#include <stdio.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argvs[]){
	int fd[2]; //Matriz de descripciones de archivos
	
	if ((pipe(fd)) < 0){
		perror("error- pipe()\n");
	}
	printf("Los descriptores son %d %d\n", fd[0], fd[1]);
	close(fd[0]);
	close(fd[1]);
	exit(EXIT_SUCCESS);
}
