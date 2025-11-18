#include <iostream>
#include <string>
#include <vector>
#include "helpers.h"

using namespace std;

long long part1(const vector<string> &lines)
{
  // TODO
  return 0;
}

long long part2(const vector<string> &lines)
{
  // TODO
  return 0;
}

int main(int argc, char *argv[])
{
  if (argc < 2)
  {
    cerr << "Usage: " << argv[0] << " <input_file>" << endl;
    return 1;
  }

  vector<string> lines = readLines(argv[1]);

  cout << "Part 1: " << part1(lines) << endl;
  cout << "Part 2: " << part2(lines) << endl;

  return 0;
}