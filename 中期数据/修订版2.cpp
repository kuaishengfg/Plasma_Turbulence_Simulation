#include<iostream>
using namespace std;

int main(){
	int seed,x1,x2,y,z,i=1,j;
	long double steinsgate;
	cout<<"输入所需随机数个数  "<<endl;
	cin>>j;
	cout<<"输入种子  "<<endl;
	cin>>seed;
	cout<<"得到的随机数为 "<<endl;
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
		cout<<steinsgate<<endl;
	}
	return 0;
}
