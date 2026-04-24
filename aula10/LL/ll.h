#define InicioVetor 0
#define MaxTam  1000
typedef int Posicao;
typedef struct tipoitem TipoItem;
typedef struct tipolista TipoLista;

struct tipoitem {
	int valor;
	/* outros componentes */
};

struct tipolista{
	TipoItem Item[MaxTam];
	Posicao Primeiro, Ultimo;
};

//inicializa um descritor da lista
TipoLista* initializeLL(void);
//faz a lista vazia
void makeNUllLL (TipoLista* Lista);
//insere um elemento de valor x na posição anterior a p
void insertLL(TipoLista* Lista,TipoItem* x, Posicao p); 
//retorna o número de elementos armazenados na lista
int lengthLL(TipoLista* Lista); 
//busca um elemento na posição anterior a p
TipoItem* getLL(TipoLista* Lista, Posicao p); 
//modifica um elemento de valor x na posição anterior a p
void setLL(TipoLista* Lista, int novoValor,  Posicao p); 
//apaga o elemento de posição p			
TipoItem* deleteLL(TipoLista* Lista, Posicao p);
//imprime a lista
void showLL(TipoLista* Lista);
//cria um novo item com o valor
TipoItem* createTipoItem(int valor);
//altera o campo valor para o novoValor
void modifyTipoItem(TipoItem* x, int novoValor);
//imprime o campo valor do Item
void showTipoItem(TipoItem x);
