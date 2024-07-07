#include<omp.h>
#include<fstream>
#include<iostream>
#include<cmath>
#include<cstdlib>
#include<ctime>
#include<iomanip>
//#include <unistd.h>
using namespace std;


//constant numbers;
const long double pai = 3.14159265354;

int totalnumber = 100000, testnumber = 9;
//array relate to totalnumber and testnumber(if you want to chenge totalnumber and testnumber,do not forget to change them)
//testnumber:the number of Rr(testnode)
long double R0 = 5.0, Rm = 0.5;
//R0 :outer edge
//Rm :inner edge
long double sita [100000], r [100000], r1 [100000] [9], r2 [100000] [9], MT [100000] [5], flux[3] [9];
//sita [totalnumber]:location sita memory
//r    [totalnumber]:location r memory
//r1   [totalnumber] [testnumber]:location r memory before compute the flux
//r2   [totalnumber] [testnumber]:location r memory after compute the flux
//MT   [totalnumber] [5]:random number memory
//If you need more random number,increase the second number and then codinate the random function
//flux [1] [testnumber]:flux out to Rr
//flux [2] [testnumber]:flux in to Rr
//flux [0] [testnumber]:flux [0] = flux [1] - flux [2],it is the total flux

long double sitam, rm;
//key var(they are used in the progress of 4 stage Runge-Kutta methods)
long double m =5.0, fai = 0.0, A = 200, B = 1.0, h = 0.0001, n, k, w = 200, t;
//other var
//m  :
//fai:
//A  :
//B  :
//h  :time step
//n  :n = (1.0 * T) / (h * 1.0), it is the total stimulation times
//k  :
//w  :
//t  :### Key variable t
long double hhh = 1.0 / h;
int hh = hhh + 1;
//In fact, hh = 1 / h, here is a mistake
long double deltar, deltasita, crashr, crashsita;
//###  I can not descripe it in English
long double Rr, T;
//Rr   :test nodes
//T    :all sport time   


//4 stage Runge-Kutta methods
long double ksita1 = 1.0, ksita2 = 1.0, ksita3 = 1.0, ksita4 = 1.0;
long double kr1 = 1.0, kr2 = 1.0, kr3 = 1.0, kr4 = 1.0;
const long double judgement = 0.01;   
//judgement is the judge point of 1% possibility for crash

//function of d(sita)/dt;
long double fsita(long double tt, long double sitaa, long double rr) {
	long double output;
	//output=(-1.0)*(pai*A*sin(2.0*pai*rr/R0)*sin(m*sitaa+fai))/(B*R0*rr);
	output = -(A / (B * rr)) * (pai * sin(2 * pai * rr / R0) * sin(m * sitaa + w * tt + k * rr) / R0 + k * sin(pai * rr / R0) * sin(pai * rr / R0) * cos(m * sitaa + w * tt + k * rr));
	return output;
}

//function of dr/dt;
long double fr(long double tt, long double sitaa, long double rr) {
	long double output;
	//output=(A*m*sin(pai*r/R0)*sin(pai*r/R0)*cos(m*sita+fai))/(B*rr);
	output = A * m * sin(pai * rr / R0) * sin(pai * rr / R0) * cos(m * sitaa + w * tt + k * rr) / (B * rr);
	return output;
}

//function of 4 stage Runge-Kutta
void RG (long double sitax, long double rx, long double tx){
	ksita1 = fsita(tx, sitax, rx);
	kr1    =    fr(tx, sitax, rx);
	
	ksita2 = fsita(tx + h / 2.0, sitax + ksita1 * h / 2.0, rx + kr1 * h / 2.0);
	kr2    =    fr(tx + h / 2.0, sitax + ksita1 * h / 2.0, rx + kr1 * h / 2.0);
	
	ksita3 = fsita(tx + h / 2.0, sitax + ksita2 * h / 2.0, rx + kr2 * h / 2.0);
	kr3    =    fr(tx + h / 2.0, sitax + ksita2 * h / 2.0, rx + kr2 * h / 2.0);
	
	ksita4 = fsita(tx + h, sitax + h * ksita3, rx + h * ksita3);
	kr4    =    fr(tx + h, sitax + h * ksita3, rx + h * ksita3);
	
	sitax  = sitax + h * (ksita1 + 2.0 * ksita2 + 2.0 * ksita3 + ksita4) / 6.0;
	rx     =    rx + h * (kr1 + 2.0 * kr2 + 2.0 * kr3 + kr4) / 6.0;
}


//other function
//indecate the progress
int percent (int m1, int m2){return (m1 * 100 / m2); }
void progress (int m1, int m2){
	cout << '\r' << "progress: " << percent (m1, m2) << "%";
}

int test = 0;

//main function
int main() {
	//Monte Carlo method to save random number
	srand((unsigned int)time(NULL) * 100);
	long double output;
	int seeed, xx1, xx2, yy, zz;
	seeed = rand();
	for(int i=0; i < (totalnumber * 4); i++){
		while (seeed > 10000000000) {
			seeed = seeed % 107;
		}
		xx1 = 7257 * seeed + 2161, yy = xx1 % 10000;
		xx2 = 3789 * seeed + 1251, zz = xx2 % 10000;
		seeed = 5607 * seeed + 4527;
		seeed = 5607 * seeed + 4527;
		if (yy < 0) {
			yy += 10000;
		}
		if (zz < 0) {
			zz += 10000;
		}
		output = 0.0001 * yy + 0.00000001 * zz;
		if (i < totalnumber){MT [i] [1] = output;}
		else{
			if (i < (totalnumber * 2)){MT [i-totalnumber] [2] = output;}
			else{
				if (i < (totalnumber * 3)){MT [i-(totalnumber * 2)] [3] = output;}
				else{
					if (i < (totalnumber * 4)){MT [i-(totalnumber * 3)] [4] = output;}
					else{
						if (i < (totalnumber * 5)){MT [i-(totalnumber * 4)] [5] = output;}
					}
				}
			}
		}
	}
	
	//input pre-variable 
	printf("###  R0 = %Lf ,m = %Lf ,fai = %Lf ,A = %Lf ,B = %Lf ,k = %Lf\n",R0,m,fai,A,B,k);
	cout << "###  Here h = " << h << ", w = " << w << ", total number =" << totalnumber << endl;
	cout << "###  If you want to change them, please do it in the program" << endl;
	cout << "###  Enter the total execution time T" << endl;
	cout << "T=" ;
	cin >> T ;
	n = (1.0 * T) / (h * 1.0);
	
	for(int i = 0; i < 3; i++){
		for(int ii = 0; ii < testnumber; ii++){
			flux [i] [ii] = 0;
		}
	}
	for(int ii = 0; ii < totalnumber; ii++){
		sita [ii] = MT [ii] [1] * 2 * pai;
		r    [ii] = MT [ii] [2] * (R0 - Rm) + Rm;
	}
	t = 1.0;
	Rr = Rm;
	
	ofstream outputFile ("output.txt");
	if (!outputFile.is_open()) {
		cout << "The file is not open" << endl;
		return 1;
	}
	
	for (int i = 0; i < n; i++){
		t = h * i * 1.0 ; // ### debug here in 2024.5.28 ###
		
		for(int ii=0; ii < totalnumber; ii++){
			sitam = sita [ii];
			rm    = r    [ii];
			
			//judge every t=1
			if (((i + 1) * 100) % hh == 0){
				if (MT [((ii + 1) +(i + 1) * 3) % totalnumber] [3]>= judgement){
					//without crash//
					RG (sitam, rm, t);
				}
				else{
					//with crash//
					RG (sitam, rm, t);
					
					//relate to deltar,deltasita,dd,faii;
					//random crash;
					crashsita = MT [((ii + 1) +(i + 1) * 3) % totalnumber] [4] * 2 * pai;
					crashr    = MT [((ii + 1) +(i + 1) * 3) % totalnumber] [5] * R0 / 100;
					
					//random crash
					deltar = crashr * cos(crashsita);
					rm = rm + deltar;
					deltasita = crashr * sin(crashsita) / rm;
					sitam = sitam + deltasita;
				}
			}
			//no judge
			else{
				RG (sitam, rm, t);
			}
			
			sita [ii] = sitam;
			r    [ii] = rm;
			
			for (int iii = 0; iii < testnumber; iii++){
				if (((i + 100) * 10) % hh == 0) {
					r1 [ii] [iii] = rm;
				}
				if (((i + 1) * 10) % hh == 0) {
					r2 [ii] [iii] = rm;
					if(r1 [ii] [iii] <= Rr){
						if(r2 [ii] [iii] >= Rr){
							flux [1] [iii] += 1;
						}
					}
					if(r1 [ii] [iii] >= Rr){
						if(r2 [ii] [iii] <= Rr){
							flux [2] [iii] += 1;
						}
					}
				}
				Rr = Rm + 0.5 * iii;
			}	
		}
		
		//indecate the progress
		if (((i + 1) * 1000) % hh == 0) {progress ((((i + 1) * 10) % hh), hh);}
		
		if(((i + 1) * 10) % hh == 0) {
			cout << '\r' << "t = " << h * (i + 1) * 1.0;
			outputFile << endl;
			outputFile << "t = " << h * (i + 1) * 1.0;
			for(int ii = 0; ii < testnumber; ii++){
				Rr = Rm + 0.5 * ii;
				flux [0] [ii] = flux [1] [ii] - flux [2] [ii];
				cout << "     Rr = " << Rr <<"     flux+ = " << flux [1] [ii] << "     flux- = " << flux [2] [ii] << "     flux = " << flux [0] [ii] << endl;
				outputFile << "     Rr = " << Rr <<"     flux+ = " << flux [1] [ii] << "     flux- = " << flux [2] [ii] << "     flux = " << flux [0] [ii];
				for(int i = 0; i<3; i++){
					flux [i] [ii] = 0;
				}
				Rr = Rm;
			}
			cout << endl;
		}
	}
	
	return 0;
}

//Version 3.0 2024.3.14
//Version 3.1 2024.3.16 
//Version 3.2 2024.3.20
//Version 3.3 2024.3.20
//Version 4.0 2024.3.22
//Version 5.0 2024.5.11
//Version 5.1 2024.5.19
//Version 5.2.a 2024.5.28
//Version 5.2.b 2024.5.28
//Version 6.0 2024.6.21
//Version 6.1.a 2024.6.23
//Version 6.1.b 2024.6.23
