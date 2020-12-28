
//#ifndef __EINSTEINPROBLEM__
//#define __EINSTEINPROBLEM__
#pragma once
#include <iostream>
#include <limits.h>
#include <string.h>
#include <iomanip>
#define  SIZE 5

using namespace std;

class House {
private:
	int color;
	int nation;
	int beverage;
	int cigar;
	int pet;

public:
	House() {
		color    = INT_MAX;
		nation   = INT_MAX;
		beverage = INT_MAX;
		cigar    = INT_MAX;
		pet      = INT_MAX;
	}
	void set(int row, int value);
	int  get(int row);
};
House house[SIZE];

enum Kind     { COLOR, NATION, BEVERAGE, CIGAR, PET };
enum Color    { BLUE, GREEN, RED, WHITE, YELLOW };
enum Nation   { BRIT, DANE, GERMAN, NORWEGIAN, SWEDE };
enum Beverage { BEER, COFFEE, MILK, TEA, WATER };
enum Cigar    { BLUE_MASTER, DUNHILL, PALL_MALL, PRINCE, BLEND };
enum Pet      { CAT, BIRD, DOG, FISH, HORSE };

bool used[5][5];

void execute();
void backtracking(const int row, const int col, const int pre_row, const int pre_col);
bool promising(const int row, const int col);
void print(const int row, const int col);
//#endif // !__EINSTEINPROBLEM__

