#include<iostream>
#include<stdlib.h>
using namespace std;


//ÃÉÌØ¿¨ÂåËæ»ú
long double MT(long double xxx){
	long double output;
	//***//
	
	int seed,x1,x2,y,z,i=1,j=1;
	long double steinsgate;
	seed=xxx;

	while(i<=j){
		while(seed>10000000000){
			seed=seed%107;
		}
		x1=747*seed+211,y=x1%1000;
		x2=379*seed+159,z=x2%1000;
		seed=1107*seed+427;
		while(y<0){
			y+=1000;
		}
		while(z<0){
			z+=1000;
		}
		steinsgate=0.001*y+0.000001*z;
		i+=1;
	output=steinsgate;
}
return output;
}
int xyz;	
	
int main(){
	
	cin>>xyz;
for(int j=1;j<=xyz ; j++){
	
	
	cout<<MT(rand())<<endl;
	
	
                         }

return 0;



}

	

