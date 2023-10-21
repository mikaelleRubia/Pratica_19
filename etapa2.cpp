#include <iostream>
#include <unordered_set>

using namespace std;

class Conjunto {
private:
    unordered_set<int> elementos;

public:

    Conjunto();

    Conjunto(const Conjunto& outro);


    Conjunto& operator=(const Conjunto& outro) {
        if (this != &outro) {
            elementos = outro.elementos;
        }
        return *this;
    }

    Conjunto operator+(const Conjunto& outro) const {
        Conjunto uniao = *this;
        for (const auto& elemento : outro.elementos) {
            uniao.elementos.insert(elemento);
        }
        return uniao;
    }

    Conjunto operator*(const Conjunto& outro) const {
        Conjunto intersecao;
        for (const auto& elemento : elementos) {
            if (outro.elementos.count(elemento) > 0) {
                intersecao.elementos.insert(elemento);
            }
        }
        return intersecao;
    }

    Conjunto operator<(const Conjunto& outro) const {
        Conjunto diferenca;
        for (const auto& elemento : elementos) {
            if (outro.elementos.count(elemento) == 0) {
                diferenca.elementos.insert(elemento);
            }
        }

        for (const auto& elemento : outro.elementos) {
            if (elementos.count(elemento) == 0) {
                diferenca.elementos.insert(elemento);
            }
        }

        return diferenca;
    }

    void addElemento(int elemento) {
        elementos.insert(elemento);
    }


    void imprimirElementos() const {
        for (const auto& elemento : elementos) {
            cout << elemento << " ";
        }
        cout << endl;
    }
};
Conjunto::Conjunto(){}

Conjunto::Conjunto(const Conjunto& outro){
    elementos = outro.elementos;
}



int main() {
    Conjunto A;
    Conjunto B;

    A.addElemento(5);
    A.addElemento(3);
    A.addElemento(2);
    B.addElemento(3);
    B.addElemento(1);
    B.addElemento(2);
    B.addElemento(2);


    cout << "Conjunto A: ";
    A.imprimirElementos();

    cout << "Conjunto B: ";
    B.imprimirElementos();

    Conjunto T(A);
    cout << "Conjunto T: ";
    T.imprimirElementos();

    Conjunto C = A + B;
    cout << "Uniao de A e B: ";
    C.imprimirElementos();

    Conjunto D = A * B;
    cout << "Intersecao de A e B: ";
    D.imprimirElementos();

    // O operador <> não é um operador válido em C++ então como alternativa usei o operador <
    /*
        Lista de Operadores que podem ser sobrecarregados
 
        Operadores  Unários
        +  -  *  &  ~  !  ++  --  ->  ->*

        Operadores Binários
        
        +  -  *  /  %  ^  &  |  <<  >> 

        += -= *= /= %= ^= &= |= <<= >>= 
        
        <  <=  >  >=  ==  !=  &&  || 
        
        ,  []  () 
        
        new  new[]  delete  delete[]
    */
    Conjunto E = A < B;
    cout << "Diferenca de A e B: ";
    E.imprimirElementos();

    return 0;
}