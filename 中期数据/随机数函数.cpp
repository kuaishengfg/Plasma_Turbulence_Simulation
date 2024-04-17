#include<iostream>
using namespace std;

int seed,j;
//这两个变量主函数和随机数函数都得用

long double steinsgate(int seed,int j){
	//不知道为什么必须得再定义一遍，你要是会处理，删掉不影响的话可以改
	int x1,x2,y,z,i=1;
	long double steinsgate0;
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
		steinsgate0=0.001*y+0.000001*z;
		i+=1;
	}
    return steinsgate0;
}
//j表示该序列第j个随机数，seed控制序列种类以便函数多次使用

int main(){
	//这里拿主函数试验输出及演示用法
	int k;
	cout<<"请输入需要随机数的个数：";
	cin>>k;
	cout<<"请输入种子：";
	cin>>seed;
	cout<<"得到随机数为："<<endl;
	j=1;
	while(j<=k){
		cout<<steinsgate(seed,j)<<endl;
		j+=1;
	}
	
	return 0;
}
