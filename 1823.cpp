#include<iostream>
#include<queue>
#include<vector>
using namespace std;

class Solution {
public:
    int findTheWinner(int n, int k) {

        queue<int> cola;

        for (int i = 1; i <= n; i++){
            cola.push(i);
        }

        while(cola.size() > 1){
            for (int i = 0; i < k;i++){
                int temp = cola.front();
                cola.pop();
                if(i != k-1)
                    cola.push(temp);
            }
        }
        return cola.front();
    }
};


int main(){
    return 0;
}