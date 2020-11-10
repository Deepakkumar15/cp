#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>

using namespace std ;
#define N 10
int n ;

void printfun(int board[N][N])
{
	for(int i = 0 ; i < n ; ++i)
	{
	    for(int j = 0 ; j < n ; ++j )
        {   
            if(board[i][j] == 1)
                cout << "Q" << " " ;
            else
                cout << "_" << " " ;
        }
        cout << endl ;
	}
}

bool isSafe(int board[N][N], int row, int col)
{
	int i, j ;
	for (i = 0 ; i < row ; i++)
		if(board[i][col] == 1)
			return false ;
    
   for (i=row, j=col; i>=0 && j>=0; i--, j--) 
        if (board[i][j] == 1) 
            return false; 
  
    for (i=row, j=col; i>=0 && j<N ; i--, j++) 
        if (board[i][j] == 1) 
            return false; 

return true ;

}

bool solveNQUEEN(int board[N][N], int row)
{
	if(row == n)
		return true ;
	
	for (int j = 0; j < n ; j++)
	{
		if(isSafe(board, row, j))
		{
			board[row][j] = 1 ;
			
			if(solveNQUEEN(board, row+1))
				return true ;
                
			board[row][j] = 0 ; // BACKTRACKING
		}	
	}

return false ;

}

int main()
{
	cin >> n ;

	int board[N][N] = {0} ;

	bool result = solveNQUEEN(board, 0) ;
	if(result)
		printfun(board) ;
	else
		cout << "Solution doesn't exist" ;

return 0 ;	
}