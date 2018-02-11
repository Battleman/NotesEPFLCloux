#include <stdio.h>


/*NOTE AUX CORRECTEURS : POUR LANCER LE PROGRAMME, ALLEZ DANS LA CONSOLE (A L'EMPLACEMENT DU FICHIER
 * ET ENTREZ ./nom_du_fichier . SI VOUS N'AVEZ "PAS LES DROITS", RENDEZ LE FICHIER EXECUTABLE (LINUX : chmod +x nom_du_fichier).
 */
 
 
  
int motCode[3];
int G[5][3]; /* matrice génératrice*/
int i,j,k = 0; /* indices courants */
int encode[5]; /*le mot encodé*/

void introduction(){
	printf("Bienvenue dans ce programme de calcul de distance minimale. Nous allons ici analyser récursivement\n"
			"chaque mot entre (0,0,0) et (12,12,12), le multiplier par la matrice génératrice G (que vous serez\n"
			"invité à remplir), puis calculé la distance de Hamming du mot ainsi encodé.	\n");
	printf("Commençons directement. Veuillez remplir la matrice G (rappelez vous de la notation : G[x][y] signifie colonne x, ligne y)");
}
void remplissageG(void){
	printf("*** Matrice G ***\n");
	int M, N;
	for (M=0; M<5; M++){
		for (N=0; N<3; N++){
			M+= 1; N+= 1;
			printf("Elément[%d][%d] : ",M,N);
			M-= 1; N-= 1;
			scanf("%d", &G[M][N]);
		}
	}
}
void afficherMatrice(int A[5][3]){
	int M,N;
	printf("Matrice donnée G :\n");
	for (M=0; M<3; M++) {
		for (N=0; N<5; N++){
			printf("%7d", A[N][M]);
		}
		printf("\n");
	}
}
int dimension(int tab[5]){
	int col;
	int dimension = 0;
	for(col = 0; col< 5; col++){
		if(!(tab[col] == 0) ){
			dimension++;
		}
	}
	return dimension;
}

void afficherVec(){
	int col;
	printf("(");
	for(col = 0; col < 5; col++){
		printf("%d", encode[col]);
		if(col < 4){
			printf(";");
		}
	}
	printf(")");
}

void afficheMotCode(){
	int i;
	printf("(");
	for(i = 0; i < 3; i++){
		printf("%d", motCode[i]);
		if(i < 2){
			printf(";");
		}
	}
	printf(")");
}

void mulmat(){
	int i,k;
	for (i=0; i<5; i++){
		encode[i] = 0;
		for (k=0; k<3; 	k++){
			encode[i] += (motCode[k]*G[i][k]);
		}
		encode[i] = (encode[i]) % 13;
	}
}
int main(void){
	int dmin = 5;
	int dtemp;

	introduction();
	remplissageG();
	afficherMatrice(G);
	for(i = 0; i < 12; i++){
		motCode[0]=i;
		for( j = 0; j < 12; j++){
			motCode[1] = j;
			for( k = 0; k < 12; k++){
				motCode[2] = k;
				
				mulmat();
				dtemp = dimension(encode);				
				if ((dtemp < dmin) && !(dtemp==0)){
					dmin = dtemp;
				}
				afficheMotCode(); printf(" --> "); afficherVec();  printf(" La distance de ce mot est de %d\n", dtemp); 
			}
		}
	}
	printf("La distance minimale est : %d\n ", dmin);

return 0;
}
