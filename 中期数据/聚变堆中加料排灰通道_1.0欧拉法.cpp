#include<iostream>
#include<cmath>
using namespace std;
const long double pai=3.14159265354;
//ע��:�Զ��峣��R0���ڰ뾶 ,m,fai
//Euler Meathod Version 1.0 2024.3.11 
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
cout<<"��������R0��m��fai"<<endl;
cin>>R0>>m>>fai;
cout<<"��������sita0��r0,nround.//nround>=2"<<endl;
cin>>sita>>r>>nround;
//let's define f(sita,r)

//special define finish . later is the main function
h=2.00*pai/nround;
for(int i=1;i<=nround-1;i++)
{
   r=r+h*fsr(sita,r);
   sita=sita+h;
   cout<<"��ʱn="<<i<<"  "<<"sita="<<sita<<"  "<<"r="<<r<<endl; 
}
	return 0;
}
