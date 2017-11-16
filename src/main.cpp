/*************************************************
 *CS325 Project Group 30
 *Amy Weller, Joseph Valencia, Matthew Toro 
 *Nearest Neighbor Greedy Algorithm
 *to solve travelling salesmen problem
 *Inputs:  Set of points
 *Outputs:  Shortest Hamiltonian Cycle
 *
 ***************************************************/
#include <iostream>
#include <fstream>
#include <vector>
#include <stdio.h>
#include <string>
#include <cstdlib>
#include <cstddef>
#include<stdlib.h>
#include <sstream>
#include <ctime>
using namespace std;

 struct city
 {
	 int cityID;   		//City Identifier
	 int cityXCoord;	//City X Coordinate
	 int cityYCoord;	//City Y Coordinate
	 
 };
 
 void nearestNeighbor(vector<city> &C, ofstream &outputFile)
 {
	 
	 
		 
	 //run algorithm
	 //place the algorithim's trip count into the first line of out file
	 int testCount = 500;
	 outputFile<< testCount;
	 outputFile << endl;
	 
	 
	 //place in outputFile by looping through vector 
	 int size = C.size();
	 	for (int i = 0; i < size; i++) 
		{
			outputFile << C[i].cityID;
			outputFile << " ";
			outputFile << C[i].cityXCoord;
			outputFile << " ";
			outputFile << C[i].cityYCoord;
			outputFile << endl;
			
		}
		outputFile.close();
	 
 }
 
 int main()
 {
	 
	//read from file using ifstream
	ifstream inputFile;		
	//get file name from user
	cout<<"please enter the name of the input file."<<endl;
	string inFileName;
	cin>> inFileName;
	inputFile.open(inFileName.c_str());
	//write to file using ofstream
	ofstream outputFile;
	//file name is change.txt
	string outFileName = inFileName + ".tour";
	//open file for writing
	outputFile.open(outFileName.c_str());
	//cout<<"outputFileName is " <<outFileName<<endl;
	//this is the vector to store all cities on the route
	vector <city> route;	
	//string to read the line
	string line;
	//number of lines in the file
	int lineCount = 0;
	//variable to hold city, x or y
	//int cityValue;
	//int xValue;
	//int yValue;
	vector <int> lineValues;
	//read untl the end of the file
	 while (!inputFile.eof())
	{
		
		//read each line to get the line count 
		while(getline(inputFile, line))
		{
			lineCount ++;
		}
		//cout<<lineCount;
		//variable to hold city, x or y
		int cityValue;
		int xValue;
		int yValue;
		for (int i = 0; i < lineCount; i++) 
		{
			route.push_back(city());
			//getline(inputFile, line);
			//stringstream lineStream(line);
			//read each value on the line and store in a vector called lineValues
			inputFile >> cityValue;
			inputFile >> xValue;
			inputFile >> yValue;
			
			cout<<cityValue<<" ";
			cout<<xValue<<" ";
			cout<<yValue<<endl;
			
			route[i].cityID = cityValue;
			route[i].cityXCoord = xValue;
			route[i].cityYCoord = yValue;
			//cout<<route[i].cityID << " ";
			//cout<<route[i].cityXCoord << " ";
			//cout<<route[i].cityYCoord<<endl;
		}
	}
	 nearestNeighbor(route, outputFile);	//call stub for algorithm.
	 
	 return 0;
 }
