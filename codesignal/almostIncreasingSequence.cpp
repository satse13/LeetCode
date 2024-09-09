#include <iostream>
#include <vector>
using namespace std;

bool solution(vector<int> sequence) {
    int prev = INT_MIN, preprev = INT_MIN;
    int count = 0;
    for (const auto& n : sequence) {
        if (n <= prev) {
			if(count == 1) return false;
			count++;
            if (n > preprev)
                prev = n;
        } else {
            preprev = prev;
            prev = n;
        }
    }
    return true;
}



int main(){
	vector<int> v = {1, 2, 3, 4, 3, 6};
	if(solution(v))
		cout << "true";
	else 
		cout << "false";

	return 0;
}

