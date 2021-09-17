#include "stack.hpp"

void __stack::__MallocMemory(Word_t __tam)
{
    if (__tam <= 0)
        exit(1);
    __Memory = new Word_t[__tam];
    if (!__Memory)
        exit(2);
}

void __stack::__FreeMemory()
{
    delete[] __Memory;
}

void __stack::__ValidMemory()
{
    if (PC > Buffer)
    {
        std::cout << "Stack overflow" << std::endl;
        exit(3);
    }
    if (PC == 0)
    {
        std::cout << "Stack empty" << std::endl;
        exit(4);
    }
}

void __stack::__WriteMemory(Word_t __addr, Word_t __dice)
{
    __Memory[__addr] = __dice;
}

Word_t __stack::__ReadMemory(Word_t __addr)
{
    return __Memory[__addr];
}

void __stack::stack_push(Word_t __dice)
{
    __WriteMemory(SP += 2, __dice & 0xff);
    __WriteMemory(BS += 2, (__dice >> 8) & 0x1);
    PC += 2;
    __ValidMemory();
}

Word_t __stack::stack_pop()
{
    __ValidMemory();
    Word_t Read = __ReadMemory(SP);
    PC--;
    SP -= 2;
    return Read;
}

Word_t __stack::stack_size()
{
    __ValidMemory();
    return PC;
}

Word_t __stack::stack_sign()
{
    __ValidMemory();
    Word_t Read = __ReadMemory(BS);
    BS -= 2;
    return Read;
}

bool __stack::stack_empty()
{
    if (PC == 0)
        return true;
    else
        return false;
}

__stack::Stack(Word_t __tam)
{
    Buffer = __tam*2;
    SP = 0;
    PC = 0;
    BS = 1;
    __MallocMemory(Buffer);
}

__stack::~Stack()
{
    __FreeMemory();
}
