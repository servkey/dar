/*
	Desarrollo de Aplicaciones en Red
	Probando fork
*/
#include <stdio.h>
#include <unistd.h> //fork
#include <stdlib.h>

int main(int argc, char *argvs[]){
	pid_t child;

	printf("Probando fork(): %d!\n", getpid());

	if ((child = fork()) == -1){
		perror("error- fork");
		exit(EXIT_FAILURE);
	}else if (child == 0){
		puts("En hijo...");
		printf("\thijo pid (id proceso) = %d  \n", getpid());
		printf("\thijo ppid (id proceso padre) = %d  \n", getppid());
	}else{
		puts("En padre...");
		printf("\tpadre pid (id proceso) = %d  \n", getpid());
		printf("\tpadre ppid (id proceso padre) = %d  \n", getppid());
	}
	printf("Terminando fork():  %d!\n", getpid());
	return 0;
}
