// Copyright (c) 2021 VitorMob
// All rights reserved.

#include <stdint.h>


typedef uint16_t word_t;
typedef uint8_t byte_t;

struct Stack
{
  word_t m_SP;
  byte_t *m_memory;
  word_t m_size;

  inline byte_t read_memory_byte ( word_t addr );
  inline word_t read_memory_word ( word_t addr );
  inline void write_memory_byte ( word_t addr, byte_t data16 );
  inline void write_memory_word ( word_t addr, word_t data16 );

 public:
  Stack ( word_t = 65535 );
  Stack ( const Stack & );
  Stack operator= ( const Stack & );
  ~Stack();
  void push ( word_t );
  word_t pop();
};
