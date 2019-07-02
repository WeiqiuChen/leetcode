#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>

using namespace std;
/*
 * https://leetcode-cn.com/problems/longest-palindromic-substring/comments/
 * 1.动态规划
 * babad
 * 长度为1，肯定为回文子串  如"b","a"
 * 长度为2，若s[j]==s[k],则为回文子串,此时长度为2,如"bb"为回文子串，"ba"则不是
 * 长度>2,若s[j]==s[k],且[j+1,k-1]是回文子串,那么[j,k]是回文子串。dp[j][k] = dp[j+1][k-1]+2;
 * 如"a"是回文子串，"bab"前后为相同，那么"bab"为回文子串
 */

class Solution {
public:
    string longestPalindrome(string s) {
		int n = s.size();
        vector<vector <int> > dp(n,vector<int>(n,0));
		int maxlen=0,idx=0;
		for(int i=0; i<n; i++){
			for(int j=0,k=i;j<n&&k<n;++j,++k){
				if(k==j) dp[j][k]=1;
				else if(s[k]==s[j]&&j+1==k) dp[j][k]=2;
				else if(s[k]==s[j]&&dp[j+1][k-1]>0) dp[j][k]=dp[j+1][k-1]+2;
				else dp[j][k]=0;
				if(dp[j][k]>maxlen){
					maxlen=dp[j][k];
					idx=j;
				}
			}
		}
		return s.substr(idx,maxlen);
    }
};


int main(int argc, char **argv){
	
	
	Solution s;
	std::cout<<s.longestPalindrome("babad")<<endl;
	getchar();
	return 0;
}
