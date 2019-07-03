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
 * 2.中心扩展
 * babad
 * iter从0到n-1寻找各个位置最大的回文子串，分为奇偶两种情况
 * 此时为奇数个，假设迭代到t，此时要判断t-r，t+r是否越边界，且是否s[t-r]==s[t+r]
 * 此时为偶数个，首先保证s[t]=s[t+1],此时要判断t-r，t+r+1是否越边界，且是否s[t-r]==s[t+r+1]
 * 3.马拉车方法(之后更新）
 */

class Solution {
public:
    string longestPalindrome(string s) {
		int n=s.size();
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
	string longestPalindrome1(string s) {
		int n=s.size();
		int pos=0,maxlen=0;
		for(int i=0;i<n;i++){
			int r=1;
			while(i-r>=0&&i+r<n&&s[i-r]==s[i+r]) r++;
			if(maxlen<2*r-1){
				maxlen=2*r-1;
				pos=i-r+1;
			}
			if(i>=n-1||s[i]!=s[i+1])continue;
			r=1;
			while(i-r>=0&&i+1+r<n&&s[i-r]==s[i+1+r])r++;
			if(maxlen<2*r){
				maxlen=2*r;
				pos=i-r+1;
			}
		}
		return s.substr(pos,maxlen);
    }
	string longestPalindrome2(string s) {
		int n=s.size();
		int m=2*n+1;
		vector<char> str(n,'*');
		vector<int> slen(n,0);
		for(int i=0;i<n;i++) str[2*i+1]=s[i];
		int curpos=0,curlen=0,maxpos=0,maxlen=0;
		for(int i=0;i<m;i++){
			int mi =2*curpos-i,r=slen[mi];
			if(i+r<curpos+curlen){
				slen[i]=slen[mi];
				continue;
			}
			r=curpos+curlen-i;
			while(i-r>=0&&i+r<n&&str[i-r])==str[i+r])r++;
			r--;
			slen[i]=r;
			curpos=i;
			curlen=r;
			if(maxr<r){
				maxpos=i;
				maxr=r;
			}
			if(i+maxr>=n)break;
		}
		return s.substr(maxpos/2-maxr/2,maxr);
    }
	
};


int main(int argc, char **argv){
	
	
	Solution s;
	std::cout<<s.longestPalindrome("babad")<<endl;
	std::cout<<s.longestPalindrome1("babad")<<endl;
	getchar();
	return 0;
}
