#include<iostream>
#include<unordered_map>
#include<stack>
using namespace std;
template<typename T>

struct ListNode {
   ListNode(const T &v) : value(v), next(nullptr) {}
   T value;
   ListNode *next;
 };


 ListNode<int> * solution(ListNode<int> * a, ListNode<int> * b) {

    unordered_map<ListNode<int>*, ListNode<int>*> padre;
    ListNode<int>* i = a;
    ListNode<int>* j = b;
    padre[i]=  nullptr;
    padre[j] = nullptr;
    while(i && i->next != nullptr){
        padre[i->next] = i;
        i = i->next;
    }
    while(j && j->next != nullptr){
        padre[j->next] = j;
        j = j->next;
    }
    
    int acarreo = 0;
    
    stack<ListNode<int>*> pila;
    
    // Sumar los nodos mientras ambas listas tienen elementos
    while (i != nullptr && j != nullptr) {
        int suma = i->value + j->value + acarreo;
        pila.push(new ListNode<int>(suma % 10000));  // Crear un nuevo nodo dinámicamente
        acarreo = suma / 10000;
        i = padre[i];
        j = padre[j];
    }
    
    // Procesar la lista restante en `a` (si tiene más elementos)
    while (i != nullptr) {
        int suma = i->value + acarreo;
        pila.push(new ListNode<int>(suma % 10000));
        acarreo = suma / 10000;
        i = padre[i];
    }
    
    // Procesar la lista restante en `b` (si tiene más elementos)
    while (j != nullptr) {
        int suma = j->value + acarreo;
        pila.push(new ListNode<int>(suma % 10000));
        acarreo = suma / 10000;
        j = padre[j];
    }
    
    // Si aún queda acarreo
    if (acarreo > 0) {
        pila.push(new ListNode<int>(acarreo));
    }
    
    // Reconstruir la lista en el orden correcto
    ListNode<int>* ret = pila.top();  // Obtener el primer nodo
    pila.pop();
    ListNode<int>* cur = ret;
    
    while (!pila.empty()) {
        cur->next = pila.top();
        pila.pop();
        cur = cur->next;
    }
    
    return ret;
}

int main(){

	ListNode a(9876);
	ListNode b(5432);
	ListNode c(1999);

	ListNode d(1);
	ListNode e(8001);

	a.next = &b;
	b.next = &c;
	d.next = &e;

	solution(&a,&d);

	return 0;
}