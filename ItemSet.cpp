#include <vector>
#include <string>
#include <iostream>

using namespace std;

class ItemSet{
    private:
        vector<string> itens;
    public:
        void inserirItem(string);
        void excluirItem(string);
        void imprimirItens();
        bool operator==(ItemSet);
        vector<string> getItens();
};

void ItemSet::inserirItem(string s){
    bool jaExiste = false;

    for(string item : itens) if(item == s) jaExiste = true;

    if(jaExiste){
        cout<<s<<" ja existe no conjunto de itens!"<<endl;
        return;
    } 

   itens.push_back(s);
   cout<<"Item "<<s<<" adicionado com sucesso!"<<endl;
}

void ItemSet::excluirItem(string s){
    for(int i = 0; i < itens.size(); i++){
        if(itens.at(i) == s){
            itens.erase(itens.begin() + i);
            cout<<s<<" foi removido com sucesso!"<<endl;
            return;
        } 
    }

    cout<<s<<" nao existe no conjunto de dados!"<<endl;
}

void ItemSet::imprimirItens(){
    cout<<"####### ITENS #######"<<endl;
    for(string item : itens){
        cout<<item<<endl;
    }
}

int main(){
    ItemSet set;

    set.inserirItem("abc");
    set.inserirItem("bcd");
    set.inserirItem("dce");

    //tentando adicionar item repetido
    set.inserirItem("abc");

    //Removendo item que existe no conjunto
    set.excluirItem("bcd");

    //Tentando remover item que não existe no conjunto
    set.excluirItem("bdc");

    cout<<endl;
    set.imprimirItens();
}