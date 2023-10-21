# include <iostream>
# include <limits>
# include <cstring>
# include <vector>

using namespace std;

class ItemSet{
    private:
        vector<string> conjunto;
    public:
        ItemSet();
        vector<string> getConjunto();
        void addItem(string);
        void removeItem(string);
        void listar();
};

int Menu();

void pause();
void limpaTela();

int main(){
    ItemSet myConjunto = ItemSet();
    string aux_Str;
    int op;
    do{
        limpaTela();
        op = Menu();
        switch(op){
            case 1:
                limpaTela();
                cout << "========== Cadastro de Items ==========\n\n";
                cout << "Informe um Nome: ";
                cin >> aux_Str;
                myConjunto.addItem(aux_Str);
                pause();
                break;
            case 2:
                limpaTela();
                if(myConjunto.getConjunto().size() == 0){
                    cout << " Nao existem Itens !!!\n\n";
                    pause();
                    break;
                }
                cout << "========== Remover Item ==========\n\n";
                cout << "Informe um Nome: ";
                cin >> aux_Str;
                myConjunto.removeItem(aux_Str);
                pause();
                break;
            case 3:
                limpaTela();
                if(myConjunto.getConjunto().size() == 0){
                    cout << " Nao existem Itens !!!\n\n";
                    pause();
                    break;
                }
                cout << "========== Listar Itens ==========\n\n";
                myConjunto.listar();
                pause();
                break;
            case 0:
                limpaTela();
                cout << "Saindo...\n";
                pause();
                break;
            default:
                limpaTela();
                cout << "Opcao invalida!\n";
                pause();
        }
    }while(op != 0 );
    return 0;
}

ItemSet::ItemSet(){
    conjunto = vector<string>();
}

vector<string> ItemSet::getConjunto(){
    return conjunto;
}

void ItemSet::addItem(string item){
    for(auto i :conjunto){
        if(i == item){
            cout << "Item ja existente!\n";
            return;
        }
    }
    cout << "Item adicionado!\n";
    conjunto.push_back(item);
}

void ItemSet::removeItem(string item){
    auto it = conjunto.begin();
    for(auto i :conjunto){
        if(i == item){
            cout << "Item removido!\n";
            conjunto.erase(it);
            return;
        }
        it++;
    }
    cout << "Item nao encontrado!\n";
}

void ItemSet::listar(){
    cout << "Itens: \n";
    cout << "---------------------------\n";
    for(auto i :conjunto){
        cout << i << "\n";
        cout << "---------------------------\n";
    }
}

int Menu(){
    int op;
    cout << "1 - Adicionar item\n";
    cout << "2 - Remover item\n";
    cout << "3 - Listar itens\n";
    cout << "0 - Sair\n";
    cin >> op;
    return op;
}

void pause()
{
    cin.ignore();
    cout << "\nPressione a tecla Enter para continuar...\n";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

void limpaTela()
{
    cin.clear();

    // Verifica se a variável de ambiente WINDIR está definida (ambiente Windows)
    const char *windir = getenv("WINDIR");

    if (windir != nullptr && strlen(windir) > 0)
    {
        // Se estiver definida, estamos no Windows, então use "cls"
        system("cls");
    }
    else
    {
        // Caso contrário, estamos em um ambiente Unix/Linux, use "clear"
        system("clear");
    }
}