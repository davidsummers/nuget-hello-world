#include <iostream>

#include "zlib.h"

int main( )
{
  const char *version = zlibVersion( );
  std::cout << "Hello, Zlib (" << version << ") World!" << std::endl;
  return 0;
}
