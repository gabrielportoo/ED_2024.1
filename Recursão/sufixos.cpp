#include <iostream>
#include <string>

using namespace std;

void printTower(string palavra, int inicio) {
    // O método length() retorna o comprimento da string, ou seja, o número de
    // caracteres na string.
    if (inicio == palavra.length()){ 
        return;
    }
    
    printTower(palavra, inicio + 1);

    // O método substr(inicio) retorna uma sub-string da string original, 
    // começando a partir do índice especificado (inicio). Ele extrai os caracteres da
    // posição inicio até o final da string original.
    cout << palavra.substr(inicio) << endl;
}

int main() {
    string palavra;
    cin >> palavra;

    printTower(palavra, 0);
}