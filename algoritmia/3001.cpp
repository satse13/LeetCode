#include <iostream>
#include <cmath>
using namespace std;

int minMovesToCaptureTheQueen(int a, int b, int c, int d, int e, int f);
bool mismaDiagonal(int a,int b,int c,int d, int e, int f);
int main() {

	cout << minMovesToCaptureTheQueen(4,5,6,4,3,1);

	return 0;
}

// Torre -> misma fila o columna y alfil no en medio = 1 | alfil en medio = 2
// Alfil -> como torre al revés

// a,b -> torre
// c,d -> alfil
// e,f -> dama

int minMovesToCaptureTheQueen(int a, int b, int c, int d, int e, int f){

	// torre
	if(e == a) {
		if(c != a || ((c == a) && (!((b > d && b > f) && abs(b-d) < abs(b-f)) && !((b < d && b < f) && abs(b-d) < abs(b-f)))))
			return 1;
	}

	if(b == f){
		if(d != f || ((d == f) && (!((a > c && a > e) && abs(a-c) < abs(a-e)) && !((a < c && a < e) && abs(a-c) < abs(a-e)))))
			return 1;
	}

	// alfil

	if((int)abs(c-e) == (int)abs(d-f)){
		if(!mismaDiagonal(a,b,c,d,e,f) || (mismaDiagonal(a,b,c,d,e,f) && ((int)abs(c - a) >= (int)abs(c -e))) ){
			return 1;
		}
	}
	return 2;
}

bool mismaDiagonal(int a,int b,int c,int d, int e, int f){

  if(!(abs(c - a) == abs(d - b) && abs(c - e) == abs(d- f))) return false;

	if(a > c && e > c && b > d && f > d) return true;
	if(a < c && e < c && b < d && f < d) return true;
	if(a < c && e < c && b > d && f > d) return true;
	if(a > c && e > c && b < d && f < d) return true;

	return false;
}


