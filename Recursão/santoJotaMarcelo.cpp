#include <iostream>
#include <iomanip>

using namespace std;

double calcularValorInicial(int N, int C) {

    if (N == 1){
        return C / 2.0;
    }
    
    return (calcularValorInicial(N - 1, C) + C) / 2.0;
}

int main() {
    int N, C;
    cin >> N >> C;

    double valor_inicial = calcularValorInicial(N, C);

    cout << fixed << setprecision(2) << valor_inicial << endl;
}
