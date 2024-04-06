#include <iostream>
#include <cctype>>

using namespace std;

enum class Estado {Inicio, Q1, Q2, Q3, Q4, Q5, Q6, Q7, Q8, Q9, FIN, WA};

Estado analisis(const string& s);

int main(){
	
	for(int i = 0; i < 50; i++){
		
		cout << "INGRESE UNA HORA :D\n";
		
		string cadena;
		getline(cin, cadena);
		
		Estado x = analisis(cadena);
		
		if(x == Estado::FIN){
			
			cout << "CADENA VÁLIDA =)\n";
		}else{
			
			cout << "CADENA INVÁLIDA :(\n";
		}
		
		cout << endl << endl;
	}
	
	
	return 0;
}

Estado analisis(const string& s){
	
	int pos = 0;
	bool bandera = true;
	Estado actual = Estado::Inicio;
	
	while(bandera && pos < s.length()){
		
		char c = s[pos];
		
		// Inicio, Q1, Q2, Q3, Q4, Q5, Q6, Q7, Q8, Q9, FIN, WA
		switch(actual){
			
			case Estado::Inicio:
				
				if(c >= '0' && c <= '1'){
					
					actual = Estado::Q1;
				}
				
				else if(c == '2'){
					
					actual = Estado::Q3;
				}else{
					
					bandera = false;
				}
				
				break;
				
			case Estado::Q1:
				
				if(isdigit(c)){
					
					actual = Estado::Q2;
				}else{
					
					bandera = false;
				}
				
				break;
				
			case Estado::Q2:
				
				if(c == ':'){
					
					actual = Estado::Q5;
				}else{
					
					bandera = false;
				}
				
				break;
				
			case Estado::Q3:
				
				if(c <= '3' && c >= '0'){
					
					actual = Estado::Q4;
				}else{
					
					bandera = false;
				}
				
				break;
				
			case Estado::Q4:
				
				if(c == ':'){
					
					actual = Estado::Q5;
				}else{
					
					bandera = false;
				}
				
				break;
				
			case Estado::Q5:
				
				if(c <= '5' && c >= '0'){
					
					actual = Estado::Q6;
				}else{
					
					bandera = false;
				}
				
				break;
				
			case Estado::Q6:
				
				if(isdigit(c)){
					
					actual = Estado::Q7;
				}else{
					
					bandera = false;
				}
				
				break;
				
			case Estado::Q7:
				
				if(c == ':'){
					
					actual = Estado::Q8;
				}else{
					
					bandera = false;
				}
				
				break;
				
			case Estado::Q8:
				
				if(c <= '5' && c >= '0'){
					
					actual = Estado::Q9;
				}else{
					
					bandera = false;
				}
				
				break;
				
			case Estado::Q9:
				
				if(isdigit(c)){
					
					actual = Estado::FIN;
				}else{
					
					bandera = false;
				}
				
				break;
				
			case Estado::FIN:
				
				bandera = false;
				
				break;
		}
		
		pos++;
	}
	
	if(bandera == false || actual != Estado::FIN){
		
		actual = Estado::WA;
	}
	
	return actual;
}