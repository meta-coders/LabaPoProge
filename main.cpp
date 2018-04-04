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

struct country{
  string name;
  int rating;
};

int max(int *arr, int amount){
  int index = 0;
  int max = arr[0];
  for (int i = 1; 1<amount; i++){
    if (max<arr[i]){
      max = arr[i];
      index = i;
    }
  }
  return index;
}

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

void fillRating(country *countriesTable, int **dataMatrix, int numberOfCountries){
  for (int i = 0; i < numberOfCountries; i++){
    for (int j = 0; j < numberOfCountries; j++){
      
    }
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

    country *countriesTable = new country[numberOfCountries];

    cout<<"Number of Countries: "<<stoi(numberOfCountriesstr)<<endl;
    int counter = 0;
    if (dataFile.is_open()) {
      while (counter<numberOfCountries){
        getline(dataFile, sLine);
        countriesTable[counter].name = sLine.substr(0, sLine.find(','));
        countriesTable[counter].rating = 0;
        strToArr(
          sLine.substr(sLine.find(',')+1,sLine.length()-1),
          dataMatrix[counter],
          numberOfCountries
        );
        counter++;
      }
    }



    for (int j=0; j<numberOfCountries; j++){
      cout<<"Country: "<<countriesTable[j].name;
      for (int k=0; k<numberOfCountries; k++){
        cout<<" "<<dataMatrix[j][k];
      }
      cout<<endl;
    }

    // country *countriesTable = new country[numberOfCountries];

    dataFile.close();



    return 0;
}
