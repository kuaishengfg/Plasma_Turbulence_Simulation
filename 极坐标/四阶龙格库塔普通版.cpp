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
	cout<<"����������R0��m,fai,A,B"<<endl;
	cin>>R0>>m>>fai>>A>>B;
    
    
    
	//�����ʼֵ 
	cout<<"������t=0ʱ�̵ĳ�ʼλ��sita0��r0"<<endl;
    cin>>sita>>r;
           //ע�⣡���� �˴��ٶ���r0��(0,R0/2)�ķ�Χ����; 
	
	//����ʱ�䲽��h����ִ��ʱ��T,����n=T/h 
	cout<<"������ʱ�䲽��h����ִ��ʱ��T"<<endl;
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
