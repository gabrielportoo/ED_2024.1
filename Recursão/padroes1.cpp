#include <stdio.h>
#include <iostream>
using namespace std;

int QuadradosSombreados(int n) { 
    if(n == 1) { 
        return 20; 
    }else { 
        return QuadradosSombreados(n - 1) + 8; 
    }
}
        
int main() { 
    int n; 
    cin >> n; 
    cout << QuadradosSombreados(n) << endl;
}