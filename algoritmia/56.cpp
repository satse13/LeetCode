#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<vector<int>> merge(vector<vector<int>>& intervals);



int main(){

	vector<vector<int>> intervals = {{1,4},{4,5}};
	vector<vector<int>> v = merge(intervals);
	
	for(int i = 0; i < v.size();i++){
		for(int j = 0;j < v[i].size();j++){
			cout << v[i][j] << " ";
		}
		// cout << endl;
	}

	return 0;
}

vector<vector<int>> merge(vector<vector<int>>& intervals) {

	 sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
        return a[0] < b[0];
    });

	vector<vector<int>> v;
	int lastNoMerged = 0;
	for(int i = 0; i < intervals.size()-1;i++){

		if(intervals[i+1][1] < intervals[i][1]){
			intervals[i+1][1] = intervals[i][1];
		}

		if(intervals[i][1] < intervals[i+1][0]) {
			v.push_back({intervals[lastNoMerged][0], intervals[i][1]});
			lastNoMerged = i+1;
		}

	}

	v.push_back({intervals[lastNoMerged][0], intervals[intervals.size()-1][1]});
	return v;
}