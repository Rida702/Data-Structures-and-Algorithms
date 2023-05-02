#include <stdio.h>

struct Point{
	int x, y;
};

int main(){
	struct Point p1, p2;
	p1.x=5, p1.y=9;
	p2.x=7, p2.y=-6;
	printf("Point 1: %d, %d\n", p1.x, p1.y);
	printf("Point 2: %d, %d\n", p2.x, p2.y);
	return 0;
}

