#pragma once
#include <iostream>
#include <vector>

using Mat = std::vector<std::vector<int>>;

class Sudoku {
private:
	Mat boardValues;
public:
	Sudoku() {};
	Sudoku(Mat&& m) noexcept;
	bool badRow(const int x, const int r) const;
	bool badCol(const int x, const int c) const;
	bool badBox(const int x, const int r, const int c) const;
	bool isSolved(int& x, int& y) const;
	bool isValidPlace(const int x, const int y, const int val) const;
	bool solve();
	friend std::ostream& operator << (std::ostream& out, const Sudoku & c);
};

