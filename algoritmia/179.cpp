#include <iostream>
#include <vector>
#include <algorithm>
#include<string>
using namespace std;


string largestNumber(vector<int>& nums);

int main(){
	vector<int> v = {3,30,34,5,9};
	cout << largestNumber(v);

	return 0;
}

bool compare(int a, int b){
	 return to_string(a)+to_string(b)>to_string(b)+to_string(a);
}

	string largestNumber(vector<int>& arr) {
        sort(arr.begin(),arr.end(),compare);
        string ans = "";
        for(int i = 0;i<arr.size();i++)
        ans+=to_string(arr[i]);
        if(ans[0]=='0') return "0";
        return ans; 
    }

