// Master79

#include <ctype.h>
#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

enum class Estado {
	
	// Finales: q26, q22, q13, q9
	q0, q1, q2, q3, q4, q5, q6, q7, q8, q9, q10, 
	q11, q12, q13, q14, q15, q16, q17, q18, q19, 
	q20, q21, q22, WA
};

Estado analisis(const string& s);

int main(){
	
	cout << "Ingrese una fecha :)\n";
	
	string s;
	getline(cin, s);
	
	Estado x = analisis(s);
	
	if(x == Estado::q9 || x == Estado::q11 || x == Estado::q20 || x == Estado::q22){
		
		cout << "Cadena Aceptada =D\n";
	}else{
		
		cout << "WA :(\n";
	}
	
	cout << endl;
    system("pause");
    system("cls");
    
    main(); 
	
	return 0;
}

Estado analisis(const string& s){
	
	long long pos = 0; // INICIALIZAMOS POSICION DEL CARACTER DE LA CADENA
	Estado actual = Estado::q0; // INICIALIZAMOS EL ESTADO
	bool judge = false; // INICIALIZAMOS UNA BANDERA PARA SABER SI ES AC O WA
	char caracter;
	
	if(s.length() == 0){
		
		cout << "La cadena no sigue todas las ER\n";
		
		judge = true;
	}
	
	// CREAMOS UN BUCLE PARA ANALIZAR LA CADENA DE CARACTERES
	while(not judge && pos < s.length()){
		
		caracter = s[pos]; // TOMAMOS EL CARACTER DE MUESTRA
		
		// CREAMOS UN SWITCH PARA EVITARNOS MIL IF ELSE IF
		
		switch(actual){
			
			case Estado::q0:
				
				if(caracter == '0'){
					
					cout << "q0 (" << caracter << ") --> q1\n";
				
					actual = Estado::q1;
				}
			
				else if(caracter == '1' || caracter == '2'){
					
					cout << "q0 (" << caracter << ") --> q2\n";
				
					actual = Estado::q2;
				}
			
				else if(caracter == '3'){
					
					cout << "q0 (" << caracter << ") --> q3\n";
				
					actual = Estado::q3;
				}else{
					
					cout << caracter << " hace que rompa en q0 porque solo acepta dígitos entre 0 y 3.\n";
					
					judge = true;
				}
			
			break;
			
			case Estado::q1:
				
				if(caracter != '0' && isdigit(caracter)){
					
					cout << "q1 (" << caracter << ") --> q4\n";
				
					actual = Estado::q4;
				}else{
					
					cout << caracter << " hace que rompa en q1 porque solo acepta dígitos entre 1 y 9.\n";
				
					judge = true;
				}
				
			break;
				
			case Estado::q2:
				
				if(isdigit(caracter)){
					
					cout << "q2 (" << caracter << ") --> q4\n";
				
					actual = Estado::q4;
				}else{
					
					cout << caracter << " hace que rompa en q1 porque solo acepta dígitos.\n";
					
					judge = true;
				}
				
			break;
				
			case Estado::q3:
				
				if(caracter == '1'){
					
					cout << "q3 (" << caracter << ") --> q15\n";
					
					actual = Estado::q15;
				}
				
				else if(caracter == '0'){
					
					cout << "q3 (" << caracter << ") --> q12\n";
					
					actual = Estado::q12;
				}else{
					
					cout << caracter << " hace que rompa en q3 porque solo acepta dígitos entre el 0 y 1.\n";
					
					judge = true;
				}
				
			break;
				
			case Estado::q4:
				
				if(caracter == '/'){
					
					cout << "q4 (" << caracter << ") --> q5\n";
				
					actual = Estado::q5;
				}else{
					
					cout << caracter << " hace que rompa en q4 porque solo acepta el caracter /.\n";
				
					judge = true;
				}
				
			break;
				
			case Estado::q5:
				
				if(pos+2 <= s.length()){
				
				if( ((s[pos] == 'E' || s[pos] == 'e') && (s[pos+1] == 'N' || s[pos+1] == 'n') && (s[pos+2] == 'E' || s[pos+2] == 'e')) ||
					((s[pos] == 'F' || s[pos] == 'f') && (s[pos+1] == 'E' || s[pos+1] == 'e') && (s[pos+2] == 'B' || s[pos+2] == 'b')) ||
					((s[pos] == 'M' || s[pos] == 'm') && (s[pos+1] == 'A' || s[pos+1] == 'a') && (s[pos+2] == 'R' || s[pos+2] == 'r')) ||
					((s[pos] == 'A' || s[pos] == 'a') && (s[pos+1] == 'B' || s[pos+1] == 'b') && (s[pos+2] == 'R' || s[pos+2] == 'r')) ||
					((s[pos] == 'M' || s[pos] == 'm') && (s[pos+1] == 'A' || s[pos+1] == 'a') && (s[pos+2] == 'Y' || s[pos+2] == 'y')) ||
					((s[pos] == 'J' || s[pos] == 'j') && (s[pos+1] == 'U' || s[pos+1] == 'u') && (s[pos+2] == 'N' || s[pos+2] == 'n')) ||
					((s[pos] == 'J' || s[pos] == 'j') && (s[pos+1] == 'U' || s[pos+1] == 'u') && (s[pos+2] == 'L' || s[pos+2] == 'l')) ||
					((s[pos] == 'A' || s[pos] == 'a') && (s[pos+1] == 'G' || s[pos+1] == 'g') && (s[pos+2] == 'O' || s[pos+2] == 'o')) ||
					((s[pos] == 'S' || s[pos] == 's') && (s[pos+1] == 'E' || s[pos+1] == 'e') && (s[pos+2] == 'P' || s[pos+2] == 'p')) ||
					((s[pos] == 'O' || s[pos] == 'o') && (s[pos+1] == 'C' || s[pos+1] == 'c') && (s[pos+2] == 'T' || s[pos+2] == 't')) ||
					((s[pos] == 'N' || s[pos] == 'n') && (s[pos+1] == 'O' || s[pos+1] == 'o') && (s[pos+2] == 'V' || s[pos+2] == 'v')) ||
					((s[pos] == 'D' || s[pos] == 'd') && (s[pos+1] == 'I' || s[pos+1] == 'i') && (s[pos+2] == 'C' || s[pos+2] == 'c'))
				){
					
					cout << "q5 (" << caracter << ") --> q6\n";
						
					pos+=2;
					actual = Estado::q6;
					}else{
						
						
					cout << caracter << " hace que rompa en q5 porque no se reconoce el mes en cuestión.\n"; 
					
					judge = true;
				}
				
				}else{
					
					cout << caracter << " hace que rompa en q5 porque no se reconoce el mes en cuestión.\n"; 
					
					judge = true;
				}
				
			break;
				
			case Estado::q6:
				
				if(caracter == '/'){
					
					cout << "q6 (" << caracter << ") --> q7\n";
				
					actual = Estado::q7;
				}else{
				
					cout << caracter << " hace que rompa en q6 porque solo se acepta el caracter /.\n"; 
					
					judge = true;
				}
				
			break;
				
			case Estado::q7:
				
				if(isdigit(caracter)){
					
					cout << "q7 (" << caracter << ") --> q8\n";
				
					actual = Estado::q8;
				}else{
					
					cout << caracter << " hace que rompa en q7 porque solo se aceptan dígitos.\n"; 
					
					judge = true;
				}
				
			break;
				
			case Estado::q8:
				
				if(isdigit(caracter)){
					
					cout << "q8 (" << caracter << ") --> q9\n";
				
					actual = Estado::q9;
				}
			
				else{
					
					cout << caracter << " hace que rompa en q8 porque solo se reconocen dígitos.\n"; 
				
					judge = true;
				}
				
			break;
				
			case Estado::q9:
				
				// F
				
				if(isdigit(caracter)){
					
					cout << "q9 (" << caracter << ") --> q10\n";
				
					actual = Estado::q10;
				}else{
					
					cout << caracter << " hace que rompa en q9 porque solo se reconocen dígitos.\n"; 
				
					judge = true;
				}
				
			break;
				
			case Estado::q10:
				
				if(isdigit(caracter)){
					
					cout << "q10 (" << caracter << ") --> q11\n";
				
					actual = Estado::q11;
				}else{
					
					cout << caracter << " hace que rompa en q10 porque solo se reconocen dígitos.\n"; 
				
					judge = true;
				}
				
			break;
				
			case Estado::q11:
				
				cout << "Rompe en Nodo q11 porque la cadena sobrepasa la longitud de caracteres." << endl;
				
				judge = true;
				
			break;
				
			case Estado::q12:
				
				if(caracter == '/'){
					
					cout << "q12 (" << caracter << ") --> q13\n";
					
					actual = Estado::q13;
				}else{
					
					cout << caracter << " hace que rompa en q12 porque solo se acepta el caracter /.\n"; 
					
					judge = true;
				}
				
			break;
			
			case Estado::q13:
				
				if(pos+2 <= s.length()){
				
				if( ((s[pos] == 'E' || s[pos] == 'e') && (s[pos+1] == 'N' || s[pos+1] == 'n') && (s[pos+2] == 'E' || s[pos+2] == 'e')) ||
					((s[pos] == 'M' || s[pos] == 'm') && (s[pos+1] == 'A' || s[pos+1] == 'a') && (s[pos+2] == 'R' || s[pos+2] == 'r')) ||
					((s[pos] == 'A' || s[pos] == 'a') && (s[pos+1] == 'B' || s[pos+1] == 'b') && (s[pos+2] == 'R' || s[pos+2] == 'r')) ||
					((s[pos] == 'M' || s[pos] == 'm') && (s[pos+1] == 'A' || s[pos+1] == 'a') && (s[pos+2] == 'Y' || s[pos+2] == 'y')) ||
					((s[pos] == 'J' || s[pos] == 'j') && (s[pos+1] == 'U' || s[pos+1] == 'u') && (s[pos+2] == 'N' || s[pos+2] == 'n')) ||
					((s[pos] == 'J' || s[pos] == 'j') && (s[pos+1] == 'U' || s[pos+1] == 'u') && (s[pos+2] == 'L' || s[pos+2] == 'l')) ||
					((s[pos] == 'A' || s[pos] == 'a') && (s[pos+1] == 'G' || s[pos+1] == 'g') && (s[pos+2] == 'O' || s[pos+2] == 'o')) ||
					((s[pos] == 'S' || s[pos] == 's') && (s[pos+1] == 'E' || s[pos+1] == 'e') && (s[pos+2] == 'P' || s[pos+2] == 'p')) ||
					((s[pos] == 'O' || s[pos] == 'o') && (s[pos+1] == 'C' || s[pos+1] == 'c') && (s[pos+2] == 'T' || s[pos+2] == 't')) ||
					((s[pos] == 'N' || s[pos] == 'n') && (s[pos+1] == 'O' || s[pos+1] == 'o') && (s[pos+2] == 'V' || s[pos+2] == 'v')) ||
					((s[pos] == 'D' || s[pos] == 'd') && (s[pos+1] == 'I' || s[pos+1] == 'i') && (s[pos+2] == 'C' || s[pos+2] == 'c'))
				){
					
					cout << "q13 (" << caracter << ") --> q14\n";
						
					pos+=2;
					actual = Estado::q14;
					}else{
						
					cout << caracter << " hace que rompa en q13 porque no se reconoce el mes en cuestión.\n"; 
					
					judge = true;
				}
				
				}else{
					
					cout << caracter << " hace que rompa en q13 porque no se reconoce el mes en cuestión.\n"; 
						
					judge = true;
				}
				
				break;
				
			case Estado::q14:
				
				if(caracter == '/'){
					
					cout << "q14 (" << caracter << ") --> q18\n";
					
					actual = Estado::q18;
				}else{
					
					cout << caracter << " hace que rompa en q14 porque solo se acepta el caracter /.\n"; 
					
					judge = true;
				}
				
			break;
				
			case Estado::q15:
				
				if(caracter == '/'){
					
					cout << "q15 (" << caracter << ") --> q16\n";
					
					actual = Estado::q16;
				}else{
					
					cout << caracter << " hace que rompa en q15 porque solo se acepta el caracter /.\n"; 
					
					judge = true;
				}
				
			break;
				
			case Estado::q16:
				
				if(pos+2 <= s.length()){
				
				if( ((s[pos] == 'E' || s[pos] == 'e') && (s[pos+1] == 'N' || s[pos+1] == 'n') && (s[pos+2] == 'E' || s[pos+2] == 'e')) ||
					((s[pos] == 'M' || s[pos] == 'm') && (s[pos+1] == 'A' || s[pos+1] == 'a') && (s[pos+2] == 'R' || s[pos+2] == 'r')) ||
					((s[pos] == 'M' || s[pos] == 'm') && (s[pos+1] == 'A' || s[pos+1] == 'a') && (s[pos+2] == 'Y' || s[pos+2] == 'y')) ||
					((s[pos] == 'J' || s[pos] == 'j') && (s[pos+1] == 'U' || s[pos+1] == 'u') && (s[pos+2] == 'L' || s[pos+2] == 'l')) ||
					((s[pos] == 'A' || s[pos] == 'a') && (s[pos+1] == 'G' || s[pos+1] == 'g') && (s[pos+2] == 'O' || s[pos+2] == 'o')) ||
					((s[pos] == 'O' || s[pos] == 'o') && (s[pos+1] == 'C' || s[pos+1] == 'c') && (s[pos+2] == 'T' || s[pos+2] == 't')) ||
					((s[pos] == 'D' || s[pos] == 'd') && (s[pos+1] == 'I' || s[pos+1] == 'i') && (s[pos+2] == 'C' || s[pos+2] == 'c'))
				){
					
					cout << "q16 (" << caracter << ") --> q17\n";	
					
					pos+=2;
					actual = Estado::q17;
					}else{
						
						cout << caracter << " hace que rompa en q16 porque no se reconoce el mes en cuestión.\n"; 
					
						judge = true;
					}			
				}else{
					
					cout << caracter << " hace que rompa en q16 porque no se reconoce el mes en cuestión.\n"; 
						
					judge = true;
				}
				
			break;
				
			case Estado::q17:
				
				if(caracter == '/'){
					
					cout << "q17 (" << caracter << ") --> q18\n";
					
					actual = Estado::q18;
				}else{
					
					cout << caracter << " hace que rompa en q17 porque solo se acepta el caracter /.\n"; 
					
					judge = true;
				}
				
			break;
				
			case Estado::q18:
				
				if(isdigit(caracter)){
					
					cout << "q18 (" << caracter << ") --> q19\n";
				
					actual = Estado::q19;
				}else{
					
					cout << caracter << " hace que rompa en q18 porque solo acepta dígitos.\n";
					
					judge = true;
				}
				
			break;
				
			case Estado::q19:
				
				if(isdigit(caracter)){
					
					cout << "q19 (" << caracter << ") --> q20\n";
				
					actual = Estado::q20;
				}else{
					
					cout << caracter << " hace que rompa en q19 porque solo acepta dígitos.\n";
					
					judge = true;
				}
				
			break;
				
			case Estado::q20:
				
				if(isdigit(caracter)){
					
					cout << "q20 (" << caracter << ") --> q21\n";
				
					actual = Estado::q21;
				}else{
					
					cout << caracter << " hace que rompa en q20 porque solo acepta dígitos.\n";
					
					judge = true;
				}
				
			break;
				
			case Estado::q21:
				
				if(isdigit(caracter)){
					
					cout << "q21 (" << caracter << ") --> q22\n";
				
					actual = Estado::q22;
				}else{
					
					cout << caracter << " hace que rompa en q21 porque solo acepta dígitos.\n";
					
					judge = true;
				}
				
			break;
				
			case Estado::q22:
				
				cout << "Rompe en Nodo q22 porque la cadena sobrepasa la longitud de caracteres." << endl;
				
				judge = true;
			
			break;
		}
			
		pos++;
	}
	
	if(judge == true){
		
			actual = Estado::WA;
	}
	
	return actual;
}
	