#include <stdio.h>

/**calcul amélioré du modulo. Evite les résultats négatifs.**/
int Modulo (int chiffre, int classe){
	int reste = chiffre % classe;	
	while(reste < 0){
		reste+= classe;
	}
	return reste;
}
/**Permet de calculer le syndrome pour un vecteur et une matrice donnés.
 * Simple mutiplication matricielle
 * 
 * @param res 
 * 		le tableau qui accueillera le résultat de la multiplication. C'est le syndrome.
 * @param first
 * 		Le premier vecteur (pour nous y) à gauche de la multiplication.
 * @param second
 * 		une matrice à droite de la multiplication. H pour nous.
 **/

void Syndrome (int res[3], int first[7], int second[7][3])
{
	int i = 0, j=0;
	for(i=0; i< 3; i++){
		res[i] = 0;
		for(j=0; j<7; j++){
			res[i] += first[j]*second[j][i];
		}
	res[i] = Modulo(res[i], 7);
	}
}
/**Vérification si un syndrome vaut bien 0.
 * 
 * @param syndrome 
 * 		Le syndrome (taille 3) à tester
 * 
 * @return
 * 		1 si le syndrome vaut 0.
 * 		0 si au moins un élément du syndrome vaut 0.
 **/
int GoodSyndrome(int syndrome[3]){
	if((syndrome[0] == 0) && (syndrome[1] == 0) && (syndrome[2] == 0)){
		return 1;
	} else{
		 return 0;
	 }
}

int main(void)
{	/*########## déclaration variables ##########*/
	int i,j;

	/*########## déclaration tableaux ##########*/
	int y[7]; 			//notre mot de code à corriger
	int H[7][3];		//notre matrice de controle (deja transposée)
	int syndrome[3];	//le syndrome, résultat de y*H
	
	/*########## initialisation H ##########*/
	printf("Quel est la transposée de la matrice de contrôle ?\n");
	for(i = 0; i < 3; i++){
		for(j = 0; j< 7; j++){
			printf("H[%d][%d] =", j+1, i+1);
			scanf("%d", &H[j][i]);
		}
	}
	
	/*##########initialisation y ##########*/
	printf("Quel est le mot y à corriger ?\n");
	for(i = 0; i < 7; i++){
		printf("y[%d] = ", i+1);
		scanf("%d", &y[i]);
	}
	
	/*########## test validité y ##########*/
	Syndrome(syndrome, y, H);
	if(GoodSyndrome(syndrome)){
		printf("Le mot est correcte (syndrome = 0)\n");
	} else{
		/*########## exhaustation ##########*/
		
		/**Part de la dernière coordonnée de y, et ajoute toujours 1
		* de manière a faire le tour du modulo. Le but : regarder une coordonnée avec son syndrome, 
		* et tant qu'il ne vaut pas 0, ajouter 1. Une fois cette opération faite 7x
		* (donc revenus à la case départ), on passe à la coordonnée précédente et on recommence a ajouter 1.
		* 
		* @todo ajouter réponse si pas de correction possible et améliorer commentaires
		**/
		i=6; 
		do{
			j = 0;
			do{
				y[i]++; //ajoute 1 à la coordonnée pour ensuite tester le syndrome
				y[i] = Modulo(y[i], 7);	//évite d'avoir une coordonnée à 7 ou 8
				Syndrome(syndrome, y, H);	//calcul le syndrome de y*H et le met dans syndrome
				j++; //sert d'index. quand il vaut 7, alors on a fait le tour du modulo donc on peut arreter.
			} while(!(GoodSyndrome(syndrome)) && j< 7); //s'arrête quand le syndrome vaut 0 ou qu'on a fait le tour du modulo (on a ajouté 7 à notre coordonnée, donc retour à la  case départ)
			i--;
		} while(!(GoodSyndrome(syndrome)) && i >= 0); //s'arrete aussi quand le syndrome vaut 0 ou qu'on a fait toutes les coordonnées des vecteurs
		if(GoodSyndrome(syndrome)){
			printf("Le mot corrigé est (%d, %d, %d, %d, %d, %d, %d)\n", y[0], y[1], y[2], y[3], y[4], y[5], y[6]); //simple impression si le syndrome a été corrigé
		} else{
			printf("Le mot ne peut pas être corrigé, car l'erreur est de poids supérieur à 1\n");
		}
		
	}
	return 0;
}
