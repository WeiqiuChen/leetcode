#include <stdio.h>
#include <string>
#include <iostream>
#include <algorithm>
#include <map>
/*
https://leetcode-cn.com/problems/longest-substring-without-repeating-characters/
*/
using namespace std;
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxlen = 0, left = 0, n = s.size();
		std::map<char,int> m;
		for(int i=0;i<n;++i){
			left = max(left,m[s[i]]);
			m[s[i]] = i+1;
			maxlen = max(maxlen,i-left+1);
		}
		return maxlen;
		
        
    }
};


int main(int argc, char **argv){
	string s1 = "pwwkew";
	Solution s;
	std::cout<<s.lengthOfLongestSubstring(s1)<<endl;
	getchar();
	return 0;
}
