#include <iostream>
#include <cmath>
#include "generators/numbers.h"

using namespace std;

/**
 * Ce fichier permet de tester la géneration aléatoire des nombres et vérifier que la distribution soit bien uniforme
 */
int main(){

    srand(time(NULL));

    const int SAMPLE = 1000000;
    const int RANGE = 101; //NECESSITE DE MOFIFER CRITICAL SI MODIFIER (impossible a calculer sans lib supplémentaire)
    const double CRITICAL = 124.342; //Valeur à 95% de sûreté
    const double EXPECTED_PROB = (double) SAMPLE / RANGE;

    //Test pour Int
    //Création du tableau & remplissage
    int distrib_int[RANGE] = {0};
    for(int i = 0; i < SAMPLE; i++){
        distrib_int[random_int(0,RANGE-1)]++;
    }

    //Etude statistiques
    double khi_deux = 0;
    for(int i = 0; i < RANGE; i++){
        khi_deux += ((distrib_int[i] - EXPECTED_PROB) * (distrib_int[i] - EXPECTED_PROB)) / EXPECTED_PROB;
    }

    cout << "Est ce que la distribution est uniforme pour la géneration de chiffre entiers ? : " << (khi_deux < CRITICAL ) << endl;

    //Test pour float
    float distrib_float[RANGE] = {0.0};
    for(int i = 0; i < SAMPLE; i++){
        distrib_float[(int) floor(random_float(0, RANGE))]++; //DEGEUX, PEUT PLANTER
    }

    khi_deux = 0;
    for(int i = 0; i < RANGE; i++){
        khi_deux += ((distrib_float[i] - EXPECTED_PROB) * (distrib_float[i] - EXPECTED_PROB)) / EXPECTED_PROB;
    }

    cout << khi_deux << endl;
    cout << "Est ce que la distribution est uniforme pour la géneration de chiffre flottants ? : " << (khi_deux < CRITICAL ) << endl;

}