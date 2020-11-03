#include "Sudoku.h"
#include <chrono>

void measurePerformance(Sudoku& s) {
	auto t1 = std::chrono::high_resolution_clock::now();
	s.solve();
	auto t2 = std::chrono::high_resolution_clock::now();
	std::cout << std::chrono::duration_cast<std::chrono::microseconds>
		(t2 - t1).count()<< "\n";
}

int main() {

	Sudoku s({{8,0,0,  0,0,0,  0,0,0},
		  {0,0,3,  6,0,0,  0,0,0},
		  {0,7,0,  0,9,0,  2,0,0},
		  
		  {0,5,0,  0,0,7,  0,0,0},
		  {0,0,0,  0,4,5,  7,0,0},
		  {0,0,0,  1,0,0,  0,3,0},
		  
		  {0,0,1,  0,0,0,  0,6,8},
		  {0,0,8,  5,0,0,  0,1,0},
		  {0,9,0,  0,0,0,  4,0,0},
	});

	measurePerformance(s);

}
