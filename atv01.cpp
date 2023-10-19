#include <iostream>
#include <vector>
using namespace std;

class ItemSet{
    private:
        vector<string> itens;
    public:
       void inserirItem(string item);
       void removerItem(string item);
       bool jaExisteItem(string item);
       void imprimeItens();
};


int main(){
    ItemSet item ;
    item.inserirItem("feijao");
    item.inserirItem("arroz");
    item.inserirItem("pinga");

    item.imprimeItens();

    item.removerItem("arroz");
    item.imprimeItens();
    item.removerItem("pao");

    return 0;
}




bool ItemSet::jaExisteItem(string item){
    for(size_t i = 0; i < itens.size(); i++){
        if(itens[i] == item){
            return true;
        }
    }
    return false;
}

void ItemSet::inserirItem(string item){
    if(!jaExisteItem(item)){
        itens.push_back(item);
        cout << "Item '" << item << "' inserido com sucesso." << endl;
    } else {
            cout << "Item '" << item << " ja existe . Nao foi inserido." << endl;
    }
}

void ItemSet::removerItem(string item){
    for(size_t i = 0; i < itens.size(); i++){
        if(itens[i] == item){
            itens.erase(itens.begin() + i);
           cout << "Item '" << item << "' excluido com sucesso." << endl;
           return;
        }        
    }
    cout << "Item '" << item << " nao encontrado." << endl;
}

void ItemSet::imprimeItens(){
    for(size_t i = 0; i < itens.size(); i++){
        cout << itens[i] << endl;
    }
}