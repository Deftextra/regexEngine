#include <iostream>
#include <sstream>
#include <Automata.h> 
using namespace Automata;


int main(int argc, char* argv[])
{ 

  NDFA regexToNDFA {"tca*"};

  std::istringstream ss("tcaa");
  std::cout <<  regexToNDFA.match(ss) << std::endl; 
}
