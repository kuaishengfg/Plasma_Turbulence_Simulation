#include<iostream>
#include<cmath>
#include<cstdlib>
#include <ctime>
#include <unistd.h>

using namespace std;

//constant numbers;
const long double pai=3.14159265354; 

                               //various numbers;
long double t,sita,r;         //key var
long double R0,m,fai,A,B,T,h,n,seedd;    //other var
long double deltar,deltasita,dd,faii;

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

//���ؿ������
long double MT(long double xxx){
	long double output;
	//***//
	
	int seeed,xx1,xx2,yy,zz,iii=1,jjj=1;
	long double steinsgate;
	seeed=xxx;

	while(iii<=jjj){
		while(seeed>10000000000){
			seeed=seeed%107;
		}
		xx1=747*seeed+211,yy=xx1%1000;
		xx2=379*seeed+159,zz=xx2%1000;
		seeed=1107*seeed+427;
		while(yy<0){
			yy+=1000;
		}
		while(zz<0){
			zz+=1000;
		}
		steinsgate=0.001*yy+0.000001*zz;
		iii+=1;
	output=steinsgate;
              }
	//***//
	return output;
}
 
//main function,�Ľ��������; 
int main(){
	
	
	//set for rand()
	srand((unsigned int)time(NULL)*100); 
	int numberseed = rand() % 100 + 1;
	
	
    //����ǰ����
    cout<<"����������R0��m,fai,A,B"<<endl;
    cout<<"�������˰汾 �Ѿ�����R0=5��m=5��fai=0��A=1��B=1"<<endl;
    R0=5,m=5,fai=0,A=1,B=1;
    
    
	//�����ʼֵ 
	cout<<"������t=0ʱ�̵ĳ�ʼλ��sita0��r0"<<endl;
	cout<<"������ �˰汾 sita0,r0�Ѿ��������"<<endl;
	sita=MT(numberseed)*2*pai;
	r=MT(numberseed)*R0;              //ע�⣡���� �˴��ٶ���r0��(0,R0/2)�ķ�Χ����; 
	cout<<"sita="<<sita<<"     "<<"r="<<r<<endl;
	
	
	//����ʱ�䲽��h����ִ��ʱ��T,����n=T/h 
	cout<<"������ʱ�䲽��h����ִ��ʱ��T"<<endl;
	cin>>h>>T;
	n=(1.0*T)/(h*1.0);
	

	
	
	//�Ľ����������
    long double ksita1=1.0,ksita2=1.0,ksita3=1.0,ksita4=1.0;
	long double kr1=1.0,kr2=1.0,kr3=1.0,kr4=1.0;
	const long double judgement=0.01;   //judgement��Ϊ1%���ʵ����е�; 
	
	t=1;
	
	for(int i=1;i<=n;i++){
	                      if(MT(numberseed) >= judgement)  //common case
	                                           {

														//*****//
														
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
	
														//*****//
	
													cout<<"t="<<h*i*1.0<<"   "<<"sita="<<sita<<"   "<<"r="<<r<<endl;
                                                }
                                                
                                                
                        else                       //particle random crash; 
						{
                        
											//*****//
		
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
	
											//*****//
										
										//relate to deltar,deltasita,dd,faii;
										//random crash;
										dd=R0/10000;
										faii=MT(numberseed)*2*pai;
										
										//random crash
										deltar=dd*cos(faii);
										r=r+deltar;
										deltasita=dd*sin(faii)/r;
										sita=sita+deltasita;
										
										
										
										cout<<"t="<<h*i*1.0<<"   "<<"sita="<<sita<<"   "<<"r="<<r<<endl;	
                       	
						}
	}
	
	
	return 0;
}

//Version 3.0 2024.3.14
//Version 3.1 2024.3.16 
//Version 3.2 2024.3.20
//Version 3.3 2024.3.20
