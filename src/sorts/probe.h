/**
 * Définition des constantes de mesures (les sondes)
 */

#pragma once

long long int __COMPARISION_COUNT__ = 0;
long long int __SWAP_COUNT__ = 0;
long long int __BYTES_ALLOCATED__ = 0; // taile en octet
long long int __BUFFER_SIZE__ = 0; // nombre d'éléments bufferisés

void __reset_probes(){
    __COMPARISION_COUNT__ = 0; 
    __SWAP_COUNT__ = 0; 
    __BYTES_ALLOCATED__ = 0;
    __BUFFER_SIZE__ = 0;
}