#include <iostream>
#include "chip8.h"

unsigned char chip8_fontset[FONTSET_SIZE] =
{ 	0xF0, 0x90, 0x90, 0x90, 0xF0, //0
	0x20, 0x60, 0x20, 0x20, 0x70, //1
	0xF0, 0x10, 0xF0, 0x80, 0xF0, //2
	0xF0, 0x10, 0xF0, 0x10, 0xF0, //3
	0x90, 0x90, 0xF0, 0x10, 0x10, //4
	0xF0, 0x80, 0xF0, 0x10, 0xF0, //5
	0xF0, 0x80, 0xF0, 0x90, 0xF0, //6
	0xF0, 0x10, 0x20, 0x40, 0x40, //7
	0xF0, 0x90, 0xF0, 0x90, 0xF0, //8
	0xF0, 0x90, 0xF0, 0x10, 0xF0, //9
	0xF0, 0x90, 0xF0, 0x90, 0x90, //A
	0xE0, 0x90, 0xE0, 0x90, 0xE0, //B
	0xF0, 0x80, 0x80, 0x80, 0xF0, //C
	0xE0, 0x90, 0x90, 0x90, 0xE0, //D
	0xF0, 0x80, 0xF0, 0x80, 0xF0, //E
	0xF0, 0x80, 0xF0, 0x80, 0x80  //F
};

void Chip8::initialize() {
	/* Initialize system state */
	pc_ 		= 0x200;
	opcode_ 	= 0;
	I_		= 0;
	sp_		= 0;

	/* Clear display */
	for (int i = 0; i < DISPLAY_SIZE ; i ++) {
		graphics_[i] = 0;
	}

	/* Clear stack */
	for (i = 0; i < STACK_SIZE ; i++) {
		stack_[i] = 0;
	}

	/* Clear registers V0-VF */
	for (i = 0; i < REGISTER_SIZE_16 ; i++) {
		V_[i] = 0;
	}
		
	/* Clear memory */
	for (i = 0; i < RAM_SIZE ; i++) {
		memory_[i] = 0;
	}


	/* Load fontset - part of interpretter region */
	for (i = 0; i < FONTSET_SIZE ; i++) {
		memory_[i] = chip8_fontset[i];
	};

	/* Reset timers */
	delay_timer_ = 0;
	sound_timer_ = 0;

}

void Chip8::emulate_cycle() {

	/* Fetch */
	opcode_ = memory_[pc_] << 8 | memory_[pc_ + 1];

	/* Decode & Execute */
}
