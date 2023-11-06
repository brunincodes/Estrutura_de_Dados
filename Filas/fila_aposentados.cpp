#include <iostream>
#include <list>
#include <string>

using namespace std;

class FilaAposentados{
	public:
		Fila(){}
	
	void chegada(string aposentados){
		lista.push_back(aposentados);
	}
	
	string saida(){
		if (lista.empty()){
			return 0;
		}
		string aposentados = lista.front();
			lista.pop_front();
			return aposentados;
	}
	
	bool vazia(){
		return lista.empty();
	}
	
	void mostrarElementos(){
		for (string aposentado : lista){
			cout << aposentado << endl;
		}
	}
	
	private:
		list<string> lista;
};

int main(){
	
	string name[10];
	FilaAposentados fila;
	
	for (int i=0; i<10; i++){
		cout << "Digite o nome do aposentado: ";
		cin >> name[i];
		fila.chegada(name[i]);
	}
	
	cout << endl << "CHEGADA DOS APOSENTADOS: " << endl;
	fila.mostrarElementos();
	
	cout << endl << "RECEBERAM O DINHEIRO: " << endl;
	for(int i=0; i<5; i++){
		cout << name[i] << " recebeu" << endl;
		fila.saida();
	}
	
	cout << endl << "CHEGADA DOS OUTROS APOSENTADOS: " << endl;
	for (int i=0; i<4; i++){
		cout << "Digite o nome do aposentado: ";
		cin >> name[i];
		fila.chegada(name[i]);
	}
	
	cout << endl << "FILA ATUAL: " << endl;
	fila.mostrarElementos();
	
	return 0;
}
