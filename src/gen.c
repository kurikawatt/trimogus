#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/** Notes
 *
 * 4 Tailles de données : 100, 5_000, 100_000, 1_000_000 (int only)
 * Chiffre géneré compris entre 0 et 10n
 * Capable de génerer des int, double, char, char* (string)
 * 4 type de tab : complètement rng, Quasi trié, quasi trié à l'envers, Déja trié sauf à la fin
 *
 */

/* Fonction permettant de swap deux élements dans un tableau (obvious) */
void swap(void* tab, int i, int j){
    int tmp = ((int*) tab)[i]; 
    ((int*) tab)[i] = ((int*) tab)[j];
    ((int*) tab)[j] = tmp;

}

/* Fonction génerant aléatoirement un tableau de taille n, il n'y a aucun controlle sur l'aléatoire ici */
int* genIntTab(int n){


	int* res = malloc(sizeof(int)*n);
	for(int i = 0; i < n; i++){
		res[i] = rand() % (10*n + 1);
	}

	return res;
	
}

double* genDoubleTab(int n){

	double* res = malloc(sizeof(double)*n);
	for(int i = 0; i < n; i++){
		res[i] = ((double)rand() / RAND_MAX) * 10 * n;
	}

	return res;
}

/* 
 * Mélange le tableau donnée en entrée
 * Complexite en Temps : O(n)
 * Complexite en Espace : O(1)
 * */
void shuffle(int* tab, int n){
	
	for(int i = 0; i < n; i++){
		int index = rand() % (n);
		while(index == i){
			index = rand() % (n);
		}
		swap(tab, i, index);
	}
}

void displayIntTab(int* tab, int n){

	for(int i = 0; i < n; i++){
		printf("Index %d : %d\n", i, tab[i]);
	}

}

void displayDoubleTab(double* tab, int n){

	for(int i = 0; i < n; i++){
		printf("Index %d : %f\n", i, tab[i]);
	}

}

/**
 * Permet d'afficher de manière génerique les différents tableaux, la liste des Id est la suivante :
 * 
 * 0 - int
 * 1 - double/float
 * 2 - Char
 * 3 - String
 */
void displayTab(void* tab, int n, int idType){

	switch (idType){
		case 0:
			displayIntTab((int*) tab, n);
			break;

		case 1:
			displayDoubleTab((double*) tab, n);
			break;

		/*
		case 2:
			displayCharTab((char*) tab, n);
			break;

		case 3:
			displayStrTab((char**) tab, n);
			break;
		*/

		default:
			printf("Erreur : Le type spécifié n'est pas pris en charge");
			exit(EXIT_FAILURE);
	}
}




int main(){
    srand(time(NULL));

	int n = 10;
	double* tab = genDoubleTab(n);
	
	/*
	displayTab(tab, n);
	shuffle(tab, n);
	*/
	displayTab(tab, n, 1);
	free(tab);



    return EXIT_SUCCESS;
}
