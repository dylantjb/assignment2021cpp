#ifndef SUDOKU_H
#define SUDOKU_H

#include "Searchable.h"

// TODO: Your Sudoku class goes here:
#include <set>
using std::set;

class Sudoku {
private:
  vector<vector<set<int>>> board;
  int size;

public:
  Sudoku(int sizeIn) : size(sizeIn) {
    for (auto &row : board) {
      board.resize(sizeIn);
      for (auto &col : row) {
        for (int sqr = 1; sqr <= sizeIn; sqr++)
          col.insert(sqr);
      }
    }
  }

  const int getSquare(int row, int col) const {
    set<int> sqr = board[row][col];
    return ((sqr.size() == 1) ? *(sqr.begin()) : -1);
  }

  bool setSquare(int row, int col, int value) {
      set<int> newSet;
      newSet.insert(value);
      board[row][col] = newSet;

      // TODO: Do the loop
      return true;
  }
};

#endif
