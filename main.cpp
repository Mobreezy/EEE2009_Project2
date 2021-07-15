#include "Sensor.hpp"
#include "Person.hpp"
#include <iostream>
#include <stdlib.h>

using namespace std;

int main(int argc, char* argv[]) {
  unsigned int sampleTime, precisionBits, numberOfSimulatedSamples,
      numberOfPersons;
  std::string usage(argv[1]);
  if (argc < 2) {
    cerr << "Usage: " << argv[0]
         << " <sampleTime> <precisionBits> <numberOfSimulatedSamples>"
         << std::endl;
  } else if (usage == "--sensorOnly") {
    //If the input matches the requiremnet of having 8 elements, continue
    if (argc == 8) {
      cout << "You passed the following arguments: ";
      for (int argcount = 1; argcount < argc; argcount++) {
        cout << argv[argcount] << "\t";
      }
      for (int i = 0; i < argc; i++) {
        if (string(argv[i]) == "--sampleTime") {
          sampleTime = stoi(argv[i + 1]);
        } else if (string(argv[i]) == "--PrecisionBits") {
          precisionBits = stoi(argv[i + 1]);
        } else if (string(argv[i]) == "--numberOfSimulatedSamples") {
          numberOfSimulatedSamples = stoi(argv[i + 1]);
        } else {
        }
      }
      // Run sensor 
      Sensor A("A", sampleTime, precisionBits);
      A.showInfo();
      A.generateSamples(numberOfSimulatedSamples);

    } else {
      cout << "Please enter the right number of arguments,--sensorOnly "
              "<Usage> --sampleTime <sampleTime> "
              "--PrecisionBits <PrecisionBits> -- numberOfSimulatedSamples "
              "<numberOfSimulatedSamples>"
           << endl;
    }
  } else if (usage == "--personOnly") {
    numberOfPersons = stoi(argv[2]);
    int age;
    int personNo;
    for (int i = 0; i < numberOfPersons; i++) {
      age = stoi(argv[i + 3]);
      personNo = i+1;
      Person p(age, personNo);     
    }
    // p.lastLine();
    
  } else {
    cout << "Error: usage name incorrect" << endl;
  }
  return 0;
}
//How to run
// i. ./program --sensorOnly --sampleTime 100 --PrecisionBits 3 --numberOfSimulatedSamples 100
// ii. ./program --sensorOnly --numberOfSimulatedSamples 100 --PrecisionBits 3 --sampleTime 100
// iii. ./program --personOnly 4 34 12 6 81
// iv. ./program --personOnly 3 8 19 39