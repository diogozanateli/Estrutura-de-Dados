#include <iostream>
using namespace std;

int main(){
	int vetor[10], num;
	for (int i=0; i<10 ; i++){
		vetor[i]=0;
		cin >> num;
		if(num > 0){
			vetor[i]=num;
		}
	}
	for(int i=0; i<10 ; i++){
		if(vetor[i]>0){
			cout << vetor[i] << " ";
		}
	}
	return 0;
}
