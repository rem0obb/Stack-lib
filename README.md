# Stack

## Help

for usage stack create obj `Stack stack(2)` and allocate 1 

for stack up `stack.push(0x15)` 

for unstack `stack.pop()` 

> example

```C++
  #include "include/stack.hpp"
  
  int main()
  {
   Stack stack(6);
  
  stack.push(0x42);
  stack.push(0x4f);
  stack.push(0x4d);
 
  std::cout << (char)stack.pop() << (char)stack.pop() << (char)stack.pop() << std::endl;
 
  return 0;
 }
```

## Compiler example

```
mkdir build

cd build

cmake ..

make

```

## Notes 

> Stack based in intel 8080
