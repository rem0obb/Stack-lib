// Stack Based in intel-8080
// Copyright (c) 2021 VitorMob
// All rights reserved.

#include <iostream>

typedef int16_t Word_t;

typedef class Stack
{
private:
    Word_t BS;        // byte sign
    Word_t SP;        // stack pointer
    Word_t PC;        // program counter
    Word_t *__Memory; // memory allocated
    Word_t Buffer;    // buffer size

    void __MallocMemory(Word_t __tam);
    void __FreeMemory();
    void __ValidMemory();
    void __WriteMemory(Word_t __addr, Word_t __dice);
    Word_t __ReadMemory(Word_t __addr);

public:
    Stack(Word_t __tam);
    ~Stack();

    void stack_push(Word_t __dice);
    Word_t stack_pop();
    Word_t stack_size();
    Word_t stack_sign();
    bool stack_empty();

} __stack;
