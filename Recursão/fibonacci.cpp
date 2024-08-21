#include <iostream>
using namespace std;

int fibonacci(int n, int k) {
    if (n == 1 || n == 2)
        return 1;
    
    int prev = 1;
    int curr = 1;
    int next;

    for (int i = 3; i <= n; ++i) {
        next = curr + prev * k;
        prev = curr;
        curr = next;
    }

    return curr;
}

int main() {
    int n, k;
    cin >> n >> k;

    int total_pairs = fibonacci(n, k);
    
    cout << total_pairs << endl;

    return 0;
}
