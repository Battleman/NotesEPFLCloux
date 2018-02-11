#include <stdio.h>

int main(void){
	int i,j,K;
	int pS, sS;
	int S[2];
	int e[5];
	int boolean = 0;
	printf("Entrer le premier élément de s\n");
	scanf("%d", &S[0]);
	printf("Entrer le second élément de s\n");
	scanf("%d", &S[1]);
	while(!boolean) {
		for(i = 4; i >= 0; i--){
			for(K = 0; K < 5; K++){
				e[K] = 0;
			}
			for(j = 1; j< 13 ; j++){
				e[i] = j;
				pS =  (5*e[0] + 6*e[1] + e[2] + e[3]) %13 ;
				sS =  (10*e[0]+8*e[1]+7*e[2]+e[4]) %13 ;
				if( (S[0] == pS) && (S[1] == sS)){
					printf("e = (%d,%d,%d,%d,%d)\n", e[0],e[1],e[2],e[3],e[4]);
					boolean=1;
				}
			}
		}
	}
	

	return 0;
}
