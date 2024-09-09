#include<iostream>
using namespace std;
template<typename T>
struct ListNode {
  ListNode(const T &v) : value(v), next(nullptr) {}
  T value;
  ListNode *next;
};
ListNode<int> * solution(ListNode<int> * l, int n) {
    if(!l) return l;
    
    int contador = 0;
    ListNode<int>* head = l;
    // contamos la cantidad de nodos
    ListNode<int>* curr = l;
    while(curr != nullptr){
        contador++;
        curr = curr->next;
    }
    if(n >= contador) return l;
    
    
    // llego hasta el anterior al que tengo que recolocar 
    // me guardo el primero que tengo que recolocar y pongo a null el sig del anterior
    curr = l;
    int primeros = contador - n;
    ListNode<int>* nth;
    while(primeros > 0){
        if(primeros == 1){
           nth = curr->next;
           curr->next = nullptr;
           l = nth;
           break;     
        }
        curr = curr->next;
        primeros--;
    }
    while(nth->next){
        nth = nth->next;
    }
    nth->next = head;
    return l;
}

int main(){

	ListNode<int> a(1);
	ListNode<int> b(2);
	ListNode<int> c(3);
	ListNode<int> d(4);
	ListNode<int> e(5);

	a.next = &b;
	b.next = &c;
	c.next = &d;
	d.next = &e;

	solution(&a,3);

	return 0;
}