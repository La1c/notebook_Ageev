#include <cstdio>
#include <string>
#include "interface.h"
#include "controller.h"
#include "tests.h"

using std::string;

int main(int argc, char ** argv)
{
  DB myDB;
  run_all_tests(argc, argv);
  interface(myDB);
  return 0;
}
