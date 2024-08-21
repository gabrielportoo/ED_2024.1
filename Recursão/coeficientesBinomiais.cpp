#include <iostream>
using namespace std;

int coeficienteBinomiais(int n, int k){
    int fatn = 1;
    int fatk = 1;
    int i;
    int menos = n - k;
    int fatm = 1;
    int cb;

    if(n == 0){
        return 1;
    }else{
        for(i = 1; i <= n; i++){
            fatn *= i;
        }
    }

    if(k == 0){
        return 1;
    }else{
        for(i = 1; i <= k; i++){
            fatk *= i;
        }
    }

    for(i = 1; i <= menos; i++){
        fatm *= i;
    }

    cb = fatn / (fatk * fatm);

    return cb;
}




int main(){

    int n, k;

    cin >> n >> k;

    cout << coeficienteBinomiais(n, k);
}