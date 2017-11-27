/*
 File: bst.c
 Implementation of the binary search tree data structure.
 
 */
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
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


struct Node {
	TYPE         val;
	struct Node *left;
	struct Node *right;
};

struct BSTree {
	struct Node *root;
	int          cnt;
};

/*----------------------------------------------------------------------------*/
/*
 function to initialize the binary search tree.
 param tree
 pre: tree is not null
 post:	tree size is 0
		root is null
 */

void initBSTree(struct BSTree *tree)
{
	tree->cnt  = 0;
	tree->root = 0;
}

/*
 function to create a binary search tree.
 param: none
 pre: none
 post: tree->count = 0
		tree->root = 0;
 */

struct BSTree*  newBSTree()
{
	struct BSTree *tree = (struct BSTree *)malloc(sizeof(struct BSTree));
	assert(tree != 0);

	initBSTree(tree);
	return tree;
}

/*----------------------------------------------------------------------------*/
/*
function to free the nodes of a binary search tree
param: node  the root node of the tree to be freed
 pre: none
 post: node and all descendants are deallocated
*/

void _freeBST(struct Node *node)
{
	if (node != 0) {
		_freeBST(node->left);
		_freeBST(node->right);
		free(node);
	}
}

/*
 function to clear the nodes of a binary search tree
 param: tree    a binary search tree
 pre: tree ! = null
 post: the nodes of the tree are deallocated
		tree->root = 0;
		tree->cnt = 0
 */
void clearBSTree(struct BSTree *tree)
{
	_freeBST(tree->root);
	tree->root = 0;
	tree->cnt  = 0;
}

/*
 function to deallocate a dynamically allocated binary search tree
 param: tree   the binary search tree
 pre: tree != null;
 post: all nodes and the tree structure itself are deallocated.
 */
void deleteBSTree(struct BSTree *tree)
{
	clearBSTree(tree);
	free(tree);
}

/*----------------------------------------------------------------------------*/
/*
 function to determine if  a binary search tree is empty.

 param: tree    the binary search tree
 pre:  tree is not null
 */
int isEmptyBSTree(struct BSTree *tree) { return (tree->cnt == 0); }

/*
 function to determine the size of a binary search tree

param: tree    the binary search tree
pre:  tree is not null
*/
int sizeBSTree(struct BSTree *tree) { return tree->cnt; }

/*----------------------------------------------------------------------------*/
/*
 recursive helper function to add a node to the binary search tree.
 HINT: You have to use the compare() function to compare values.
 param:  cur	the current root node
		 val	the value to be added to the binary search tree
 pre:	val is not null
 */
struct Node *_addNode(struct Node *cur, struct city* val)
{
	struct Node* newNode;
	if (!cur) //if current node doesn't exist, make it
	{
		newNode = (struct Node*)malloc(sizeof(struct Node));
		assert(newNode != 0);
		newNode->val = val;
		newNode->left = newNode->right = 0;
		return newNode;
	}
	if (compare(val, (struct city*)cur->val) == -1) //if value is less than current node's value, go down left side, otherwise go down right
		cur->left = _addNode(cur->left, val);
	else
		cur->right = _addNode(cur->right, val);
	return cur;
}

/*
 function to add a value to the binary search tree
 param: tree   the binary search tree
		val		the value to be added to the tree

 pre:	tree is not null
		val is not null
 pose:  tree size increased by 1
		tree now contains the value, val
 */
void addBSTree(struct BSTree *tree, struct city* val)
{
	tree->root = _addNode(tree->root, val);
	tree->cnt++;
}


/*
 function to determine if the binary search tree contains a particular element
 HINT: You have to use the compare() function to compare values.
 param:	tree	the binary search tree
		val		the value to search for in the tree
 pre:	tree is not null
		val is not null
 post:	none
 */

/*----------------------------------------------------------------------------*/
int containsBSTree(struct BSTree *tree, struct city* val)
{
	struct Node* cur = tree->root;
	while (cur != 0) //keep going down until you find a null Node, then return 0 if not found, 1 if found
	{
		if (compare(val, (struct city*)cur->val) == 0)
			return 1;
		else if (compare(val, (struct city*)cur->val) == 1)
			cur = cur->right;
		else
			cur = cur->left;
	}
	return 0;
}

/*
 helper function to find the left most child of a node
 return the value of the left most child of cur
 param: cur		the current node
 pre:	cur is not null
 post: none
 */

/*----------------------------------------------------------------------------*/
TYPE _leftMost(struct Node *cur)
{
	while (cur->left != 0) //keep going down left side till you reach the end
	{
		cur = cur->left;
	}
	return cur->val;
}


/*
 recursive helper function to remove the left most child of a node
 HINT: this function returns cur if its left child is NOT NULL. Otherwise,
 it returns the right child of cur and free cur.

Note:  If you do this iteratively, the above hint does not apply.

 param: cur	the current node
 pre:	cur is not null
 post:	the left most node of cur is not in the tree
 */
/*----------------------------------------------------------------------------*/
struct Node *_removeLeftMost(struct Node *cur)
{
	struct Node* temp;
	if (cur->left == 0) //if you find the last node on the left side, remove it
	{
		temp = cur->right; //right node becomes new current node if it exists
		free(cur);
		cur = 0;
		return temp;
	}
	cur->left = _removeLeftMost(cur->left); //keep going down left
	return cur;
}
/*
 recursive helper function to remove a node from the tree
 HINT: You have to use the compare() function to compare values.
 param:	cur	the current node
		val	the value to be removed from the tree
 pre:	val is in the tree
		cur is not null
		val is not null
 */
/*----------------------------------------------------------------------------*/
struct Node *_removeNode(struct Node *cur, struct city* val)
{
	struct Node* temp;
	if (compare(val, (struct city*)cur->val) == 0) //if you find the node, remove it
	{
		if (cur->right != 0) //if it has a right node, replace it with the leftmost of the right side
		{
			cur->val = _leftMost(cur->right);
			cur->right = _removeLeftMost(cur->right);
		}
		else //otherwise replace it with the left side
		{
			temp = cur->left;
			free(cur);
			cur = 0;
			return temp;
		}
	}
	else if (compare(val, (struct city*)cur->val) == -1) //keep going down left or right looking for the node
		cur->left = _removeNode(cur->left, val);
	else
		cur->right = _removeNode(cur->right, val);
	return cur;
}
/*
 function to remove a value from the binary search tree
 param: tree   the binary search tree
		val		the value to be removed from the tree
 pre:	tree is not null
		val is not null
		val is in the tree
 pose:	tree size is reduced by 1
 */
void removeBSTree(struct BSTree *tree, struct city* val)
{
	if (containsBSTree(tree, val)) {
		tree->root = _removeNode(tree->root, val);
		tree->cnt--;
	}
}

void printNode(struct Node *cur) {
	if (cur == 0) return;
	printf("(");
	printNode(cur->left);
	/*Call print_type which prints the value of the TYPE*/
	print_type((struct city*)cur->val);
	printNode(cur->right);
	printf(")");
}

void printTree(struct BSTree *tree) {
	if (tree == 0) return;
	printNode(tree->root);
}

struct BSTree *buildBSTTree(vector<city> &theCity, int num) {

    struct BSTree *tree	= newBSTree();
	
		
	for(int i = 0;i<num;i++){
		struct city* tempCity = new city;
		*tempCity = theCity[i];
		addBSTree(tree, tempCity);
		delete tempCity;
	}
    
    return tree;
}
