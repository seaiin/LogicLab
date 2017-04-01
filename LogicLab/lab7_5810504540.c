#include <stdio.h>


int absVal(int x) {
	int signX = x >> 31;
	int temp = x ^ signX;
	return temp + (1 & signX);
}


int whatIsByte(int x, int para) {
	return (x >> (para << 3)) & 0xff;
}

int srlForced(int x, int para) {
	int temp = x >> para;
	return temp & (0x7FFFFFFF >> (para-1));
}

int main() {
	int input = 0x8765abcd, pr = 3;
	printf("%x : %x\n", input, srlForced(input, pr));
}