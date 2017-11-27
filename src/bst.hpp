#include <vector>
using namespace std;

/*
  File: bst.h
  Interface definition of the binary search tree data structure.
*/

#ifndef __BST_H
#define __BST_H
#endif

/* Defines the type to be stored in the data structure.  These macros
 * are for convenience to avoid having to search and replace/dup code
 * when you want to build a structure of doubles as opposed to ints
 * for example.
 */

# ifndef TYPE
# define TYPE      void*
# endif


typedef struct city city;

struct city
{
	int cityID;   		//City Identifier
	int cityXCoord;	//City X Coordinate
	int cityYCoord;	//City Y Coordinate
	bool visited;		// whether the city has been visited in the path yet
	city* closestNeighbor;	// pointer to a city's nearest neighbor
	long long int distanceToNeighbor; // distance to the city's nearest neighbor
};




struct BSTree;
/* Declared in the c source file to hide the structure members from the user. */

/* Initialize binary search tree structure. */
void initBSTree(struct BSTree *tree);

/* Alocate and initialize search tree structure. */
struct BSTree *newBSTree();

/* Deallocate nodes in BST. */
void clearBSTree(struct BSTree *tree);

/* Deallocate nodes in BST and deallocate the BST structure. */
void deleteBSTree(struct BSTree *tree);

/*-- BST Bag interface --*/
int  isEmptyBSTree(struct BSTree *tree);
int     sizeBSTree(struct BSTree *tree);

void     addBSTree(struct BSTree *tree, TYPE val);
int containsBSTree(struct BSTree *tree, TYPE val);
void  removeBSTree(struct BSTree *tree, TYPE val);
void printTree(struct BSTree *tree);
struct BSTree* buildBSTTree(vector <city> &acity, int thenum);
