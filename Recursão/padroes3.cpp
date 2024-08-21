#include <iostream>

using namespace std;

int main(){
	int n, m;
	cin >> n >> m;

	int razao = n - 2;
	int a_m = razao * (m - 1) + 1;
	int resultado = (1 + a_m) * m / 2;

	cout << resultado << endl;
}