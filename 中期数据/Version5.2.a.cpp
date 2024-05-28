#include<iostream>
#include<cmath>
#include<cstdlib>
#include <ctime>
//#include <unistd.h>

using namespace std;

//constant numbers;
const long double pai = 3.14159265354;

//various numbers;
long double t, sita, r;         //key var
long double R0, m, fai, A, B, T, h, n, seedd, k, w;    //other var
long double deltar, deltasita, dd, faii;

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

//Monte Carlo method
long double MT(long double xxx) {
	long double output;
	//***//

	int seeed, xx1, xx2, yy, zz, iii = 1, jjj = 1;
	long double steinsgate;
	seeed = xxx;

	while (iii <= jjj) {
		while (seeed > 10000000000) {
			seeed = seeed % 107;
		}
		xx1 = 747 * seeed + 211, yy = xx1 % 1000;
		xx2 = 379 * seeed + 159, zz = xx2 % 1000;
		seeed = 1107 * seeed + 427;
		while (yy < 0) {
			yy += 1000;
		}
		while (zz < 0) {
			zz += 1000;
		}
		steinsgate = 0.001 * yy + 0.000001 * zz;
		iii += 1;
		output = steinsgate;
	}
	//***//
	return output;
}

//main function,4 stage Runge-Kutta methods; 
int main() {


	//set for rand()
	srand((unsigned int)time(NULL) * 100);
	int numberseed = rand() % 1000 + 1;


	//input pre-variable 
	cout << "###  Please input :R0,m,fai,A,B,w,k" << endl;
	R0 = 5.0, m = 5.0, fai = 0.0, A = 200.0, B = 1.0, w = 10.0, k = 1.0;
	printf("###  R0=%Lf ,m=%Lf ,fai=%Lf ,A=%Lf ,B=%Lf ,w=%Lf ,k=%Lf\n",R0,m,fai,A,B,w,k);



	//input Initial value 
	cout << "###  Please input sita0,r0 while t=0 " << endl;
	cout << "###  In this Version5.2. Initial position sita0,r0 have been randomly given" << endl;
	sita = MT(numberseed) * 2 * pai;
	r = MT(numberseed) * R0;              //Attension !!! It is assumed that r0 is generated in the range (0, R0/2) 
	cout << "	sita=" << sita << "     " << "  	r=" << r << endl;


	//Enter the time step h and the total execution time T, where n=T/h.
	
		h = 0.0001;	//
	cout << "###  Here h="<<h<<endl;
	cout << "###  Enter the time step h and the total execution time T" << endl;
	cin >> T;
		n = (1.0 * T) / (h * 1.0);// n is the total stimulation times.




	//4 stage Runge-Kutta methods
	
	long double ksita1 = 1.0, ksita2 = 1.0, ksita3 = 1.0, ksita4 = 1.0;
	long double kr1 = 1.0, kr2 = 1.0, kr3 = 1.0, kr4 = 1.0;
	
	const long double judgement = 0.01;   
	//judgement is the judge point of 1% possibility for crash

	t = 1.0; // ### Key variable t ,

	for (int i = 1; i <= n; i++) {
		
		t= h * i * 1.0 ; // ### debug here in 2024.5.28 ###
		
		if (MT(numberseed) >= judgement)  //common case
		{

			//*****//

			ksita1 = fsita(t, sita, r);
			kr1    =    fr(t, sita, r);

			ksita2 = fsita(t + h / 2.0, sita + ksita1 * h / 2.0, r + kr1 * h / 2.0);
			kr2    =    fr(t + h / 2.0, sita + ksita1 * h / 2.0, r + kr1 * h / 2.0);

			ksita3 = fsita(t + h / 2.0, sita + ksita2 * h / 2.0, r + kr2 * h / 2.0);
			kr3    =    fr(t + h / 2.0, sita + ksita2 * h / 2.0, r + kr2 * h / 2.0);

			ksita4 = fsita(t + h, sita + h * ksita3, r + h * ksita3);
			kr4    =    fr(t + h, sita + h * ksita3, r + h * ksita3);

			sita   = sita + h * (ksita1 + 2.0 * ksita2 + 2.0 * ksita3 + ksita4) / 6.0;
			r      =    r + h * (kr1 + 2.0 * kr2 + 2.0 * kr3 + kr4) / 6.0;

			//*****//
			
			if(i % 10000 == 0)
			{
				cout << "t=" << h * i * 1.0 << "   " << "sita=" << sita << "   " << "r=" << r << endl;
			}
		}


		else                       //particle random crash; 
		{

			//*****//

			ksita1 = fsita(t, sita, r);
			kr1    = 	fr(t, sita, r);

			ksita2 = fsita(t + h / 2.0, sita + ksita1 * h / 2.0, r + kr1 * h / 2.0);
			kr2    = 	fr(t + h / 2.0, sita + ksita1 * h / 2.0, r + kr1 * h / 2.0);

			ksita3 = fsita(t + h / 2.0, sita + ksita2 * h / 2.0, r + kr2 * h / 2.0);
			kr3    = 	fr(t + h / 2.0, sita + ksita2 * h / 2.0, r + kr2 * h / 2.0);

			ksita4 = fsita(t + h, sita + h * ksita3, r + h * ksita3);
			kr4    = 	fr(t + h, sita + h * ksita3, r + h * ksita3);

		    sita   = sita + h * (ksita1 + 2.0 * ksita2 + 2.0 * ksita3 + ksita4) / 6.0;
			r      =    r + h * (kr1 + 2.0 * kr2 + 2.0 * kr3 + kr4) / 6.0;

			//*****//

			//relate to deltar,deltasita,dd,faii;
			//random crash;
			dd = R0 / 100;
			faii = MT(numberseed) * 2 * pai;

			//random crash
			deltar = dd * cos(faii);
			r = r + deltar;
			deltasita = dd * sin(faii) / r;
			sita = sita + deltasita;



			if (i % 10000 == 0)
			{
				cout << "t=" << h * i * 1.0 << "   " << "sita=" << sita << "   " << "r=" << r << endl;
			}
			/*
			
			there is a question is we can't give out to much r&sita in a time ,so we choose 1 in 10000 particle to have longer runing time.
			however ,once we learned how to operate flies ,this would be no problem.
			in Version5.2.a ,we keeps the (i % 10000 == 0)
			in Version5.2.b ,we give up it.
			
			*/
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
