#include <stdlib.h>
#include <stdio.h>
#include "islandPerimeter.h"


/***********************
* islandPerimeter
* Given a map in form of a bidimensional array of integers filled with 1's, representing land, and 0's,
* representing water. Determine the perimeter of the only one island there is (one or more connected land cells).
* Notes:
* - Grid cells are connected horizontally/vertically (not diagonally).
* - The island doesn't have "lakes" (water inside that isn't connected to the water around the island).
* - One cell is a square with side length 1.
* - The grid is rectangular, width and height don't exceed 100.
* @param:
* grid: bidimensional integer array filled with 1's and 0's
* gridRowSize: number of rows in grid
* gridColSize: number of columns in grid
* @return:
* integer: island perimeter
*/
 // int islandPerimeter(int ** island, int row_size, int col_size) {
int islandPerimeter(int** grid, int gridRowSize, int gridColSize) {
	int totalPerimeter = 0;
  int  temp = 0;
	for (int i = 0; i < gridRowSize; i++) {
		for (int j = 0; j < gridColSize; j++) {
			if (grid[i][j] == 0) {
				temp = 0;
			}
			else {
        temp = 4;
				if (i != 0) {
					temp -= grid[i - 1][j];
				}
				if (i != gridRowSize - 1) {
					temp -= grid[i + 1][j];
				}
				if (j != 0) {
					temp -= grid[i][j - 1];
				}
				if (j != gridColSize - 1) {
					temp -= grid[i][j + 1];
				}
			}
			totalPerimeter += temp;
		}
	}

	return totalPerimeter;
}
