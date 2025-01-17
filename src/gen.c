#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct personne_s{ //Il doit manquer un ptr quelque part
	char[32] nom;
	char[32] prenom;
	int age;
} personne_t;


/* Fonction permettant de swap deux élements dans un tableau (obvious) */
void swap(void* tab, int i, int j){
    int tmp = ((int*) tab)[i]; 
    ((int*) tab)[i] = ((int*) tab)[j];
    ((int*) tab)[j] = tmp;

}

double randomDouble(int min, int max){

	double res = (double)rand()/RAND_MAX * (max - min) + min;
	return res;

}

int randomInt(int min, int max){

	int res = rand() % (max - min + 1) + min;
	return res;
}

/* Fonction génerant aléatoirement un tableau de taille n, il n'y a aucun controlle sur l'aléatoire ici */
int* genIntTab(int n){


	int* res = malloc(sizeof(int)*n);
	for(int i = 0; i < n; i++){
		res[i] = randomInt(0, 10*n);
	}

	return res;
	
}

/**
 * arg "proc" == 0 -> Tableau trié
 */
int* genIntTabControlled(int n, double proc){

	int* res = malloc(sizeof(int) * n);
	for(int i = 0; i < n; i++){
		res[i] = i;
	}

	for(int i = 0; i < n-1; i++){
		double rng = randomDouble(0,1);
		if(rng < proc){
			int index = randomInt(i, n-1);
			swap(res, i, index);
		}
	}

	return res;
}

double* genDoubleTab(int n){

	double* res = malloc(sizeof(double) * n);
	for(int i = 0; i < n; i++){
		res[i] = randomDouble(0, 10 * n);
	}

	return res;
}

/*
char* genCharTab(int n ){

	char* res = malloc(sizeof(char) * n);
	for(int i = 0; i < n; i++){
		res[i] = rand() % (10*n + 1); //A MODIF
	}
}
*/

/**
 * Génère un tableau de String de taille 32 max TODO: Rajouter la gen des mots
 */
char** genStringTab(int n){

	char** res = malloc(sizeof(char[32]) * n);

	res[0] = "oui";
	res[1] = "non";
	res[2] = "oskour";
	res[3] = "Peut etre ?";
	res[4] = "Buster Wolf";

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

void displayCharTab(char* tab, int n){

	for(int i = 0; i < n; i++){
		printf("Index %d : %c\n", i, tab[i]);
	}
}

void displayStringTab(char** tab, int n){

	for(int i = 0; i < n; i++){
		printf("Index %d : %s\n", i, tab[i]);
	}
}

/**
 * Permet d'afficher de manière génerique les différents tableaux, la liste des Id est la suivante :
 * 
 * 0 - int
 * 1 - double/float
 * 2 - Char
 * 3 - String (tab de String plus précisement)
 */
void displayTab(void* tab, int n, int idType){

	switch (idType){
		case 0:
			displayIntTab((int*) tab, n);
			break;

		case 1:
			displayDoubleTab((double*) tab, n);
			break;

		
		case 2:
			displayCharTab((char*) tab, n);
			break;
		
		case 3:
			displayStringTab((char**) tab, n);
			break;

		default:
			printf("Erreur : Le type spécifié n'est pas pris en charge");
			exit(EXIT_FAILURE);
	}
}

int main(){

    srand(time(NULL));

	int n = 5;
	char** tab = genStringTab(n);
	
	/*
	displayTab(tab, n);
	shuffle(tab, n);
	*/

	displayTab(tab, n, 3);
	free(tab);



    return EXIT_SUCCESS;
}
