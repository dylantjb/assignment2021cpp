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
  TimeAndCaseData(int timeIn, int numberOfCasesIn)
      : time(timeIn), numberOfCases(numberOfCasesIn) {}
  int getTime() const { return time; }
  int getNumberOfCases() const { return numberOfCases; }
};

class CovidCaseMap {
private:
  vector<CovidCase> cases;

public:
  void addCase(const CovidCase &caseIn) { cases.push_back(caseIn); }
  vector<TimeAndCaseData> getCasesOverTime(const int &timeIn) {
    int activeCases = 0;
    vector<TimeAndCaseData> timedCases;
    timedCases.push_back(TimeAndCaseData(0, 0));

    int time = 0;
    int numberOfCases = 0;

    for (int i = 0; i < cases.size(); i++) {
      time = cases[i].getTime();
      for (int j = 1; j < timedCases.size(); j++) {
        if (timedCases.size() + timeIn < time)
          timedCases.push_back(TimeAndCaseData(timedCases[j].getTime() + timeIn,
                                               --numberOfCases));
      }
      timedCases.push_back(
          TimeAndCaseData(timedCases[i].getTime(), ++numberOfCases));
      if (i == cases.size() - 1) {
        for (int k = 0; k < cases.size(); k++) {
          if (cases[k].getTime() + timeIn > time) {
            timedCases.push_back(TimeAndCaseData(
                timedCases[k].getTime() + timeIn, --numberOfCases));
          }
          if (timedCases[k].getTime() == timeIn) {
            break;
          }
        }
      }
    }
  }
};

// don't write any code below this line

#endif
