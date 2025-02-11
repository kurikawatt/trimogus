#include <cmath>
#include <iostream>

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

    int nbOccur = floor(size/26);
    int nbRestant = size - (nbOccur * 26);

    for(int i = 0; i < 26; i++){
        for(int j = 0; j < nbOccur; j++){
            c.push_back((char) 97+i);
        }
        if(nbRestant != 0){
            c.push_back((char) 97+i);
            nbRestant--;
        }
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

void nextWord(string &currWord){

    int size = currWord.size();

    for(int i = size-1; i >= 0; i--){
        if(currWord[i] != 'z'){
            currWord[i]++;
            break;
        } else {
            currWord[i] = 'a';
        }
    }
}

void previousWord(string &currWord){
    int size = currWord.size();

    for(int i = size-1; i >= 0; i--){
        if(currWord[i] != 'a'){
            currWord[i]--;
            break;
        } else {
            currWord[i] = 'z';
        }
    }
}



vector<string> random_string_vector_controlled(size_t size, float proc){
    vector<string> c;

    //Détermination de la taille des string
    int len = 0;
    while(pow(26,len) < size){
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


vector<string> random_word_vector_controlled(size_t size, vector<string> &words, float proc){
    vector<string> c;

    int tailleDoc = words.size();
    int nbOccur = floor(size/tailleDoc);
    int nbRestant = size - (nbOccur * tailleDoc);

    for(int i = 0; i < tailleDoc-1; i++){
        for(int j = 0; j < nbOccur; j++){
            c.push_back(words[i]);
        }
        if(nbRestant != 0){
            c.push_back(words[i]);
            nbRestant--;
        }
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

vector<char> reversed_sorted_char_vector(size_t size){
    vector<char> c;

    int nbOccur = floor(size/26);
    int nbRestant = size - (nbOccur * 26);

    for(int i = 1; i < 27; i++){
        for(int j = 0; j < nbOccur; j++){
            c.push_back((char) 123-i);
        }
        if(nbRestant != 0){
            c.push_back((char) 123-i);
            nbRestant--;
        }
    }
      
    c.shrink_to_fit();
    return c;

}

vector<string> reversed_sorted_word_vector(size_t size, vector<string> words){
    vector<string> c;

    int tailleDoc = words.size();
    int nbOccur = floor(size/tailleDoc);
    int nbRestant = size - (nbOccur * tailleDoc);


    for(int i = tailleDoc-1; i >= 0; i--){
        for(int j = 0; j < nbOccur; j++){
            c.push_back(words[i]);
        }
        if(nbRestant != 0){
            c.push_back(words[i]);
            nbRestant--;
        }
    }

    c.shrink_to_fit();
    return c;

}

vector<string> reversed_sorted_string_vector(size_t size){

    vector<string> c;

    //Détermination de la taille des string
    int len = 0;
    while(pow(26,len) < size){
        len++;
    }

    //Géneration du tableau triée
    string mot(len, 'z'); //Génère un mot de taille "size" constitué uniquement de 'a'
    for(int i = 0; i < size; i++){
        c.push_back(mot);
        previousWord(mot);
    }

    return c;
}

