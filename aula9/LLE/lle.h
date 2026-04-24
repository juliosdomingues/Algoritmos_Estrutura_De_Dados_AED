typedef int Posicao;
typedef struct tipoitem TipoItem;
typedef struct tipolista TipoLista;

struct tipoitem{
	int valor;
	TipoItem *Prox;
	/* outros componentes */
};

struct tipolista{
	TipoItem* Primeiro, *Ultimo;
	int tamanho;
};

//inicializa um descritor da lista
TipoLista* initializeLLE(void);
//faz a lista vazia
void makeNUllLLE (TipoLista* Lista);
//insere um elemento de valor x na posição anterior a p
void insertLLE(TipoLista* Lista,TipoItem* x, Posicao p); 
//retorna o número de elementos armazenados na lista
int lengthLLE(TipoLista* Lista); 
//busca um elemento na posição anterior a p
TipoItem* getLLE(TipoLista* Lista, Posicao p); 
//modifica um elemento de valor x na posição anterior a p
void setLLE(TipoLista* Lista, int novoValor,  Posicao p); 
//apaga o elemento de posição p			
TipoItem* deleteLLE(TipoLista* Lista, Posicao p);
//imprime a lista
void showLLE(TipoLista* Lista);
//cria um novo item com o valor
TipoItem* createTipoItem(int valor);
//altera o campo valor para o novoValor
void modifyTipoItem(TipoItem* x, int novoValor);
//imprime o campo valor do Item
void showTipoItem(TipoItem *x);
