#include <iostream>
#include <string>
#include <vector>

using namespace std;

template <typename T>
int partition(vector<T>& arr, int low, int high) {
  
    T pivot = arr[high];
    int i = low - 1;

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);  
    return i + 1;
}

template <typename T>
void quickSort(vector<T>& arr, int low, int high) {
  
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

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
    int nint = vecint.size();

    vector<float> vecfloat = {0.1,0.2,0.25,0.34,0.7,0.6,0.89,0.11,0.251}; // vec float
    int nfloat = vecfloat.size();

    vector<double> vecdouble = {0,1,2,34,7,6,89,10,25}; // vec int
    int ndouble = vecdouble.size();

    vector<string> vecstring = {"Banane","banane","pomme","Poire","2spi"}; // vec char
    int nstring = vecstring.size();

    //testers
    display(vecint);
    quickSort(vecint,0,nint-1);
    display(vecint);

    display(vecfloat);
    quickSort(vecfloat,0,nfloat-1);
    display(vecfloat);

    display(vecdouble);
    quickSort(vecdouble,0,nfloat-1);
    display(vecdouble);

    display(vecstring);
    quickSort(vecstring,0,nstring-1);
    display(vecstring);

    cout << "END." << endl;

    return 0;
};