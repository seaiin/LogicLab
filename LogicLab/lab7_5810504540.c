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
		case ��� 1 test input �� -
		case ��� 2 test input �� +
		case ��� 3 test input �� �ӹǹ�ǡ����ҡ����ش
		case ��� 4 test input �� �ӹǹź����ҡ����ش (����դӵͺ���١��ͧ���Ф�Һǡ����ҡ����ش��� 0x7fffffff)
		case ��� 5,6 test input +0, -0
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
		case ��� 1, 2, 3, 4 test para �� 0 - 3
		case ��� 5, 6 test ��� +, -
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
		test ��� input �� +, - ��� para ��ҵ�ҧ�
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
		case ��� 1, 2, 4 test input ��ҷ����
		case ��� 3 test input ����� 1 �ҡ����ش
		case ��� 5 test input 0 ����� 1 �������
		case ��� 6 test input 1 �� 1 �������
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
		case ��� 1-6 test ��� input �ͧ Onecount ��觨���º����Ѵਹ
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
		�� case ���� return �繤�� 0x8000000 ���ź����բ�Ҵ�ҡ����ش ���դ�ҹ��·���ش
	*/
	printf("Test largestNeg\n\n");
	printf("largestNeg() = (%d) %x\n\n", largestNeg(), largestNeg());

	/* 
		Test isFitable Func.
		case ��� 1, 2 test input ������ fitable ����� input ��� +, -
		case ��� 3, 4 test input ��� fitable ����� input ��� +, -
		case ��� 5,6 test input ����� ����� +, -
		�ҡ test case ��ҧ�������Ҥ�ҷ�� fitable �����ҷ���繨ӹǹ��� ����դ����ҡѺ 2^n ��мŷ���������͹�ѹ��� +, -
		��� para = n+1
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
		test ��� +, - �ͧ��� 1,0 ��� ��� +, - ����ҡ����ش
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
		case ��� 	1, 2, 4 test ��� +, - �����
		case ��� 3 test ��� 0
		case ��� 5, 6 test ��� +, - ����ҡ����ش
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
		case ��� 1, 2 test ��� +, + ����ҡ���� ��� ���¡���
		case ��� 3, 6 test �����ҡѹ��� +, -
		case ��� 4, 5 test ��� -, - ����ҡ���� ��� ���¡���
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