#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Fonction génerant aléatoirement un tableau de taille n, il n'y a aucun controlle sur l'aléatoire ici */
int* genIntTab(int n){

	srand(time(NULL));

	int* res = malloc(sizeof(int)*n);
	for(int i = 0; i < n; i++){
		res[i] = rand();
	}

	return res;
	
}

/* 
 * Mélange le tableau donnée en entrée
 * Complexite en Temps : O(n)
 * Complexite en Espace : O(1)
 * DOESNT WORK
 * */
void shuffle(int* tab, int n){
	
	for(int i = 0; i > n; i++){
		int index = rand() % (n + 1);
		int tmp = tab[i];
		tab[i] = tab[index];
		tab[index] = tmp;
	}
}

void displayTab(int* tab, int n){

	for(int i = 0; i < n; i++){
		printf("Index %d : %d\n", i, tab[i]);
	}
}


int main(){
    
	int n = 5;
	int* tab = genIntTab(n);

	displayTab(tab, n);
	shuffle(tab, n);
	displayTab(tab, n);
	free(tab);



    return EXIT_SUCCESS;
}
