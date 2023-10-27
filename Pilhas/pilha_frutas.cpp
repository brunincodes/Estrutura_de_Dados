#include <iostream>
#include <stack>

using namespace std;

int main() {
	setlocale(LC_ALL, "");

	stack<string> pilha1, pilha2;

	pilha1.push("Manga");
	pilha2.push(pilha1.top());
	pilha1.pop();
	pilha1.push("Uva");
	pilha2.push(pilha1.top());
	pilha1.pop();
	pilha1.push("Banana");
	pilha1.push("Maçã");
	pilha1.push("Pera");
	pilha1.push("Laranja");
	
	pilha2.push("Abacate");
	pilha2.push("Mamão");
	pilha2.push("Melancia");
	pilha2.push("Kiwi");
	pilha2.push("Morango");
	pilha1.push(pilha2.top());
	pilha2.pop();
	pilha2.push("Abacaxi");
	pilha1.push(pilha2.top());
	pilha2.pop();

	cout << "PILHA 1 ATUALIZADA:" << endl;
	while (!pilha1.empty()) {
   		cout << "- " << pilha1.top() << endl;;
		pilha1.pop();
	}
	
	cout << endl << "PILHA 2 ATUALIZADA:" << endl;
	while (!pilha2.empty()) {
		cout << "- " << pilha2.top() << endl;;
		pilha2.pop();  
	}

	return 0;
}
