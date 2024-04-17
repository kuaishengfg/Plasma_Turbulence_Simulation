#include<iostream>
#include<cmath>
#include<stdlib.h>

using namespace std;

//constant numbers;
const long double pai=3.14159265354; 

                               //various numbers;
long double t,sita,r;         //key var
long double R0,m,fai,A,B,T,h,n,seedd;    //other var
long double deltar,deltasita,dd,faii;

    long double ksita1,ksita2,ksita3,ksita4;
	long double kr1,kr2,kr3,kr4;

//function of d(sita)/dt;
long double fsita(long double tt, long double sitaa, long double rr){
	long double output;
	output=(-1.0)*(pai*A*sin(2.0*pai*rr/R0)*sin(m*sitaa+fai))/(B*R0*rr);
	return output;
}

//function of dr/dt;
long double fr(long double tt, long double sitaa, long double rr){
	long double output;
	output=(A*m*sin(pai*r/R0)*sin(pai*r/R0)*cos(m*sita+fai))/(B*rr);
	return output;
}

int main()
{
	cout<<"请依次输入R0，m,fai,A,B"<<endl;
	cin>>R0>>m>>fai>>A>>B;
    const long double R0=5,m=5,fai=0,A=1,B=1;
    
    
	//输入初始值 
	cout<<"请输入t=0时刻的初始位置sita0，r0"<<endl;
    cin>>sita>>r;
           //注意！！！ 此处假定了r0在(0,R0/2)的范围生成; 
	
	//输入时间步长h和总执行时间T,其中n=T/h 
	cout<<"请输入时间步长h，总执行时间T"<<endl;
	cin>>h>>T;
	n=(1.0*T)/(h*1.0);
    
	for(int i=1 ; i<=n ; i++ )
{

	
                         				ksita1=fsita(t,sita,r);
										kr1=fr(t,sita,r);
	
										ksita2=fsita(t+h/2.0,sita+ksita1*h/2.0,r+kr1*h/2.0);
										kr2=fr(t+h/2.0,sita+ksita1*h/2.0,r+kr1*h/2.0);
	
										ksita3=fsita(t+h/2.0,sita+ksita2*h/2.0,r+kr2*h/2.0);
										kr3=fr(t+h/2.0,sita+ksita2*h/2.0,r+kr2*h/2.0);
	
										ksita4=fsita(t+h,sita+h*ksita3,r+h*ksita3);
										kr4=fr(t+h,sita+h*ksita3,r+h*ksita3);
	
										sita=sita+h*(ksita1+2.0*ksita2+2.0*ksita3+ksita4)/6.0;
										r=r+h*(kr1+2.0*kr2+2.0*kr3+kr4)/6.0;
										
										cout<<"t="<<h*i*1.0<<"   "<<"sita="<<sita<<"   "<<"r="<<r<<endl;
}
	return 0;
}
