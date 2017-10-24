#include "Grid.h"

FGrid::FGrid(int32 width, int32 length) {
	grid.resize(length, std::vector<ETileType>(width, EMPTY));
}

bool FGrid::SetTile(int32 x, int32 y, ETileType type) {
	if (grid[y][x] != EMPTY) return false;
	grid[y][x] = type;
	return true;
}

TArray<FCoord> FGrid::GetAllPosOfType(ETileType type) {
	TArray<FCoord> pos;
	for (int x = 0; x < grid.at(0).size(); x++)
		for (int y = 0; y < grid.size(); y++)
			if (grid[y][x] == type)
				pos.Add(FCoord(x, y));
	return pos;
}