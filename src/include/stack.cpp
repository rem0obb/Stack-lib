#include "stack.hpp"

void __stack::__MallocMemory(Word_t __tam)
{
    if (__tam <= 0)
        exit(1);
    __stack::__Memory = (Word_t *)malloc(__tam);
    if (!__stack::__Memory)
        exit(2);
}

void __stack::__ValidMemory()
{
    if (__stack::PC > __stack::Buffer)
    {
        std::cout << "Stack overflow" << std::endl;
        exit(3);
    }
    if(__stack::PC == 0)
    {
        std::cout << "Stack empty" << std::endl;
        exit(4);
    }
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
    __stack::PC += 2;
    __stack::__ValidMemory();
}

Word_t __stack::stack_pop()
{
    __stack::__ValidMemory();
    Word_t Read = __stack::__ReadMemory(__stack::SP);
    __stack::SP += 2;
    return Read;
}

Word_t __stack::stack_size()
{
    __stack::__ValidMemory();
    return __stack::PC;
}

Word_t __stack::stack_sign()
{    
    __stack::__ValidMemory();
    Word_t Read = __stack::__ReadMemory(__stack::BS);
    __stack::BS += 2;
    return Read;
}

bool __stack::stack_empty()
{
    if(__stack::PC == 0)
        return true;
    else 
        return false;
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
{
}
