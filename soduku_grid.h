#ifndef _SODUKU_GRID_H_
#define _SODUKU_GRID_H_


#include <iostream>
using namespace std;

class soduku_grid {
private:
	int grid[9][9];
	bool check(int row, int col,int num);
	bool rowCheck(int row, int num);
	bool colCheck(int col, int num);
	bool boxCheck(int rowStart, int colStart, int num);
	bool find_empty_box(int &row, int &col);
public:

	soduku_grid();

	//temporary soduku grid constructor with 2D array to test 
	soduku_grid(int arr[9][9]);

	//temporary printer to test 
	void print() {
		for (int row = 0; row < 9; row++)
		{
			for (int col = 0; col < 9; col++)
			{
				cout << grid[row][col] << " ";
			}
			cout << endl;
		}
	}

	void fill();
	bool solve();
};

#endif 