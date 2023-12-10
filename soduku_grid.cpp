#include "soduku_grid.h"


soduku_grid::soduku_grid() {
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			grid[i][j] = 0;
		}
	}
}

soduku_grid::soduku_grid(int arr[9][9]) {
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			grid[i][j] = arr[i][j];
		}
	}
}

void soduku_grid::fill() {
	//gonna create a gui that the user can interact with to fill in the soduku grid,


}

bool soduku_grid::solve() {
	//go through the grid and find an empty box. If found, you fill it with a number (loop)  
	int row, col; 

	if (!find_empty_box(row, col))
		// if there are no empty boxes, then check if the assignments of numbers are correct. Will be added later.
		// for now, just assume that when all the boxes are filled, the grid is correct. 
		return true; 

	//if an empty box is found, then go through 1 to 9 and find a number that fits and assign it to the box. 

	for (int potNum = 1; potNum < 10; potNum++)
	{
		//see if potNum that was iterated is alright in the row, col position. 
		if (check(row,col,potNum))
		{
			//if it's alright, then assign the number for now. 
			grid[row][col] = potNum;

			//then recursively solve the new grid. 
			if (solve())
				return true; 


			//if it doesn't work, then try again with a new potNum value. 
			grid[row][col] = 0;
		}
	}

	// if poNum's value doesn't work from 1 to 9, then you've done something wrong coming here and backtracking is done.
	return false;
}

bool soduku_grid::check(int row, int col,int num) {
	//return true if the potential number is ok with regards to the col, row, and box.

	return !colCheck(col,num) && !rowCheck(row,num) && !boxCheck(row - row%3,col - col%3,num);
}

bool soduku_grid::find_empty_box(int &row, int  &col) {
	for (row  = 0; row < 9; row++)
	{
		for (col= 0; col < 9; col++)
		{
			if (grid[row][col] == 0)
				return true;
		}
	}
	return false;
}


bool soduku_grid::rowCheck(int row, int num) {
	for (int col = 0; col < 9; col++)
	{
		if (grid[row][col] == num)
		{
			return true;
		}
	}
	return false;
}

bool soduku_grid::colCheck(int col, int num) {
	for (int row = 0; row < 9; row++)
	{
		if (grid[row][col] == num)
		{
			return true;
		}
	}
	return false;
}

bool soduku_grid::boxCheck(int rowStart, int colStart, int num) {
	for (int row = 0;  row < 3;  row++)
	{
		for (int col = 0; col < 3; col++)
		{
			if (grid[rowStart + row][colStart + col] == num)
			{
				return true;
			}
		}
	}
	return false;
}