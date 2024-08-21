#include <vector>
#include <fstream>
using namespace std; // pra não escrever std::

/*
Um lindo código em C++
pra gerar todas as combinações simples possíveis
serve para Loterias e outros.
*/

ofstream escreva;

// Função para gerar combinações
// use essa função pra gerar todas as combinações simples possíveis
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

    // Gerar combinações
    for (int i = inicio; i < tamanho; i++)
	{
        combination.push_back(elementos[i]);
        combinations(elementos, combination, i + 1, tamanho, k);
        combination.pop_back(); // Remove o último elemento para voltar atrás
    }
}

int main()
{
    // Elementos do conjunto
    vector<int> elementos = {2,5,7,8,9};  // aqui você coloca os números pra fazer combinações
    int k = 3; // aqui você coloca o número de grupo de combinações
    
    
    escreva.open("combinações.txt");
    
    vector<int> combination;
    combinations(elementos, combination, 0, elementos.size(), k);
    
    escreva.close();
    return 0;
}

