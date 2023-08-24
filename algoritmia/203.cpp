#include<iostream>
#include<vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {

        if(!head)
            return head;
        
        while(head && head->val == val){
            head = head->next;
        }
        if(!head)
            return head;

        ListNode *p1 = head;

        while(p1 && p1->next){
            
            while(p1->next && p1->next->val == val)
                p1->next = p1->next->next;

            p1 = p1->next;
        }
        return head;
    }
};