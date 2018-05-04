#ifndef LISTA_INCLUDE
#define LISTA_INCLUDE

#include <cstdlib>

#define SUCCESS 1
#define ERROR (-1)

template <class T>
struct node
{
	T* item;
	struct node<T>* prox;
	~node()
	{
		delete(item);
	}
};


template <class T>
class Lista {
public:
	Lista();
	~Lista() = default;

	// Adiciona no começo da lista
	void add(T* element);

	int remover(int index);

	int removerAll(void);

	// Retorna comprimento da lista
	int length(void);

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

// Não sera mais utilizado
// Caso deseja deletar os elementos, use removerAll antes de deletar a lista
/*template<class T>
Lista<T>::~Lista(){
	removerAll();
}*/

// Adiciona no começo da lista
template<class T>
void Lista<T>::add(T* element){
	// Aloca um nó
	struct node<T>*	pointer_new_first = new struct node<T>();
		
	// Aponta o item para o elemento adicionado 
	pointer_new_first->item = element;
	// Aponta para o primeiro
	pointer_new_first->prox = first;
		
	//Primeiro aponta para o nó
	first =	pointer_new_first;

	// Atualiza quantidade de elementos
	quantidade_elementos++;
}

template<class T>
int Lista<T>::remover(int index){
	// pointer_index aponta para indice 0
	struct node<T>*	pointer_index = first;
	struct node<T>* pointer_index_anterior;

	if(index < quantidade_elementos && quantidade_elementos > 0){
		
		// Caso especial de remoção do primeiro elemento
		if(index == 0){
			first = first->prox;
			delete(pointer_index);
			
			// Atualiza quantidade de elementos
			quantidade_elementos--;
			
			return SUCCESS;
		}

		// Caso generico
		for(int i = 0; i < index; i++){
			pointer_index_anterior = pointer_index;			// pointer_index_anterior aponta para o elemento na posição index-1
			pointer_index =	pointer_index->prox;			// pointer_index aponta para o elemento na posição index
		}
		pointer_index_anterior->prox = pointer_index->prox;	// index-1 aponta para index+1 (não tem problema caso index+1 seja nulo)
		delete(pointer_index);	// Remove index

		// Atualiza quantidade de elementos
		quantidade_elementos--;

		return SUCCESS;
	}
	return ERROR;
}

template<class T>
int Lista<T>::removerAll(void){
	// Enquanto tem elementos na lista
	while (this->length()) {

		// Se houver erro na remoção, sendo que tem elementos, ocorreu algum erro
		if(remover(0) == ERROR)
			return ERROR;
	}
	return SUCCESS;
}

// Retorna comprimento da lista
template<class T>
int Lista<T>::length(void){
	return quantidade_elementos;
}

// Retorna o elemento no indice pesquisado
template<class T>
T* Lista<T>::atIndex(int index){
	struct node<T>*	pointer_index = first;

	// Verifica se o index informado não é inválido
	if(index >= length() || index < 0)
		return NULL;

	for(int i = 0; i < index; i++){
		pointer_index =	pointer_index->prox;
	}

	return	pointer_index->item;
}

#endif
