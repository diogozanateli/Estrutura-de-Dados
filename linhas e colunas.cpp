#include <iostream>
using namespace std;
int main(){
	int N, fib=0, ultimo, penultimo, antip;
	antip=0;
	penultimo=1;
	ultimo=2;
	cin >> N;
	if(N!=1 and N!=2){
		cout << antip << endl << penultimo << endl << ultimo << endl;
	}
	else{
		cout << antip << endl;
	}
	while(N>3){
		fib=antip+penultimo+ultimo;
		cout << fib << endl;
		antip=penultimo;
		penultimo=ultimo;
		ultimo=fib;
		N--;
	}
	return 0;
}
