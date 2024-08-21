#include <iostream>

// Função recursiva para calcular o número total de peças da n-ésima imagem da sequência
int calcularTotalPecas(int n) {
    // Caso base: para n = 1, retorna 3
    if (n == 1) {
        return 3;
    } else {
        // Chamada recursiva para n - 1 e soma n ao resultado
        return n + calcularTotalPecas(n - 1);
    }
}

int main() {
    int n;
    std::cin >> n;

    // Calcular o número total de peças da n-ésima imagem da sequência
    int totalPecas = calcularTotalPecas(n);

    // Imprimir o resultado
    std::cout << totalPecas << std::endl;

    return 0;
}
