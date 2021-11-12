#ifndef COVIDCASE_H
#define COVIDCASE_H

#include <iostream>
using std::ostream;

// TODO: your code  goes here

#include <cmath>
#include <string>
using std::stod;
using std::stoi;
using std::string;

inline double convertInRadians(double coord);

class CovidCase {
private:
  double lat;
  double lon;
  string name;
  int age;
  int time;

public:
  CovidCase(const double latIn, const double lonIn, const string &nameIn,
            const int ageIn, const int timeIn)
      : lat(latIn), lon(lonIn), name(nameIn), age(ageIn), time(timeIn) {}
  explicit CovidCase(const string &stringIn) : lat(0), lon(0), name(""), age(0), time(0) {
    string temp = "";
    int element = 0;
    int x = stringIn.find('"');
    int y = stringIn.find_last_of('"');
    name = stringIn.substr(x+1, y-x-1);

    for (int i = 0; i < stringIn.length(); i++) {
      char current = stringIn[i];
      if (current == ',' || i == stringIn.length()-1) {
        switch (element) {
        case 0: {
          lat = stod(temp);
          break;
        }
        case 1: {
          lon = stod(temp);
          break;
        }
        case 3: {
          age = stoi(temp);
          break;
        }
        case 4: {
          temp = stringIn.substr(i-1);
          time = stoi(temp);
          break;
        }
        }
        std::cout << temp << std::endl;
        element++;
        temp = "";
      } else if (std::isdigit(current) || current == '.' || current == '-') {
        temp.push_back(current);
      }
    }
  }
  void write(ostream &o) const {
    o << '{' << lat << ", " << lon << ", " << '"' << name << "\", " << age
      << ", " << time << '}';
  }
  bool operator==(const CovidCase &other) {
    return (lat == other.getLatitude() && lon == other.getLongitude() &&
            name == other.getName() && age == other.getAge() &&
            time == other.getTime());
  }
  double getLongitude() const { return lon; }
  double getLatitude() const { return lat; }
  string getName() const { return name; }
  int getAge() const { return age; }
  int getTime() const { return time; }
  double distanceTo(const CovidCase &other) const {
    // convert to radians (* pi/180)
    double lat1 = convertInRadians(lat);
    double lon1 = convertInRadians(lon);
    double lat2 = convertInRadians(other.getLatitude());
    double lon2 = convertInRadians(other.getLongitude());

    double dlon = lon1 - lon2;
    double dlat = lat1 - lat2;
    double a = pow((sin(dlat / 2)), 2) +
               cos(lat1) * cos(lat2) * pow((sin(dlon / 2)), 2);
    double c = 2 * atan2(sqrt(a), sqrt(1 - a));

    return 3960 * c;
  }
};

inline double convertInRadians(double coord) {
  return (atan(1) * coord) / 45;
}
inline ostream &operator<<(ostream &o, const CovidCase &rhs) {
  rhs.write(o);
  return o;
}

// don't write any code below this line

#endif
