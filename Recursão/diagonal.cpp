#include <iostream>
#include <string>

using namespace std;

void palavraDiagonal(string palavra){

    int tamanho = palavra.length();
    int i;
    for(i = 0; i <= tamanho; i++){
        for(int j = 0; j < i; ++j){
            cout << ' ';
        }

        cout << palavra[i] << endl;
    }
}

int main(){

    string palavra;
    cin >> palavra;

    palavraDiagonal(palavra);
}