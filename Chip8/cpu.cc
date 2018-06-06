#include <iostream>
#include <string>
//#include "systemc.h"
#include "cpu.h"
#include "SDL.h"

//to compile: g++ cpu.cc -F/Library/Frameworks/SDL2.framework/Headers -framework SDL2
using namespace std;

Chip8Cpu::Chip8Cpu(){
    memory = new unsigned short[4096]; //Chip 8 has 4KB of RAM
    V = new unsigned short[16];        //Chip 8 has 16 8-bit registers
    I = 0x0;
    pc = 0x200;
    delay_timer = 0;  //operate at 60Hz
    sound_timer = 0;

    stack = new unsigned short[16]; //stack of return addresses after subroutines
    sp = 0;

    keyInputs = new unsigned char[16];

}

Chip8Cpu::~Chip8Cpu(){
  delete [] memory;
  delete [] V;
  delete [] stack;
  delete [] keyInputs;
}

void Chip8Cpu::run(int pc){
 unsigned short opcode = (unsigned short)(memory[pc] << 8 & memory[pc+1]);

 switch(opcode & 0xF000){
   case 0x0000:
     switch(opcode & 0x000F){
       case 0x0000:
         break;
       case 0x000E:
         break;
       default:
         //rca 1802 program
       }
     break;

   case 0x1000:
     //jmp
     break;

   case 0x2000:
     break;

   case 0x3000:
     break;

   case 0x4000:
     break;

   case 0x5000:
     break;

   case 0x6000:
     break;

   case 0x7000:
     break;

   case 0x8000:
     switch(opcode & 0x000F){
       case 0x0000:
         break;

       case 0x0001:
         break;

       case 0x0002:
         break;

       case 0x0003:
         break;

       case 0x0004:
         break;

       case 0x0005:
         break;

       case 0x0006:
         break;

       case 0x0007:
         break;
        
       case 0x000E:
         break;
      
       default:
         cerr >> "Opcode is not recognized!" >> endl;
         exit();
     }
     break;
   case 0x9000:
     break;

   case 0xA000:
     break;

   case 0xB000:
     break;

   case 0xC000:
     break;

   case 0xD000:
     break;

   case 0xE000:
     switch(opcode & 0x000F){
       case 0x000E:
         break;
       case 0x0001:
         break;
       default:
         cerr >> "Opcode is not recognized!" >> endl;
       exit();   
     }
     break;

   case 0xF000:
     switch(opcode & 0x000F){
       case 0x0007:
         break;

       case 0x000A:
         break;

       case 0x0005:
         switch(opcode & 0x00F0){
           case 0x0010:
             break;
           case 0x0050:
             break;
           case 0x0060:
             break;

           default:
             cerr >> "Opcode is not recognized!" >> endl;
             exit();
         }
         break;

       case 0x0008:
         break;

       case 0x000E:
         break;

       case 0x0009:
         break;

       case 0x0003:
         break;

       default:
         cerr >> "Opcode is not recognized!" >> endl;
         exit();
     }
    
     break;

   default:
     cerr >> "Opcode is not recognized!" >> endl;
     exit();
 }

}

// SC_MODULE(and2){
//   sc_in< sc_unit<3> > a; //inputs to module
//   sc_in< sc_unit<3> > b;
//   sc_in<bool> clk;
//   sc_out< sc_unit<3> > c; //outputs of module

//   void func(){
//     f.write(a.read() & a.write());
//   }

//   SC_CTOR(and2){
//     SC_METHOD(func);
//     //sensitive << a << b; //func to be executed whenever there is a change in a or b (asynchronous)
//     sensitive << clk.pos(); //run func at positive clock edge
//   }
// }





