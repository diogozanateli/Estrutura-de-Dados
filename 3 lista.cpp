#include <iostream>
using namespace std;

int binomial(int n, int k){
	if((k==0) or (k==n)){
		return 1;
	}
	else{
	return binomial(n-1,k-1) + binomial(n-1,k);	
	}
}

int main(){
	int a, b;
	cin >> a >> b;
	
	cout << binomial(a,b) << endl;
	return 0;
}
