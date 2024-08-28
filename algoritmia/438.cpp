#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

vector<int> findAnagrams(string s, string p);

int main() {

	string s = "cbaebabacd";
	string p = "abc";

	vector<int> v  =findAnagrams(s,p);

	for(int i : v){
		cout << i << " ";
	}

	return 0;
}

vector<int> findAnagrams(string s, string p){

		int n=s.length(),m=p.length();
        if(m>n) return {};
        vector<int> res,cnt1(26,0),cnt2(26,0);
        for(int i=0;i<m;i++){
            cnt1[s[i]-'a']++;
            cnt2[p[i]-'a']++;
        }
        int i=0,j=m;
        if(cnt1==cnt2) res.push_back(0);
        while(j<n){
            cnt1[s[i]-'a']--;
            cnt1[s[j]-'a']++;
            i++;
            j++;
            if(cnt1==cnt2) res.push_back(i);
        }
        return res;
}


