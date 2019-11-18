#include <iostream>
#include <string>
#include <fstream>
#include "Data.h"
#include <queue>
#include<stack>

using namespace std;


int main() {

    Data deletePayGap;
    //container for stack and queue
    stack<Data> dataStack;
    queue<Data> dataQueue;
    priority_queue<Data> pQ;

    ifstream inFile;
    ofstream outFileStack;
    ofstream outFileQueue;
    ofstream outFileSortedLinkedList;

    //opening files
    inFile.open("../GenderGap.csv");
    outFileStack.open("Stack.txt");
    outFileQueue.open("Queue.txt");
    outFileSortedLinkedList.open("SortedLinkedList");

    //making sure all of the files are opened
    if(!inFile.is_open()){
        cout<<"Gender Pay Gap File did not open.";
    }
    if(!outFileStack.is_open()){
        cout<<"Stack file did not open.";
    }
    if(!outFileQueue.is_open()){
        cout<<"Queue file did not open.";
    }
    if(!outFileSortedLinkedList.is_open()){
        cout<<"Sorted Linked List file did not open.";
    }

    int i=0;
    while(!inFile.eof()){

        string name,meanString, medianString,numberString;
        getline(inFile,name, ',');
        getline(inFile,numberString,',');
        getline(inFile,meanString, ',');
        getline(inFile,medianString, '\n');


        //cout << "mean " << meanString << endl;
        double mean=stod(meanString);
        //cout << "median " << medianString << endl;
        double median=stod(medianString);

        Data payGap=Data(name, median, mean, numberString);

        //pushes Data member onto stack and queue
        dataStack.push(payGap);
        dataQueue.push(payGap);
        pQ.push(payGap);

        deletePayGap=payGap;
        i++;
    }

    //having the list print into the 3 output files
    while(!pQ.empty()){
        outFileSortedLinkedList<<pQ.top();
        pQ.pop();
    }
    while(!dataStack.empty()){
        outFileStack<<dataStack.top();
        dataStack.pop();
    }
    while(!dataQueue.empty()){
        outFileQueue<<dataQueue.front();
        dataQueue.pop();
    }



    //closing files
    inFile.close();
    outFileStack.close();
    outFileQueue.close();
    outFileSortedLinkedList.close();
    return 0;

}
