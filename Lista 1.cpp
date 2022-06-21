#include <iostream>

using namespace std;

typedef int Dado;

class noh {
    friend class lista;
    private:
        const Dado dado;
        noh* proximo;
    public:
        noh(Dado d = 0);
};

noh::noh(Dado d) : dado(d) {
    proximo = NULL;
}

class lista {
    private:
        noh* primeiro;
        noh* ultimo;
        int tamanho;
    public:
        lista();
        ~lista();
        void insere(Dado dado);
        void insere(Dado dado, int pos);
        void remove(int posicao);
        int procura(Dado valor);
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

void lista::insere(Dado dado) {
     noh *novo = new noh(dado);
    if (vazia()){
		primeiro = novo;
		ultimo = novo;
	}
	else {
		ultimo->proximo = novo;
		ultimo = novo;
	}
	tamanho++;
}

void lista::insere(Dado dado, int posicao) {
    noh *novo = new noh(dado);
    noh *aux;
    if (!vazia()){
		if (posicao == 0) {
			novo->proximo = primeiro;
			primeiro = novo;
			tamanho++;
		}
		else if (posicao == tamanho-1) {
			aux = primeiro;
			while (aux->proximo!=ultimo) {
				aux = aux->proximo;
			}
			aux->proximo = novo;
			novo->proximo = ultimo;
			tamanho++;
		}
		else if ((posicao > 0) and (posicao < tamanho - 1)) {
			noh *pont = primeiro;
			for (int i=0; i< posicao - 1; i++) {
				pont = pont->proximo;
			}
			aux = pont->proximo;
			pont->proximo = novo;
			novo->proximo = aux;
			tamanho++;
		}
		else if (posicao == tamanho) {
			insere(dado);
		}
	}
	else {
		if (posicao == 0) {
			primeiro = novo;
			ultimo = novo;
			tamanho++;
		}
	}
}

void lista::remove(int posicao) {
    noh *auxiliar ;
    if (!vazia()) {
		if (posicao == 0) {
			auxiliar = primeiro;
			primeiro = primeiro->proximo;
			auxiliar->proximo = NULL;
			delete auxiliar;
			tamanho--;
		}
		else if ((posicao > 0) and (posicao < tamanho - 1)) {
			noh *pont;
			pont = primeiro;
			for (int i=0;i<posicao-1;i++) {
				pont = pont->proximo;
			}
			auxiliar = pont->proximo;
			pont->proximo = auxiliar->proximo;
			auxiliar->proximo = NULL;
			delete auxiliar;
			tamanho--;
		}
		else if (posicao==tamanho-1) {
			auxiliar = primeiro;
			for (int i=0;i<posicao-1;i++) {
				auxiliar = auxiliar->proximo;
			}	
			ultimo = auxiliar;
			auxiliar = auxiliar->proximo;
			ultimo->proximo = NULL;
			delete auxiliar;
			tamanho--;
		}
	}
}

int lista::procura(Dado valor) {
     noh* aux = primeiro;
    int cont = 0;
    while ((aux!=NULL) and (aux->dado != valor)) {
		aux = aux->proximo;
		cont++;
	}
	if (aux!=NULL) {
		return cont;
	}
	else {
		return -1;
	}
    }


inline bool lista::vazia() {
        if(primeiro == NULL){
    	return true;
	}
	else{
		return false;
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
