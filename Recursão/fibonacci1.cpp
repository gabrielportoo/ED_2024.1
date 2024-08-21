#include <iostream>
using namespace std;

int Fibonacci(int n, int k){

    if(n == 1 || n == 2){
        return 1;
    }

    int antes = 1;
    int atual = 1;
    int depois;
    int i;

    for(i = 3; i <= n; ++i){
        depois = atual + antes * k;
        antes = atual;
        atual = depois;
    }

    return atual;
}

int main(){

    int n, k;

    cin >> n >> k;

    int totalPares = Fibonacci(n, k);

    cout << totalPares << endl;
}