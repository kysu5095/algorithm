
#pragma once
#include <iostream> 
#include <queue>     // for priority queue
#include <vector>    // for save path
#include <algorithm> // for use min function
#include <limits.h>  // for use MAX
#include <string.h> 
#include <random>    // for create random map
#include <time.h>    // for checking execute time

using namespace std;

int graphSize, generatedNode, boundCnt, minDistance;
double boundTime;
int** map;
int** dp;

class Node {
public:
	int level;
	int bound;
	int visited;
	vector<int> path;
	/* operator overloading */
	bool operator < (const Node& node) const {
		if (bound <= node.bound) return false;
		else return true;
	}
};

/* create different graphs using user input */
void createRandomMap();
/* execute best search first version */
void bestFirstSearch(int num);
/* start best first search */
void salesPerson(priority_queue<Node>& pq, int minLength, int flag);
/* get lower bound - text book version- */
int getLowerBound_textbookVersion(vector<int>& path, int level);
/* get lower bound - my own version - */
int getLowerBound_myOwnVersion(vector<int>& path, int index, int visited);
/* get path length */
int getLength(vector<int>& path);

