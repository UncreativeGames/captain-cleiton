#ifndef LISTAESTATICA_INCLUDE
#define LISTAESTATICA_INCLUDE

#include "Rigidbody.hpp"

#define TAM_MAP_X 25
#define TAM_MAP_Y 18
#define TAM_LISTA (TAM_MAP_X * TAM_MAP_Y) 
#define SUCCESS 1
#define ERROR -1

template<class T>
class Listaestatica
{
public:

	// Cria a lista com 0 elementos;
	Listaestatica(void) {
		quantidade_elementos_atual = 0;
	}

	// Destrutor da Classe destroi todos os elementos dentro desta lista
	~Listaestatica(void) {
		for (int i = 0; i < quantidade_elementos_atual; i++) 
		{
			delete(elementos[i]);
		}
	}

	// Adiciona elemento no final da lista (complexidade O(1))
	int add(T* elemento) {
		// Caso a lista esteja cheia não é possivel adicionar elementos
		if(quantidade_elementos_atual == TAM_LISTA)
			return ERROR;

		elementos[quantidade_elementos_atual] = elemento;

		// Atualiza quantidade de elementos atual
		quantidade_elementos_atual++;

		return SUCCESS;
	}

	// Remove elemento pelo indice
	int remover(int index) {
		// Indice inválido
		if(index >= quantidade_elementos_atual || index < 0)
			return ERROR;

		// Deleta o elemento no indice
		delete(elementos[index]);

		// Atualiza quantidade de itens
		quantidade_elementos_atual--;

		// Anda com todos os elementos para trás
		for(int i = index; i < quantidade_elementos_atual; i++){
			elementos[i] = elementos[i+1];
		}

		// Aponta elemento duplicado que foi puxado para trás para NULL
		elementos[quantidade_elementos_atual+1] = NULL;

		return SUCCESS;
	}
    // Limpar
    int limpar() {
        while(quantidade_elementos_atual!=0)
        {
            remover(0);
        }

        return SUCCESS;
    }
	// Retorna elemento na posição index
	T* atIndex(int index) {
		// Indice inválido
		if(index >= quantidade_elementos_atual || index < 0)
			return NULL;

		return elementos[index];
	}

	// Retorna quantidade de elementos atual da lista
	int length(void) {
		return quantidade_elementos_atual;
	}

private:
	T* elementos[TAM_LISTA];
	int quantidade_elementos_atual;
};


// Especialização da classe para Rigidbody
template<>
class Listaestatica<Rigidbody>
{
public:

	// Cria a lista com 0 elementos;
	Listaestatica(void) {
		quantidade_elementos_atual = 0;
	}

	// Destrutor da Classe destroi todos os elementos dentro desta lista
	~Listaestatica(void) {
		for (int i = 0; i < quantidade_elementos_atual; i++) 
		{
			delete(elementos[i]);
		}
	}

	// Adiciona elemento no final da lista (complexidade O(1))
	int add(Rigidbody* elemento) {
		// Caso a lista esteja cheia não é possivel adicionar elementos
		if(quantidade_elementos_atual == TAM_LISTA)
			return ERROR;

		elementos[quantidade_elementos_atual] = elemento;

		// Atualiza quantidade de elementos atual
		quantidade_elementos_atual++;

		return SUCCESS;
	}

	// Remove elemento pelo indice
	int remover(int index) {
		// Indice inválido
		if(index >= quantidade_elementos_atual || index < 0)
			return ERROR;

		// Deleta o elemento no indice
		delete(elementos[index]);

		// Atualiza quantidade de itens
		quantidade_elementos_atual--;

		// Anda com todos os elementos para trás
		for(int i = index; i < quantidade_elementos_atual; i++){
			elementos[i] = elementos[i+1];
		}

		// Aponta elemento duplicado que foi puxado para trás para NULL
		elementos[quantidade_elementos_atual+1] = NULL;

		return SUCCESS;
	}
	// Limpar
	int limpar() {
		while(quantidade_elementos_atual!=0)
		{
			remover(0);
		}

		return SUCCESS;
	}
	// Retorna elemento na posição index
	Rigidbody* atIndex(int index) {
		// Indice inválido
		if(index >= quantidade_elementos_atual || index < 0)
			return NULL;

		return elementos[index];
	}

	// Retorna quantidade de elementos atual da lista
	int length(void) {
		return quantidade_elementos_atual;
	}

	// Função que ordena pela posição do transform
	void ordena(void) {
		quickSort(0, length()-1);
	}

private:
	Rigidbody* elementos[TAM_LISTA];
	int quantidade_elementos_atual;

	// Parte do código para quicksort
	// low e high representam o menor e o maior indice da partição que está sendo trabalhada
	int partition(int low, int high){
		//Pego um pivo como sendo o elemento com maior indice
		Rigidbody* pivo = elementos[high];
		Rigidbody* auxiliar_troca;
		int i = (low - 1); // indice para menor elemento

		for (int j = low; j <= high - 1; j++) {
			// Se j.y < pivo.y ou (j.y == pivo.y && j.x <= pivo.x)
			if(elementos[j]->getPosition().y < pivo->getPosition().y || (elementos[j]->getPosition().y == pivo->getPosition().y && elementos[j]->getPosition().x <= pivo->getPosition().x)){
				i++;

				// Troca com o "menor elemento"
				auxiliar_troca = elementos[j];
				elementos[j] = elementos[i];
				elementos[i] = auxiliar_troca;
			}
		}
			
		// Troca o pivo para sua posição, deixando assim todos os que são maiores a direita,
		// e todos os que são menores a esquerda.
		auxiliar_troca = elementos[i+1];
		elementos[i+1] = elementos[high];
		elementos[high] = auxiliar_troca;

		// Retorna o indice onde o vetor foi particionado
		return (i + 1);	
	}

	void quickSort(int low, int high) {
		// Enquanto os indices não forem iguais
		if (low < high) {
			// Pega a partição
			int indice_particao = partition(low, high);

			// Faz o mesmo com ambos os lados da partição
			quickSort(low,indice_particao - 1);
			quickSort(indice_particao + 1, high);
		}
	}
};

#endif
