#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;
/*
 * https://leetcode-cn.com/problems/median-of-two-sorted-arrays/
 */

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
       int m = nums1.size();
	   int n = nums2.size();
	   int maxindex = (m+n)/2+1;
	   std::vector<int> newnum;
	   vector<int>::iterator iter1 = nums1.begin();
	   vector<int>::iterator iter2 = nums2.begin();
	   for(int i =0;i<maxindex;++i){
		   if(iter1==nums1.end()){
			   newnum.push_back(*iter2);
			   iter2++;
		   }else if(iter2==nums2.end()){
			   newnum.push_back(*iter1);
			   iter1++;
		   }else if (*iter1<*iter2){
			   newnum.push_back(*iter1);
			   iter1++;
		   }else {
			   newnum.push_back(*iter2);
			   iter2++;
		   }
	   }
	   double res;
	   if((m+n)%2==0){
		   res = (newnum[maxindex-2]+newnum[maxindex-1])/2.0;
	   }else{
		   res = newnum[maxindex-1];
	   }
	   return res;
	   
	   
    }
};


int main(int argc, char **argv){
	int a[]={1,2};
	vector<int> v1;
	v1.assign(a,a+2);
	int b[]={3,4};
	vector<int> v2;
	v2.assign(b,b+2);
	
	Solution s;
	std::cout<<s.findMedianSortedArrays(v1,v2)<<endl;
	getchar();
	return 0;
}
