#include <iostream>

using namespace std;

struct ListNode {
		int val;
		ListNode *next;
		ListNode() : val(0), next(nullptr) {}
		ListNode(int x) : val(x), next(nullptr) {}
		ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* mergeNodes(ListNode* head);

int main() {




	return 0;
}

ListNode* mergeNodes(ListNode* head) {
	
	ListNode* prev = head;
	ListNode* it =  head->next;
	
	int cont = 0;
	while(it){
		
		if(it->val != 0){
			cont += it->val;
		}
		
		else {
			it->val = cont;
			prev->next = it;
			prev = it;
			cont = 0;
		}
		
		it = it->next;

	}

	return head->next;

}