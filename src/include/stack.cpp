#include "stack.hpp"
#include <string.h>
#include <iostream>

Stack::Stack ( word_t p_size ) : m_SP ( p_size ), m_size ( p_size )
{
  m_memory = new byte_t[p_size];
}

Stack::Stack ( const Stack &p_stack )
{
  delete [] m_memory;

  m_size = p_stack.m_size;
  m_memory = new byte_t[p_stack.m_size];
  memcpy ( m_memory, p_stack.m_memory, p_stack.m_size );
  m_SP = p_stack.m_SP;

}

Stack Stack::operator= ( const Stack &p_stack )
{
  delete [] m_memory;

  m_size = p_stack.m_size;
  m_memory = new byte_t[p_stack.m_size];
  memcpy ( m_memory, p_stack.m_memory, p_stack.m_size );
  m_SP = p_stack.m_SP;

  return *this;
}

Stack::~Stack()
{
  delete [] m_memory;
}

void Stack::push ( word_t data16 )
{
  m_SP -= 2;
  write_memory_word ( m_SP, data16 );
}

word_t Stack::pop()
{
  word_t mem = read_memory_word ( m_SP );
  m_SP += 2;
  return mem;
}


inline byte_t Stack::read_memory_byte ( word_t addr )
{
  return m_memory[addr];
}

inline word_t Stack::read_memory_word ( word_t addr )
{
  return read_memory_byte ( addr + 1 ) << 8 |
         read_memory_byte ( addr );
}

inline void Stack::write_memory_byte ( word_t addr, byte_t data16 )
{
  m_memory[addr] = data16;
}

inline void Stack::write_memory_word ( word_t addr, word_t data16 )
{
  write_memory_byte ( addr, data16 );
  write_memory_byte ( addr + 1, data16 >> 8 );
}
