#include <iostream>
#include <vector>
using namespace std;

vector<int> spiralOrder(vector<vector<int>>& matrix);

int main(){

	vector<vector<int>> v =  { {1,2,3}, {4,5,6}, {7,8,9}};
	spiralOrder(v);


	return 0;
}

vector<int> spiralOrder(vector<vector<int>>& matrix) {

	vector<int> sol;

	int left = 0;
	int right = matrix[0].size()-1;
	int top = 0;
	int bottom = matrix.size()-1;

	while(left <= right && top<=bottom){

		for(int i=left;i<=right;i++){
				sol.push_back(matrix[top][i]);
		}
		top++;
		for(int i=top;i<=bottom;i++){
				sol.push_back(matrix[i][right]);
		}
		right--;
		if(top<=bottom){
				for(int i=right;i>=left;i--){
						sol.push_back(matrix[bottom][i]);
				}
				bottom--;
		}
		if(left<=right){
				for(int i=bottom;i>=top;i--){
						sol.push_back(matrix[i][left]);
				}
				left++;
		}

	}
	return sol;

}