#include <stdio.h>

struct Point{
	int x, y;
};
void print(struct Point p){
	printf("Point: %d, %d\n", p.x, p.y);
}
struct Point reverse(struct Point p){
	struct Point newP;
	newP.x = -p.x;
	newP.y = -p.y;
	return newP;
}

int main(){
	struct Point p1, p2;
	p1.x=5, p1.y=9;
	p2 = reverse(p1);
	print(p1)	;
	print(p2)	;
	printf("Size of integer: %d\n", sizeof(int));
	printf("Size of Point: %d\n", sizeof(struct Point));
	return 0;
}

