#pragma once
//======================================================================================
//Header file for bots: initially cBotRandom is defined here, but other bot classes
//can go here too
//
//(c) Patrick Dickinson, University of Lincoln, School of Computer Science, 2020
//======================================================================================

#include "botbase.h"
#include <vector>

class cBotRandom : public cBotBase
{
	virtual void ChooseNextGridPosition();
};


class cDijkstra : public cBotBase
{
	public:
		bool closed[GRIDWIDTH][GRIDHEIGHT]; //whether or not location is closed
		float cost[GRIDWIDTH][GRIDHEIGHT]; //cost value for each location
		int linkX[GRIDWIDTH][GRIDHEIGHT]; //link X coord for each location
		int linkY[GRIDWIDTH][GRIDHEIGHT]; //link Y coord for each location
		bool inPath[GRIDWIDTH][GRIDHEIGHT]; //whether or not a location is in
		bool completed;

		cDijkstra() { completed = false; }
		
		virtual void ChooseNextGridPosition() ;

		virtual void Build(cBotBase& bot);
};

class cAStar : public cDijkstra
{
	public:
		virtual void Build(cBotBase& bot);
		virtual void ChooseNextGridPosition();
		std::vector <std::pair<int, int>> locationList;
		bool check;

		int currentIndex;

};

extern cDijkstra gDijkstra;
extern cAStar gAstar;