#include <vector>
#include <fstream>
using namespace std; // pra n�o escrever std::

/*
Um lindo c�digo em C++
pra gerar todas as combina��es simples poss�veis
serve para Loterias e outros.
*/

ofstream escreva;

// Fun��o para gerar combina��es
// use essa fun��o pra gerar todas as combina��es simples poss�veis
void combinations(vector<int>& elementos, vector<int>& combination, int inicio, int tamanho, int k)
{
    // Se o tamanho da combination for igual a k, imprimimos a combination
    if (combination.size() == k)
	{
        for (int i = 0; i < k; i++)
		{
            escreva << combination[i] << " ";
        }
        escreva << endl;
        return;
    }

    // Gerar combina��es
    for (int i = inicio; i < tamanho; i++)
	{
        combination.push_back(elementos[i]);
        combinations(elementos, combination, i + 1, tamanho, k);
        combination.pop_back(); // Remove o �ltimo elemento para voltar atr�s
    }
}

int main()
{
    // Elementos do conjunto
    vector<int> elementos = {2,5,7,8,9};  // aqui voc� coloca os n�meros pra fazer combina��es
    int k = 3; // aqui voc� coloca o n�mero de grupo de combina��es
    
    
    escreva.open("combina��es.txt");
    
    vector<int> combination;
    combinations(elementos, combination, 0, elementos.size(), k);
    
    escreva.close();
    return 0;
}

