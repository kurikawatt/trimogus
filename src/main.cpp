#include <iostream>
#include <string>
#include <unistd.h>

using namespace std;

void print_version(){
    cout << "Trimogus InDev" << endl;
}

int main(int argc, char *argv[]){

    int opt;

    while ( (opt = getopt(argc, argv, "v")) != -1){
        switch (opt){
            case 'v':
                print_version();
                break;
            default:
                break;
        }
    }

    return 0;
}