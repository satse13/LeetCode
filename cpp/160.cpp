#include<iostream>
using namespace std;
//   Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
  };
 
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        
        int a = listLength(headA);
        int b = listLength(headB);
        if(a > b){
            int diff = a - b;
            while(diff--){
                headA = headA->next;
            }
        }
        else{
            int diff = b - a;
            while(diff--){
                headB = headB->next;
            }
        }
        while(headA != NULL && headB != NULL){
            if(headA == headB)
                return headA;
            headA = headA->next;
            headB = headB->next;
        }
        return NULL;
    }

    int listLength(ListNode *head){
        int len = 0;
        while(head != NULL){
            len++;
            head = head->next;
        }
        return len;
    }
};