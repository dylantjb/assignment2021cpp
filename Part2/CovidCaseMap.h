#ifndef COVIDCASEMAP_H
#define COVIDCASEMAP_H

#include "CovidCase.h"

// TODO: your code goes here
#include <string>
#include <vector>
using std::string;
using std::vector;

class TimeAndCaseData {
private:
    int time;
    int numberOfCases;
public:
    TimeAndCaseData(int timeIn, int numberOfCasesIn) : time(timeIn), numberOfCases(numberOfCasesIn) {}
    int getTime() const { return time; }
    int getNumberOfCases() const { return numberOfCases; }
};


class CovidCaseMap {
private:
  vector<CovidCase> cases;

public:
  void addCase(const CovidCase &caseIn) { cases.push_back(caseIn); }
  // vector<TimeAndCaseData> getCasesOverTime(int timeIn) {
  //     int activeCases = 0;
  //     for (CovidCase i : cases) {
  //         if (i.getAge() > 14)
  //             activeCases++;
  //     }

  // }
};

// don't write any code below this line

#endif
