#include <iostream>
using namespace std;

int selection(int vet[], int tam){
	int posmenor;
	for(int i=0; i<tam-1 ; i++){
		posmenor=i;
		for(int j=i+1; j<tam; j++){
			if(vet[j]<vet[posmenor]){
				posmenor=j;
			}
		}
swap (vet[i], vet[posmenor]);	
}
}

int binaria(int vetor[], int inicio, int fim, int j){
	int meio=(inicio+fim)/2;
	if(j==vetor[meio]){
		return meio;
	}
	if(inicio==fim){
		return -1;
	}
	if(j<vetor[meio]){
		fim=meio-1;
		return binaria(vetor,inicio,fim,j);
	}
	if(j>vetor[meio]){
		inicio=meio+1;
		return binaria(vetor,inicio,fim,j);
	}
	return 0;
}


int main(){
	int a,b;
	cin >> a;
	int v[a];
	for(int i=0; i<a ; i++){
		cin >> v[i];
	}
	cin >> b;
	selection(v,a);
	cout << binaria(v,0,a-1,b) << endl;

	return 0;
}
