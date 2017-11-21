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
#include <cmath>
#include <iomanip>
using namespace std;



 struct city
 {
	 int cityID;   		//City Identifier
	 double cityXCoord;	//City X Coordinate
	 double cityYCoord;	//City Y Coordinate
	 double distance;	//distance from start
	 
 };
 /*****************************************************************
 *checkTime() uses time() from the C++ std library to check curr time
 *it is passed in the start time of the program
 * if time exceeds 180 seconds, program will exit
  ******************************************************************/
 
 void checkTime(float start)
 {
	float currTime = time(0);
	float secondsElapsed = (currTime - start);
	//cout<<"In checkTime, seconds Elapsed is" <<setprecision(8)<<secondsElapsed<<endl;
	//cout<<"start is : "<<start<<endl;
	//cout<<"clock is: "<<currTime<<endl;
	
	if(secondsElapsed >= 180)
		{ 
			// 180 seconds elapsed -> leave main lopp 
			cout<<"Time limit exceeded.   Exiting program"<<endl;
			exit (0);
		}
		
	
 }
 
 /*****************************************************************
 *caluclateDistanceFromStart()  take the vector of cities 
 *calculates the distance from first point in the array as the origin
 * rounded to the nearest int
  ******************************************************************/
 int calculateDistanceFromStart(vector<city> &C, float start, int choice)
 {
	 int size = C.size();
	 double startX = C[0].cityXCoord;
	 double startY = C[0].cityYCoord;
	 
	 for (int i = 0; i < size; i++) 
		{
			if (choice ==1)
				checkTime(start);
			C[i].distance = sqrt((C[i].cityXCoord - startX)* (C[i].cityXCoord - startX) + (C[i].cityYCoord - startY) *(C[i].cityYCoord - startY));
			//cout<<"Distance from origin (not rounded) is: "<<C[i].distance<<endl;
			C[i].distance = round(C[i].distance);
			//cout<<"Distance from origin rounded is: "<<C[i].distance<<endl;
		}
 } 
  /*****************************************************************
 *sortByDisatnce() takes in the vector of cities
 *it conducts a merge sort of the distances from the first
 *entry in the vector 
 ******************************************************************/
 void sortByDistance(vector<city> &C, float start, int choice)	
 {
	 //placeholder to Merge Sort by distances calculated
 }
 /*****************************************************************
 *verifies the time from the start of the program running
 *if called, the start time is passed in
 *program exits if time exceeds 180 seconds 
 
 ******************************************************************/
 
 void nearestNeighbor(vector<city> &C, ofstream &outputFile, float start, int choice)
 {
	 
	 
		 
	 //run algorithm, each time checking for elapsed time by calling checkTime on start
	 	 
	 //and exiting if max time is exceeded by passing start to checkTime()
	 if(choice == 1)
		checkTime(start);
		
	 //place the algorithim's total length of the tour as first item in output file
	// int testCount = 500;
	// outputFile<< testCount;
	// outputFile << endl;
	 if(choice == 1)
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
			outputFile << " ";
			outputFile << C[i].distance;
			outputFile << endl;
			if (choice ==1)
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
	float start = time(0);

	cout<<setprecision(8)<<"start time is "<<start<<endl;
	
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
	//calculate nearest distance from first point in the list.
	 calculateDistanceFromStart(route, start, choice);
	 sortByDistance(route, start, choice);
	 nearestNeighbor(route, outputFile, start, choice);	//call stub for algorithm.
	 
	 return 0;
 }
