# Advent of Code 2025 - C++ Template

A streamlined C++ template for solving Advent of Code problems with automatic project structure setup and a powerful Makefile.

## Quick Start

All 25 day directories are already set up and ready to use!

1. **Add your puzzle input**:
   - Paste the full input into `src/dayXX/input.txt`
   - Paste the example input into `src/dayXX/test_input.txt`

2. **Implement your solution** in `src/dayXX/solution.cpp`:
   ```cpp
   long long part1(const vector<string> &lines) {
       // Iterate through lines
       for (const string& line : lines) {
           // Your solution here
       }
       return 0;
   }
   
   long long part2(const vector<string> &lines) {
       // Your solution here
       return 0;
   }
   ```

## Build & Run Commands

### Compile a Solution
```bash
make build 1    # Compiles day 1
make build 15   # Compiles day 15
```

### Run with Full Input
```bash
make run 1      # Compiles and runs day 1 with input.txt
```

### Run with Test Input
```bash
make test 1     # Compiles and runs day 1 with test_input.txt
```

### Run All Completed Days
```bash
make all        # Runs all days with solution.cpp files
```

### Clean Build Files
```bash
make clean      # Removes all compiled binaries
```
## Helper Functions

Available in `utils/helpers.h`: 

```cpp
// Read file as vector of lines
vector<string> lines = readLines("src/day01/input.txt");

// Split string by delimiter
vector<string> parts = split("1,2,3", ',');

// Trim whitespace
string clean = trim("  hello  "); // "hello"

// Convert to int/long long
int num = toInt("42");
long long big = toLong("9999999999");
```

## Tips

- **Test first**: Use `make test 1` with example input before running the full input
- **Debug output**: Add `cout` statements for debugging, they'll show in the terminal
- **Large numbers**: Use `long long` for return types (handles up to ~9 quintillion)
- **Input parsing**: The `readLines()` function returns a vector of lines - iterate with a for loop

## Project Structure

All day directories (`src/day01/` through `src/day25/`) are pre-created with:
- `solution.cpp` - Template for your solution
- `input.txt` - For your full puzzle input
- `test_input.txt` - For example/test input

The `setup.sh` script is included if you need to regenerate the structure.

## Requirements

- C++ compiler with C++14 support (g++-14 or compatible)
- Make
