#include <iostream>
#include <string>
#include <vector>
#include "helpers.h"

using namespace std;

long long part1(const string &data)
{
  // TODO
  return 0;
}

long long part2(const string &data)
{
  // TODO
  return 0;
}

int main(int argc, char *argv[])
{
  if (argc < 2)
  {
    cerr << "Usage: " << argv[0] << " " << endl;
    return 1;
  }

  string data = readInput(argv[1]);

  cout << "Part 1: " << part1(data) << endl;
  cout << "Part 2: " << part2(data) << endl;

  return 0;
}