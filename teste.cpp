#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <sys\timeb.h> 
#include <time.h>

struct timeb start, startu, end, endu;
float diff, diffu;

void NoLoopUnrollingFor (void) {
    int i,i2;
    long int a[100000];
    
    clock_t tempo;
	tempo = clock();

	for(i2=0;i2<1000;i2++){
    	for(i=0;i<100000;i++)
        	a[i] = 0;
	}
    
    diffu = (float) (clock() - tempo) / (double)CLOCKS_PER_SEC;
    
    printf("\nUnfactored code done! ELAPSED TIME: %.2f seconds", diffu);
}

void LoopUnrollingFor (void) {
    int i, i2;
    int a[100000];
    
    clock_t tempo;
	tempo = clock();

	for(i2=0;i2<1000;i2++){
	    for(i=0;i<100000;i+=10){
	        a[i] = 0;
	        a[i+1] = 0;
	        a[i+2] = 0;
	        a[i+3] = 0;
	        a[i+4] = 0;
	        a[i+5] = 0;
	        a[i+6] = 0;
	        a[i+7] = 0;
	        a[i+8] = 0;
	        a[i+9] = 0;
	    }
	}

    diff = (float) (clock() - tempo) / (double)CLOCKS_PER_SEC;
    
    printf("\nFactored code done! ELAPSED TIME: %.2f seconds", diff);
}

void NoLoopUnrollingWhile (void) {
    int i,i2;
    long int a[100000];
    
    clock_t tempo;
	tempo = clock();

	for(i2=0;i2<1000;i2++){
		i = 0;
    	while(i<100000){
			a[i] = 0;
			
			i++;
		}
	}
    
    diffu = (float) (clock() - tempo) / (double)CLOCKS_PER_SEC;
    
    printf("\nUnfactored code done! ELAPSED TIME: %.2f seconds", diffu);
}

void LoopUnrollingWhile (void) {
    int i, i2;
    int a[100000];
    
    clock_t tempo;
	tempo = clock();

	for(i2=0;i2<1000;i2++){
		i = 0;
    	while(i<100000){
			a[i] = 0;
	        a[i+1] = 0;
	        a[i+2] = 0;
	        a[i+3] = 0;
	        a[i+4] = 0;
	        a[i+5] = 0;
	        a[i+6] = 0;
	        a[i+7] = 0;
	        a[i+8] = 0;
	        a[i+9] = 0;
			
			i+=10;
		}
	}
 
    diff = (float) (clock() - tempo) / (double)CLOCKS_PER_SEC;
    
    printf("\nFactored code done! ELAPSED TIME: %.2f seconds", diff);
}

int isWorking(){	
	clock_t tempo;
	tempo = clock();

    // código de teste
	Sleep(1000);
	//fim
	printf("Tempo:%f",(clock() - tempo) / (double)CLOCKS_PER_SEC);
}

int main(){
	
	printf("Iniciando for...\n");
	
    NoLoopUnrollingFor();
    LoopUnrollingFor();
    
    printf("\n------------------------------------------------\n");
    
    printf("\nIniciando while...\n");
    
    NoLoopUnrollingWhile();
    LoopUnrollingWhile();
	
    return(0);
}

