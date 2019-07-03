#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>

using namespace std;
/*
 * https://leetcode-cn.com/problems/zigzag-conversion/
 * LEETCODEISHIRING
 * L   C   I   R
 * E T O E S I I G
 * E   D   H   N
 * 
 * 0, 0+(2*3-2), 0+(2*3-2)*2, 0+(2*3-2)*3
 * 1, 1+(2*3-2-2*1), 1+(2*3-2), 1+(2*3-2)+(2*3-2-2*1), ....
 * 2, 2+(2*3-2), 2+(2*3-2)*2, 2+(2*3-2)*3
 */


class Solution {
public:
    string convert(string s, int numRows) {
		string str="";
        int n = s.size();
		if(numRows==1||n<numRows)return s;
		int p=0;
		for(int i=0;i<numRows;i++){
			p=i;
			while(p<n){
				str+=s[p];
				if(i!=0&&i!=numRows-1&&p+numRows*2-2-2*i<n)
					str+=s[p+numRows*2-2-2*i];
				p+=numRows*2-2;
			}
		}
		return str;
    }
};

int main(int argc, char **argv){
	
	
	Solution s;
	std::cout<<s.convert("LEETCODEISHIRING",3)<<endl;
	std::cout<<s.convert("LEETCODEISHIRING",4)<<endl;
	getchar();
	return 0;
}
