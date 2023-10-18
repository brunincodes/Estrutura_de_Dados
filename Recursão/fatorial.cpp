#include <iostream>

using namespace std;

int fatorial(int n) {
  	if (n == 0) {
    	return 1;
  	}else {
    	return n * fatorial(n - 1);
  	}
}
int main() {
  	setlocale(LC_ALL, "");
  	
	int n;
	cout << "Digite um número: ";
  	cin >> n;

  	int fat = fatorial(n);
  	cout << n << "! = ";
  	for (int i = n; i > 1; i--) {
   		cout << i << " * ";
 	}
 	cout << 1 << " = " << fat << endl;
	return 0;
}


