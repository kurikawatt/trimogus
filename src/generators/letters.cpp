#include "generators/letters.h"
#include "generators/numbers.h"


char random_char(){
    return random_int(97,122); //Cursed af
}

string random_string(size_t size){
    string s = "";
    for (int i = 0; i < size; i++){
        s += random_char();
    }
    return s;
}

string random_word(vector<string> &words){
    return "random";
}

vector<char> random_char_vector(size_t size){
    vector<char> c;
    for (int i = 0; i < size; i++){
        c.push_back(random_char());
    }
    c.shrink_to_fit();
    return c;
}

/*
vector<char> genCharArray(int n){
	vector<char> res;
	vector<char> charTab;
	//Obtention de la taille du fichier
	int sizeCharTab = 0;
	string ligne;
	ifstream file("letter.txt");
	while (getline (file, ligne)) {
		charTab.push_back(ligne[0]);
		sizeCharTab++;
	}
	file.close();

	//Remplissage du tableau
	for(int i = 0; i < n; i++){
		int randomIndex = randomInt(0, sizeCharTab-1);
		res.push_back(charTab[randomIndex]);
	}

	res.shrink_to_fit();
	return res;
}
*/

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