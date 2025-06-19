#include <bits/stdc++.h> 

using namespace std; 

// 1. vector<int> 
// 2. set<int> 
// 3. multiset<int> 
// 4. map<int,int> 


#define all(v) v.begin(),v.end() 

const int MAXN = 1e9; 

int main() {
	int n; cin >> n; 

	// vector /////////////////////////
	vector<int> v = {1, 5, 6, 8, 8, 8, 8, 9, 10}; 
	//                        !                    lower_bound
	//                                    !        upper_bound

	sort(all(v)); 

	auto itl = lower_bound(all(v), 8); // x >= 8
	auto itu = upper_bound(all(v), 8); // x > 8
	int x = *itl; 
	int y = *itu; 
	int id = itl -v.begin(); // O(1) 

	for (auto x: v) {
		// itero sobre elementos del vector v
	} 

	// set ////////////////////////// 
	set<int> s{1, 5, 6, 8, 9, 10}; 
	s.insert(101); // O(log(n)) 
	auto it = s.begin(); 
	while (it != s.end()) {
		it++; 
	} 
	auto itsl = s.lower_bound(8); 
	s.erase(8); 
	auto its = s.find(10); 
	if (its != s.end()) {
		// stuff 
	} 

// Enfoque	   |  Complejidad      | Comentario
// Tu codigo con sort   |  O(n log n)	| Muy bueno y sin estructuras adicionales
// set<int>	                   |  O(n log n)	| Menor codigo, ordena automaticamente
// unordered_set<int> |  O(n)	                | Mas rapido promedio, ideal para conteos

	// multiset //////////////////////// 
	multiset<int> ms = {1, 5, 6, 8, 8, 8, 8, 9, 10}; 
	int sz = ms.count(8); // O(k) 

	// opcion 1: elimina todos los elementos con el valor '8'
	ms.erase(8); 
	// {1, 5, 6, 9, 10}; 
	
	// opcion 2: elimina una aparicion del valor '8'
	auto itms = ms.find(8); 
	if (itms != ms.end()) ms.erase(itms); 
	// {1, 5, 6, 8, 8, 8, 9, 10}; 


	// map //////////////////////// 
	int arr[MAXN]; // [0..MAXN -1] 
	map<int,string> mp; 
	mp[101] = "ejemplo"; // O(log(n)) 
	if (mp[102] == "ejemplo") { 
		// preguntar por una llave que aun no esta creada, 
		// crea automaticamente una llave con el valor por defecto
		// mp[102] = ""
	} 

	
	return 0;
}
