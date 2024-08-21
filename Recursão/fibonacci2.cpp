#include <iostream>
using namespace std;

int ParesFinais(int n){

    if(n <= 2){
        return 1;
    }else if(n == 3){
        return 2;
    }

    return ParesFinais(n - 1) + ParesFinais(n - 2) - ParesFinais(n - 4);
}

int main(){

    int n;

    cin >> n;

    int totalPares = ParesFinais(n);

    cout << totalPares << endl;
}