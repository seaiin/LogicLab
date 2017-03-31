#include <stdio.h>

int whatIsByte(int x, int para) {
	return (x >> (para << 3)) & 0xff;
}

int main() {

}