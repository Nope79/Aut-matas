// Master79

// CURP
//LVLLaammddGesCCC**

#include <iostream>
#include <ctype.h>
#include <cstdlib>

using namespace std;

enum class Estado{
	
	WA, q0, q1, q2, q3, q4, q5, q6, q7, q8, q9, q10, q11, q12, q13,q14, 
	q15, q16, q17, q18, q19, q20, q21, q22, q23, q24, q25
};

Estado analisis(const string& s);

int main(){
	
	cout << "Ingrese su CURP:)\n";
	
	string s;
	getline(cin, s);
	
	Estado x = analisis(s);
	
	if(x == Estado::q25){
		
		cout << "AC" << endl;
	}else{
		
		cout << "WA" << endl;
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
	bool v = true;
	char c;
	
	if(s.length() > 18){
		
		cout << "Bro, la CURP tiene exactamente 18 caracteres. Vuelve a intentarlo cuando no andes de payaso ingresando cadenas con 30 caracteres extra. Gracias.\n";
		
		v = false;
	}
	
	else if(s.length() < 18){
		
		cout << "Oye... Si vas a ponerme a trabajar, que sea para un trabajo que no quede inconcluso. La CURP no puede tener menos de 18 caracteres. Gracias.\n";
		
		v = false;
	}
	
	while(pos < s.length() && v){
		
		c = s[pos];
		
		switch(actual){
			
			case Estado::q0:
				
				if(c >= 65 && c <= 90){
					
					cout << "q0 (" << c << ") --> q1\n";
					
					actual = Estado::q1;
				}else{
					
					cout << "q0 (" << c << ") --> X\n";
					
					cout << c << " hace que rompa en q0 porque solo acepta letras mayúsculas.\n";
					
					v = false;
				}
				
				break;
				
			case Estado::q1:
				
				if(c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U'){
					
					cout << "q1 (" << c << ") --> q2\n";
					
					actual = Estado::q2;
					
				}else{
					
					cout << "q1 (" << c << ") --> X\n";
					
					cout << c << " hace que rompa en q1 porque solo acepta VOCALES mayúsculas.\n";
					
					v = false;
				}
				
				break;
				
			case Estado::q2:
				
				if(c >= 65 && c <= 90){
					
					cout << "q2 (" << c << ") --> q3\n";
					
					actual = Estado::q3;
				}else{
					
					cout << "q2 (" << c << ") --> X\n";
					
					cout << c << " hace que rompa en q2 porque solo acepta letras mayúsculas.\n";
					
					v = false;
				}
				
				break;
				
			case Estado::q3:
				
				if(c >= 65 && c <= 90){
					
					cout << "q3 (" << c << ") --> q4\n";
					
					actual = Estado::q4;
				}else{
					
					cout << "q3 (" << c << ") --> X\n";
					
					cout << c << " hace que rompa en q3 porque solo acepta letras mayúsculas.\n";
					
					v = false;
				}
				
				break;
				
			case Estado::q4:
				
				if(isdigit(c)){
					
					cout << "q4 (" << c << ") --> q5\n";
					
					actual = Estado::q5;
				}else{
					
					cout << "q4 (" << c << ") --> X\n";
					
					cout << c << " hace que rompa en q4 porque solo acepta dígitos.\n";
					
					v = false;
				}
				
				break;
				
			case Estado::q5:
				
				if(isdigit(c)){
					
					cout << "q5 (" << c << ") --> q6\n";
					
					actual = Estado::q6;
				}else{
					
					cout << "q5 (" << c << ") --> X\n";
					
					cout << c << " hace que rompa en q5 porque solo acepta dígitos.\n";
					
					v = false;
				}
				
				break;
				
			case Estado::q6:
				
				if(c ==  '0'){
					
					cout << "q6 (" << c << ") --> q7\n";
					
					actual = Estado::q7;
				}
				
				else if(c == '1'){
					
					cout << "q6 (" << c << ") --> q11\n";
					
					actual = Estado::q11;
					
				}
				
				else{
					
					cout << "q6 (" << c << ") --> X\n";
					
					cout << c << " hace que rompa en q6 porque solo acepta dígitos entre el 0 y 1.\n";
					
					v = false;
				}
				
				break;
				
			case Estado::q7:
				
				if(c == '1' || c == '3' || c == '5' || c == '7' || c == '8'){
					
					cout << "q7 (" << c << ") --> q8\n";
					
					actual = Estado::q8;
				}
				
				else if(c == '4' || c == '6' || c == '9'){
					
					cout << "q7 (" << c << ") --> q9\n";
					
					actual = Estado::q9;
				}
				
				else if(c == '2'){
					
					cout << "q7 (" << c << ") --> q9\n";
					
					actual = Estado::q10;
				}else{
					
					cout << "q7 (" << c << ") --> X\n";
					
					cout << c << " hace que rompa en q7 porque solo acepta dígitos entre el 0 y 9.\n";
					
					v = false;
				}
				break;
				
			case Estado::q8:
				
				if(c == '0'){
					
					cout << "q8 (" << c << ") --> q14\n";
					
					actual = Estado::q14;
				}
				
				else if(c == '1' || c == '2'){
					
					cout << "q8 (" << c << ") --> q15\n";
					
					actual = Estado::q15;
				}
				
				else if(c == '3'){
					
					cout << "q8 (" << c << ") --> q16\n";
					
					actual = Estado::q16;
					
				}else{
					
					cout << "q8 (" << c << ") --> X\n";
					
					cout << c << " hace que rompa en q8 porque solo acepta dígitos entre el 0 y 3.\n";
					
					v = false;
				}
				
				break;
				
			case Estado::q9:
				
				if(c == '0'){
					
					cout << "q9 (" << c << ") --> q14\n";
					
					actual = Estado::q14;
				}
				
				else if(c == '1' || c == '2'){
					
					cout << "q9 (" << c << ") --> q15\n";
					
					actual = Estado::q15;
				}
				
				else if(c == '3'){
					
					cout << "q9 (" << c << ") --> q17\n";
					
					actual = Estado::q17;
					
				}else{
					
					cout << "q9 (" << c << ") --> X\n";
					
					cout << c << " hace que rompa en q9 porque solo acepta dígitos entre el 0 y 3.\n";
					
					v = false;
				}
				
				break;
				
			case Estado::q10:
				
				if(c == '0'){
					
					cout << "q10 (" << c << ") --> q14\n";
					
					actual = Estado::q14;
				}
				
				else if(c == '1' || c == '2'){
					
					cout << "q10 (" << c << ") --> q15\n";
					
					actual = Estado::q15;
				}else{
					
					cout << "q10 (" << c << ") --> X\n";
					
					cout << c << " hace que rompa en q10 porque solo acepta dígitos entre el 0 y 3.\n";
					
					v = false;
				}
				
				break;
				
			case Estado::q11:
				
				if(c == '0' || c == '2'){
					
					cout << "q11 (" << c << ") --> q12\n";
					
					actual = Estado::q12;
				}
				
				else if(c == '1'){
					
					cout << "q11 (" << c << ") --> q13\n";
					
					actual = Estado::q13;
					
				}else{
					
					cout << "q11 (" << c << ") --> X\n";
					
					cout << c << " hace que rompa en q11 porque solo acepta dígitos entre el 0 y 2.\n";
					
					v = false;
				}
				break;
				
			case Estado::q12:
				
				if(c == '0'){
					
					cout << "q12 (" << c << ") --> q14\n";
					
					actual = Estado::q14;
				}
				
				else if(c == '1' || c == '2'){
					
					cout << "q12 (" << c << ") --> q15\n";
					
					actual = Estado::q15;
				}
				
				else if(c == '3'){
					
					cout << "q12 (" << c << ") --> q16\n";
					
					actual = Estado::q16;
					
				}else{
					
					cout << "q12 (" << c << ") --> X\n";
					
					cout << c << " hace que rompa en q12 porque solo acepta dígitos entre el 0 y 3.\n";
					
					v = false;
				}
				
				break;
				
			case Estado::q13:
				
				if(c == '0'){
					
					cout << "q13 (" << c << ") --> q14\n";
					
					actual = Estado::q14;
				}
				
				else if(c == '1' || c == '2'){
					
					cout << "q13 (" << c << ") --> q15\n";
					
					actual = Estado::q15;
				}
				
				else if(c == '3'){
					
					cout << "q9 (" << c << ") --> q17\n";
					
					actual = Estado::q17;
					
				}else{
					
					cout << "q9 (" << c << ") --> X\n";
					
					cout << c << " hace que rompa en q13 porque solo acepta dígitos entre el 0 y 3.\n";
					
					v = false;
				}
				
				break;
				
			case Estado::q14:
				
				if(c != '0' && isdigit(c)){
					
					cout << "q14 (" << c << ") --> q18\n";
					
					actual = Estado::q18;
				}else{
					
					cout << "q14 (" << c << ") --> X\n";
					
					cout << c << " hace que rompa en q14 porque solo acepta dígitos entre el 1 y 9.\n";
					
					v = false;
				}
				
				break;
				
			case Estado::q15:
				
				if(isdigit(c)){
					
					cout << "q15 (" << c << ") --> q18\n";
					
					actual = Estado::q18;
				}else{
					
					cout << "q15 (" << c << ") --> X\n";
					
					cout << c << " hace que rompa en q15 porque solo acepta dígitos.\n";
					
					v = false;
				}
				
				break;
			
			case Estado::q16:
				
				if(c == '0' || c == '1'){
					
					cout << "q16 (" << c << ") --> q18\n";
					
					actual = Estado::q18;
				}else{
					
					cout << "q16 (" << c << ") --> X\n";
					
					cout << c << " hace que rompa en q16 porque solo acepta dígitos entre 0 y 1.\n";
					
					v = false;
				}
				
				break;
				
			case Estado::q17:
				
				if(c == '0'){
					
					cout << "q17 (" << c << ") --> q18\n";
					
					actual = Estado::q18;
				}else{
					
					cout << "q17 (" << c << ") --> X\n";
					
					cout << c << " hace que rompa en q16 porque solo acepta el dígito 0.\n";
					
					v = false;
				}
				
				break;
				
			case Estado::q18:
				
				if(c == 'H' || c == 'M'){
					
					cout << "q18 (" << c << ") --> q19\n";
					
					actual = Estado::q19;
				}else{
					
					cout << "q18 (" << c << ") --> X\n";
					
					cout << c << " hace que rompa en q16 porque solo acepta los caracteres 'H' y 'M'.\n";
					
					v = false;
				}
				
				break;
				
			case Estado::q19:
				
				if(
				(s[11] == 'A' && s[12] == 'S') || (s[11] == 'B' && s[12] == 'C') ||
				(s[11] == 'B' && s[12] == 'S') || (s[11] == 'C' && s[12] == 'C') ||
				(s[11] == 'C' && s[12] == 'L') || (s[11] == 'C' && s[12] == 'M') ||
				(s[11] == 'C' && s[12] == 'S') || (s[11] == 'C' && s[12] == 'H') ||
				(s[11] == 'D' && s[12] == 'F') || (s[11] == 'D' && s[12] == 'G') ||
				(s[11] == 'G' && s[12] == 'T') || (s[11] == 'G' && s[12] == 'R') ||
				(s[11] == 'H' && s[12] == 'G') || (s[11] == 'J' && s[12] == 'C') ||
				(s[11] == 'M' && s[12] == 'C') || (s[11] == 'M' && s[12] == 'N') ||
				(s[11] == 'M' && s[12] == 'S') || (s[11] == 'N' && s[12] == 'T') ||
				(s[11] == 'N' && s[12] == 'L') || (s[11] == 'O' && s[12] == 'C') ||
				(s[11] == 'P' && s[12] == 'L') || (s[11] == 'Q' && s[12] == 'T') ||
				(s[11] == 'Q' && s[12] == 'R') || (s[11] == 'S' && s[12] == 'P') ||
				(s[11] == 'S' && s[12] == 'L') || (s[11] == 'S' && s[12] == 'R') ||
				(s[11] == 'T' && s[12] == 'C') || (s[11] == 'T' && s[12] == 'S') ||
				(s[11] == 'T' && s[12] == 'L') || (s[11] == 'V' && s[12] == 'Z') ||
				(s[11] == 'Y' && s[12] == 'N') || (s[11] == 'Z' && s[12] == 'S')
				){
					
					pos++;
					cout << "q19 (" << c << ") --> q20\n";
					
					actual = Estado::q20;
				}else{
					
					cout << "q19 (" << c << ") --> X\n";
					
					cout << c << " hace que rompa en q19 porque solo acepta CONSONANTES mayúsculas.\n";
					
					v = false;
				}
				
				break;
				
			case Estado::q20:
				
				if((c >= 65 && c <= 90) && (c != 'A' && c != 'E' && c != 'I' && c != 'O' && c != 'U')){
					
					cout << "q20 (" << c << ") --> q21\n";
					
					actual = Estado::q21;
				}else{
					
					cout << "q20 (" << c << ") --> X\n";
					
					cout << c << " hace que rompa en q20 porque solo acepta CONSONANTES mayúsculas.\n";
					
					v = false;
				}
				
				break;
				
			case Estado::q21:
				
				if((c >= 65 && c <= 90) && (c != 'A' && c != 'E' && c != 'I' && c != 'O' && c != 'U')){
					
					cout << "q21 (" << c << ") --> q22\n";
					
					actual = Estado::q22;
				}else{
					
					cout << "q21 (" << c << ") --> X\n";
					
					cout << c << " hace que rompa en q21 porque solo acepta CONSONANTES mayúsculas.\n";
					
					v = false;
				}
				
				break;
				
			case Estado::q22:
				
				if((c >= 65 && c <= 90) && (c != 'A' && c != 'E' && c != 'I' && c != 'O' && c != 'U')){
					
					cout << "q22 (" << c << ") --> q23\n";
					
					actual = Estado::q23;
				}else{
					
					cout << "q22 (" << c << ") --> X\n";
					
					cout << c << " hace que rompa en q22 porque solo acepta CONSONANTES mayúsculas.\n";
					
					v = false;
				}
				
				break;
				
			case Estado::q23:
				
				if(isdigit(c) || (c >= 65 && c <= 90)){
					
					cout << "q23 (" << c << ") --> q24\n";
					
					actual = Estado::q24;
					
				}else{
					
					cout << "q23 (" << c << ") --> X\n";
					
					cout << c << " hace que rompa en q23 porque solo acepta mayúsculas o dígitos.\n";
					
					v = false;
				}
				
				break;
				
			case Estado::q24:
				
				if(isdigit(c) || (c >= 65 && c <= 90)){
					
					cout << "q24 (" << c << ") --> q25\n";
					
					actual = Estado::q25;
					
				}else{
					
					cout << "q24 (" << c << ") --> X\n";
					
					cout << c << " hace que rompa en q24 porque solo acepta mayúsculas o dígitos.\n";
					
					v = false;
				}
				
				break;
		}
		
		pos++;	
	}
	
	if(!v){
		
		actual = Estado::WA;
	}
	
	return actual;
}