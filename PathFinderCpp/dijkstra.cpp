#include <iostream>
#include "stdlib.h"
#include "bots.h"


void cDijkstra::Build(cBotBase& bot)
{
	int savedY; //Saves the y position of the tile we are searching for
	int savedX; //Saves the x position of the tile we are searching for
	
	float savedDirectionCost;
	bool loop = false;
	for (int i = 0; i < GRIDWIDTH; i++)
	{
		for (int j = 0; j < GRIDHEIGHT; j++)
		{
			closed[i][j] = false;
			cost[i][j] = 1000000.0f;
			linkX[i][j] = -1;
			linkY[i][j] = -1;
			inPath[i][j] = false;
		}
	}

	cost[bot.PositionX()][bot.PositionY()] = 0;

	//Searching
	while (!loop)
	{
		int starterCost = 1000000;
		for (int i = 0; i < GRIDWIDTH; i++)
		{
			for (int j = 0; j < GRIDHEIGHT; j++)
			{
				if (cost[i][j] < starterCost && closed[i][j] == false)
				{
					savedX = i;
					savedY = j;
					starterCost = cost[i][j];
				}
			}
		}
		
		closed[savedX][savedY] = true;

		for (int i = -1; i < 2; i++)
		{
			for (int j = -1; j < 2; j++)
			{
				if (gLevel.isValid(savedX + i, savedY + j) == true && closed[savedX + i][savedY + j] == false)
				{
					if (i == 0 && j == 0)
					{
						continue;
					}
					else if (i == 0 || j == 0)
					{
						savedDirectionCost = 1;

					}
					else
					{
						savedDirectionCost = 1.4;
					}

					if (cost[savedX + i][savedY + j] > cost[savedX][savedY] + savedDirectionCost)
					{
						cost[savedX + i][savedY + j] = cost[savedX][savedY] + savedDirectionCost;
						linkX[savedX + i][savedY + j] = savedX;
						linkY[savedX + i][savedY + j] = savedY;
					}
				}
			}
		}


		
		if (savedX == gTarget.PositionX() && savedY == gTarget.PositionY())
		{
			loop = true;
		}

	}

	bool done = false;
	int nextClosedX = gTarget.PositionX();
	int nextClosedY = gTarget.PositionY();

	while (!done)
	{
		inPath[nextClosedX][nextClosedY] = true;
		int tempX = nextClosedX;
		int tempY = nextClosedY;
		nextClosedX = linkX[tempX][tempY];
		nextClosedY = linkY[tempX][tempY];
		if ((nextClosedX == bot.PositionX()) && (nextClosedY == bot.PositionY()))
		{
			done = true;
		}
	}

	completed = true;
}
void cDijkstra::ChooseNextGridPosition()
{
}

void cAStar::Build(cBotBase& bot)
{
	int savedY; //Saves the y position of the tile we are searching for
	int savedX; //Saves the x position of the tile we are searching for

	float savedDirectionCost;
	bool loop = false;
	for (int i = 0; i < GRIDWIDTH; i++)
	{
		for (int j = 0; j < GRIDHEIGHT; j++)
		{
			closed[i][j] = false;
			cost[i][j] = 1000000.0f;
			linkX[i][j] = -1;
			linkY[i][j] = -1;
			inPath[i][j] = false;
		}
	}

	cost[bot.PositionX()][bot.PositionY()] = 0;

	//Searching
	while (!loop)
	{
		int starterCost = 1000000;
		for (int i = 0; i < GRIDWIDTH; i++)
		{
			for (int j = 0; j < GRIDHEIGHT; j++)
			{
				float heuristic = fabs(gTarget.PositionX() - i) + fabs(gTarget.PositionY() - j);
				if (cost[i][j] + heuristic < starterCost && closed[i][j] == false)
				{
					savedX = i;
					savedY = j;
					starterCost = cost[i][j] + heuristic;
				}
			}
		}

		closed[savedX][savedY] = true;

		for (int i = -1; i < 2; i++)
		{
			for (int j = -1; j < 2; j++)
			{
				if (gLevel.isValid(savedX + i, savedY + j) == true && closed[savedX + i][savedY + j] == false)
				{
					if (i == 0 && j == 0)
					{
						continue;
					}
					else if (i == 0 || j == 0)
					{
						savedDirectionCost = 1;

					}
					else
					{
						savedDirectionCost = 1.4;
					}

					if (cost[savedX + i][savedY + j] > cost[savedX][savedY] + savedDirectionCost)
					{
						cost[savedX + i][savedY + j] = cost[savedX][savedY] + savedDirectionCost;
						linkX[savedX + i][savedY + j] = savedX;
						linkY[savedX + i][savedY + j] = savedY;
					}
				}
			}
		}



		if (savedX == gTarget.PositionX() && savedY == gTarget.PositionY())
		{
			loop = true;
		}

	}
	check = false;
	locationList.clear();
	bool done = false;
	int nextClosedX = gTarget.PositionX();
	int nextClosedY = gTarget.PositionY();
	
	while (!done)
	{
		inPath[nextClosedX][nextClosedY] = true;
		int tempX = nextClosedX;
		int tempY = nextClosedY;
		locationList.push_back(std::make_pair(tempX, tempY));
		nextClosedX = linkX[tempX][tempY];
		nextClosedY = linkY[tempX][tempY];
		if ((nextClosedX == bot.PositionX()) && (nextClosedY == bot.PositionY()))
		{
			done = true;
		}
	}

	completed = true;
}

void cAStar::ChooseNextGridPosition()
{
	if (gAstar.locationList.empty() == false && !gAstar.check)
	{
		gAstar.currentIndex = gAstar.locationList.size();
		gAstar.check = true;
	}

	if (gAstar.locationList.empty() == false && gAstar.currentIndex > 0)
	{
		gAstar.currentIndex -= 1; 
		SetNext(gAstar.locationList[gAstar.currentIndex].first, gAstar.locationList[gAstar.currentIndex].second, gLevel);
	}
}

cDijkstra gDijkstra;
cAStar gAstar;