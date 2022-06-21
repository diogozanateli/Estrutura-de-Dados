#include <iostream>
using namespace std;

int fatorial(int n){
	int aux;
	if((n==0) or (n==1)){
		return 1;
	}
	else if(n==2){
		return 2;
	}
	else{
		aux=n*fatorial(n-2);
	}
	return aux;
}

int main (){
	int a;
	cin >> a;
	
	cout << fatorial(a) << endl;
	
	return 0;
}
