// Master79

#include <iostream>
#include <ctype.h>
#include <cstdlib>

using namespace std;

enum class Estado{
	
	WA, q0, q1, q2, q3, q4, q5, q6, q7, q8, q9, q10, q11, q12, q13
};

Estado analisis(const string& s);

int main(){
	
	cout << "Ingrese una hora :)\n";
	
	string s;
	getline(cin, s);
	
	Estado x = analisis(s);
	
	if(x == Estado::q13){
		
		cout << "Cadena Aceptada =D\n";
	}else{
		
		cout << "WA :(. La cadena no cumple con las ER preestablecidas\n";
		cout << "Por favor, intente aprender a escribir una hora correctamente...\n";
	}
	
	cout << endl;
    system("pause");
    system("cls");
    
    main(); 
	
	return 0;
}

Estado analisis(const string& s){
	
	int pos = 0;
	Estado actual = Estado::q0;
	bool judge = true;
	char c;
	
	if(s.length() == 0){
		
		judge == false;
	}
	
	while(pos < s.length() && judge){
		
		c = s[pos];
		
		switch(actual){
			
			case Estado::q0:
				
				if(c == '0' || c == '1'){
					
					cout << "q0 (" << c << ") --> q1\n";
					
					actual = Estado::q1;
				}else if(c == '2'){
					
					cout << "q0 (" << c << ") --> q2\n";
					
					actual = Estado::q2;
				}else{
					
					cout << c << " hace que rompa en q0 porque solo acepta 0, 1 o 2.\n";
					
					judge = false;
				}
				
				break;
				
			case Estado::q1:
				
				if(isdigit(c)){
					
					cout << "q1 (" << c << ") --> q3\n";
					
					actual = Estado::q3;
				}else{
					
					cout << c << " hace que rompa en q1 porque solo acepta dígitos.\n";
					
					judge = false;
				}
				
				break;
				
			case Estado::q2:
				
				if(c == '0' || c == '1' || c == '2' || c == '3'){
					
					cout << "q2 (" << c << ") --> q4\n";
					
					actual = Estado::q4;
				}else{
					
					cout << c << " hace que rompa en q2 porque solo acepta valores entre 0 y 3.\n";
					
					judge = false;
				}
				
				break;
				
			case Estado::q3:
				
				if(c == ':'){
					
					cout << "q3 (" << c << ") --> q5\n";
					
					actual = Estado::q5;
				}else{
					
					cout << c << " hace que rompa en q3 porque solo acepta el caracter :.\n";
					
					judge = false;
				}
				
				break;
				
			case Estado::q4:
				
				if(c == ':'){
					
					cout << "q4 (" << c << ") --> q5\n";
					
					actual = Estado::q5;
				}else{
					
					cout << c << " hace que rompa en q4 porque solo acepta el caracter :.\n";
					
					judge = false;
				}
				
				break;
				
			case Estado::q5:
				
				if(c == '0' || c == '1' || c == '2' || c == '3' || c == '4' || c == '5'){
					
					cout << "q5 (" << c << ") --> q6\n";
					
					actual = Estado::q6;
				}else{
					
					cout << c << " hace que rompa en q5 porque solo acepta digitos entre el 0 y 5.\n";
					
					judge = false;
				}
				
				break;
				
			case Estado::q6:
				
				if(isdigit(c)){
					
					cout << "q6 (" << c << ") --> q7\n";
					
					actual = Estado::q7;
				}else{
					
					cout << c << " hace que rompa en q6 porque solo acepta digitos.\n";
					
					judge = false;
				}
				
				break;
				
			case Estado::q7:
				
				if(c == ':'){
					
					cout << "q7 (" << c << ") --> q8\n";
					
					actual = Estado::q8;
				}else{
					
					cout << c << " hace que rompa en q7 porque solo acepta el caracter :.\n";
					
					judge = false;
				}
				
				break;
				
			case Estado::q8:
				
				if(c == '0' || c == '1' || c == '2' || c == '3' || c == '4' || c == '5'){
					
					cout << "q8 (" << c << ") --> q9\n";
					
					actual = Estado::q9;
				}else{
					
					cout << c << " hace que rompa en q8 porque solo acepta digitos entre el 0 y 5.\n";
					
					judge = false;
				}
				
				break;
				
			case Estado::q9:
				
				if(isdigit(c)){
					
					cout << "q9 (" << c << ") --> q10\n";
					
					actual = Estado::q10;
				}else{
					
					cout << c << " hace que rompa en q10 porque solo acepta digitos.\n";
					
					judge = false;
				}
				
				break;
				
			case Estado::q10:
				
				if(c == ':'){
					
					cout << "q10 (" << c << ") --> q11\n";
					
					actual = Estado::q11;
				}else{
					
					cout << c << " hace que rompa en q10 porque solo acepta el caracter :.\n";
					
					judge = false;
				}
				
				break;
				
			case Estado::q11:
				
				if(isdigit(c)){
					
					cout << "q11 (" << c << ") --> q12\n";
					
					actual = Estado::q12;
				}else{
					
					cout << c << " hace que rompa en q11 porque solo acepta digitos.\n";
					
					judge = false;
				}
				
				break;
				
			case Estado::q12:
				
				if(isdigit(c)){
					
					cout << "q12 (" << c << ") --> q13\n";
					
					actual = Estado::q13;
				}else{
					
					cout << c << " hace que rompa en q12 porque solo acepta digitos.\n";
					
					judge = false;
				}
				
				break;
				
			case Estado::q13:
				
				judge = false;
				
				break;
		}
		
		pos++;
	}
	
	if(judge == true && actual != Estado::q13){
		
		cout << "La cadena no cumple debido a que le faltan ER por concluir...\n";
	}
	
	if(!judge){
		
		actual = Estado::WA;
	}
	
	return actual;
}