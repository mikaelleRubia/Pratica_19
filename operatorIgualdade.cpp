#include "ItemSet.cpp"

bool ItemSet::operator==(ItemSet setB){
    ItemSet setA = *this;

    if(setA.getItens() == setB.getItens()){
        return true;
    }

    return false;
}