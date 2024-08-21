#include <iostream>
using namespace std;

void QuadradoRecursivo(int n) {
    if (n == 1) {
        cout << "1^2 = 1" << endl;
        return;
    }
    
    int quadradoMenos1 = (n - 1) * (n - 1);
    cout << n << "^2 = " << (n - 1) << "^2 + 2*" << (n - 1) << " + 1 = " << "?" << endl;
    
    QuadradoRecursivo(n - 1);
    
    cout << n << "^2 = " << (n - 1) << "^2 + 2*" << (n - 1) << " + 1 = " << quadradoMenos1 + 2 * (n - 1) + 1 << endl;
}

int main() {
    int n;
    
    cin >> n;
    
    QuadradoRecursivo(n);
}
