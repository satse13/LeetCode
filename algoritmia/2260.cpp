#include <iostream>
#include<unordered_map>
#include<vector>
#include <climits>
#include <cmath>
using namespace std;

int minimumCardPickup(vector<int>& cards);

int main(){
	vector<int> v = {1,0,5,3};
	cout << minimumCardPickup(v);

	return 0;
}

int minimumCardPickup(vector<int>& cards) {

	unordered_map<int,int> map;
	int minim = INT_MAX;

	for(int i = 0;i < cards.size();i++){

		if(map.count(cards[i])){
			minim = min(minim, i - map[cards[i]]+1);
			map[cards[i]] = i;
		}

		else {
			map[cards[i]] = i;
		}
	}
  return minim == INT_MAX ? -1 : minim;
}