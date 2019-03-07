#define N 8
#include<stdio.h>
#include <iostream>

/*The program loops to find as many possible ways that 8 Queens (1) can be placed without intersecting same row or column*/

/* A utility function to print solution */
void printSolution(int board[N][N])
{
	static int k = 1;
	printf("%d-\n", k++);
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
			printf(" %d ", board[i][j]);
		printf("\n");
	}
	printf("\n");
}


bool isSafe(int board[N][N], int row, int col)
{
	int i, j;

	/* Check this row on left side */
	for (i = 0; i < col; i++)
		if (board[row][i])
			return false;

	return true;
}

/* A recursive utility function to solve 8
rook problem */
bool solveNRUtil(int board[N][N], int col)
{
	/* base case: If all rook are placed
	then return true */
	if (col == N)
	{
		printSolution(board);
		return true;
	}

	/* Consider this column and try placing
	this rook in all rows one by one */
	for (int i = 0; i < N; i++)
	{
		/* Check if rook can be placed on
		board[i][col] */
		if (isSafe(board, i, col))
		{
			/* Place this rook in board[i][col] */
			board[i][col] = 1;

			/* recur to place rest of the Rook */
			solveNRUtil(board, col + 1);

			/* If placing rook in board[i][col]
			doesn't lead to a solution, then
			remove rook from board[i][col] */
			board[i][col] = 0; // BACKTRACK
		}
	}

	/* If rook can not be place in any row in
	this column col then return false */
	return false;
}

void solveNR()
{
	int board[N][N] = { 
	{ 0, 0, 0, 0 },
	{ 0, 0, 0, 0 },
	{ 0, 0, 0, 0 },
	{ 0, 0, 0, 0 },
	{ 0, 0, 0, 0 },
	{ 0, 0, 0, 0 },
	{ 0, 0, 0, 0 },
	{ 0, 0, 0, 0 }
	};
	// it will keep printing many possible solutions to the problem
	if (solveNRUtil(board, 0))
	{
		printf("Solution does not exist");
		return;
	}

	return;
}

// driver program to test above function
int main()
{
	solveNR();

	system("pause");
	return 0;
}