#include <stdio.h>

int main(void){
	int pS, sS;
	int i,j,K;
	int donne[5];
	int S[2];
	int e[5];
	int boolean = 0;
	int eSol[5];
	printf("Entrez votre mot à corriger :\n");
	for(i=0; i< 5; i++){
		printf("Position %d : \n", i);
		scanf("%d", &donne[i]);
	}
	i=0;
	S[0] =  (5*donne[0] + 6*donne[1] + donne[2] + donne[3]) %13 ;
	S[1] =  (10*donne[0]+8*donne[1]+7*donne[2]+donne[4]) %13 ;
	if(S[0] == 0 && S[1] == 0){
		printf("Ceci est une solution");
	} else {
		for(i = 4; i >= 0; i--){
			for(K = 0; K < 5; K++){
				e[K] = 0;
				eSol[K] = 0;				
			}
			for(j = 1; j< 13 ; j++){
				e[i] = j;
				pS =  (5*e[0] + 6*e[1] + e[2] + e[3]) %13 ;
				sS =  (10*e[0]+8*e[1]+7*e[2]+e[4]) %13 ;
				if( (S[0] == pS) && (S[1] == sS)){
					eSol[i] = j;
					boolean = 1;			
				}
			}		
		}
		if(boolean){
			for(i=0; i< 4; i++){
				e[i] = donne[i]-eSol[i];
			}
			printf("Le mot corrigé est : (%d,%d,%d,%d,%d)",e[0],e[1],e[2],e[3],e[4]);
		} else {
			printf("Cette erreur ne peut pas être corrigée");
		}
	}
	return 0;
}
