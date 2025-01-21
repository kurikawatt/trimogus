#include <iostream>
#include <vector>

using namespace std;

template <typename T>
void swap(vector<T> tab, int i, int j){
    T tmp = tab[i]; 
    tab[i] = tab[j];
    tab[j] = tmp;

};

template <typename T>
void displayArray(vector<T> tab){

    int n = tab.size();
    for(int i = 0; i < n; i++){
        cout << tab[i] << endl;
    }
};


int main(){
    vector<string> myVector = {"Venom", "Ky", "Sol", "Slayer", "Johny"};
    displayArray(myVector);
}
