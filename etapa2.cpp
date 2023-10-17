#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Conjunto {
private:
    int* elementos;
    int tamanho;

public:
    Conjunto(int* outroConjunto, int tam);

    void imprimirElementos();

    static void operador_mais(int vet1[], int tam1, int vet2[], int tam2);
    
    static void operador_inter(int array1[], int tam1, int array2[], int tam2);
};

Conjunto::Conjunto(int* outroConjunto, int tam) {
    elementos = new int[tam];
    tamanho = tam;
    for(int i = 0; i < tam; ++i) {
        elementos[i] = outroConjunto[i];
    }
}

void Conjunto::imprimirElementos() {
    for(int i = 0; i < tamanho; ++i) {
        cout << elementos[i] << " ";
    }
    cout << endl;
}

void Conjunto::operador_mais(int vet1[], int tam1, int vet2[], int tam2) {
    unordered_set<int> conjuntoUniao;
    for (int i = 0; i < tam1; ++i) {
        conjuntoUniao.insert(vet1[i]);
    }

    for (int i = 0; i < tam2; ++i) {
        conjuntoUniao.insert(vet2[i]);
    }

    cout <<"---Uniao---" << endl;
    for (const auto& i : conjuntoUniao) {
        cout << i << " ";
    }
    cout << "\n\n";

}

void Conjunto::operador_inter(int array1[], int tam1, int array2[], int tam2) {
    unordered_set<int> conjuntoArray1(array1, array1 + tam1);
    cout <<"---Intersecao---" << endl;
    for (int i = 0; i < tam2; ++i) {
        if (conjuntoArray1.find(array2[i]) != conjuntoArray1.end()) {
            cout << array2[i] << " ";
        }
    }
    cout << "\n\n";
}

int main() {

    int conjuntoOriginal[] = {1, 2, 3, 4, 9,5};
    int conjuntoB[] = {2, 1, 9, 4};
    int tam1 = sizeof(conjuntoB) / sizeof(conjuntoB[0]);
    int tam2 = sizeof(conjuntoOriginal) / sizeof(conjuntoOriginal[0]);

    Conjunto A(conjuntoOriginal, tam2);
    Conjunto B(conjuntoB, tam1);

    A.imprimirElementos();
    B.imprimirElementos();

    Conjunto::operador_mais(conjuntoB, tam1, conjuntoOriginal, tam2);
    Conjunto::operador_inter(conjuntoB, tam1, conjuntoOriginal, tam2);

    return 0;
}
