#include<iostream>
#include<vector>
#include<stack>
using namespace std;

class StockSpanner {
private:
    stack<pair<int,int>> pila; // <precio, dias>
public:
    StockSpanner() {}

    int next(int price) {
        if(pila.empty()){
            pila.push({price,1});
            return 1;
        }
        
        int dias = 1;
        while(!pila.empty() && pila.top().first <= price){
            dias += pila.top().second;
            pila.pop();
        }
        pila.push({price,dias});
        return dias;
    }
};


int main(){
    return 0;
}