#ifndef COUNTDOWN_H
#define COUNTDOWN_H

#include <string>
#include <sstream>

// this is provided code for the last part of the README

std::string intToString(const int x) {
    std::ostringstream str;
    str << x;
    return str.str();
}

class CountdownSolution {
  
private:
    std::string solution;
    int value;
    
public:
    
    CountdownSolution() : solution(), value(0) {}
    
    CountdownSolution(const std::string & solutionIn, const int valueIn)
        : solution(solutionIn), value(valueIn) {
    }
    
    const std::string & getSolution() const {
        return solution;
    }
    
    int getValue() const {
        return value;
    }
    
};

// Do not edit above this line

// TODO: write code here:
#include <vector>
using namespace std;

inline double evaluateCountdown(const string &expr) {
  vector<double> numbers;

  double op1;
  double op2;

  int pos = 0;
  while (pos < expr.length()) {
    switch (expr[pos]) {
    case '+':
      op1 = numbers.back();
      numbers.pop_back();
      op2 = numbers.back();
      numbers.pop_back();

      numbers.push_back(op2 + op1);
      pos += 2;
      break;
    case '-':
      op1 = numbers.back();
      numbers.pop_back();
      op2 = numbers.back();
      numbers.pop_back();

      numbers.push_back(op2 - op1);
      pos += 2;
      break;
    case '/':
      op1 = numbers.back();
      numbers.pop_back();
      op2 = numbers.back();
      numbers.pop_back();

      numbers.push_back(op2 / op1);
      pos += 2;
      break;
    case '*':
      op1 = numbers.back();
      numbers.pop_back();
      op2 = numbers.back();
      numbers.pop_back();

      numbers.push_back(op2 * op1);
      pos += 2;
      break;
    default:
      int i = 0;
      while (expr[pos + i] != ' ') {
        i++;
      }
      numbers.push_back(stod(expr.substr(pos, i)));
      pos += i + 1;
      break;
    }
  }
  return numbers.back();
}

// Pick two numbers, use an operator, see if you get the (close to the) answer, pick another ... save the difference between it and the answer.
// Keep all the differences with their expressions
// Let it run 100 times then find the closest.
inline CountdownSolution solveCountdownProblem(const vector<int> &numbers, const double target) {
  vector<char> operators{'+', '-', '*', '/'};
  string expression = "";
  for (int i=0; i < numbers.size(); ++i) {
    if (i > 1) {
      char op = operators.back();
      operators.pop_back();
    } else {
      expression += intToString(numbers.back()) + " ";
    }
  }
  return CountdownSolution(expression);
}


// Do not edit below this line


#endif
