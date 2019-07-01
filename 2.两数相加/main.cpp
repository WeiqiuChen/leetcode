#include <stdio.h>
#include <vector>
#include <iostream>

/*
https://leetcode-cn.com/problems/add-two-numbers/
*/

using namespace std;
/**
 * Definition for singly-linked list.
 * 
*/
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

void print_ListNode(ListNode *l){
	while(l!=NULL){
		std::cout<<l->val<<" ";
		l=l->next;
	}
	std::cout<<endl;
}

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *l =new ListNode(0);
		ListNode *p=l;
		int a,b;
		int j=0;
		while(l1!=NULL||l2!=NULL){
			if(l1==NULL){
				a = 0;
			}else{
				a = l1->val;
				l1 = l1->next;
			}
			if(l2==NULL){
				b = 0;
			}else{
				b = l2->val;
				l2 = l2->next;
			}
			int temp = a+b+j;
			p->next  = new ListNode(temp%10);
			j = temp/10;
			p = p->next;
			
			
		}
		if(j!=0){
			p->next = new ListNode(j);
		}
		//print_ListNode(l->next);
		return l->next;
		
    }
};


int main(int argc, char **argv){
	ListNode *l1 = new ListNode(1);
	ListNode *temp = l1;
	temp->next = new ListNode(8);

	ListNode *l2 = new ListNode(0);
	temp = l2->next;

	
	print_ListNode(l1);
	print_ListNode(l2);
	Solution s;
	print_ListNode(s.addTwoNumbers(l1,l2));
	getchar();
	return 0;
}
