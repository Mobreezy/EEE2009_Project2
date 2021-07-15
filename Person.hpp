#ifndef PERSON_H
#define PERSON_H

#include <string>
#include <fstream>
#include <vector>

class Person{
public:
  //Getters and setters
	void setAge(unsigned int);
	unsigned int getAge();

  void setIDNumber();
  unsigned int getIDNumber();
  /**
    * Method for calculating critical percentages
    * @param - total number of samples of time window, total number of critical samples for said time window
    * @return - critical sample percentage
*/
  int percentage(int, int);
  /**
    * Method for geting the time window
    * @param - timestamp in the form of a string
    * @return - time window as a number i.e 1 = night 2=morning 3 = daytime 4 = evening
*/
  int getTimeWindow(std::string);
  /**
    * Method for analysing sesned data and working out if the data is critical or not
    * @param - time window, sample value
    * @return - 0 = not critical 1 = critical
*/
  int analyseSensedData(unsigned int, double);
  /**
    * Method for analsysing data
*/
  void analysis();
  /**
    * Method for calculating the number of critical values for a given time window
    * @param - time window, critical
    * @return - total number of critical values
*/
  std::vector <int> noOfcritical(unsigned int, unsigned int);

  void showPersonInfo(int);
  void analysisFile(int);
  void lastLine();
  Person();
  Person(unsigned int,int);
	  
private:
  
  std::ofstream personFile;

	unsigned int ID_Number;
	unsigned int age;

  std::vector<int> vectorTotalCritical{0,0,0,0};
  std::vector<int> vectorCritical{0,0,0,0};

  std::string name;
	
};

#endif