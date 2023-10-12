#include <vector>
#include <iostream>

using namespace std;

class ItemSet{
    private:
        vector <string> itens;

    public:
        bool verificarItem(const string& item){
            for( string i : itens){
                if( i == item){
                    return false;
                }
            }
            return true;
        }

        void adicionarItem(const string& item) { 
            if(verificarItem(item)){
                itens.push_back(item);
            }else{
                cout << "O Item "<< item <<" ja existe"<< endl;
            }
            
        }

        static bool removerItem(vector <string>& itens){ 
            string nome_;

            cout << "Digite o o item que deseja remover" << endl;
            cin >> nome_;

            for (int i = 0; i < itens.size(); i++){
                if (itens[i] == nome_){
                    itens.erase(itens.begin() + i);
                    return true;
                }
            }
            return false;
        }


        vector <string> getItens() const{
            return itens;
        }

        void setItens(vector <string>& novoItens){
            itens = novoItens;
        }

};

int main(){
    ItemSet itens;

    itens.adicionarItem("item1");
    itens.adicionarItem("item2");
    itens.adicionarItem("item6");

    vector<string> vector_itens = itens.getItens();
    
    cout << "----------Itens------------"<< endl;
    for( string itens : vector_itens){
        cout << itens << ","<< endl;
    };


    if(ItemSet::removerItem(vector_itens)){
        cout << "Item removido com sucesso"<< endl;
    }else{
        cout << "Item nao encontrado"<< endl;
    }

    cout << "----------Itens------------"<< endl;
    for( string itens : vector_itens){
        cout << itens << ","<< endl;
    };
    return 0;
}