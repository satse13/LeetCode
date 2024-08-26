#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

vector<int> prevPermOpt1(vector<int>& arr);

int main() {
	vector<int> v = {3,1,1,3};
	v = prevPermOpt1(v);

	for(int i : v){
		cout << i << " ";
	}

	return 0;
}

vector<int> prevPermOpt1(vector<int>& arr){

	int punto = -1;

	for(int i = arr.size()-1; i >= 1;i--){

		if(arr[i-1] > arr[i]){
			punto = i-1;
			break;
		}
	}
	if(punto == -1) return arr;
	int max;
	int valor = INT_MIN;
	for(int i = arr.size()-1; i > punto;i--){
		if(arr[i] >= valor && arr[i] < arr[punto]){
			valor = arr[i];
			max = i;
		}
	}

	int temp = arr[punto];
	arr[punto] = arr[max];
	arr[max] = temp;

	return arr;

}


// Recorrer desde la derecha e interacambiar el primer par de números tal que el de la izquierda es mayor que el de la derecha.