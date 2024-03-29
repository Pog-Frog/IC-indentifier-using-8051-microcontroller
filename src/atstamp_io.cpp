// Checks status of push button connected to P2.0  (active low)
// When pushed, LED connected to P1.0 flashes five times
#include "ATSTAMP.h"
#include <stdio.h>
#include <conio.h>
#include <windows.h>

char* ic_name = "";
char ic_recognized = 0;

void test_74125() {
	// TRI-STATE Quad Buffers
	// Gate 01: Control = P1^0, Input = P1^1, Output = P1^2.
	// Gate 02: Control = P1^3, Input = P1^4, Output = P1^5.
	// Gate 03: Control = P2^2, Input = P2^1, Output = P2^0.
	// Gate 04: Control = P2^5, Input = P2^4, Output = P2^3.

	ic_recognized = 1;

	//---------------Gate 01---------------

	// Test 01
	clr(P1, 0); setb(P1, 1);
	if(!GetBit(P1, 2)) ic_recognized = 0;

	// Test 02
	clr(P1, 0); clr(P1, 1);
	if(GetBit(P1, 2)) ic_recognized = 0;

	//---------------Gate 02---------------

	// Test 01
	clr(P1, 3); setb(P1, 4);
	if(!GetBit(P1, 5)) ic_recognized = 0;

	// Test 02
	clr(P1, 3); clr(P1, 4);
	if(GetBit(P1, 5)) ic_recognized = 0;

	//---------------Gate 03---------------

	// Test 01
	clr(P2, 2); setb(P2, 1);
	if(!GetBit(P2, 0)) ic_recognized = 0;

	// Test 02
	clr(P2, 2); clr(P2, 1);
	if(GetBit(P2, 0)) ic_recognized = 0;

	//-----------------End-----------------

	if(ic_recognized) ic_name = "74125";
}

void test_7486() {
	// Quad 2-Input Exclusive Or Gate
    // Gate 01: input 01 = P1^0, input 02 = P1^1, output = P1^2.
	// Gate 02: input 01 = P1^3, input 02 = P1^4, output = P1^5.
	// Gate 03: input 01 = P2^5, input 02 = P2^4, output = P2^3.
	// Gate 04: input 01 = P2^2, input 02 = P2^1, output = P2^0.

	ic_recognized = 1;

	//---------------Gate 01---------------

	// Test 01
	setb(P1, 0); setb(P1, 1);
	if(GetBit(P1, 2)) ic_recognized = 0;

	// Test 02
	setb(P1, 0); clr(P1, 1);
	if(!GetBit(P1, 2)) ic_recognized = 0;

	// Test 03
	clr(P1, 0); setb(P1, 1);
	if(!GetBit(P1, 2)) ic_recognized = 0;

	// Test 04
	clr(P1, 0); clr(P1, 1);
	if(GetBit(P1, 2)) ic_recognized = 0;

	//---------------Gate 02---------------

	// Test 01
	setb(P1, 3); setb(P1, 4);
	if(GetBit(P1, 5)) ic_recognized = 0;

	// Test 02
	setb(P1, 3); clr(P1, 4);
	if(!GetBit(P1, 5)) ic_recognized = 0;

	// Test 03
	clr(P1, 3); setb(P1, 4);
	if(!GetBit(P1, 5)) ic_recognized = 0;

	// Test 04
	clr(P1, 3); clr(P1, 4);
	if(GetBit(P1, 5)) ic_recognized = 0;

	//-----------------End-----------------

	if(ic_recognized) ic_name = "7486";
}

void test_7432() {
	// 2-Input OR Gate
	// Gate 01: input 01 = P1^0, input 02 = P1^1, output = P1^2.
	// Gate 02: input 01 = P1^3, input 02 = P1^4, output = P1^5.
	// Gate 03: input 01 = P2^5, input 02 = P2^4, output = P2^3.
	// Gate 04: input 01 = P2^2, input 02 = P2^1, output = P2^0.

	ic_recognized = 1;z

	//---------------Gate 01---------------

	// Test 01
	setb(P1, 0); setb(P1, 1);
	if(!GetBit(P1, 2)) ic_recognized = 0;

	// Test 02
	setb(P1, 0); clr(P1, 1);
	if(!GetBit(P1, 2)) ic_recognized = 0;

	// Test 03
	clr(P1, 0); setb(P1, 1);
	if(!GetBit(P1, 2)) ic_recognized = 0;

	// Test 04
	clr(P1, 0); clr(P1, 1);
	if(GetBit(P1, 2)) ic_recognized = 0;

	//---------------Gate 02---------------

	// Test 01
	setb(P1, 3); setb(P1, 4);
	if(!GetBit(P1, 5)) ic_recognized = 0;

	// Test 02
	setb(P1, 3); clr(P1, 4);
	if(!GetBit(P1, 5)) ic_recognized = 0;

	// Test 03
	clr(P1, 3); setb(P1, 4);
	if(!GetBit(P1, 5)) ic_recognized = 0;

	// Test 04
	clr(P1, 3); clr(P1, 4);
	if(GetBit(P1, 5)) ic_recognized = 0;

	//-----------------End-----------------

	if(ic_recognized) ic_name = "7432";

}

void test_7408() {
	// Quad 2-Input AND Gate
	// Gate 01: input 01 = P1^0, input 02 = P1^1, output = P1^2.
	// Gate 02: input 01 = P1^3, input 02 = P1^4, output = P1^5.
	// Gate 03: input 01 = P2^5, input 02 = P2^4, output = P2^3.
	// Gate 04: input 01 = P2^2, input 02 = P2^1, output = P2^0.

	ic_recognized = 1;

	//---------------Gate 01---------------

	// Test 01
	setb(P1, 0); setb(P1, 1);
	if(!GetBit(P1, 2)) ic_recognized = 0;

	// Test 02
	setb(P1, 0); clr(P1, 1);
	if(GetBit(P1, 2)) ic_recognized = 0;

	// Test 03
	clr(P1, 0); setb(P1, 1);
	if(GetBit(P1, 2)) ic_recognized = 0;

	// Test 04
	clr(P1, 0); clr(P1, 1);
	if(GetBit(P1, 2)) ic_recognized = 0;

	//---------------Gate 02---------------

	// Test 01
	setb(P1, 3); setb(P1, 4);
	if(!GetBit(P1, 5)) ic_recognized = 0;

	// Test 02
	setb(P1, 3); clr(P1, 4);
	if(GetBit(P1, 5)) ic_recognized = 0;

	// Test 03
	clr(P1, 3); setb(P1, 4);
	if(GetBit(P1, 5)) ic_recognized = 0;

	// Test 04
	clr(P1, 3); clr(P1, 4);
	if(GetBit(P1, 5)) ic_recognized = 0;

	//-----------------End-----------------

	if(ic_recognized) ic_name = "7408";
}

void test_7404() {
	// Inverter (NOT Gate)
	// Gate 01: input = P1^0, output = P1^1.
	// Gate 02: input = P1^2, output = P1^3.
	// Gate 03: input = P1^4, output = P1^5.
	// Gate 04: input = P2^5, output = P2^4.
	// Gate 05: input = P2^3, output = P2^2.
	// Gate 06: input = P2^1, output = P2^0.

	ic_recognized = 1;

	//---------------Gate 01---------------

	// Test 01
	setb(P1, 0);
	if(GetBit(P1, 1)) ic_recognized = 0;

	// Test 02
	clr(P1, 0);
	if(!GetBit(P1, 1)) ic_recognized = 0;

	//---------------Gate 02---------------

	// Test 01
	setb(P1, 2);
	if(GetBit(P1, 3)) ic_recognized = 0;

	// Test 02
	clr(P1, 2);
	if(!GetBit(P1, 3)) ic_recognized = 0;

	//---------------Gate 03---------------

	// Test 01
	setb(P1, 4);
	if(GetBit(P1, 5)) ic_recognized = 0;

	// Test 02
	clr(P1, 4);
	if(!GetBit(P1, 5)) ic_recognized = 0;

	//-----------------End-----------------

	if(ic_recognized) ic_name = "7404";

}

void test_7402() {
	// 2-Input NOR Gate
	// Gate 01: input 01 = P1^1, input 02 = P1^2, output = P1^0.
	// Gate 02: input 01 = P1^4, input 05 = P1^4, output = P1^3.
	// Gate 03: input 01 = P2^4, input 02 = P2^3, output = P2^5.
	// Gate 04: input 01 = P2^1, input 02 = P2^0, output = P2^2.

	ic_recognized = 1;

	//---------------Gate 01---------------

	// Test 01
	setb(P1, 1); setb(P1, 2);
	if(GetBit(P1, 0)) ic_recognized = 0;

	// Test 02
	setb(P1, 1); clr(P1, 2);
	if(GetBit(P1, 0)) ic_recognized = 0;

	// Test 03
	clr(P1, 1); setb(P1, 2);
	if(GetBit(P1, 0)) ic_recognized = 0;

	// Test 04
	clr(P1, 1); clr(P1, 2);
	if(!GetBit(P1, 0)) ic_recognized = 0;

	//---------------Gate 02---------------

	// Test 01
	setb(P1, 4); setb(P1, 5);
	if(GetBit(P1, 3)) ic_recognized = 0;

	// Test 02
	setb(P1, 4); clr(P1, 5);
	if(GetBit(P1, 3)) ic_recognized = 0;

	// Test 03
	clr(P1, 4); setb(P1, 5);
	if(GetBit(P1, 3)) ic_recognized = 0;

	// Test 04
	clr(P1, 4); clr(P1, 5);
	if(!GetBit(P1, 3)) ic_recognized = 0;

	//-----------------End-----------------

	if(ic_recognized) ic_name = "7402";

}

void test_7400() {
	// 2-Input NAND Gate
	// Gate 01: input 01 = P1^0, input 02 = P1^1, output = P1^2.
	// Gate 02: input 01 = P1^3, input 05 = P1^4, output = P1^5.
	// Gate 03: input 01 = P2^5, input 02 = P2^4, output = P2^3.
	// Gate 04: input 01 = P2^2, input 02 = P2^1, output = P2^0.

	ic_recognized = 1;

	//---------------Gate 01---------------

	// Test 01
	setb(P1, 0); setb(P1, 1);
	if(GetBit(P1, 2)) ic_recognized = 0;

	// Test 02
	setb(P1, 0); clr(P1, 1);
	if(!GetBit(P1, 2)) ic_recognized = 0;

	// Test 03
	clr(P1, 0); setb(P1, 1);
	if(!GetBit(P1, 2)) ic_recognized = 0;

	// Test 04
	clr(P1, 0); clr(P1, 1);
	if(!GetBit(P1, 2)) ic_recognized = 0;

	//---------------Gate 02---------------

	// Test 01
	setb(P1, 3); setb(P1, 4);
	if(GetBit(P1, 5)) ic_recognized = 0;

	// Test 02
	setb(P1, 3); clr(P1, 4);
	if(!GetBit(P1, 5)) ic_recognized = 0;

	// Test 03
	clr(P1, 3); setb(P1, 4);
	if(!GetBit(P1, 5)) ic_recognized = 0;

	// Test 04
	clr(P1, 3); clr(P1, 4);
	if(!GetBit(P1, 5)) ic_recognized = 0;

	//-----------------End-----------------

	if(ic_recognized) ic_name = "7400";
}

int main()
{
	if(!OpenCom(3, 115200))
	{
		exit(0);
	}

	while(1) {

		while(1) {
			ic_recognized = 0;

			test_7400(); if(ic_recognized) break;
			test_7402(); if(ic_recognized) break;
			test_7404(); if(ic_recognized) break;
			test_7408(); if(ic_recognized) break;
			test_7432(); if(ic_recognized) break;
			test_7486(); if(ic_recognized) break;
			test_74125(); if(ic_recognized) break;

			printf("No IC is recognized.\n");

			Sleep(3000);
		}

		printf("%s IC is recognized.\n", ic_name);

		Sleep(3000);
    }
}





