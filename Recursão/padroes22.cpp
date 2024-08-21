#include <iostream>
using namespace std;

int PecasTotais(int n){
    if(n == 1){
        return 3;
    }else{
        return (n * n) + (n + n);
    }
}

int main(){

    int n;

    cin >> n;

    int totalPecas = PecasTotais(n);

    cout << totalPecas << endl;
}