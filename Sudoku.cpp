#include <vector>
#include "Sudoku.h"

Sudoku::Sudoku(Mat&& m) noexcept
{
    boardValues = std::move(m);
}

bool Sudoku::badRow(const int x, const int r) const 
{
    for (int i = 0; i < boardValues[r].size(); i++) {
        if (boardValues[r][i] == x) {
            return true;
        }
    }
    return false;
}

bool Sudoku::badCol(const int x, const int c) const
{
    for (int i = 0; i < boardValues.size(); i++) {
        if (boardValues[i][c] == x) {
            return true;
        }
    }
    return false;
}

bool Sudoku::badBox(const int x, const int r, const int c) const
{
    for (int row = 0; row < 3; row++) {
        for (int col = 0; col < 3; col++) {
            if (boardValues[row + r][col + c] == x)
                return true;
        }
    }
    return false;
}

bool Sudoku::isSolved(int& x, int& y) const
{
    for (x = 0; x < boardValues.size(); x++) {
        for (y = 0; y < boardValues[0].size(); y++) {
            if (boardValues[x][y] == 0) {
                return false;
            }
        }
    }
    return true;
}

bool Sudoku::isValidPlace(const int x, const int y, const int val) const
{
    return !badRow(val, x) and !badCol(val, y) and !badBox(val, x - x % 3, y - y % 3)
        and boardValues[x][y] == 0;
}

bool Sudoku::solve()
{
    int row, col;
    if (isSolved(row, col)) {
        return true;
    }
    else {
        for (unsigned int i = 1; i <= 9; i++) {
            if (isValidPlace(row, col, i)) {
                boardValues[row][col] = i;
                if (solve()) {
                    return true;
                }
                boardValues[row][col] = 0;
            }
        }
    }
    return false;
}

std::ostream& operator<<(std::ostream& out, const Sudoku& c)
{
    for (auto row : c.boardValues) {
        for (auto col : row) {
            out << col << " ";
        }
        out << "\n";
    }
    return out;
}
