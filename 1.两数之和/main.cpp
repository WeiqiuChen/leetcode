#include <stdio.h>
#include <vector>
#include <iostream>

using namespace std;

void print_vector(std::vector<int> a){
	for(int i=0;i<a.size();i++){
		std::cout<<a[i]<<" "; 
	}
	std::cout<<endl;
}

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
		std::vector<int> indexs;
		for(int i=0;i<nums.size()-1;i++){
			for(int j=i+1;j<nums.size();j++){
				if(nums[i]+nums[j]==target){
					indexs.push_back(i);
					indexs.push_back(j);
					return indexs;
				}
			}
		}
		return indexs;
	}
};


int main(int argc, char **argv){
	int ary[]={3,2,4};
	std::vector<int> nums;
	nums.assign(ary,ary+3);
	print_vector(nums);
	Solution s;
	print_vector(s.twoSum(nums,6));
	getchar();
	return 0;
}
