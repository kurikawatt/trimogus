#include "class/Person.h"

using namespace std;

class Person{

	private:

		string lastname;
		string firstname;
		int age;

	public:

		Person(string lastname, string firstname, int age){
			this->lastname = lastname;
			this->lastname = firstname;
			this->age = age;
		}

		string get_lastname(){
			return this->lastname;
		}

		string get_firstname(){
			return this->firstname;
		}

		int get_age(){
			return this->age;
		}

		void set_lastname(string lastname){
			this->lastname = lastname;
		}

		void set_firstname(string firstname){
			this->firstname = firstname;
		}

		void set_age(int age){
			this->age = age;
		}

		bool operator == (const Person &other){
			return (this->lastname == other.lastname) 
					&& (this->firstname == other.firstname)
					&& (this->age == other.age);
		}
	
        bool operator < (const Person &other){
			if(!(this->lastname == other.lastname)){  
				return this->lastname < other.lastname;
			}
			if(!(this->firstname == other.firstname)){
				return this->firstname < other.firstname;
			}
			if(!(this->age == other.age)){
				return this->age < other.age;
			}
			//Les deux personnes ont le même nom, prénom et age, ils ne sont donc pas différents
			return false; 
        }

		bool operator < (const Person &other){
			if(!(this->lastname == other.lastname)){  
				return this->lastname > other.lastname;
			}
			if(!(this->firstname == other.firstname)){
				return this->firstname > other.firstname;
			}
			if(!(this->age == other.age)){
				return this->age > other.age;
			}
			//Les deux personnes ont le même nom, prénom et age, ils ne sont donc pas différents
			return false; 
        }
};
