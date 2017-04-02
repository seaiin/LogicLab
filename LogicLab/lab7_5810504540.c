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
	int mask = (x >> 1) & ~(1 << 31);
	return mask >> para - 1;
}

int oneCount(int x) {
	int temp = x, mask = 1, count = 0, res = 0;
	mask = (mask << 8) + 1;
	mask = (mask << 8) + 1;
	mask = (mask << 8) + 1;
	count = count + (temp & mask);
	temp = temp >> 1;
	count = count + (temp & mask);
	temp = temp >> 1;
	count = count + (temp & mask);
	temp = temp >> 1;
	count = count + (temp & mask);
	temp = temp >> 1;
	count = count + (temp & mask);
	temp = temp >> 1;
	count = count + (temp & mask);
	temp = temp >> 1;
	count = count + (temp & mask);
	temp = temp >> 1;
	count = count + (temp & mask);
	temp = temp >> 1;
	res = res + (count & 0xff);
	count = count >> 8;
	res = res + (count & 0xff);
	count = count >> 8;
	res = res + (count & 0xff);
	count = count >> 8;
	res = res + (count & 0xff);
	return res;
}

int isNumOneOdd(unsigned x) {

}

int largestNeg() {
	return 1 << 31;
}

int isFitable(int x, int para) {
	int mask = ~(~0 << para), temp = ~x + 1;
	return !((x & mask) - (temp & mask));
}

int oppNum(int x) {
	return ~x + 1;
}

int isGTZ(int x) {
	int mask = 1 << 31;
	return !((x & mask) | !(0 ^ x));
}

int isLTE(int x, int y) {
	int result = y - x, mask = 1 << 31;
	return !(result & mask);
}

int main() {

}