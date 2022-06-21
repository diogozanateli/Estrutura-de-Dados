#include <iostream>
#include <string>
using namespace std;

typedef int data;

class noh {
    friend class lista;
    private:
        data dado;
        noh* proximo;
    public:
        noh();
        ~noh();
};

noh::noh(){
    proximo = NULL;
}

noh::~noh(){
	delete proximo;
}

class lista {
    private:
        noh* primeiro;
        noh* ultimo;
        int tamanho;
    public:
        lista();
        ~lista();
        void insere(data entrada);
        void insere(data entrada, int pos);
        void remove(int posicao);
        void removeFim();
        int procura(data valor);
        void imprime();
        inline bool vazia();
};

lista::lista() {
    tamanho = 0;
    primeiro = NULL;
    ultimo = NULL;
}

lista::~lista() {
    noh* iter = primeiro;
    noh* proximo = NULL;
    while (iter != NULL) {
        proximo = iter->proximo;
        delete iter;
        iter = proximo;
    }
}

void lista::imprime() {
    noh* aux = primeiro;
    while (aux != NULL) {
        cout << aux->dado << " ";
        aux = aux->proximo;
    }
    cout << endl;
}

void lista::insere(data entrada) {
    noh* novo = new noh();
	novo->dado = entrada ;
	if(!vazia()){
		ultimo->proximo = novo;
		ultimo = novo;
	}
	else{
		primeiro = novo;
		ultimo = novo;
	}
}

void lista::insere(data entrada, int posicao) {
    noh* novo = new noh();
    novo->dado = entrada;
    
    noh* aux = primeiro;
    int cont = 0;
    
    while(cont < posicao-1){
    	cont++;
    	aux = aux->proximo;
	}
	novo->proximo = aux->proximo;
	aux->proximo = novo;
}

void lista::remove(int posicao) {
   noh* aux= primeiro;  
   int cont = 0;
   if(posicao>tamanho){
   while(cont < posicao-1){
   	aux = aux->proximo;
   }  
    noh* remover = aux->proximo;
    aux->proximo = aux->proximo->proximo;
    remover->proximo = NULL;
    if(ultimo == remover){
    	ultimo = aux;
	}
	delete remover;
}
}

void lista::removeFim(){
	noh* aux= primeiro;
	while(aux->proximo != ultimo){
		aux=aux->proximo;
	}
	ultimo=aux;
	aux=aux->proximo;
	ultimo->proximo=NULL;
	aux->proximo=NULL;
	
	delete aux;
}

int lista::procura(data valor) {
    noh* aux = primeiro;
    int cont=0;
    while((aux!=NULL) and (aux->dado != valor)){
    	cont++;
		aux= aux->proximo;
	}
       return cont;
    }


inline bool lista::vazia() {
    if(primeiro == NULL){
    	return true;
	}
	else{
		return false;
	}
}

class mhash{
friend class lista;
	private:
		lista *t;
		int capacidade;
	public:
		mhash (int capacidade);
		~mhash();
		int calculaposicao(int chave);
		void insereelemento(int chave);
		void removeelemento(int chave);
		void limpahash();
};

mhash::mhash(int capacidade=20){
	int cap=capacidade;
	t = new lista[cap];
}
mhash::~mhash(){
	limpahash();
	delete [] t;
}

int mhash :: calculaposicao(int chave){
	return(chave%capacidade);
}
void mhash :: insereelemento(int chave){
	int p = calculaposicao(chave);
	t[p].insere(chave);
	
}
void mhash :: removeelemento(int chave){
	int p=calculaposicao(chave);
	t[p].remove(chave);
} 
void mhash :: limpahash(){
	for (int i = 0; i < capacidade; i++)
	{
		t[i].removeFim();
	}
}

int main() { 
    lista minhaLista;
    char opcao;
    int valor, pos;
    cin >> opcao;
    while (opcao != 'Q') {
        switch(opcao) {
            case 'I':
                cin >> valor;
                minhaLista.insere(valor);
                break;
            case 'W':
                cin >> valor;
                cin >> pos;
                minhaLista.insere(valor, pos);
                break;
            case 'P':
                cin >> valor;
                cout << minhaLista.procura(valor) << endl;
                break;
            case 'R':
                cin >> pos;
                minhaLista.remove(pos);
                break;
            case 'V':
                cout << minhaLista.vazia() << endl;
                break;
        }
        cin >> opcao;
    }
    minhaLista.imprime();
    return 0;
}
