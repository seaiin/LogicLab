#include <stdio.h>

int absVal(int x) {
	int signX = x >> 31;
	int temp = x ^ signX;
	return temp + (1 & signX);
}

int main() {

}