#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> arr = {38, 27, 43, 3, 9, 82};
    /*Nomeamos um vetor do tipo INT de "arr" onde iniciamos esse vetor com 5 valores:
    38, 27, 43, 3, 9 e 82.
    */
    int n = arr.size();
    //Depois declaramos um nova vari�vel "n" onde ela vai receber o vetor "arr" at� o seu tamanho


				//MERGE SORT
    for (int tamanho = 1; tamanho < n; tamanho *= 2) {
    	/*Esse primeiro LOOP varia o tamanho do SUBVETORES que est�o sendo mesclados, come�ando com SUBVETORES
    	de tamanho 1 e dobra esse tamanho a cada itera��o at� que o tamanho seja maior ou igual a "n".
    	*/
        for (int esquerda = 0; esquerda < n - 1; esquerda += 2 * tamanho) {
       		/*Esse segundo LOOP itera sobre os SUBVETORES de tamanho atual. 'esquerda' representa o �ndice de 
    		in�cio do SUBVETOR. A cada itera��o 'esquerda' � incrementado em "2 * TAMANHO", garantindo que os
    		subvetores se sobreponham corretamente.
        	*/
            int meio = min(esquerda + tamanho - 1, n - 1);
            /*Calculo do meio, ele � calculado como o minimo entre "esquerda + tamanho - 1 e n - 1"
            isso garante que o �ndice do meio n�o ultrapasse os limites do vetor.
            */
            int direita = min(esquerda + 2 * tamanho - 1, n - 1);
            /*Calculo da direita, � calculado como o minimo entre "esquerda + 2 * tamanho - 1 e n - 1"
            isso define o �ndice final do SUBVETOR
            */

            vector<int> temp;
            /*Aqui foi criado um novo vetor do tipo INT, nomeei de "temp", lembrando que � um vetor tempor�rio
            onde esse vetor ir� servir para armazenar os elementos mesclados.
            */
            int i = esquerda, j = meio + 1;
            /*Declaramos uma vari�vel "i", onde ela inicializa os �ndices 'i' e 'j' para rastrear a posi��o
            nos SUBVETORES que est�o sendo mesclados.
            */

			//LOOP DE MESCLAGEM
            while (i <= meio || j <= direita) {
            	//Esse LOOP continua at� que ambos os SUBVETORES tenham sido percorridos
            	//SUBVETORES: "esquerda...meio" e "meio+1...direita".
                if (j > direita || (i <= meio && arr[i] <= arr[j])) {
                	/*Essa condi��o verifica se o SUBVETOR � direita foi completamente percorrido ou se o elemento
                	em 'arr[i]' � menor ou igual ao elemento em 'arr[j]'.
                	*/
                    temp.push_back(arr[i]);
                    i++;
                    //Se a condi��o de cima, for verdadeira o elemento em 'arr[i]' � adicionado a "TEMP" e o i � incrementado
                } else {
                    temp.push_back(arr[j]);
                    j++;
                    /*Caso contr�rio, caso a primeira condi��o seja falsa, ela ir� pular pra c�
                    o elemento 'arr[j]' � adicionado a "TEMP" e j � incrementado
                    */
                }
            }

            for (int p = 0; p < temp.size(); p++) {
            	/*Esse � um LOOP que itera sobre os elementos do vetor tempor�rio "TEMP"
            	onde inicializa uma vari�vel "P" que ser� usada como �ndice para acessar os elementos do "TEMP"
            	onde o LOOP continuar� enquanto "P" for menor que o tamanho do "TEMP"
            	*/
                arr[esquerda + p] = temp[p];
                //Essa � a opera��o que copia cada elemento de "TEMP" para a posi��o correta no vetor original "arr"
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

