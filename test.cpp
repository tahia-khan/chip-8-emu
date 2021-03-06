#include <cstdlib>
#include <iostream>
#include <string>

#include <iomanip>

#include "chip-8.h"
#include "defs.h"

using namespace std;

void Chip8::testPrintV() {
    cout << "print V registers: ";

    for( int i = 0; i < REGISTER_SIZE_16; i++) {
        cout << hex << int(V_[i]) << ", ";
    }
        cout << endl;
}

void Chip8::testPrintRegisters() {
    
        cout << "pc: " << hex << int(pc_) << endl;
        cout << "sp: " << hex << int(sp_) << endl;
        cout << "I: " << hex  << int(I_) << endl;
        cout << "opcode: " << hex << int(opcode_) << endl;
        
        cout << endl;
}

void Chip8::testPrintStack() {
    cout << "print Stack: ";
    for( int i = 0; i < STACK_SIZE; i++) {
        cout << hex << int(stack_[i]) << ", ";
    }
        cout << endl;
}
void Chip8::testLoadV() {
    
    for( int i = 0; i < REGISTER_SIZE_16; i++) {
        V_[i] = i;
    }
}

void Chip8::test8XYN() {
    
/* op_8XY0 */
    testLoadV();
    opcode_ = 0x83a0;
    op_8XY0();
    testPrintV();

/* op_8XY1 */
    testLoadV();
    opcode_ = 0x8141;
    op_8XY1();
    testPrintV();

/* op_8XY2 */
    testLoadV();
    opcode_ = 0x8502;
    op_8XY2();
    testPrintV();

/* op_8XY3 */
    testLoadV();
    opcode_ = 0x8a63;
    op_8XY3();
    testPrintV();

/* op_8XY4 with carry */
    testLoadV();
    opcode_ = 0x88a4;
    op_8XY4();
    testPrintV();

/* op_8XY4 no carry */
    testLoadV();
    opcode_ = 0x8a14;
    op_8XY4();
    testPrintV();

/* op_8XY5 with borrow */
    testLoadV();
    opcode_ = 0x84a5;
    op_8XY5();
    testPrintV();


/* op_8XY5 no borrow */
    testLoadV();
    opcode_ = 0x8a45;
    op_8XY5();
    testPrintV();
}


/*
    test methods
    void testPrintV();
    void testPrintRegisters();
    void testPrintStack();
    void testLoadV();

    unsigned short 	pc_;
	unsigned short 	sp_;
	unsigned short 	I_;
	unsigned short 	opcode_;

	unsigned char 	delay_timer_;
	unsigned char 	sound_timer_;

	unsigned char 	V_[REGISTER_SIZE_16];
	unsigned short 	stack_[STACK_SIZE];
	unsigned char 	memory_[RAM_SIZE];


*/
