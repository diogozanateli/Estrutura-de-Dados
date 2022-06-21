#include <iostream>
using namespace std;

void selection(int vet[], int tam){
	int posmaior;
	int aux;
	for(int i=tam; i>=0 ; i--){
		posmaior=i;
		for(int j=tam-1; j>=0 ; j--){
			if(vet[j]>vet[posmaior]){
				posmaior=j;
			}
		}
		aux=vet[i];
		vet[i]=vet[posmaior];
		vet[posmaior]=aux;
			
		for(int i=0; i<tam ; i++){
		cout << vet[i] << " ";
	}
	cout << endl;
	}

}

int main (){
	int n;
	cin >> n;
	int v[n];
	for(int i=0; i<n ; i++){
		cin >> v[i];
	}
	
	selection(v,n);
	
return 0;
}
