#include <iostream>
using namespace std;

int Busca(int vet[],int inicio, int fim, int buscado);
void leitura(int vet[],int x);

int main(){
	
int x;
cin >> x;	
	
int vet[x];

leitura(vet,x);

int buscado;
cin >> buscado;

cout << Busca(vet,0,x-1,buscado) << endl;
	
}

int Busca(int vet[],int inicio, int fim, int buscado){

int meio = (fim+inicio)/2;

 if(vet[meio] == buscado){
	return meio;
 }
 if(fim == inicio){
	return -1;
 }
 if(vet[meio] > buscado){
	return Busca(vet,meio+1,fim,buscado);
 }
 if(vet[meio] < buscado){
	return Busca(vet,inicio,meio-1,buscado);
 }
}
void leitura(int vet[],int x){
	for(int i=0;i<x;i++){
		cin >> vet[i];
	}
}
