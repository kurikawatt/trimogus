#include "sorts/SortsIterator.hpp"

namespace trimogus {

    SortsIterator::SortsIterator(std::map<std::string, void (*)(std::vector<std::any>&)> sorts){
        this->sorts = sorts;
    }

    SortsIterator::~SortsIterator(){ return; } // Il fait acte de présence ici


    bool SortsIterator::hasNext(){
        return !(this->current < this->sorts.size() - 1);
    }

    std::tuple<std::string, void (*)(std::vector<std::any>&)> SortsIterator::next() {
        if (this->hasNext()) {
            auto it = std::next(sorts.begin(), current);
            current++;
            return std::make_tuple(it->first, it->second);
        } 
        throw std::out_of_range("I already gave you all my sorts...");
    }

}