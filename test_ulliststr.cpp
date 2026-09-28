#include <string>
#include <vector>
#include <iostream>
#include <sstream>

#include "ulliststr.h"
using namespace std;

//Use this file to test your ulliststr implementation before running the test suite

int main(int argc, char* argv[])
{
  ULListStr list;

  cout << list.empty() << endl;

  list.push_back("a");
  list.push_back("b");

  for(int i = 0; i < 10; i++){
    list.push_back(to_string(i));
  }

  cout << list.size() << endl;
  cout << list.front() << " " << list.back() << endl;

}
