#include <iostream>
#include <cctype>

// Master79

using namespace std;

// Inicio: Q0. Finales: Q3, Q4.
enum class Estado {Q0, Q1, Q2, Q3, Q4, WA};

Estado analisis(const string& s);

int main(){
	
	string s;
	
	for(int i = 0; i < 100; i++){
		
		getline(cin, s);
		
		Estado x = analisis(s);
		
		if(x != Estado::WA){
			
			cout << "Cadena válida :)\n";
		}else{
			
			cout << "Caden no válida :(\n";
		}
	}
	
	return 0;
}

Estado analisis(const string& s){
	
	Estado actual = Estado::Q0;
	int pos = 0;
	bool ban = true;
	
	while(ban && pos < s.length()){
		
		char c = s[pos];
		
		switch(actual){
			
			case Estado::Q0:
				
				if(c == '('){
					
					cout << "Q0(" << c << ") => Q1\n";
					
					actual = Estado::Q1;
				}
				
				else if(isdigit(c)){
					
					cout << "Q0(" << c << ") => Q4\n";
					
					actual = Estado::Q4;
				}else{
					
					ban = false;
				}
				
				break;
				
			case Estado::Q1:
				
				if(isdigit(c)){
					
					cout << "Q1(" << c << ") => Q2\n";
					
					actual = Estado::Q2;
				}else{
					
					ban = false;
				}
				
				break;
				
			case Estado::Q2:
				
				if(isdigit(c)){
					
					cout << "Q2(" << c << ") => Q2\n";
					
					// Esta línea está de más. ¿Y qué?
					actual = Estado::Q2;
				}
				
				else if(c == '+' || c == '-' || c == '*' || c == '/'){
					
					cout << "Q2(" << c << ") => Q1\n";
					
					actual = Estado::Q1;
				}
				
				else if(c == ')'){
					
					cout << "Q2(" << c << ") => Q3\n";
					
					actual = Estado::Q3;
				}else{
					
					ban = false;
				}
				
				break;
				
			case Estado::Q3:
				
				if(isdigit(c)){
					
					cout << "Q3(" << c << ") => Q4\n";
					
					actual = Estado::Q4;
				}
				
				else if(c == '+' || c == '-' || c == '*' || c == '/'){
					
					cout << "Q3(" << c << ") => Q0\n";
					
					actual = Estado::Q0;
				}
				
				else if(c == '('){
					
					cout << "Q3(" << c << ") => Q1\n";
					
					actual = Estado::Q1;
				}else{
					
					ban = false;
				}
				
				break;
				
			case Estado::Q4:
				
				if(isdigit(c)){
					
					cout << "Q4(" << c << ") => Q4\n";
					
					//lol
					actual = Estado::Q4;
				}
				
				else if(c == '('){
					
					cout << "Q4(" << c << ") => Q1\n";
					
					actual = Estado::Q1;
				}
				
				else if(c == '+' || c == '-' || c == '*' || c == '/'){
					
					cout << "Q4(" << c << ") => Q0\n";
					
					actual = Estado::Q0;
				}else{
					
					ban = false;
				}
				
				break;
		}
		
		pos++;
	}
	
	if(ban == false || (actual != Estado::Q3 && actual != Estado::Q4)){
		
		actual = Estado::WA;
	}
	
	return actual;
}