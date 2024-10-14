#include <iostream>
#include<vector>
#include<cmath>
using namespace std;
pair<int, int>pacmanPosition = { 7,5 };

int hueristicPill(int state[11][20]) {
	int numberOfPills = 0;
	for (int i = 0; i <   11; ++i) {
		for (int j = 0; j < 20; ++j)
			if (state[i][j] == 2)
				numberOfPills++;
	}
	return numberOfPills;
}

void detectGhost(vector<pair<int, int>>& ghosts, int state[11][20]) {
	for (int i = 0; i < 11; ++i) {
		for (int j = 0; j < 20; ++j) {
			if (state[i][j] == 3)
				ghosts.push_back({ i,j });
		}
	}
}

int hueristicGhost(int state[11][20]) {
	vector<pair<int, int>> ghostPosition;
	detectGhost(ghostPosition,state);
	int minDistance = INT_MAX;
	double distance;
	for (int i = 0; i < ghostPosition.size(); ++i) {
		distance = sqrt(pow(pacmanPosition.first - ghostPosition[i].first,2) + pow(pacmanPosition.second - ghostPosition[i].second,2));
		if (distance < minDistance)
			minDistance = (int)distance;
	}
	return minDistance;
	return 0;
}
int pacmanHueristicValue(int state[11][20]) {
	int hueristicValue;
	int pill, ghost;
	pill = hueristicPill(state);
	ghost = hueristicGhost(state);

	hueristicValue = 23 - ghost + pill;//23 is the max distance from a ghost and pacman
	return hueristicValue;
}

int main() {
	int state[11][20] = {
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,3},
	{1,0,1,0,1,0,0,0,0,0,0,0,0,0,0,1,1,0,0,1},
	{1,0,1,1,0,1,0,1,1,1,1,1,1,0,1,0,1,1,0,3},
	{1,0,1,2,0,0,0,2,2,2,2,2,2,0,2,0,0,1,0,1},
	{1,0,1,2,1,1,2,1,1,1,0,1,1,0,1,1,0,1,0,1},
	{1,0,2,2,2,2,2,1,0,0,0,0,1,0,0,0,0,0,0,1},
	{1,0,1,2,1,1,2,1,1,1,1,1,1,2,1,1,0,1,2,1},
	{1,0,1,2,0,4,2,2,2,2,2,2,2,0,0,0,0,1,2,1},
	{1,0,1,1,0,1,2,1,1,1,1,1,1,0,1,2,1,1,2,1},
	{1,0,0,0,0,1,2,2,2,0,0,0,0,0,1,2,2,2,2,1},
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
	};
	cout << pacmanHueristicValue(state);
}