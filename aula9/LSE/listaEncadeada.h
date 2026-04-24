struct nodo{
	int dado;
	struct nodo *prox;
};

struct desc_lista_encadeada{
	int tamanho;
	struct nodo *lista;
};

struct nodo* criaNodo(int novoDado);
struct desc_lista_encadeada * criaDescritor(void);
struct nodo* removeLista(struct desc_lista_encadeada *minhaLista, int posicao);
void insere(struct desc_lista_encadeada *minhaLista, struct nodo *novo_elemento, int posicao);
int tamanho(struct desc_lista_encadeada *minhaLista);
void libera(struct desc_lista_encadeada *minhaLista);
//implementação dos alunos
void imprime(struct desc_lista_encadeada *minhaLista);
struct nodo * get(struct desc_lista_encadeada *minhaLista, int posicao);
void set(struct desc_lista_encadeada *minhaLista, int valor, int posicao);

