#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> arr = {38, 27, 43, 3, 9, 82};
    /*Nomeamos um vetor do tipo INT de "arr" onde iniciamos esse vetor com 5 valores:
    38, 27, 43, 3, 9 e 82.
    */
    int n = arr.size();
    //Depois declaramos um nova variável "n" onde ela vai receber o vetor "arr" até o seu tamanho


				//MERGE SORT
    for (int tamanho = 1; tamanho < n; tamanho *= 2) {
    	/*Esse primeiro LOOP varia o tamanho do SUBVETORES que estão sendo mesclados, começando com SUBVETORES
    	de tamanho 1 e dobra esse tamanho a cada iteração até que o tamanho seja maior ou igual a "n".
    	*/
        for (int esquerda = 0; esquerda < n - 1; esquerda += 2 * tamanho) {
       		/*Esse segundo LOOP itera sobre os SUBVETORES de tamanho atual. 'esquerda' representa o índice de 
    		início do SUBVETOR. A cada iteração 'esquerda' é incrementado em "2 * TAMANHO", garantindo que os
    		subvetores se sobreponham corretamente.
        	*/
            int meio = min(esquerda + tamanho - 1, n - 1);
            /*Calculo do meio, ele é calculado como o minimo entre "esquerda + tamanho - 1 e n - 1"
            isso garante que o índice do meio não ultrapasse os limites do vetor.
            */
            int direita = min(esquerda + 2 * tamanho - 1, n - 1);
            /*Calculo da direita, é calculado como o minimo entre "esquerda + 2 * tamanho - 1 e n - 1"
            isso define o índice final do SUBVETOR
            */

            vector<int> temp;
            /*Aqui foi criado um novo vetor do tipo INT, nomeei de "temp", lembrando que é um vetor temporário
            onde esse vetor irá servir para armazenar os elementos mesclados.
            */
            int i = esquerda, j = meio + 1;
            /*Declaramos uma variável "i", onde ela inicializa os índices 'i' e 'j' para rastrear a posição
            nos SUBVETORES que estão sendo mesclados.
            */

			//LOOP DE MESCLAGEM
            while (i <= meio || j <= direita) {
            	//Esse LOOP continua até que ambos os SUBVETORES tenham sido percorridos
            	//SUBVETORES: "esquerda...meio" e "meio+1...direita".
                if (j > direita || (i <= meio && arr[i] <= arr[j])) {
                	/*Essa condição verifica se o SUBVETOR á direita foi completamente percorrido ou se o elemento
                	em 'arr[i]' é menor ou igual ao elemento em 'arr[j]'.
                	*/
                    temp.push_back(arr[i]);
                    i++;
                    //Se a condição de cima, for verdadeira o elemento em 'arr[i]' é adicionado a "TEMP" e o i é incrementado
                } else {
                    temp.push_back(arr[j]);
                    j++;
                    /*Caso contrário, caso a primeira condição seja falsa, ela irá pular pra cá
                    o elemento 'arr[j]' é adicionado a "TEMP" e j é incrementado
                    */
                }
            }

            for (int p = 0; p < temp.size(); p++) {
            	/*Esse é um LOOP que itera sobre os elementos do vetor temporário "TEMP"
            	onde inicializa uma variável "P" que será usada como índice para acessar os elementos do "TEMP"
            	onde o LOOP continuará enquanto "P" for menor que o tamanho do "TEMP"
            	*/
                arr[esquerda + p] = temp[p];
                //Essa é a operação que copia cada elemento de "TEMP" para a posição correta no vetor original "arr"
            }
        }
    }

	//E por fim, fizemos um FOR EACH, onde iremos imprimir cada elemento do VETOR de forma ordenada.
    cout << "Lista ordenada:";
    for (int num : arr) {
    	cout << " " << num;
	}
    cout << endl;

    return 0;
}

