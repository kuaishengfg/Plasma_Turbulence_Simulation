#include<iostream>
#include<cmath>
using namespace std;


const long double pai=3.14159265354;


//注意:自定义常数R0器壁半径 ,m,fai
//Euler Meathod Version 1.0 2024.3.11
//龙格库塔法 Version 2.0 2024.3.13 


long double R0,m,fai,h;


long double fsr (long double sitaa , long double rr )
{
	long double output;
	output=(-1.0)*(m*R0)*tan((pai*rr)*1.0/R0)/(2*pai*rr*tan(m*sitaa+fai));
	return output;
}


int main( )
{
	
	
int nround;
long double sita,r;
long double k1,k2,k3,k4;


cout<<"依次输入R0，m，fai"<<endl;
cin>>R0>>m>>fai;
cout<<"依次输入sita0，r0,nround.//nround>=2"<<endl;
cin>>sita>>r>>nround;


//let's define f(sita,r)

//special define finish . later is the main function


h=2.00*pai/nround;
for(int i=1;i<=nround-1;i++)
{
	
	
   //r=r+h*fsr(sita,r);
   //sita=sita+h;
   //cout<<"n="<<i<<"  "<<sita<<"  "<<r<<endl; 
   
   
   k1=fsr(sita,r);
   k2=fsr(sita+h/2.0,r+k1*h/2.0);
   k3=fsr(sita+h/2.0,r+k2*h/2.0);
   k4=fsr(sita+h,r+h*k3);
   
   r=r+h*(k1+2*k2+2*k3+k4)/6.0;
   
   sita=sita+h;
   
   cout<<"n="<<i<<"   "<<"sita="<<sita<<"   "<<"r="<<r<<endl;
   
   
}
    cout<<"四阶龙格库塔法"<<endl;
    cin.get();
	return 0;
}
