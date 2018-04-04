//
//  main.cpp
//  LabaPoProge
//
//  Created by Dima on 03.04.18.
//  Copyright © 2018 dimanadko. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

void strToArr(string line, int *arrData, int numberOfCountries){
  stringstream ss(line);
  string temp;
  char delim = ',';
  int i = 0;
  for(int j=0; j<numberOfCountries; j++) {
      getline(ss, temp, delim);
      arrData[j] = (stoi(temp));
  }
}

int main(int argc, const char * argv[]) {
    ifstream dataFile;
    dataFile.open ("eurovision.csv");
    string sLine = "";

    string numberOfCountriesstr;
    getline(dataFile, numberOfCountriesstr);
    int numberOfCountries = stoi(numberOfCountriesstr);

    int **dataMatrix = new int*[numberOfCountries];
    for (int i=0; i<numberOfCountries; i++){
      dataMatrix[i]=new int[numberOfCountries];
      for (int k=0; k<numberOfCountries; k++){
        dataMatrix[i][k] = 0;
      }
    }

    string *countries = new string[numberOfCountries];

    cout<<"Number of Countries: "<<stoi(numberOfCountriesstr)<<endl;
    int counter = 0;
    if (dataFile.is_open()) {
      while (counter<numberOfCountries){
        getline(dataFile, sLine);
        countries[counter] = sLine.substr(0, sLine.find(','));
        strToArr(
          sLine.substr(sLine.find(',')+1,sLine.length()-1),
          dataMatrix[counter],
          numberOfCountries
        );
        counter++;
      }
    }

    

    for (int j=0; j<numberOfCountries; j++){
      cout<<"Country: "<<countries[j];
      for (int k=0; k<numberOfCountries; k++){
        cout<<" "<<dataMatrix[j][k];
      }
      cout<<endl;
    }
    dataFile.close();
    return 0;
}
