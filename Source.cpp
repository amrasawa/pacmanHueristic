#include <iostream>
#include<vector>
#include<pair>
using namespace std; 

int pacmanHueristicValue(int state[11][20]) {
	int hueristicValue;
	int huerisitcPill, hueristicGhost;
	
	return hueristicValue;
}

int hueristicPill(int state[11][20]) {
	int numberOfPills = 0;
	for (int i = 0; i < 11; ++i) {
		for (int j = 0; j < 20; ++j)
			if (state[i][j] == 2)
				numberOfPills++;
	}
	return numberOfPills;
}

int hueristicGhost(int state[11][20]) {
	vector<pair<int, int>> ghostPosition;
	detectGhost(ghostPosition);
}

void detectGhost(vector<pair<int, int>>& ghosts, int state[11][20]) {
	for (int i = 0; i < 11; ++i) {
		for (int j = 0; j < 20; ++j) {
			if (state[i][j] == 3)
				ghosts.push_back({ i,j });
		}
	}
}
int main() {

}