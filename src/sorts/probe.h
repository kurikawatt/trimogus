/**
 * Définition des constantes de mesures (les sondes)
 */

#pragma once

long long int __COMPARISION_COUNT__;
long long int __SWAP_COUNT__ = 0;

void __reset_probes(){__COMPARISION_COUNT__ = 0; __SWAP_COUNT__ = 0;}