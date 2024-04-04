#include <iostream>
#include <string>

using namespace std;

enum class Estado {Inicio, Q1, Q2, Fin1, Fin2, WA};

Estado analisis(const string& s);

int main(){
	
	cout << "Ingrese una cadena :)\n";
	
	string s;
	getline(cin, s);
	
	Estado estado = analisis(s);
	
	if(estado == Estado::Fin1 || estado == Estado::Fin2){
		
		cout << "Cadena válida :D\n";
	}else{
		
		cout << "Cadena inválida :(\n";
	}
	
	return 0;
}

Estado analisis(const string& s){
	
	int pos = 0;
	bool ban = true;
	Estado actual = Estado::Inicio;
	
	while(ban && pos < s.length()){
		
		char c = s[pos];
		
		switch(actual){
			
			case Estado::Inicio:
				
				if(c == 'a'){
					
					actual = Estado::Q1;
				}else{
					
					ban = false;
				}
				
				break;
				
			case Estado::Q1:
				
				if(pos + 4 <= s.length()){
					
					string substring = s.substr(pos, 4);
					
					if(substring == "HOLA"){
						
						actual = Estado::Q2;
						pos += 3;
					}
					
					else if(c == 'b'){
						
						actual = Estado::Fin1;
					}else{
						
						ban = false;
					}
				}
				
				else if(c == 'b'){
				
					actual = Estado::Fin1;
				}else{
						
					ban = false;
				}
				
				break;
				
			case Estado::Q2:
				
				if(pos + 5 <= s.length()){
					
					string substring = s.substr(pos, 5);
					
					if(substring == "MUNDO"){
						
						actual = Estado::Fin2;
						pos += 4;
					}else{
						
						ban = false;
					}
				}else{
					
					ban = false;
				}
				
				break;
				
			case Estado::Fin1:
				
				if(c == 'c'){
					
					actual = Estado::Fin2;
				}else{
					
					ban = false;
				}
				
				break;
				
			case Estado::Fin2:
				
				ban = false;
				
				break;
		}
		
		pos++;
	}
	
	if(ban == false || (actual != Estado::Fin1 && actual != Estado::Fin2)){
		
		actual = Estado::WA;
	}
	
	return actual;
}

