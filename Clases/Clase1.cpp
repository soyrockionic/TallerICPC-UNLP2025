#include <bits/stdc++.h>
using namespace std;

int main(){
	
    //Declaracion de variables
    int numero; 
    numero=0;  //Asignacion
    char caracter='C';
    bool verd=true;
	
	
    //Lectura y escritura
	
    cin >> numero;
	
    cout << "Hola\n";
    cout << numero<<" Este es el numero que lei"<<"\n";
	
    //Operaciones
	
    int variable=numero; //Asignacion
    variable=variable+2-1; //Suma y resta
    variable=numero*10; //Multiplicacion
    variable= numero/2; //Division. Devuelve la PARTE ENTERA
    variable=numero%2; //Modulo; evuelve el resto de la division.
	
    //Vectores
    vector<int> secuencia(10,5); 
    vector<int> secuencia2={10,5,3,4,9,12,21,356,-56};
    //5,5,5,5,5,5,5,5,5,5
    string palabra; //Equivale a vector<char>
    cin >> palabra;
    cout << palabra.size() << "\n";  //size() devuelve la cantidad de elementos del vector
    cout << secuencia.size() << "\n";
    cout << secuencia[9];
    secuencia.push_back(7);
    cout << "Tamano nuevo "<<secuencia.size()<<"\n";
	
    //Control de flujo
	
    if(numero%2 == 0){  //LA COMPARACION ES CON ==
        cout << "El numero es par\n";
    }else if(numero%5 == 0){
        cout << "El numero es impar pero multiplo de 5\n";
    }else{
        cout << "El numero no es ni impar ni mult de 5\n";
    }
	
    for(int i=0; i<10;i++){  //Inicio, fin y cambio
        cout<<"Ciclo del for "<<i<<"\n";
    }
	
    while(numero<20){
        numero = numero+1;
    }
    cout << numero << "\n";
	
    return 0;
}
