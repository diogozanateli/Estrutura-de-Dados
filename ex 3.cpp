#include <iostream>
using namespace std;

int main(){

	int vetor[20];
	float A=0,B=0,C=0,D=0,E=0,F=0;
	
	for(int i=0; i<20 ; i++){
		cin >> vetor[i];
		if(vetor[i]==1){
			A++;
		}
		else if(vetor[i]==2){
			B++;
		}
		else if(vetor[i]==3){
			C++;
		}
		else if(vetor[i]==4){
			D++;
		}
			else if(vetor[i]==5){
			E++;
		}
			else if(vetor[i]==6){
			F++;
		}
	}
		cout << "1: " << (A/20) << endl;
		cout << "2: " << (B/20) << endl;
		cout << "3: " << (C/20) << endl;
		cout << "4: " << (D/20) << endl;
		cout << "5: " << (E/20) << endl;
		cout << "6: " << (F/20);
	
	return 0;
}
