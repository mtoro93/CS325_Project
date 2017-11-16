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
	 
	 cout<<"I'm in nearest neighbor"<<endl;
		 
	 //run algorithm
	 
	 //place in outputFile by looping through vector 
	 
	 
 }
 
 int main()
 {
	 cout<<"I'm in  main"<<endl;
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
	cout<<"outputFileName is " <<outFileName<<endl;
	//this is the vector to store all cities on the route
	vector <city> route;		
	
	 
	 

	 nearestNeighbor(route, outputFile);	//call stub for algorithm.
	 
	 return 0;
 }