#include <iostream>
#include <string>

using namespace std;

class aluno{
	friend class lista;
	private:
		string nome;
		int matricula;
		string curso;
		aluno *proximo;
	public:
		aluno();
		~aluno();
};

aluno :: aluno(){
	proximo = NULL;
}
aluno::~aluno(){
	delete proximo;
}

class lista{
	private:
		aluno* inicio;
		int tamanho;
	public:
		lista();
		~lista();
		bool vazia();
		void inserir(string n, int m, string c);
		int remover(aluno *retira);
		aluno* buscar(int chave);
		void imprimirAluno(aluno* noh);
		void imprimir();
};
lista::lista(){
 	inicio = NULL;
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
 void lista::inserir(string n, int m, string c){
 	aluno *novo = new aluno();
 	novo->nome=n;
 	novo->matricula=m;
 	novo->curso=c;
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
	
	void lista::imprimir(){
	aluno* auxiliar = inicio;
	if(!vazia()){
		while(auxiliar != NULL){
			cout << endl << auxiliar->matricula << endl;
			cout << auxiliar->nome << "\t" << auxiliar->curso << "\n";
			auxiliar = auxiliar->proximo;
		}
	}
	else {
		cout << "Lista vazia!" << endl;
	}
	}
	
	void menu(){
		cout << "1 - Inserir(nome, matricula, curso);\n2 - Remover;\n";
		cout << "3 - Imprimir aluno \n4 - Imprimir lista \n5 - Sair\n";
	}	

int main(){
	int opcao;
	lista* chamada = new lista();
	menu();
	cin >> opcao;
	while(opcao != 5){
		if(opcao == 1){
			string nomeAluno, cursoAluno;
			int matriculaAluno;
			cin >> nomeAluno >> matriculaAluno >> cursoAluno;
			chamada->inserir(nomeAluno, matriculaAluno, cursoAluno);
		}
		else if(opcao == 2){
			int procurado, removido;
			cin >> procurado;
			aluno* encontrado;
			encontrado = chamada->buscar(procurado);
			removido = chamada->remover(encontrado);
			if(removido!=-1){
				cout << "Aluno " << removido << " removido com sucesso!" << endl;	
			}
			else{
				cout << "Aluno não encontrado" << endl;
			}
		}
		else if(opcao==3){
			
		}
		else if(opcao==4){
			chamada->imprimir();
		}
		else{
			cout << "Opção inválida!" << endl;
		}
		cout << endl << endl;
		menu();
		cin >> opcao;
	}
	cout << "Até logo!\n";
	
	return 0;
}
