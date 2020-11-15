#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main(){
	printf("Program Sekuens Collatz\n");
	
	int n=0;
	pid_t pid;

	while(n<=0){
		printf("Inputkan bilangan lebih dari 0: "); 
  		scanf("%d", &n);	
	
		if(n<=0){
			printf("Input tidak sesuai.\n\n");
		}
	}

	pid = fork();

		if (pid == 0){
			printf("Proses oleh Child\n");
			printf("%d,",n);
			while (n!=1){
				if((n%2)==0){
					n = n/2;
				} else if (n%2 == 1){
					n = 3*n + 1;
				}	
			
				if(n==1){
					printf("%d.\n",n);
				} else {
					printf("%d,", n);
				}
			}
		
			printf("Akhir proses oleh Child\n");
		} else {
			printf("\nParent menunggu Child selesai\n");
			wait();
			printf("Proses oleh Parent selesai.\n");
		}
	return 0; 
}
