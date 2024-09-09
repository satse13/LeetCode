#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

bool isCryptSolution(vector<string> crypt, vector<vector<char>> solution) {
   
    unordered_map<char,char> map;
    
    for(int i = 0; i < solution.size();i++){
        map[solution[i][0]] = solution[i][1];
    }
    vector<string> numbers;
    for(string word: crypt){
        string aux = "";
        if(!map.count(word[0]) || (map[word[0]] == '0' && word.size() != 1))
            return false; 
       
        for(char c: word){
            aux.push_back(map[c]);
        }
        numbers.push_back(aux);
    }
  
    if(stol(numbers[0]) + stol(numbers[1]) != stol(numbers[2]))
        return false;
    
    return true;
}


int main(){

 	vector<string> a = {"AAAAAAAAAAAAAA", "BBBBBBBBBBBBBB", "CCCCCCCCCCCCCC"};
  vector<vector<char>> b = {{'A', '1'}, {'B', '2'}, {'C', '3'}};

	if (isCryptSolution(a, b)) {
        cout << "The solution is correct." << endl;
    } else {
        cout << "The solution is incorrect." << endl;
    }

	return 0;
}