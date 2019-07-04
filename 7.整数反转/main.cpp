#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;
/*
 * https://leetcode-cn.com/problems/reverse-integer/
 * temp = temp*10 + x%10
 * x =x/10 
 */
#define INT_MAX pow(2,31)-1
#define INT_MIN (-INT_MAX-1)


class Solution {
public:
	int reverse(int x) {
		bool flag = x<0?false:true;
		int res=0;
		while(x){
			if((flag&&(INT_MAX/10<res)||!flag&&(INT_MIN/10>res)))return 0;
			res=res*10+x%10;
			x=x/10;
		}
		return res;
    }
};

int main(int argc, char **argv){
	
	
	Solution s;
	std::cout<<s.reverse(-123)<<endl;

	getchar();
	return 0;
}
