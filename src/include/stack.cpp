#include "stack.hpp"

void __stack::__MallocMemory(Word_t __tam)
{
    if (__tam <= 0)
        exit(1);
    this->__Memory = new Word_t[__tam];
    if (!this->__Memory)
        exit(2);
}

void __stack::__ValidMemory()
{
    if (this->PC > this->Buffer)
    {
        std::cout << "Stack overflow" << std::endl;
        exit(3);
    }
    if(this->PC == 0)
    {
        std::cout << "Stack empty" << std::endl;
        exit(4);
    }
}

void __stack::__WriteMemory(Word_t __addr, Word_t __dice)
{
    this->__Memory[__addr] = __dice;
}

Word_t __stack::__ReadMemory(Word_t __addr)
{
    return this->__Memory[__addr];
}

void __stack::stack_push(Word_t __dice)
{
    this->SP -= 2;
    this->BS -= 2;
    this->__WriteMemory(this->SP, __dice & 0xff);
    this->__WriteMemory(this->BS, (__dice >> 8) & 0x1);
    this->PC += 2;
    this->__ValidMemory();
}

Word_t __stack::stack_pop()
{
    this->__ValidMemory();
    Word_t Read = this->__ReadMemory(this->SP);
    this->SP += 2;
    return Read;
}

Word_t __stack::stack_size()
{
    this->__ValidMemory();
    return this->PC-=1;
}

Word_t __stack::stack_sign()
{    
    this->__ValidMemory();
    Word_t Read = this->__ReadMemory(this->BS);
    this->BS += 2;
    return Read;
}

bool __stack::stack_empty()
{
    if(this->PC == 0)
        return true;
    else 
        return false;
}

__stack::Stack(Word_t __tam)
{
    this->Buffer = __tam;
    this->SP = 0x02;
    this->PC = 0x00;
    this->BS = 0x01;
    this->__MallocMemory(this->Buffer);
}

__stack::~Stack()
{
    delete[] this->__Memory;
}
