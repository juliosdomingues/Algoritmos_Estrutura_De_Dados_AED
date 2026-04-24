struct descritor_arvore{
	int tamanho;
	struct nodo* raiz;
	};

struct nodo{
		int chave;
		struct nodo* pai;
		struct nodo *esquerdo;
		struct nodo *direito;	
};

struct descritor_arvore* inicializa(void);
struct nodo* criaNodo(int chave);
struct nodo* insereNodo(struct nodo* atual, struct nodo* novoNodo,struct nodo *pai);
