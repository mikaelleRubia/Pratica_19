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