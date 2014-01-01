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
	sp_ = 0;

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
	int error;

	/* Fetch */
	opcode_ = memory_[pc_] << 8 | memory_[pc_ + 1];

	/* Decode & Execute */
	switch (opcode & 0xF000) {
		case (0x0000): switch (opcode & 0x00FF) {
				       case (0x00E0): 
					       error = op_00E0();
					       break;
				       case (0x00EE): break;
				       default: break;
			       }
			       break;
		case (0x1000): error = op_1NNN();
			       break;
		case (0x2000): error = op_2NNN();
			       break;
		case (0x3000): error = op_3XNN();
			       break;
		case (0x4000): break;
		case (0x5000): break;
		case (0x6000): break;
		case (0x7000): break;
		case (0x8000): switch (opcode & 0x000F) {
				       case (0x0000): break;
				       case (0x0001): break;
				       case (0x0003): break;
				       case (0x0004): break;
				       case (0x0005): break;
				       case (0x0006): break;
				       case (0x0007): break;
				       case (0x000E): break;
				       default: break;
			       }
			       break;
		case (0x9000): break;
		case (0xA000): break;
		case (0xB000): break;
		case (0xC000): break;
		case (0xD000): break;
		case (0xE000): switch (opcode & 0x00FF) {
				       case (0x009E): break;
				       case (0x00A1): break;
				       default: break;
			       }
			       break;
		case (0xF000): switch (opcode & 0x00FF) {
				       case (0x0007): break;
				       case (0x000A): break;
				       case (0x0015): break;
				       case (0x0018): break;
				       case (0x001E): break;
				       case (0x0029): break;
				       case (0x0033): break;
				       case (0x0055): break;
				       case (0x0065): break;
				       default: break;
			       }
			       break;
		default: break;	
	}

}