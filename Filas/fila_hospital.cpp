#include <iostream>
#include <list>

using namespace std;

class FilaHospital {
public:
    FilaHospital() {}

    void chegada(int paciente) {
        lista.push_back(paciente);
    }

    void preferencial(int paciente) {
        lista_preferencial.push_back(paciente);
    }

    int saida() {
        if (!lista_preferencial.empty()) {
            int paciente = lista_preferencial.front();
            lista_preferencial.pop_front();
            pacientes_preferenciais_atendidos.push_back(paciente);
            return paciente;
        } else if (!lista.empty()) {
            int paciente = lista.front();
            lista.pop_front();
            if (!pacienteFoiAtendidoComoPreferencial(paciente)) {
                return paciente;
            }
        }
        return -1;
    }

    bool vazia() {
        return lista_preferencial.empty() && lista.empty();
    }

    void mostrarElementos() {
        cout << "FILA COMUM: " << endl;
        for (int paciente : lista) {
            cout << paciente << endl;
        }

        cout << "FILA PREFERENCIAL: " << endl;
        for (int paciente : lista_preferencial) {
            cout << paciente << endl;
        }
    }

	private:
	    list<int> lista;
	    list<int> lista_preferencial;
	    list<int> pacientes_preferenciais_atendidos;

    bool pacienteFoiAtendidoComoPreferencial(int paciente) {
        for (int p : pacientes_preferenciais_atendidos) {
            if (p == paciente) {
                return true;
            }
        }
        return false;
    }
};

int main() {
    setlocale(LC_ALL, "");

    int idade[15];
    FilaHospital fila;

    for (int i = 0; i < 15; i++) {
        cout << "Digite a idade do " << i + 1 << "º paciente: ";
        cin >> idade[i];
        fila.chegada(idade[i]);
        if (idade[i] > 60) {
            fila.preferencial(idade[i]);
        }
    }

    cout << endl;
    fila.mostrarElementos();
    cout << endl;

    cout << "SAÍDA: " << endl;
    while (!fila.vazia()) {
        int paciente = fila.saida();
        if (paciente != -1) {
            cout << "PACIENTE ATENDIDO - " << paciente << endl;
        } 
    }

    return 0;
}

