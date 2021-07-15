#include "Person.hpp"
#include "Sensor.hpp"
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

void Person::setAge(unsigned int A) { age = A; }
unsigned int Person::getAge() { return age; }

void Person::setIDNumber(){
  srand(rand());
  ID_Number = rand()% 100000 + 1;
}
unsigned int Person::getIDNumber() {
  return ID_Number;
}

int Person::getTimeWindow(string date) {
  int firstDigit,secondDigit;
  try {
    firstDigit = stoi(date.substr(0, 1));
    secondDigit = stoi(date.substr(1, 2));
  } catch (std::invalid_argument &e) {
    std::cout << e.what();
    std::cout << "That is not a valid number." << '\n';
  }
  int timeWindow = 0;
    if (firstDigit == 0) {
      if (secondDigit < 7) {
        timeWindow = 1;
      } else if (secondDigit >= 7) {
        timeWindow = 2;
      } else {
        timeWindow = -1;
      }
    } else if (firstDigit == 1) {
      if (secondDigit >= 0 && secondDigit < 8) {
        timeWindow = 3;
      } else if (secondDigit >= 8) {
        timeWindow = 4;
      } else {
        timeWindow = -1;
      }
    } else if (firstDigit == 2) {
      if (secondDigit < 5) {
        timeWindow = 4;
      } else {
        timeWindow = -1;
      }
    } else {
      timeWindow = -1;
    }

  return timeWindow;
}

int Person::analyseSensedData(unsigned int timeWindow, double sampleTime) {
  int critical;
  int age = getAge();

  if (timeWindow == 1) {
    if (age >= 0 && age <= 6) {
      if (sampleTime >= 20 && sampleTime <= 30.2) {
        critical = 0;
      } else {
        critical = 1;
      }
    } else if (age >= 7 && age <= 16) {
      if (sampleTime >= 22 && sampleTime <= 35.9) {
        critical = 0;
      } else {
        critical = 1;
      }
    } else if (age >= 17 && age <= 38) {
      if (sampleTime >= 22.7 && sampleTime <= 37.3) {
        critical = 0;
      } else {
        critical = 1;
      }
    } else if (age >= 39 && age <= 55) {
      if (sampleTime >= 25.7 && sampleTime <= 38.3) {
        critical = 0;
      } else {
        critical = 1;
      }
    } else if (age >= 55) {
      if (sampleTime >= 20 && sampleTime <= 35) {
        critical = 0;
      } else {
        critical = 1;
      }
    } else {
      critical = -1;
    }
  } else if (timeWindow == 2) {
    if (age >= 0 && age <= 6) {
      if (sampleTime >= 30 && sampleTime <= 52) {
        critical = 0;
      } else {
        critical = 1;
      }
    } else if (age >= 7 && age <= 16) {
      if (sampleTime >= 30 && sampleTime <= 55) {
        critical = 0;
      } else {
        critical = 1;
      }
    } else if (age >= 17 && age <= 55) {
      if (sampleTime >= 32 && sampleTime <= 57.8) {
        critical = 0;
      } else {
        critical = 1;
      }
    } else if (age >= 55) {
      if (sampleTime >= 25.7 && sampleTime <= 38.3) {
        critical = 0;
      } else {
        critical = 1;
      }
    } else {
      critical = -1;
    }
  } else if (timeWindow == 3) {
    if (age >= 0 && age <= 6) {
      if (sampleTime >= 20 && sampleTime <= 40) {
        critical = 0;
      } else {
        critical = 1;
      }
    } else if (age >= 7 && age <= 16) {
      if (sampleTime >= 22 && sampleTime <= 39) {
        critical = 0;
      } else {
        critical = 1;
      }
    } else if (age >= 17 && age <= 55) {
      if (sampleTime >= 22.7 && sampleTime <= 41) {
        critical = 0;
      } else {
        critical = 1;
      }
    } else if (age >= 55) {
      if (sampleTime >= 25.7 && sampleTime <= 37) {
        critical = 0;
      } else {
        critical = 1;
      }
    } else {
      critical = -1;
    }
  } else if (timeWindow == 4) {
    if (age >= 0 && age <= 6) {
      if (sampleTime >= 25 && sampleTime <= 52) {
        critical = 0;
      } else {
        critical = 1;
      }
    } else if (age >= 7 && age <= 16) {
      if (sampleTime >= 25 && sampleTime <= 55) {
        critical = 0;
      } else {
        critical = 1;
      }
    } else if (age >= 17 && age <= 55) {
      if (sampleTime >= 25 && sampleTime <= 57.8) {
        critical = 0;
      } else {
        critical = 1;
      }
    } else if (age >= 55) {
      if (sampleTime >= 25 && sampleTime <= 40) {
        critical = 0;
      } else {
        critical = 1;
      }
    } else {
      critical = -1;
    }
  }

  else {
    critical = -1;
  }

  return critical;
}

int Person::percentage(int size, int noOfCritical) {
  if (noOfCritical != 0) {
    int percentage;
    percentage = (noOfCritical * 100 / size);
    return percentage;
  } else {
    return 0;
  }
}

std::vector<int> Person::noOfcritical(unsigned int timeWindow,
                                      unsigned int critical) {
  if (critical == 1) {
    if (timeWindow == 1) {
      vectorCritical.at(0)++;
    } else if (timeWindow == 2) {
      vectorCritical.at(1)++;
    } else if (timeWindow == 3) {
      vectorCritical.at(2)++;
    } else if (timeWindow == 4) {
      vectorCritical.at(3)++;
    } else {
      cout << "Error: in totalNoOfcritical method" << endl;
    }
  }
  return vectorCritical;
}

void Person::analysis() {
  unsigned int timeWindow, sensedData;

  string date,sampleV,time = "" ;
  double sampleValue;

  // Open the file
  string fileName = "sensor" + name + ".dat";
  ifstream file("sensorA.dat", std::ifstream::in);
  string line;
  // Checks whether state of stream is good. If not it returns an error message.
  if (!file.good()) {
    cerr << "Could not open file.... exitting..." << endl;
    exit(EXIT_FAILURE);
  }
  while (getline(file, line)) {
    stringstream linestream(line);
    linestream >> date >> sampleV>>time;
    sampleValue = stod(sampleV);
    date = line.substr(11, 9);
    timeWindow = getTimeWindow(date);
    sensedData = analyseSensedData(timeWindow, sampleValue);
    vectorTotalCritical.at(timeWindow - 1)++;
    vectorCritical = noOfcritical(timeWindow, sensedData);
  }
}

void Person::showPersonInfo(int personNo) {
  int age = getAge();
  personFile << "Person " << personNo << ":";
  if (age >= 0 && age <= 6) {
    personFile << "(0-6 years)";
  } else if (age >= 7 && age <= 16) {
    personFile << "(7-16 years)";
  } else if (age >= 17 && age <= 38) {
    personFile << "(17-38 years)";
  } else if (age >= 39 && age <= 55) {
    personFile << "(39 - 55 years)";
  } else if (age >= 55) {
    personFile << "(55+ years)";
  } else {
    
  }
  personFile << " ID Number: "<< getIDNumber() << endl;

}

void Person::analysisFile(int personNo) {
  string filename = "analysis.txt";
  string night, morning, daytime, evening = "";
  int nightPercentage, morningPercentage, daytimePercentage, eveningPercentage;
  personFile.open(filename.c_str(),
                  ios::app); /* Data gets appended here -- so make sure you
                                clear your file before you start to set up
                                experiments */
  cout << endl;

  if (!personFile.good()) {
    cerr << "Error opening sensor recording file" << endl;
    exit(EXIT_FAILURE);
  }
  personFile << "--------------------------------------"
             << "\n";
  showPersonInfo(personNo);
  personFile << "--------------------------------------"
             << "\n";

  night =
      to_string(percentage(vectorTotalCritical.at(0), vectorCritical.at(0)));
  morning =
      to_string(percentage(vectorTotalCritical.at(1), vectorCritical.at(1)));
  daytime =
      to_string(percentage(vectorTotalCritical.at(2), vectorCritical.at(2)));
  evening =
      to_string(percentage(vectorTotalCritical.at(3), vectorCritical.at(3)));

  personFile << "Night"
             << "\t\t" << night << "% critical samples"
             << "\n";
  personFile << "Morning"
             << "\t\t" << morning << "% critical samples"
             << "\n";
  personFile << "Daytime"
             << "\t\t" << daytime << "% critical samples"
             << "\n";
  personFile << "Evening"
             << "\t\t" << evening << "% critical samples"
             << "\n";
}
void Person::lastLine(){
  personFile << "--------------------------------------" << "\n";
}

Person::Person(unsigned int age, int personNo) {
  setAge(age);
  setIDNumber();
  analysis();
  analysisFile(personNo);
}