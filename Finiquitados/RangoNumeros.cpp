#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <cctype>

using namespace std;

enum class Estado {q0, q1, q2, q3, q4, q5, q6, q7, q8, q9, q10, q11, q12, q13, q14, q15, q16, q17, q18, WA};

Estado analisis(const string& s, ofstream& salida);

int main(){
	
	ifstream archivo;
	
	archivo.open("RangoNumeros.txt", ios::in);
	
	if(archivo.fail()){
		
		cout << "Error al abrir el archivo.\n";
		exit(1);
	}
	
	ofstream salida;
	
	salida.open("RangoNumeros_salida.txt", ios::out);
	
	if(salida.fail()){
		
		cout << "Error al crear el archivo.\n";
		exit(1);
	}
	
	string texto;
	
	while(!archivo.eof()){
		
		getline(archivo, texto);
		
		if(texto != ""){
			
			salida << "Se analizara la siguiente cadena:" << texto << endl;
			cout << "Se analizara la siguiente cadena:" << texto << endl;
		
			Estado x = analisis(texto, salida);
			
			if(x != Estado::WA){
				
				salida << "Cadena valida:D\n";
				cout << "Cadena valida:D\n";
			}else{
				
				salida << "Cadena no valida:(\n";
				cout << "Cadena no valida:(\n";
			}
			
			salida << endl;
			cout << endl;
		}		
	}
	
	archivo.close();
	salida.close();
	
	return 0;
}

Estado analisis(const string& s, ofstream& salida){
	
	Estado actual = Estado::q0;
	int pos = 0;
	bool ban = true;
	
	while(ban && pos < s.length()){
		
		char c = s[pos];
		
		switch(actual){
			
			case Estado::q0:
				
				if(isdigit(c)){
					
					if(c == '1'){
						
						salida << "Q0(" << c <<") => Q3\n";
						cout << "Q0(" << c <<") => Q3\n";
						actual = Estado::q3;
					}
					
					else if(c == '2'){
						
						salida << "Q0(" << c <<") => Q6\n";
						cout << "Q0(" << c <<") => Q6\n";
						actual = Estado::q6;
					}
					
					else if(c == '0'){
						
						salida << "Q0(" << c <<") => Q12\n";
						cout << "Q0(" << c <<") => Q12\n";
						actual = Estado::q12;
					}else{
						
						salida << "Q0(" << c <<") => Q1\n";
						cout << "Q0(" << c <<") => Q1\n";
						actual = Estado::q1;
					}
					
				}else{
					
					if(c == '-'){
						
						salida << "Q0(" << c <<") => Q13\n";
						cout << "Q0(" << c <<") => Q13\n";
						actual = Estado::q13;
					}else{
						
						salida << c << " rompe la cadena.\n";
						cout << c << " rompe la cadena.\n";
						ban = false;
					}
				}
				
				break;
				
			case Estado::q1:
				
				if(isdigit(c)){
					
					salida << "Q1(" << c <<") => Q2\n";
					cout << "Q1(" << c <<") => Q2\n";
					actual = Estado::q2;
				}else{
					
					salida << c << " rompe la cadena.\n";
					cout << c << " rompe la cadena.\n";
					ban = false;
				}
				
				break;
				
			case Estado::q2:
				
				salida << c << " rompe la cadena.\n";
				cout << c << " rompe la cadena.\n";
				ban = false;
				
				break;
				
			case Estado::q3:
				
				if(isdigit(c)){
					
					salida << "Q3(" << c <<") => Q4\n";
					cout << "Q3(" << c <<") => Q4\n";
					actual = Estado::q4;
				}else{
					
					salida << c << " rompe la cadena.\n";
					cout << c << " rompe la cadena.\n";
					ban = false;
				}
				
				break;
				
			case Estado::q4:
				
				if(isdigit(c)){
					
					salida << "Q4(" << c <<") => Q5\n";
					cout << "Q4(" << c <<") => Q5\n";
					actual = Estado::q5;
				}else{
					
					salida << c << " rompe la cadena.\n";
					cout << c << " rompe la cadena.\n";
					ban = false;
				}
				
				break;
				
			case Estado::q5:
				
				salida << c << " rompe la cadena.\n";
				cout << c << " rompe la cadena.\n";
				ban = false;
				
				break;
				
			case Estado::q6:
				
				if(isdigit(c)){
					
					if(c == '2'){
						
						salida << "Q6(" << c <<") => Q10\n";
						cout << "Q6(" << c <<") => Q10\n";
						actual = Estado::q10;
					}
					
					else if(c == '1' || c == '0'){
						
						salida << "Q6(" << c <<") => Q8\n";
						cout << "Q6(" << c <<") => Q8\n";
						actual = Estado::q8;
					}else{
						
						salida << "Q6(" << c <<") => Q7\n";
						cout << "Q6(" << c <<") => Q7\n";
						actual = Estado::q7;
					}
					
				}else{
					
					ban = false;
				}
				
				break;
				
			case Estado::q7:
				
				salida << c << " rompe la cadena.\n";
				cout << c << " rompe la cadena.\n";
				ban = false;
				
				break;
			
			case Estado::q8:
				
				if(isdigit(c)){
					
					salida << "Q8(" << c <<") => Q9\n";
					cout << "Q8(" << c <<") => Q9\n";
					actual = Estado::q9;
				}else{
					
					salida << c << " rompe la cadena.\n";
					cout << c << " rompe la cadena.\n";
					ban = false;
				}
				
				break;
				
			case Estado::q9:
				
				salida << c << " rompe la cadena.\n";
				cout << c << " rompe la cadena.\n";
				ban = false;
				
				break;
				
			case Estado::q10:
				
				if(c <= '5' && c >= '0'){
					
					salida << "Q10(" << c <<") => Q11\n";
					cout << "Q10(" << c <<") => Q11\n";
					actual = Estado::q11;
				}else{
					
					salida << c << " rompe la cadena.\n";
					cout << c << " rompe la cadena.\n";
					ban = false;
				}
				
				break;
				
			case Estado::q11:
				
				salida << c << " rompe la cadena.\n";
				cout << c << " rompe la cadena.\n";
				ban = false;
				
				break;
				
			case Estado::q12:
				
				salida << c << " rompe la cadena.\n";
				cout << c << " rompe la cadena.\n";
				ban = false;
				
				break;
				
			case Estado::q13:
				
				if(isdigit(c) && c != '0'){
					
					if(c == '1'){
						
						salida << "Q13(" << c <<") => Q14\n";
						cout << "Q13(" << c <<") => Q14\n";
						actual = Estado::q14;
					}
					
					else if(c == '2'){
						
						salida << "Q13(" << c <<") => Q16\n";
						cout << "Q13(" << c <<") => Q16\n";
						actual = Estado::q16;
					}else{
						
						salida << "Q13(" << c <<") => Q18\n";
						cout << "Q13(" << c <<") => Q18\n";
						actual = Estado::q18;
					}
				}else{
					
					salida << c << " rompe la cadena.\n";
					cout << c << " rompe la cadena.\n";
					ban = false;
				}
				
				break;
				
			case Estado::q14:
				
				if(isdigit(c)){
					
					salida << "Q14(" << c <<") => Q15\n";
					cout << "Q14(" << c <<") => Q15\n";
					actual = Estado::q15;
				}else{
					
					salida << c << " rompe la cadena.\n";
					cout << c << " rompe la cadena.\n";
					ban = false;
				}
				
				break;
				
			case Estado::q15:
				
				salida << c << " rompe la cadena.\n";
				cout << c << " rompe la cadena.\n";
				ban = false;
				
				break;
				
			case Estado::q16:
				
				if(c <= '5' && c >= '0'){
					
					salida << "Q16(" << c <<") => Q17\n";
					cout << "Q16(" << c <<") => Q17\n";
					actual = Estado::q17;
				}else{
					
					salida << c << " rompe la cadena.\n";
					cout << c << " rompe la cadena.\n";
					ban = false;
				}
				
				break;
				
			case Estado::q17:
				
				salida << c << " rompe la cadena.\n";
				cout << c << " rompe la cadena.\n";
				ban = false;
				
				break;
				
			case Estado::q18:
				
				salida << c << " rompe la cadena.\n";
				cout << c << " rompe la cadena.\n";
				ban = false;
				
				break;
		}
		pos++;
	}
	
	if(ban == false || (actual == Estado::q0 || actual == Estado::q13)){
		
		actual = Estado::WA;
	}
	
	return actual;
}