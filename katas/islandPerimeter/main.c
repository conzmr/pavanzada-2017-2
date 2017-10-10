#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "islandPerimeter.h"


#define debug(debLog) do { \
	char * value = getenv("LOG_DEBUG");\
	if (value != NULL && !strcmp(value, "t")) printf("%s", debLog);\
} while(0);

/* Add function signatures here */

int main(int argc, char **argv) {

	int **grid;
	int gridCol, gridRow;
	char msg[200];
	char * rowTokens;
	char rowMsg[101];
	char dTok[2] = ",";

	printf("Size of gridRow: ");
	scanf("%d", &gridRow);
	printf("Size of gridCol: ");
	scanf("%d", &gridCol);

	sprintf(msg, "gridCol = %d, gridRow = %d\n", gridCol, gridRow);
	debug(msg);

	grid = (int **) malloc(sizeof(int *) * gridRow);
	for (int i = 0; i < gridRow; i++) {
		grid[i] = (int *) malloc(sizeof(int *) * gridCol);
		int j = 0;
		printf("grid %d:\n", i);
		scanf("%s", rowMsg);
		rowTokens = strtok(rowMsg, dTok);
		while(rowTokens != NULL) {
			if (j >= gridCol) {
				printf("Invalid gridRow!\n");
				return 0;
			}
			grid[i][j++] = atoi(rowTokens);
			rowTokens = strtok(NULL, dTok);
		}
	}
	sprintf(msg, "\n");
	debug(msg);
	for (int i = 0; i < gridRow; i++) {
		for (int j = 0; j < gridCol; j++) {
			sprintf(msg, "%d ", grid[i][j]);
			debug(msg);
		}
		sprintf(msg, "\n");
		debug(msg);
	}

	sprintf(msg, "\n");
	debug(msg);

	int totalPerimeter = totalPerGrid(grid, gridRow, gridCol);

	for (int i = 0; i < gridRow; i++) {
		free(grid[i]);
	}
	free(grid);

    return 0;
}
