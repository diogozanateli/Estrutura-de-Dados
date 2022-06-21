#include <iostream>
#include <string>
using namespace std;


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
	capacidade=cap;
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
	t[p].inserefim(chave);
	
}
void mhash :: removeelemento(int chave){
	int p=calculaposicao(chave);
	t[p].removeposicao(chave);
} 
void mhash :: limpahash(int chave){
	for (int i = 0; i < capacidade; i++)
	{
		t[i].removerinicio();
	}
}

int main(){

mhash *minha tabela;
int capacidade;

cin >> capacidade;

minhatabela = new mhash[capacidade];




	return 0;
}
