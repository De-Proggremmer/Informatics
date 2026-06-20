#include <iostream>
#include <vector>

using namespace std;

bool check_square(vector<vector<int>>& square, int row, int col)
{
    if (col == 2) 
    {
        if (square[row][0] + square[row][1] + square[row][2] != 15) return false;
    }
    if (row == 2)
    {
        if (square[0][col] + square[1][col] + square[2][col] != 15) return false;
    }
    if (row == col && row == 2 && col == 2)
    {
        if (square[0][0] + square[1][1] + square[2][2] != 15) return false;
    }
    if (row + col == 2 && row == 2 && col == 0)
    {
        if (square[0][2] + square[1][1] + square[2][0] != 15) return false;
    }
    return true;
}

bool backtrack(vector<vector<int>>& square, vector<bool>& used, int row, int col)
{
    if (row == 3) { return true; }

    int next_row = (col == 2) ? row + 1 : row;
    int next_col = (col == 2) ? 0 : col + 1;

    for (int num = 1; num <= 9; num++)
    {
        if (!used[num]) 
        {
            square[row][col] = num;
            if (check_square(square, row, col))
            {
                used[num] = true;
                if (backtrack(square, used, next_row, next_col)) { return true; }
                used[num] = false;
            }
        }
    }
    return false;
}

int main() 
{
    int N;
    cin >> N;

    vector<vector<int>> square(3, vector<int>(3, 0));
    vector<bool> used(10, false);

    square[0][0] = N;
    used[N] = true;

    if (backtrack(square, used, 0, 1)) 
    {
        for (int i = 0; i < 3; i++) 
        {
            for (int j = 0; j < 3; j++)
            {
                cout << square[i][j] << " ";
            }
            cout << endl;
        }
    }
    else 
    {
        cout << -1;
    }

    return 0;
}