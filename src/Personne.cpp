#include <iostream>

using namespace std;

class Personne{
	private:
		string nom;
		string prenom;
		int age;

	public:

		Personne(string nomInput, string prenomInput, int ageInput){
			this->nom = nomInput;
			this->prenom = prenomInput;
			this->age = ageInput;
		}

		string getNom(){
			return this->nom;
		}

		string getPrenom(){
			return this->prenom;
		}

		int getAge(){
			return this->age;
		}

		void setNom(string nomInput){
			this->nom = nomInput;
		}

		bool operator == (const Personne& other){
			return (this->age == other.age) && (this->prenom == other.prenom) && (this->nom == other.nom);
		}
	
        bool operator < (const Personne& other){
			if(!(this->nom == other.nom)){  
				return this->nom < other.nom;
			}
			if(!(this->prenom == other.prenom)){
				return this->prenom < other.prenom;
			}
			if(!(this->age == other.age)){
				return this->age < other.age;
			}
			return false; //Les deux personnes ont le même nom, prénom et age, ils ne sont donc pas différents

        }

		bool operator > (const Personne& other){
			if(!(this->nom == other.nom)){  
				return this->nom > other.nom;
			}
			if(!(this->prenom == other.prenom)){
				return this->prenom > other.prenom;
			}
			if(!(this->age == other.age)){
				return this->age > other.age;
			}
			return false; //Les deux personnes ont le même nom, prénom et age, ils ne sont donc pas différents
		}
};


int main(){
	/*
	Personne randomPelo("Jean", "Michel", 23);
	Personne randomPelo2("Michel", "Guillaume", 23);
	cout << (randomPelo2 == randomPelo) << endl;
	*/
}
