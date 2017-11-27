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
#include <stdio.h>
#include <string>
#include <cstdlib>
#include <cstddef>
#include <stdlib.h>
#include <sstream>
#include <ctime>
#include <cmath>
#include <climits>
#include "bst.hpp"
#include "compare.hpp"



 /*****************************************************************
 *checkTime() uses time() from the C++ std library to check curr time
 *it is passed in the start time of the program
 * if time exceeds 180 seconds, program will exit
  ******************************************************************/
 
 void checkTime(long long int start)
 {
	long long int currTime = time(0);
	long long int secondsElapsed = (currTime - start);
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

/*******************************************************************
*distance() takes in a pointer to two city structs and calculates
*the distance between their x and y coordinates.
*
*******************************************************************/
 
  long long int distance(city* c1, city* c2)
 {
	  long long int xDistance = pow(c1->cityXCoord - c2->cityXCoord, 2);
	  long long int yDistance = pow(c1->cityYCoord - c2->cityYCoord, 2);
	 return  (long long int) round(sqrt(xDistance + yDistance));
 }

/*******************************************************************
*nearestNeighbor() takes input of a vector of cities and an ofstream 
*it will call distance to calculate the nearest neighbor to the
*current city, mark it as visited and then move on to the
*nearest neighbor, repeating until the entire route is complete
*It will then write to the ofstream object the total length of the tour
* and then print all the city ID's in the order they were visited
*******************************************************************/
 
 void nearestNeighbor(vector<city> &C, ofstream &outputFile, float start)
 {	 
	 //run algorithm, be sure to call checkTime frequently.
	 city* cur = &C[0];
	 cur->visited = true;
	 
	 long long int tour = 0;
	 for (int i = 0; i < C.size(); i++)
	 {
		int index;
		long long int min = LLONG_MAX;
		for (int k = 0; k < C.size(); k++)
		{
			if (cur->cityID != C[k].cityID && C[k].visited != true)
			{
				long long int temp = distance(cur, &C[k]);
				if  (temp < min)
				{
					min = temp;
					cur->closestNeighbor = &C[k];
					cur->distanceToNeighbor = min;
					index = k;
				}
			}
		}
		tour+=cur->distanceToNeighbor;
		cur = &C[index];
		cur->visited = true;
	 }
	
	// complete the circuit routing the last city back to the first
	cur->distanceToNeighbor = distance(cur, &C[0]);
	tour+=cur->distanceToNeighbor;
	cur->closestNeighbor = &C[0];
	
	//printf("tour length: %d\n", tour);
	 
	//place the algorithim's trip count into the first line of out file
	outputFile << tour;
	outputFile << endl;
	 
	cur = &C[0];
	for (int j = 0; j < C.size(); j++)
	{
		outputFile << cur->cityID;
		outputFile << endl;
		cur = cur->closestNeighbor;
	}
	 
	 /*
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
		*/
		outputFile.close();
	 
 }
 
 int main(int argc, char* argv[])
 {
	//accept input from the command line
	char* inFileName = argv[1];
	
	//variable for start time to track count up to 180 seconds
	long long int start = time(0);
	cout<<"Start time is "<<start<<endl;
	//cout<<setprecision(8)<<"start time is "<<start<<endl;
	
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
		
		//cout<<cityValue<<" ";
		//cout<<xValue<<" ";
		//cout<<yValue<<endl;
		
		route[i].cityID = cityValue;
		route[i].cityXCoord = xValue;
		route[i].cityYCoord = yValue;
		route[i].visited = false;
		//cout<<route[i].cityID << " ";
		//cout<<route[i].cityXCoord << " ";
		//cout<<route[i].cityYCoord<<endl;
		i++;
	}
	 struct BSTree* myTree = buildBSTTree(route, i);
	 printTree(myTree);
	//nearestNeighbor(route, outputFile, start);	//call stub for algorithm.
	 long long int finish = time(0);
	 cout<<"Finish time is "<<finish<<endl;
	 long long int dur = finish - start;
	 cout<<"Duration  is "<<dur<<endl;
	return 0;
 }
