// Master79

#include <iostream>
#include <ctype.h>
#include <cstdlib>

using namespace std;

enum class Estado {INICIO, Q1, Q2, Q3, Q4, Q5, FIN, WA};

Estado analisis(const string& inputString);

int main(){
	
	cout << "Ingrese una cadena para la siguiente expresión regular...\n";
	cout << "[a-zA-Z]*[0-3]{2-4}(ITSUR)?[a-f][a-f]*\n";
	
	string inputString;
	getline(cin, inputString);
	
	Estado x = analisis(inputString);
	
	if(x == Estado::FIN){
		
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

Estado analisis(const string& inputString){
	
	long long pos = 0; // INICIALIZAMOS POSICION DEL CARACTER DE LA CADENA
	Estado actual = Estado::INICIO; // INICIALIZAMOS EL ESTADO
	bool judge = false; // INICIALIZAMOS UNA BANDERA PARA SABER SI ES AC O WA
	
	// CREAMOS UN BUCLE PARA ANALIZAR LA CADENA DE CARACTERES
	while(not judge && pos < inputString.length()){
		
		char caracter = inputString[pos]; // TOMAMOS EL CARACTER DE MUESTRA
		
		// CREAMOS UN SWITCH PARA EVITARNOS MIL IF ELSE IF
		switch(actual){
			
			case Estado::INICIO:
				
				if(isalpha(caracter)){
					
					actual = Estado::INICIO;
				}else if(caracter == '0' || caracter == '1' || caracter == '2' || caracter == '3'){
					
					actual = Estado::Q1;
				}else{
					
					judge = true;
				}
				break;
				
			case Estado::Q1:
				
				if(caracter == '0' || caracter == '1' || caracter == '2' || caracter == '3'){
					
					actual = Estado::Q2;
				}else{
					
					judge = true;
				}
				
				break;
				
			case Estado::Q2:
				
				if(pos+4 <= inputString.length() && (inputString[pos] == 'I' || inputString[pos+1] == 'T' || inputString[pos+2] == 'S' || inputString[pos+3] == 'U' || inputString[pos+4] == 'R')){
					
					pos+=4;
					actual = Estado::Q5;
				}
				
				else if(caracter == '0' || caracter == '1' || caracter == '2' || caracter == '3'){
					
					actual = Estado::Q3;
				}
				
				else if(caracter == 'a' || caracter == 'b' || caracter == 'c' || caracter == 'e' || caracter == 'd' || caracter == 'f'){
					
					actual = Estado::FIN;
				}else{
					
					judge = true;
				}
				
				break;
				
			case Estado::Q3:
				
				if(pos+4 <= inputString.length() && (inputString[pos] == 'I' || inputString[pos+1] == 'T' || inputString[pos+2] == 'S' || inputString[pos+3] == 'U' || inputString[pos+4] == 'R')){
					
					pos+=4;
					actual = Estado::Q5;
				}
				
				else if(caracter == '0' || caracter == '1' || caracter == '2' || caracter == '3'){
					
					actual = Estado::Q4;
				}
				
				else if(caracter == 'a' || caracter == 'b' || caracter == 'c' || caracter == 'e' || caracter == 'd' || caracter == 'f'){
					
					actual = Estado::FIN;
				}else{
					
					judge = true;
				}
				
				break;
				
			case Estado::Q4:
				
				if(pos+4 <= inputString.length() && (inputString[pos] == 'I' || inputString[pos+1] == 'T' || inputString[pos+2] == 'S' || inputString[pos+3] == 'U' || inputString[pos+4] == 'R')){
					
					pos+=4;
					actual = Estado::Q5;
				}
				
				else if(caracter == 'a' || caracter == 'b' || caracter == 'c' || caracter == 'e' || caracter == 'd' || caracter == 'f'){
					
					actual = Estado::FIN;
				}else{
					
					judge = true;
				}
				
				break;
				
			case Estado::Q5:
				
				if(caracter == 'a' || caracter == 'b' || caracter == 'c' || caracter == 'd' || caracter == 'e' || caracter == 'f'){
					
					actual = Estado::FIN;
				}else{
					
					judge = true;
				}
				
				break;
				
			case Estado::FIN:
				
				if(caracter == 'a' || caracter == 'b' || caracter == 'c' || caracter == 'd' || caracter == 'e' || caracter == 'f'){
					
					actual = Estado::FIN;
				}else{
					
					judge = true;
				}
				
				break;
		}
		pos++;
	}
	
	if(judge){
		
		actual = Estado::WA;
	}
	
	return actual;
}

