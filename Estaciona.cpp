#include <iostream>
#include <string>

using namespace std;

class noh{
	friend class fila;
	private:
		char com;
		string car;
		noh *proximo;
	public:
		noh(string car);
		~noh();
};

noh::noh(string car){
	string carro=car;
	proximo=NULL;
}

noh::~noh(){
	delete proximo;
}

class fila{
	private:
		noh *inicio;
		noh *fim;
	public:
		fila();
		~fila();
		void insereFim(string carro);
		void removeInicio();
		void imprimeFila();
		bool vazia();	
};

fila::fila(){
	inicio=NULL;
	fim=NULL;
}

fila::~fila(){
		while(!vazia()){
			removeInicio();
		}
		delete inicio;
		delete fim;
}

void fila::insereFim(string carro){
	noh* novo= new noh(carro);
	if(!vazia()){
		fim->proximo=novo;
		novo=fim;
	}
	else{
		inicio=novo;
		fim=novo;
	}
}

void fila::removeInicio(){
	noh *aux = inicio;
	if(!vazia()){
		inicio=inicio->proximo;
		delete aux;
	}
	else{
		delete fim;
	}
}

void fila::imprimeFila(){
	noh *aux = inicio;
if (!vazia()){
		while (aux->proximo != NULL){
			cout << aux->car << endl;
			inicio = inicio->proximo;
			delete aux;
		}
	}
}

bool fila::vazia(){
		if(inicio==NULL){
			return true;
		}
		else{
			return false;
		}
}


int main(){
	
	return 0;
}
