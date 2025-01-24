#pragma once

#include <iostream>
#include <string>

using namespace std;

class Person{
    
    public:
    
        Person(string lastname, string firstname, int age);
        
        string get_lastname();
        string get_first_name(); 
        int get_age();

        void set_lastname(string lastname);
        void set_firstname(string firstname); 
        void set_age(int age);

        bool operator == (const Person *other);
        bool operator < (const Person *other);
        bool operator > (const Person *other);

};