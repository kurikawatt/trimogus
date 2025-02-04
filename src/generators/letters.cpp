#include <cmath>

#include "generators/letters.h"
#include "generators/numbers.h"
#include "tools/pickers.h"

/**
 * Gènere un lettre MINUSCULE aléatoirement
 */
char random_char(){
    return random_int(97, 122); //Cursed af
}

string random_string(size_t size){
    string s = "";
    for (int i = 0; i < size; i++){
        s += random_char();
    }
    return s;
}

string random_word(vector<string> &words){
    return pick_in_vector(words);
}

vector<char> random_char_vector(size_t size){
    vector<char> c;
    for (int i = 0; i < size; i++){
        c.push_back(random_char());
    }
    c.shrink_to_fit();
    return c;
}

vector<string> random_string_vector(size_t size){
    vector<string> c;
    size_t s;
    for (int i = 0; i < size; i++){
        s = 10;
        c.push_back(random_string(s));
    }
    c.shrink_to_fit();
    return c;
}

vector<string> random_words_vector(vector<string> &words, size_t size){
    vector<string> c;
    for (int i = 0; i < size; i++){
        c.push_back(random_word(words));
    }
    c.shrink_to_fit();
    return c;
}

vector<char> random_char_vector_controlled(size_t size, float proc){
    vector<char> c;

    /*
    
    FAUT DES TRUCS
    
    */

    //Mélange du tableau selon la probabilité passé en argument
    for(int i = 0; i < size-1; i++){
		float rng = random_float(0,1);
		if(rng < proc){
			int index = random_int(i, size-1);
			swap(c[i], c[index]);
		}
	}
      
    c.shrink_to_fit();
    return c;
}

void nextWord(string &currWord){

    int size = currWord.size();

    for(int i = size-1; i > 0; i--){
        if(currWord[i] != 'z'){
            currWord[i]++;
            break;
        } else {
            currWord[i] = 'a';
        }
    }
}



vector<string> random_string_vector_controlled(size_t size, float proc){
    vector<string> c;

    //Détermination de la taille des string
    int len = 0;
    while(pow(2,1) < len){
        len++;
    }

    //Géneration du tableau triée
    string mot(len, 'a'); //Génère un mot de taille "size" constitué uniquement de 'a'
    for(int i = 0; i < size; i++){
        c.push_back(mot);
        nextWord(mot);
    }

    //Mélange du tableau selon la probabilité passé en argument
    for(int i = 0; i < size-1; i++){
		float rng = random_float(0,1);
		if(rng < proc){
			int index = random_int(i, size-1);
			swap(c[i], c[index]);
		}
	}
      
    c.shrink_to_fit();
    return c;
}