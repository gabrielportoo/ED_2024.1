#include <iostream>

using namespace std;

int calcula(int n, int k){
	if (n <= k){
        return 1;
    }

	int metade = n / 2;

	if (n % 2 == 0){
        return 2 * calcula(metade, k);
    }

    
	return calcula(metade + 1, k) + calcula(metade, k);
}

int main(){
	int n, k;
	cin >> n >> k;

	cout << calcula(n, k) << endl;
}