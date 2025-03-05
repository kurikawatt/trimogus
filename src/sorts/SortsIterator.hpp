#pragma once

#include <iostream>
#include <map>
#include <vector>
#include <tuple>
#include <string>
#include <any>

namespace trimogus {

    class SortsIterator {
        
        private:
            // Un vecteur contenant les algos de tris de l'itérateur
            std::map<std::string, void (*)(std::vector<std::any>&)> sorts;
            size_t current = 0;
        public:
            SortsIterator(std::map<std::string, void (*)(std::vector<std::any>&)> sorts);

            ~SortsIterator();

            bool hasNext();
      
            std::tuple<std::string, void (*)(std::vector<std::any>&)> next();

    };

}


