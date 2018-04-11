
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

struct country{
  string name;
  int rating;
};

void sort(country *array, int n){
  for (int i = 0; i < n; i++){
    for(int j = i+1; j < n; j++){

      if (array[j].rating > array[i].rating){
        country temp = array[j];
        array[j] = array[i];
        array[i] = temp;
      };

    };
  };
};

void strToArr(string line, int *arrData, int numberOfCountries){
  stringstream ss(line);
  string temp;
  char delim = ',';
  int i = 0;
  for(int j=0; j<numberOfCountries; j++) {
      getline(ss, temp, delim);
      arrData[j] = (stoi(temp));
  };
};

void fillRating(country *countriesTable, int **dataMatrix, int numberOfCountries, int *marks){
  for (int i = 0; i < numberOfCountries; i++){
    for (int k = 0; k < 10; k++){

      int max = dataMatrix[0][i];
      int index = 0;

      for (int j = 0; j < numberOfCountries; j++){
        if (dataMatrix[j][i] > max){
          max = dataMatrix[j][i];
          index = j;
        };
      };

      countriesTable[index].rating+=marks[k];
      dataMatrix[index][i] = 0;
    };
  };
};

void writeInFile(country *array) {
  ofstream resultFile;
  resultFile.open("result.csv");
  for (int i = 0; i < 10; i++){
    resultFile << array[i].name << " " << array[i].rating << endl;
  };
  resultFile.close();
}

int main(int argc, const char * argv[]) {
    ifstream dataFile;
    dataFile.open ("eurovision.csv");
    string sLine = "";
    int marks[] = {12, 10, 8, 7, 6, 5, 4, 3, 2, 1};

    string numberOfCountriesstr;
    getline(dataFile, numberOfCountriesstr);
    int numberOfCountries = stoi(numberOfCountriesstr);

    int **dataMatrix = new int*[numberOfCountries];
    for (int i=0; i<numberOfCountries; i++){
      dataMatrix[i]=new int[numberOfCountries];
      for (int k=0; k<numberOfCountries; k++){
        dataMatrix[i][k] = 0;
      };
    };

    country *countriesTable = new country[numberOfCountries];

    cout<<"Number of Countries: "<<stoi(numberOfCountriesstr)<<endl;
    int counter = 0;
    if (dataFile.is_open()) {
      while (counter<numberOfCountries){
        getline(dataFile, sLine);
        if(sLine.find('"') == 0){
          // cout<<"DAROV";
          string newTempString = sLine.substr(sLine.find('"')+1,sLine.length()-1);
          countriesTable[counter].name = sLine.substr(1, newTempString.find('"'));
          countriesTable[counter].rating = 0;
          strToArr(
            newTempString.substr(newTempString.find('"')+2,newTempString.length()-1),
            dataMatrix[counter],
            numberOfCountries
          );
        } else {
          countriesTable[counter].name = sLine.substr(0, sLine.find(','));
          countriesTable[counter].rating = 0;
          strToArr(
            sLine.substr(sLine.find(',')+1,sLine.length()-1),
            dataMatrix[counter],
            numberOfCountries
          );
        }
        counter++;
      };
    };
    dataFile.close();

    fillRating(countriesTable, dataMatrix, numberOfCountries, marks);
    sort(countriesTable, numberOfCountries);

    for (int i = 0; i < numberOfCountries; i++){
      cout << countriesTable[i].name << " " << countriesTable[i].rating << endl;
    };

    writeInFile(countriesTable);

    return 0;
}
