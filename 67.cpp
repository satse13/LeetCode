#include<iostream>
using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        string sol = "";
        bool resto = false;
        int index1 = a.size()-1;
        int index2 = b.size()-1;

        while(index1 >= 0 && index2 >= 0){

            if((a[index1] == '1' && b[index2] == '0') || (a[index1] == '0' && b[index2] == '1')){
                if(!resto)
                    sol.push_back('1');
                else{
                    sol.push_back('0');
                }
            }
            
            else if(a[index1] == '0' && b[index2] == '0'){
                if(resto){
                    sol.push_back('1');
                    resto = false;
                }
                else{
                    sol.push_back('0');
                }
            }
            else{
                if(!resto){
                    sol.push_back('0');
                }
                else{
                    sol.push_back('1');
                }
                resto = true;
            }
            index1--;
            index2--;
        }

        while(index1 >= 0){
            if(a[index1] == '0'){
                if(resto){
                    sol.push_back('1');
                    resto = false;
                }
                else {
                    sol.push_back('0');
                }
            }
            else{
                if(resto){
                    sol.push_back('0');
                }
                else {
                    sol.push_back('1');
                }
            }
            index1--;
        }
        while(index2 >= 0){
            if(b[index2] == '0'){
                if(resto){
                    sol.push_back('1');
                    resto = false;
                }
                else {
                    sol.push_back('0');
                }
            }
            else{
                if(resto){
                    sol.push_back('0');
                }
                else {
                    sol.push_back('1');
                }
            }
            index2--;
        }
        if(resto)
            sol.push_back('1');

        string solB;

        for(int i = sol.size()-1;i>= 0;i--){
            solB.push_back(sol[i]);
        }
        return solB;
    }
};

int main(){
    Solution s;
    s.addBinary("110010","10111");
}