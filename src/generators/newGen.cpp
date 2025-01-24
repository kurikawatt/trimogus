#include <iostream>
#include <vector>
#include <fstream>
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
        cout << "Indice " << i << " : " << tab[i] << endl;
    }
};

vector<int> genIntArray(int n){
	vector<int> res;
	for(int i = 0; i < n; i++){
		res.push_back(randomInt(0, 10*n));
	}

	res.shrink_to_fit();
	return res;
}


vector<float> genFloatArray(int n){
	vector<float> res;
	for(int i = 0; i < n; i++){
		res.push_back((float) randomDouble(0, 10*n));
	}
	res.shrink_to_fit();
	return res;
}

vector<double> genDoubleArray(int n){
	vector<double> res;
	for(int i = 0; i < n; i++){
		res.push_back(randomDouble(0, 10*n));
	}
	res.shrink_to_fit();
	return res;
}

vector<char> genCharArray(int n){
	vector<char> res;
	vector<char> charTab;
	//Obtention de la taille du fichier
	int sizeCharTab = 0;
	string ligne;
	ifstream file("letter.txt");
	while (getline (file, ligne)) {
		charTab.push_back(ligne[0]);
		sizeCharTab++;
	}
	file.close();

	//Remplissage du tableau
	for(int i = 0; i < n; i++){
		int randomIndex = randomInt(0, sizeCharTab-1);
		res.push_back(charTab[randomIndex]);
	}

	res.shrink_to_fit();
	return res;
}

vector<string> genStringArray(int n){

	vector<string> res;
	vector<string> stringTab;
	//Obtention de la taille du fichier
	int sizeStringTab = 0;
	string ligne;
	ifstream file("wordsFile.txt");
	while (getline (file, ligne)) {
		stringTab.push_back(ligne);
		sizeStringTab++;
	}
	file.close();

	//Remplissage du tableau
	for(int i = 0; i < n; i++){
		int randomIndex = randomInt(0, sizeStringTab-1);
		res.push_back(stringTab[randomIndex]);
	}

	res.shrink_to_fit();
	return res;
}

int main(){

	srand(time(NULL));

	vector<int> myVector = genIntArray(1000000);
	//displayArray(myVector);

}
