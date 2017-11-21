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
#include <chrono>

using namespace std;



 struct city
 {
	 int cityID;   		//City Identifier
	 int cityXCoord;	//City X Coordinate
	 int cityYCoord;	//City Y Coordinate
	 
 };
 
 int checkTime(int start)
 {
	
	double secondsElapsed = (clock() - start) /(double) CLOCKS_PER_SEC;
	cout<<"In checkTime, seconds Elapsed is" <<secondsElapsed<<endl;
	if(secondsElapsed >= 180)
		{ 
			// 180 seconds elapsed -> leave main lopp 
			cout<<"Time limit exceeded.   Exiting program"<<endl;
			exit (0);
		}
		
	
 }
 
 void nearestNeighborLimited(vector<city> &C, ofstream &outputFile, int start)
 {
	 
	 
		 
	 //run algorithm, each time checking for elapsed time by calling checkTime on start
	 //and exiting if max time is exceeded by passing start to checkTime()
	 checkTime(start);
		
	 //place the algorithim's trip count into the first line of out file
	 int testCount = 500;
	 outputFile<< testCount;
	 outputFile << endl;
	 checkTime(start);
	 
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
			checkTime(start);
			
		}
		outputFile.close();
	 
 }
 
 int main()
 {
	  //integer set for menu selection  
	 int choice = 0;
	 cout<<"Please select from the following options: "<<endl<<endl;
	 cout<<"For competition mode with max of 180 seconds press 1 and Enter. "<<endl<<endl;
	 cout<<"For unlilmited mode with no maximum time limit set, press 2 and Enter. "<<endl;
	 cin>>choice;
	//variable for start time to track count up to 180 seconds
	clock_t start;
	start = clock();
	cout<<"start time is "<<start<<endl;
	
	//read from file using ifstream
	ifstream inputFile;		
	//get file name from user
	cout<<"please enter the name of the input file."<<endl;
	string inFileName;
	cin>> inFileName;
	inputFile.open(inFileName.c_str());
	//write to file using ofstream
	ofstream outputFile;
	//file name is apended to .tour
	string outFileName = inFileName + ".tour";
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
		
		//cout<<cityValue<<" ";
		//cout<<xValue<<" ";
		//cout<<yValue<<endl;
		
		route[i].cityID = cityValue;
		route[i].cityXCoord = xValue;
		route[i].cityYCoord = yValue;
		//cout<<route[i].cityID << " ";
		//cout<<route[i].cityXCoord << " ";
		//cout<<route[i].cityYCoord<<endl;
		i++;
		
	}
	 nearestNeighborLimited(route, outputFile, start);	//call stub for algorithm.
	 
	 return 0;
 }
