#include <iostream>
#include <ctype.h>
#include <cstdlib>

using namespace std;

enum class Estado {Inicio, Q1, Q3, Q4, Fin, WA};

Estado analisis(const string& s);

int main(){
	
	cout << "Ingrese una cadena :)\n";
	
	string s;
	getline(cin, s);
	
	Estado estado = analisis(s);
	
	if(estado == Estado::Fin){
		
		cout << "Es una cadena válida =D\n";
	}else{
		
		cout << "No es una cadena válida :(\n";
	}
	
	return 0;
}

Estado analisis(const string& s){
	
	int pos = 0;
	Estado actual = Estado::Inicio;
	bool v = false;
	
	while(not v && pos < s.length()){
		
		char x = s[pos];
		
		switch(actual){
			
			case Estado::Inicio:
				
				if(x == 'a'){
					
					actual = Estado::Q1;
				}
				
				else if(x == 'b'){
					
					actual = Estado::Q3;
				}else{
					
					v = true;
				}
				
				break;
				
			case Estado::Q1:
				
				if(x == 'b'){
					
					actual = Estado::Fin;
				}else{
					
					v = true;
				}
				
				break;
				
			case Estado::Q3:
				
				if(x == 'a'){
					
					actual = Estado::Q4;
				}else{
					
					v = true;
				}
				
				break;
			
			case Estado::Q4:
				
				if(x == 'a'){
					
					actual = Estado::Q1;
				}
				
				else if(x == 'b'){
					
					actual = Estado::Fin;
				}else{
					
					v = true;
				}
				
				break;
				
			case Estado::Fin:
				
				if(x == 'a'){
					
					actual = Estado::Fin;
				}else{
					
					v = true;
				}
					
				break;
		}
		
		pos++;
	}
	
	if(v){
		
		actual = Estado::WA;
	}
	
	return actual;
}