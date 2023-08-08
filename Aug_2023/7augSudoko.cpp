// practice.geeksforgeeks.org/problems/solve-the-sudoku-1587115621/1
// Topic Tags - Matrix, Backtracking, DSA

#include<bits/stdc++.h>
using namespace std;
#define N 9
#define UNASSIGNED 0

class Solution{
    public: 
    int solved = 0;

    bool SolveSudoku(int grid[N][N])
    {
        int empty[9][9], i, j, row[9][10], col[9][10], square[9][10], k;

        for(i=0; i<9; i++){
            for(j=0; j<10; j++){
                row[i][j] = col[i][j] = square[i][j] = 0;
            }
        }
        for(i=0; i<9; i++){
            for(j=0; j<10; j++){
                if(grid[i][j] == 0){
                    empty[i][j] = 1;
                }
                else{
                    row[i][grid[i][j]]++;
                    col[j][grid[i][j]]++;

                    square[calculate_grid(i, j)][grid[i][j]]++;
                    empty[i][j] = 0;
                }
            }
        }
        fillGrid(grid, empty, 0, 0, row, col, square);

        if(solved == 1){
            return true;
        }
        else{
            return false;
        }
    }

    int calculate_grid(int i, int j){
        if(i<=2 && j<=2){
            return 0;
        }
        if(i<=2 && j<=5){
            return 1;
        }
        if(i<=2 && j<=8){
            return 2;
        }
        if(i<=5 && j<=2){
            return 3;
        }
        if(i<=5 && j<=5){
            return 4;
        }
        if(i<=5 && j<=8){
            return 5;
        }
        if(i<=8 && j<=2){
            return 6;
        }
        if(i<=8 && j<=5){
            return 7;
        }
        if(i<=8 && j<=8){
            return 8;
        }
        return 0;
    }
    bool checkGrid(int row[][10], int col[][10], int square[][10], int grid[N][N])
    {
        bool ans = true;

        int i, j, k;

        for(i=0; i<9; i++){
            for(j=1; j<=9; j++){
                if(row[i][j] != 1){
                    ans = false;
                    break;
                }
            }
            if(ans == false){
                break;
            }
        }
        for(i=0; i<9; i++){
            for(j=0; j<=9; j++){
                if(col[i][j] != 1){
                    ans = false;
                    break;
                }
            }
            if(ans == false){
                break;
            }
        }
        for(i=0; i<9; i++){
            for(j=0; j<=9; j++){
                if(square[calculate_grid(i, j-1)][j] != 1){
                    ans = false;
                    break;
                }
            }
            if(ans == false){
                break;
            }
        }
        return ans;
    }
    void fillGrid(int grid[N][N], int empty[][9], int i, int j, int row[][10], int col[][10], int square[][10])
    {
        if(i == 9){
            if(checkGrid(row, col, square, grid) == true){
                solved = 1;
            }
            return;
        }
        if(empty[i][j] == 1){
            for(int k=1; k<=9 && solved == 0; k++){
                if(row[i][k] == 1 || col[j][k] == 1|| square[calculate_grid(i, j)][k] == 1){
                    continue;
                }
                grid[i][j] = k;
                row[i][k]++;
                col[j][k]++;
                square[calculate_grid(i, j)][k]++;

                if(j == 8){
                    fillGrid(grid, empty, i+1, 0, row, col, square);
                }
                else{
                    fillGrid(grid, empty, i, j+1, row, col, square);
                }

                row[i][k]--;
                col[j][k]--;
                square[calculate_grid(i, j)][k]--;
            }
        }
        else{
            if(j == 8){
                fillGrid(grid, empty, i+1, 0, row, col, square);
            }
            else{
                fillGrid(grid, empty, i, j+1, row, col, square);
            }
        }
    }

    void printGrid(int grid[N][N]){
        int i, j;
        for(i=0; i<9; i++){
            for(j=0; j<9; j++){
                cout<<grid[i][j]<<" ";
            }
        }
    }
};
int main()
{
    int grid[N][N] = {{3 ,0 ,6 ,5 ,0, 8, 4, 0, 0},
                      {5 ,2 ,0 ,0 ,0 ,0, 0 ,0, 0},
                      {0 ,8, 7, 0, 0 ,0 ,0, 3 ,1},
                      {0 ,0 ,3 ,0 ,1 ,0 ,0 ,8 ,0},
                      {9 ,0 ,0 ,8 ,6 ,3 ,0 ,0 ,5},
                      {0 ,5 ,0 ,0 ,9 ,0 ,6 ,0 ,0},
                      {1 ,3 ,0 ,0 ,0 ,0 ,2 ,5 ,0},
                      {0 ,0 ,0 ,0 ,0 ,0 ,0 ,7 ,4},
                      {0 ,0 ,5 ,2 ,0 ,6 ,3 ,0 ,0}};

    Solution ob;

    if(ob.SolveSudoku(grid) == true){
        ob.printGrid(grid);
    }
    else{
        cout<<"No solution exists";
    }
    cout<<endl;
    return 0;
}