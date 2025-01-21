#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

template <typename T>
void swap(vector<T>& tab, int i, int j){
    	T tmp = tab[i]; 
    	tab[i] = tab[j];
    	tab[j] = tmp;
};

/**
 * Génère un entier aléatoire compris entre min et max compris
 */
int randomInt(int min, int max){

	return rand() % (max - min + 1) + min;

}

/**
 * Génère un flottant aléatoire compris entre min et max compris
 */
double randomDouble(int min, int max){

	return (double)rand() / RAND_MAX * (max - min) + min;

}


/**
 * Mélange le tableau, PEUT NE PAS ETRE EFFICACE
 * Complexité en temps : O(n)
 * Complexité en espacr : O(1)
 */
template <typename T>
void shuffle(vector<T>* tab){
	
	int n = tab->size();
	for(int i = 0; i < n; i++){
		int index = randomInt(0, n-1);
		while(index == i){
			index = randomInt(0, n-1);
		}
		swap(*tab, i, index);
	}
};

/**
 * Permet d'afficher un tableau, indépendament du type qu'il contient
 */ 
template <typename T>
void displayArray(vector<T> tab){

    int n = tab.size();
    for(int i = 0; i < n; i++){
        cout << tab[i] << endl;
    }
};


int main(){

	srand(time(NULL));

    vector<string> myVector = {"Venom", "Ky", "Sol", "Slayer", "Johny"};
	cout << "--- Avant Affichage ---" << endl;
	displayArray(myVector);
	cout << "--- Après 1er affichage ---" << endl;
	shuffle(&myVector);
	cout << "--- Après mélange ---" << endl;
	displayArray(myVector);
	cout << "---Après 2nd affichage ---" << endl;
}
