#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class SeatManager {
public:

    priority_queue<int,vector<int>,greater<int>> pq;
    SeatManager(int n) {
        for (int i=1; i<=n; i++){
            pq.push(i);
        }
    }
    
    int reserve() {
        int el= pq.top();
        pq.pop();
        return el;
    }
    
    void unreserve(int seatNumber) {
        pq.push(seatNumber);
    }

};
int main(){
    
    SeatManager* seatManager = new SeatManager(5);
    seatManager->reserve();
    seatManager->reserve();
    seatManager->unreserve(2);
    seatManager->reserve();
    seatManager->reserve(); 
    seatManager->reserve();
    seatManager->reserve();
    seatManager->unreserve(5);



    return 0;
}