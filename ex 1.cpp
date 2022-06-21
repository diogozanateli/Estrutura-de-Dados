#include <iostream>
using namespace std;

int main (){
	int vetor[9];
	for(int i=0 ; i<9 ; i++){
	cin >> vetor[i];
	}
	
	for(int i=0 ; i<9 ; i++){
			if((vetor[i]%2!=0) and (vetor[i]%3!=0) and (vetor[i]%5!=0) and (vetor[i]%7!=0) and (vetor[i]%9!=0)){
				cout << vetor[i] << " " << i << endl;
			}
			else if((vetor[i]==1) or (vetor[i]==2) or (vetor[i]==3) or (vetor[i]==5) or (vetor[i]==7)){
			cout << vetor[i] << " " << i << endl;
			}
	}	
		
	return 0;
}
