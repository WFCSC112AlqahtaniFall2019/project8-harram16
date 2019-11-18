//
// Created by Addie Harrison on 11/13/19.
//
#include <iostream>
#ifndef PROJECT7_DATA_H
#define PROJECT7_DATA_H
using namespace std;

class Data {
public:
    Data();
    Data(string name, double median, double mean, string num);
    string companyName;
    double diffMedianHourlyPercent;
    double diffMeanHourlyPercent;
    string companyNumber;
    friend ostream& operator<<(ostream& os, const Data& data);
    friend bool operator>(const Data& d1, const Data& d2);
    friend bool operator<(const Data& d1, const Data& d2);
private:

    //bool operator>(Data d);
   // bool operator<(Data d);
};


#endif //PROJECT7_DATA_H
