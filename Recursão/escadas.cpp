#include <iostream>
using namespace std;

int TotalManeiras(int n){
    if(n <= 2){
        return 1;
    }else if(n == 3){
        return 2;
    }

    return TotalManeiras(n - 1) + TotalManeiras(n - 3);

}

int main(){

    int n;

    cin >> n;

    int totalManeiraEsc = TotalManeiras(n);

    cout << totalManeiraEsc << endl;
}