using namespace std;

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

struct Node {
	TYPE val;
	struct Node *left;
	struct Node *right;
};

struct BSTree {
	struct Node *root;
	int cnt;
	int threshold;
};