#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "helpers.h"
#include <cmath>
#include <unordered_map>

using namespace std;

long long part1(const vector<string> &lines)
{
  vector<int> left, right;

  for (const string &line : lines)
  {
    vector<string> splits = split(line, "   ");
    left.push_back(stoi(splits[0]));
    right.push_back(stoi(splits[1]));
  }

  sort(left.begin(), left.end());
  sort(right.begin(), right.end());

  long long res = 0;
  for (size_t i = 0; i < left.size(); i++)
  {
    res += abs(left[i] - right[i]);
  }

  return res;
}

long long part2(const vector<string> &lines)
{
  vector<int> left, right;

  for (const string &line : lines)
  {
    vector<string> splits = split(line, "   ");
    left.push_back(stoi(splits[0]));
    right.push_back(stoi(splits[1]));
  }
  long long res = 0;

  // unefficient O(n^2) version
  // for (int a : left)
  // {
  //   long long ares = 0;
  //   for (int b : right)
  //   {
  //     if (a == b)
  //     {
  //       ares++;
  //     }
  //   }
  //   res += ares * a;
  // }

  // more efficient O(n) version
  unordered_map<int, int> rightCount;
  for (int num : right)
  {
    rightCount[num]++;
  }
  for (int num : left)
  {
    res += num * rightCount[num];
  }
  
  return res;
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