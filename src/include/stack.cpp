#include "stack.hpp"

void __stack::__MallocMemory(Word_t __tam)
{
    if (__tam <= 0)
        exit(1);
    __stack::__Memory = new Word_t[__tam];
    if(!__stack::__Memory)
        exit(2);
}

void __stack::__WriteMemory(Word_t __addr, Word_t __dice)
{
    __stack::__Memory[__addr] = __dice;
}

Word_t __stack::__ReadMemory(Word_t __addr)
{
    return __stack::__Memory[__addr];
}

void __stack::stack_push(Word_t __dice)
{
    __stack::SP -= 2;
    __stack::BS -= 2;
    __stack::__WriteMemory(__stack::SP, __dice & 0xff);
    __stack::__WriteMemory(__stack::BS, (__dice >> 8) & 0x1);
    __stack::PC++;
}

Word_t __stack::stack_pop()
{
    Word_t Read = __stack::__ReadMemory(__stack::SP);
    __stack::SP += 2;
    return Read;
}

Word_t __stack::stack_size()
{
    return __stack::PC;
}

Word_t __stack::stack_sign()
{
    Word_t Read = __stack::__ReadMemory(__stack::BS);
    __stack::BS += 2;
    return Read;
}

__stack::Stack(Word_t __tam)
{
    __stack::Buffer = __tam;
    __stack::SP = 0x2;
    __stack::PC = 0x00;
    __stack::BS = 1;
    __stack::__MallocMemory(__stack::Buffer);
}

__stack::~Stack()
{}  