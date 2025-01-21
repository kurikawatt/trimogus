#include <iostream>
#include <string>
#include <vector>

using namespace std;

template <typename T>
void insertion(vector<T>& tab){
    
    for (size_t i = 0; i < tab.size(); i++){
        T k = tab[i];
        int j = i-1;

        while(j>= 0 && tab[j] >  k){
            tab[j+1] = tab[j];
            j=j-1;
        }

        tab[j+1]= k;
    }

};

template <typename T>
void display(vector<T>& tab){

    for (size_t i = 0; i < tab.size(); i++){
        cout << i << " = " << tab[i] <<"\n";
    }
    cout << endl;
}
int main() {
    
    int arr[] = {0,1,2,34,7,6,89,10,25}; // tab
    vector<int> vecint = {0,1,2,34,7,6,89,10,25}; // vec int
    vector<float> vecfloat = {0.1,0.2,0.25,0.34,0.7,0.6,0.89,0.11,0.251}; // vec float
    vector<double> vecdouble = {0,1,2,34,7,6,89,10,25}; // vec int
    vector<string> vecstring = {"Banane","banane","pomme","Poire","2spi"}; // vec char

    //testers
    display(vecint);
    insertion(vecint);
    display(vecint);

    display(vecfloat);
    insertion(vecfloat);
    display(vecfloat);

    display(vecdouble);
    insertion(vecdouble);
    display(vecdouble);

    display(vecstring);
    insertion(vecstring);
    display(vecstring);

    cout << "END." << endl;

    return 0;
};