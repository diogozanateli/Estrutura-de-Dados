#include <iostream>
using namespace std;

void quick(int vet[], int tam){
	int controle, aux,x,y;
	controle=tam/2;
	for(int i=0; i<tam ; i++){
		for(int j=tam-1; j>controle; j--){
			while(i<=j){
				if(i<controle){
					i++;
				}
				else if(j>controle){
					j--;
				}
		}
		if(i<=j){
	aux=vet[i];
	vet[i]=vet[j];
	vet[j]=aux;
	}
	x=i;
	y=j;
	}	
	}
	cout << y << endl;
	if(x>y){
		for(int i=0; i<tam ; i++){
			cout << vet[i] << " ";
		}
	}
}


int main(){
	int n;
	cin >> n;
	int v[n];
	for(int i=0; i<n ; i++){
		cin >> v[i];
	}
	
	quick(v,n);
	
	return 0;
}
