#include <iostream>
#include <unordered_map>

using namespace std;

int minSteps(string s, string t);

int main(){

	cout << minSteps("night", "coats") << endl;

	return 0;
}

int minSteps(string s, string t){

	unordered_map<char,int> map;

	for(char a: s){
		if(!map.count(a))
			map[a] = 1;
		else
			map[a]++;
	}

	string aux = "";
	for(char a: t){
		if(!map.count(a))
			aux.push_back(a);
		else {
			if(map[a] == 0)
				aux.push_back(a);
			else
				map[a]--;
		}
	}

	int cont = 0;

	for(auto it = map.begin(); it != map.end();it++){
		cont += it->second;
	}
	return cont + aux.size();
}