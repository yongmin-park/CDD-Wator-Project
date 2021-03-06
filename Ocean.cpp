/*
	Authors: Adam Eaton, Yongmin Park
*/
#include "Ocean.h"

//Creating an animal at the provided location
//and setting it's associated properties
void Ocean::create_animal(int t, int x, int y) {
	type = t;
	pos_x = x;
	pos_y = y;
	
	age = 0;
	starve = 0;
	moved = 0;
	turn = 0;
}

//In the event that a fish or shark reaches the edge of the world
//their position is moved to the opposed side, effectively wrapping
//the game world to one continious area.
void Ocean::wrap_ocean(int pos_x, int pos_y, int pos_a, int pos_b, int pos_c, int pos_d, int rows, int columns) {
	pos_a = pos_x - 1;
	pos_b = pos_y - 1;
	pos_c = pos_x + 1;
	pos_d = pos_y + 1;

	if (pos_a < 0) {
		pos_a = rows - 1;
	}
	if (pos_b < 0) {
		pos_b = columns - 1;
	}

	if (pos_a > rows - 1) {
		pos_a = 0;
	}
	if (pos_b > columns - 1) {
		pos_b = 0;
	}
}

//Displaying Animals
// . : Denotes an empty area of ocean
// F : Denotes a fish
// S : Denotes a shark
char Ocean::show_animal() {
	if (type == 0) {
		return '.';
	}
	if (type == 1) {
		return 'F';
	}
	if (type == 2) {
		return 'S';
	}
}
