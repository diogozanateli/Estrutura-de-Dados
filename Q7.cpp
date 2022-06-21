/* Código base para estrutura de dados Fila
 * 
 * by Juliana Galvani Greghi
 *                                nov/2018
 */

#include <iostream>
#include <string>

using namespace std;

    class Noh {
        friend class Fila;
        private:
            string dado; // poderia ser outro tipo de variável
            Noh *proximo;
        public:
            Noh(string info){
                dado = info;
                proximo = NULL;
            }
            ~Noh(){
                proximo = NULL;
                delete proximo;
            }
    };

    class Fila {
    private:
        Noh* inicio;
        int tamanho;
    
    public:
        Fila();
        ~Fila();
        void enfileira(string info);
        string desenfileira();
        bool estaVazia(); // verifica se existem elementos na fila     
};


Fila::Fila() {
    tamanho = 0;
    inicio = NULL;
}

Fila::~Fila() { 
    delete inicio;
    }


void Fila::enfileira(string info) {
    Noh *aux = new Noh(info);
    Noh *fim = inicio;
	if(estaVazia()){
		inicio=aux;
		tamanho++;
	}  
	else if(tamanho >= 1){
		while(fim->proximo != NULL){
		fim = fim->proximo;
		}
		fim->proximo = aux;
		tamanho++;
	} 
	fim=aux;
}

string Fila::desenfileira() {
    string removido;
    Noh* temporario;
    removido = inicio->dado;    
    temporario = inicio;
    inicio = inicio->proximo;
    delete temporario;
    tamanho--;
    if (estaVazia())
        inicio = NULL;
        
    return removido;    
}
    
bool Fila::estaVazia() {
    if (tamanho == 0)
        return true;
    else
        return false;
}

int main() {

Fila prio,norm ;
string nome, comando;
int aux;
    
    cin >> comando;
    while(comando != "fim"){
	if(comando == "normal"){
    	cin >> nome;
		norm.enfileira(nome);
	}
	else if(comando == "prioridade"){
		cin >> nome;
		prio.enfileira(nome);
	}
	else if(comando == "atender"){
		int cont=0;
		if(!prio.estaVazia()){
		while(cont<=3){
		if(!prio.estaVazia()){
			cout << prio.desenfileira() << endl;
			cont++;
		}
	}
}
		else{
		while(norm.estaVazia()){
			cout << norm.desenfileira() << endl;
		}
	}
	}
	cin >> comando;
}
	
    return 0;
}

