/* Chip-8
 *
 * MEMORY
 * Chip-8 can address 4KB of RAM, from 0x000 to 0xFFF.
 *
 * System memory map:
 * 	0x000-0x1FF - Chip 8 interpreter (contains font set in emu)
 * 	0x050-0x0A0 - Used for the built in 4x5 pixel font set (0-F)
 * 	0x200-0xFFF - Program ROM and work RAM
 *
 *	+---------------+= 0xFFF (4095) End of Chip-8 RAM
 *	|               |
 *	|               |
 *	|               |
 *	|               |
 *	|               |
 *	| 0x200 to 0xFFF|
 *	|     Chip-8    |
 *	| Program / Data|
 *	|     Space     |
 *	|               |
 *	|               |
 *	|               |
 *	|               |
 *	|               |
 *	|               |
 *	+---------------+= 0x200 (512) Start of most Chip-8 programs
 *	| 0x000 to 0x1FF|
 *	| Reserved for  |
 *	|  interpreter  |
 *	+---------------+= 0x000 (0) Start of Chip-8 RAM
 *
 *
 * REGISTERS
 * - 16 general purpose registers, V0-VF. VF is used as a carry flag 
 *   and should not be used by any program
 * - Register I, mainly used to store memory addresses
 * - Two special purpose 8-bit registers for delay and sound timer which
 *   decrement to 0 at 60Hz
 * - Stack is an array of 16 16-bit values used to store return address
 *   for subroutines
 * - PC - program counter, 16-bit 
 * - SP - stack pointer, 8-bit register
 *
 * KEYBOARD
 * 16-key hexadecimal keyboard with the following layout:
 *   	1 2 3 C
 *   	4 5 6 D
 *   	7 8 9 E
 *   	A 0 B F
 *
 * DISPLAY
 * 64x32-pixel monochrome display with the following layout:
 * 	+--------------+
 * 	|(0,0)	(63,0) |
 * 	|(0,31)	(63,31)|
 * 	+--------------+
 */

#ifndef CHIP8_H
#define CHIP8_H

#include "defs.h"

class Chip8 {

private:
	unsigned short 	pc_;
	unsigned short 	sp_;
	unsigned short 	I_;
	unsigned short 	opcode_;

	unsigned char 	delay_timer_;
	unsigned char 	sound_timer_;

	unsigned char 	V_[REGISTER_SIZE_16];
	unsigned short 	stack_[STACK_SIZE];
	unsigned char 	memory_[RAM_SIZE];

	bool     		display_updated_flag_;
	unsigned char 	graphics_[DISPLAY_SIZE];
	unsigned char 	key_[REGISTER_SIZE_16];

	/* Opcode Implementation */
	int op_00E0();	
    int op_00EE();

	int op_1NNN();
	int op_2NNN();
	int op_3XNN();
	int op_4XNN();
	int op_5XY0();
	int op_6XNN();
	int op_7XNN();

    int op_8XY0();
    int op_8XY1();
   	int op_8XY2();
    int op_8XY3();
    int op_8XY4();
    int op_8XY5();
    int op_8XY6();
    int op_8XY7();
    int op_8XYE();
    
	int op_9XY0();
	int op_ANNN();
	int op_BNNN();
	int op_CXNN();
	//DXYN here

	int op_EX9E();
	int op_EXA1();
    int op_FX07();
    int op_FX0A();
    int op_FX15();
    int op_FX18();
    int op_FX1E();
    int op_FX29();
    int op_FX33();
    int op_FX55();
    int op_FX65();
	
public:
	Chip8();
	~Chip8();

	void initialize();
	void emulate_cycle();
	void load();

    //test methods
    void testPrintV();
    void testPrintRegisters();
    void testPrintStack();
    void testLoadV();
    void test8XYN();

};

#endif 
