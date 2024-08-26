#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long numberOfRightTriangles(vector<vector<int>>& grid);

int main() {

	vector<vector<int>> v = {{0},{0}};

	numberOfRightTriangles(v);

	return 0;
}

long long numberOfRightTriangles(vector<vector<int>>& grid){
	vector<int> filas(grid.size());
	vector<int> columnas(grid[0].size());

	for(int i = 0; i < grid.size();i++){
			
		for(int j = 0; j < grid[0].size();j++){

			if(grid[i][j] == 1){
				filas[i]++;
				columnas[j]++;
			}
			
		}

	}
	
	long long cont = 0;

	for(int i = 0; i < grid.size();i++){
			
		for(int j = 0; j < grid[0].size();j++){

			if(grid[i][j] == 1){
				if(filas[i] - 1 > 0 && columnas[j] - 1 > 0){
					cont += (filas[i] - 1) * (columnas[j] -1);
				}
			}
			
		}

	}

	return cont;
}