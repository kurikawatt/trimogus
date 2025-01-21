#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

template <typename T>
void swap(vector<T> tab, int i, int j){
    T tmp = tab[i]; 
    tab[i] = tab[j];
    tab[j] = tmp;
};

int randomInt(int min, int max){

	int res = rand() % (max - min + 1) + min;
	return res;

}

double randomDouble(int min, int max){

	double res = (double)rand() / RAND_MAX * (max - min) + min;
	return res;

}

void shuffle(vector<T> tab){

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
    	displayArray(myVector);
	cout << randomInt(0, 10) << endl;
	cout << randomDouble(0, 10) << endl;
}
