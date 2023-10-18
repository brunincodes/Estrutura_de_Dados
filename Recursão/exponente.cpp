#include <iostream>

using namespace std;

int potencia(int a, int b) {
  	if (b == 0) {
    	return 1;
  	} else {
   		return a * potencia(a, b - 1);
 	}
}

int main() {
  	int a;
  	int b;

  	cout << "Digite a base: ";
  	cin >> a;
  	cout << "Digite o expoente: ";
  	cin >> b;

  	int pot = potencia(a, b);
  	cout << a << "^" << b << " = " << pot << endl;
  	return 0;
}
