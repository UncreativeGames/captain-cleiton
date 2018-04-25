#ifndef LISTA_INCLUDE
#define LISTA_INCLUDE

#include <cstdlib>

#define SUCCESS 1
#define ERROR -1

template <class T>
struct node
{
	T* item;
	struct node<T>* prox;
};


template <class T>
class Lista {
public:
	Lista();

	// Adiciona no começo da lista
	void add(T* element);


	int remover(int index);


	// Retorna comprimento da lista
	int length();


	// Retorna o elemento no indice pesquisado
	T* atIndex(int index);

private:
	struct node<T>* first;
	int quantidade_elementos;
};




template<class T>
Lista<T>::Lista(){
	first = NULL;
	quantidade_elementos = 0;
}

// Adiciona no começo da lista
template<class T>
void Lista<T>::add(T* element){
	// Aloca um nó
	struct node<T>* aux = (node<T>*)malloc(sizeof(node<T>));
		
	// Aponta o item para o elemento adicionado 
	aux->item = element;
	// Aponta para o primeiro
	aux->prox = first;
		
	//Primeiro aponta para o nó
	first = aux;

	// Atualiza quantidade de elementos
	quantidade_elementos++;
}

template<class T>
int Lista<T>::remover(int index){
	//aux aponta para indice 0
	struct node<T>* aux = first;
	struct node<T>* aux2;

	if(index < quantidade_elementos && quantidade_elementos > 0){
		
		// Caso especial de remoção do primeiro elemento
		if(index == 0){
			first = first->prox;
			free(aux);
			
			// Atualiza quantidade de elementos
			quantidade_elementos--;
			
			return SUCCESS;
		}

		// Caso generico
		for(int i = 0; i < index; i++){
			aux2 = aux;			// aux2 aponta para o elemento na posição index-1
			aux = aux->prox;	// aux aponta para o elemento na posição index
		}
		aux2->prox = aux->prox;	// index-1 aponta para index+1 (não tem problema caso index+1 seja nulo)
		free(aux);	// Remove index

		// Atualiza quantidade de elementos
		quantidade_elementos--;

		return SUCCESS;
	}
	return ERROR;
}

// Retorna comprimento da lista
template<class T>
int Lista<T>::length(){
	return quantidade_elementos;
}

// Retorna o elemento no indice pesquisado
template<class T>
T* Lista<T>::atIndex(int index){
	struct node<T>* aux = first;

	// Verifica se o index informado não é inválido
	if(index >= length() || index < 0)
		return NULL;

	for(int i = 0; i < index; i++){
		aux = aux->prox;
	}

	return aux->item;
}

#endif
