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
	int mask = 1 << 31, temp = x;
	mask = mask >> para;
	mask = ~(mask << 1);
	temp = temp >> para;
	return temp & mask;
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
	int temp = x;
	temp = temp ^ (temp >> 16);
	temp = temp ^ (temp >> 8);
	temp = temp ^ (temp >> 4);
	temp = temp ^ (temp >> 2);
	temp = temp ^ (temp >> 1);
	temp = temp & 1;
	return temp;
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
	int input, para;

	/* 
		Test absVal Func.
		case ที่ 1 test input เป็น -
		case ที่ 2 test input เป็น +
		case ที่ 3 test input เป็น จำนวนบวกที่มากที่สุด
		case ที่ 4 test input เป็น จำนวนลบที่มากที่สุด (ไม่มีคำตอบที่ถูกต้องเพราะค่าบวกที่มากที่สุดคือ 0x7fffffff)
		case ที่ 5,6 test input +0, -0
	*/

	printf("Test absVal\n\n");
	input = -25;
	printf("absVal(%d) = %d\n", input, absVal(input));
	input = 25;
	printf("absVal(%d) = %d\n", input, absVal(input));
	input = 0x7fffffff;
	printf("absVal(%d) = %d\n", input, absVal(input));
	input = 0x80000000;
	printf("absVal(%d) = %d\n", input, absVal(input));
	input = 0;
	printf("absVal(%d) = %d\n", input, absVal(input));
	input = -0;
	printf("absVal(%d) = %d\n\n", input, absVal(input));

	/* 
		Test whatIsByte Func.
		case ที่ 1, 2, 3, 4 test para เป็น 0 - 3
		case ที่ 5, 6 test ค่า +, -
	*/

	printf("Test whatIsByte\n\n");
	input = 0xabcd5678, para = 0;
	printf("whatIsByte(%x, %d) = %x\n", input, para, whatIsByte(input, para));
	input = 0xabcd5678, para = 1;
	printf("whatIsByte(%x, %d) = %x\n", input, para, whatIsByte(input, para));
	input = 0xabcd5678, para = 2;
	printf("whatIsByte(%x, %d) = %x\n", input, para, whatIsByte(input, para));
	input = 0xabcd5678, para = 3;
	printf("whatIsByte(%x, %d) = %x\n", input, para, whatIsByte(input, para));
	input = 0x00001100, para = 1;
	printf("whatIsByte(%x, %d) = %x\n", input, para, whatIsByte(input, para));
	input = 0xff000000, para = 3;
	printf("whatIsByte(%x, %d) = %x\n\n", input, para, whatIsByte(input, para));

	/* 
		Test srlForced Func.
		test ค่า input เป็น +, - และ para ค่าต่างๆ
	*/

	printf("Test srlForced\n\n");
	input = 0x8765abcd, para = 4;
	printf("srlForce(%x, %d) = %x\n", input, para, srlForced(input, para));
	input = 0x8765abcd, para = 16;
	printf("srlForce(%x, %d) = %x\n", input, para, srlForced(input, para));
	input = 0xffffffff, para = 1;
	printf("srlForce(%x, %d) = %x\n", input, para, srlForced(input, para));
	input = 0x8765abcd, para = 0;
	printf("srlForce(%x, %d) = %x\n", input, para, srlForced(input, para));
	input = 0x8765abcd, para = 31;
	printf("srlForce(%x, %d) = %x\n", input, para, srlForced(input, para));
	input = 0x80000000, para = 16;
	printf("srlForce(%x, %d) = %x\n\n", input, para, srlForced(input, para));

	/*
		Test OneCount Func.
		case ที่ 1, 2, 4 test input ค่าทั่วไป
		case ที่ 3 test input ที่มี 1 มากที่สุด
		case ที่ 5 test input 0 ไม่มี 1 อยู่เลย
		case ที่ 6 test input 1 มี 1 ตัวเดียว
	*/
	printf("Test OneCount\n\n");
	input = 15;
	printf("OneCount(%d) = %d\n", input, oneCount(input));
	input = 9;
	printf("OneCount(%d) = %d\n", input, oneCount(input));
	input = 0xffffffff;
	printf("OneCount(%d) = %d\n", input, oneCount(input));
	input = 0x7f;
	printf("OneCount(%d) = %d\n", input, oneCount(input));
	input = 0;
	printf("OneCount(%d) = %d\n", input, oneCount(input));
	input = 1;
	printf("OneCount(%d) = %d\n\n", input, oneCount(input));

	/* 
		Test isNumOneOdd Func.
		case ที่ 1-6 test ตาม input ของ Onecount ซึ่งจะเทียบผลได้ชัดเจน
	*/

	printf("Test isNumOneOdd\n\n");
	input = 15;
	printf("isNumOneOdd(%x) = %d\n", input, isNumOneOdd(input));
	input = 9;
	printf("isNumOneOdd(%x) = %d\n", input, isNumOneOdd(input));
	input = 0xffffffff;
	printf("isNumOneOdd(%x) = %d\n", input, isNumOneOdd(input));
	input = 0x7f;
	printf("isNumOneOdd(%x) = %d\n", input, isNumOneOdd(input));
	input = 0;
	printf("isNumOneOdd(%x) = %d\n", input, isNumOneOdd(input));
	input = 1;
	printf("isNumOneOdd(%x) = %d\n\n", input, isNumOneOdd(input));

	/*
		Test largestNeg Func.
		มี case เดียว return เป็นค่า 0x8000000 ค่าลบที่มีขนาดมากที่สุด แต่มีค่าน้อยที่สุด
	*/
	printf("Test largestNeg\n\n");
	printf("largestNeg() = (%d) %x\n\n", largestNeg(), largestNeg());

	/* 
		Test isFitable Func.
		case ที่ 1, 2 test input ที่ไม่ fitable แต่ให้ input ทั้ง +, -
		case ที่ 3, 4 test input ที่ fitable แต่ให้ input ทั้ง +, -
		case ที่ 5,6 test input ทั่วไป ค่าเป็น +, -
		จาก test case ต่างๆจะเห็นว่าค่าที่ fitable มีแค่ค่าที่เป็นจำนวนคู่ ที่มีค่าเท่ากับ 2^n และผลที่ได้จะเหมือนกันทั้ง +, -
		และ para = n+1
	*/

	printf("Test isFitable\n\n");
	input = 5, para = 3;
	printf("isFitable(%d, %d) = %d\n", input, para, isFitable(input, para));
	input = -5, para = 3;
	printf("isFitable(%d, %d) = %d\n", input, para, isFitable(input, para));
	input = -4, para = 3;
	printf("isFitable(%d, %d) = %d\n", input, para, isFitable(input, para));
	input = 4, para = 3;
	printf("isFitable(%d, %d) = %d\n", input, para, isFitable(input, para));
	input = 32, para = 6;
	printf("isFitable(%d, %d) = %d\n", input, para, isFitable(input, para));
	input = -9, para = 4;
	printf("isFitable(%d, %d) = %d\n\n", input, para, isFitable(input, para));

	/* 
		Test oppNum Func.
		test ค่า +, - ของค่า 1,0 และ ค่า +, - ที่มากที่สุด
	*/

	printf("Test oopNum\n\n");
	input = 1;
	printf("oopNum(%d) = %d\n", input, oppNum(input));
	input = -1;
	printf("oopNum(%d) = %d\n", input, oppNum(input));
	input = 0;
	printf("oopNum(%d) = %d\n", input, oppNum(input));
	input = -0;
	printf("oopNum(%d) = %d\n", input, oppNum(input));
	input = 0x7fffffff;
	printf("oopNum(%d) = %d\n", input, oppNum(input));
	input = 0x80000000;
	printf("oopNum(%d) = %d\n\n", input, oppNum(input));

	/* 
		Test isGTZ Func.
		case ที่ 	1, 2, 4 test ค่า +, - ทั่วไป
		case ที่ 3 test ค่า 0
		case ที่ 5, 6 test ค่า +, - ที่มากที่สุด
	*/

	printf("Test isGTZ\n\n");
	input = -1;
	printf("isGTZ(%d) = %d\n", input, isGTZ(input));
	input = 1;
	printf("isGTZ(%d) = %d\n", input, isGTZ(input));
	input = 0;
	printf("isGTZ(%d) = %d\n", input, isGTZ(input));
	input = 7777777;
	printf("isGTZ(%d) = %d\n", input, isGTZ(input));
	input = 0x7fffffff;
	printf("isGTZ(%d) = %d\n", input, isGTZ(input));
	input = 0x80000000;
	printf("isGTZ(%d) = %d\n\n", input, isGTZ(input));

	/* 
		Test isLTE Func.
		case ที่ 1, 2 test ค่า +, + ที่มากกว่า และ น้อยกว่า
		case ที่ 3, 6 test ค่าเท่ากันทั้ง +, -
		case ที่ 4, 5 test ค่า -, - ที่มากกว่า และ น้อยกว่า
	*/
	printf("Test isLTE\n\n");
	input = 4, para = 5;
	printf("isLTE(%d, %d) = %d\n", input, para, isLTE(input, para));
	input = 5, para = 4;
	printf("isLTE(%d, %d) = %d\n", input, para, isLTE(input, para));
	input = 5, para = 5;
	printf("isLTE(%d, %d) = %d\n", input, para, isLTE(input, para));
	input = -4, para = -5;
	printf("isLTE(%d, %d) = %d\n", input, para, isLTE(input, para));
	input = -5, para = -4;
	printf("isLTE(%d, %d) = %d\n", input, para, isLTE(input, para));
	input = -4, para = -4;
	printf("isLTE(%d, %d) = %d\n\n", input, para, isLTE(input, para));
}