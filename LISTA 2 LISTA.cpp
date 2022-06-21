#include <iostream>
#include <string>

using namespace std;

class aluno{
	friend class lista;
	private:
		int matricula;
		string nome;
		aluno *proximo;
		aluno *anterior;
	public:
		aluno();
		~aluno();
};

aluno :: aluno(){
	proximo = NULL;
	anterior= NULL;
}
aluno::~aluno(){
	delete proximo;
}

class lista{
	private:
		aluno* inicio;
		aluno* fim;
		int tamanho;
	public:
		lista();
		~lista();
		bool vazia();
		void inserir(int m, string n);
		aluno* buscar(int chave);
		int remover(aluno *retira);		
		void imprimirDireto();
		void imprimirReverso();
};
lista::lista(){
 	inicio = NULL;
 	fim = NULL;
 	tamanho = 0;
 }
 lista::~lista(){
 	delete inicio;
 }
 bool lista::vazia(){
 	if(inicio==NULL){
 		return true;
	 }
	 else{
	 	return false;
	 }
 }
 void lista::inserir(int m, string n){
 	aluno *novo = new aluno();
 	novo->matricula=m;
 	novo->nome=n;
if (vazia()){
	inicio = novo;
}
else{
	aluno *auxiliar = inicio;
	
	while(auxiliar->proximo != NULL){
		auxiliar = auxiliar->proximo;
		auxiliar->proximo = novo;
	}
	tamanho++;
}
}

int lista::remover(aluno* retira){
	aluno* auxiliar;
	int retorna;
	if(retira != NULL){
		if(retira == inicio){
			inicio = inicio->proximo;
		}
		if(!vazia()){
			cout << inicio->nome << endl;
		}
	}
	else{
		auxiliar = inicio;
		while(auxiliar->proximo != retira){
			auxiliar = auxiliar->proximo;
		}
		auxiliar->proximo = retira->proximo;
	}
	retorna = retira->matricula;
	retira->proximo=NULL;
	delete retira;
	tamanho--;

	return -1;
}

  aluno* lista::buscar(int chave){
		aluno *auxiliar = inicio;
		
		while ((auxiliar != NULL)and (auxiliar->matricula != chave)){
			auxiliar=auxiliar->proximo;
		}
		return auxiliar;
	}
	
	void lista::imprimirDireto(){
	aluno* auxiliar = inicio;
	if(!vazia()){
		while(auxiliar != NULL){
			cout << endl << auxiliar->matricula << endl;
			cout << auxiliar->nome << "\n";
			auxiliar = auxiliar->proximo;
		}
	}
}

		void lista::imprimirReverso(){
	aluno* auxiliar = fim;
	if(!vazia()){
		while(auxiliar != inicio){
			cout << endl << auxiliar->matricula << endl;
			cout << auxiliar->nome << "\n";
			auxiliar = auxiliar->anterior;
		}
	}
}
	

int main(){
	int opcao;
	lista* chamada = new lista();
	cin >> opcao;
	while(opcao != 't' ){
		if(opcao == 'i'){
			string nomeAluno;
			int matriculaAluno;
			cin >> matriculaAluno >> nomeAluno;
			chamada->inserir(matriculaAluno, nomeAluno);
		}
		else if(opcao == 'r'){
			int procurado, removido;
			cin >> procurado;
			aluno* encontrado;
			encontrado = chamada->buscar(procurado);
			removido = chamada->remover(encontrado);
		}
		else if(opcao=='ed'){
			chamada->imprimirDireto();
		}
		else if(opcao=='er'){
			chamada->imprimirReverso();
		}
	}
	cin >> opcao;
	return 0;
}


