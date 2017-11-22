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
 
 int main(int argc, char* argv[])
 {
	//accept input from the command line
	char* inFileName = argv[1];
	//read from file using ifstream
	ifstream inputFile;		
	inputFile.open(inFileName);
	//write to file using ofstream
	ofstream outputFile;
	//file name is apended to .tour
	string outFileName = string(inFileName) + ".tour";
	//open file for writing
	outputFile.open(outFileName.c_str());
	//this is the vector to store all cities on the route
	vector <city> route;	
	//string to read the line
	//read untl the end of the file
		int cityValue;
		int xValue;
		int yValue;
		int i = 0;
	 while (inputFile >> cityValue)
	{

		//cout<<lineCount;
		//variable to hold city, x or y
		route.push_back(city());

		
		//read each value on the line and store in a vector called lineValues
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
		i++;
		
	}
	 nearestNeighbor(route, outputFile);	//call stub for algorithm.
	 
	 return 0;
 }
