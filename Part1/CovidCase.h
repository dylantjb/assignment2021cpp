#ifndef COVIDCASE_H
#define COVIDCASE_H

#include <iostream>
using std::ostream;

// TODO: your code  goes here



#include <cmath>
#include <string>
using namespace std;

inline const double convertToRadians(double coord);

class CovidCase {
private:
  double lat;
  double lon;
  string name;
  int age;
  int time;

public:
  CovidCase(const double lat, const double lon, const string &name,
            const int age, const int time)
      : lat(), lon(), name(), age(), time() {}
  void write(ostream &o) const {
    o << '{' << lat << ", " << lon << ", " << '"' << name << "\", " << age
      << ", " << time << '}' << "\n";
  }
  double getLon() const { return lon; }
  double getLat() const { return lat; }
  double distanceTo(const CovidCase &other) const {
    // convert to radians (* pi/180)
    double lat1 = convertToRadians(lat);
    double lon1 = convertToRadians(lon);
    double lat2 = convertToRadians(other.getLat());
    double lon2 = convertToRadians(other.getLon());

    double dlon = lon1 - lon2;
    double dlat = lat1 - lat2;
    double a = pow((sin(dlat / 2)), 2) +
               cos(lat1) * cos(lat2) * pow((sin(dlon / 2)), 2);
    double c = 2 * atan2(sqrt(a), sqrt(1 - a));

    return 3960 * c;
  }
};

inline const double convertToRadians(double coord) {
  return (atan(1) * coord) / 45;
}

inline ostream &operator<<(ostream &o, const CovidCase &rhs) {
  rhs.write(o);
  return o;
}

// don't write any code below this line

#endif

