#include "../Utility/pch.h"

using namespace std;

const int64_t DAY = 7;
const int64_t PART = 1;

int64_t day7_1(ifstream &&in) {
  int64_t result = 0;

  return result;
}

int64_t day7_2(ifstream &&in) {
  int64_t result = 0;

  return result;
}

int64_t day8_1(ifstream &&in) {
  int64_t result = 0;

  return result;
}

int64_t day8_2(ifstream &&in) {
  int64_t result = 0;

  return result;
}

int64_t day9_1(ifstream &&in) {
  int64_t result = 0;

  return result;
}

int64_t day9_2(ifstream &&in) {
  int64_t result = 0;

  return result;
}

int64_t day10_1(ifstream &&in) {
  int64_t result = 0;

  return result;
}

int64_t day10_2(ifstream &&in) {
  int64_t result = 0;

  return result;
}

int64_t day11_1(ifstream &&in) {
  int64_t result = 0;

  return result;
}

int64_t day11_2(ifstream &&in) {
  int64_t result = 0;

  return result;
}

int64_t day12_1(ifstream &&in) {
  int64_t result = 0;

  return result;
}

int64_t day12_2(ifstream &&in) {
  int64_t result = 0;

  return result;
}

int64_t day13_1(ifstream &&in) {
  int64_t result = 0;

  return result;
}

int64_t day13_2(ifstream &&in) {
  int64_t result = 0;

  return result;
}

int64_t day14_1(ifstream &&in) {
  int64_t result = 0;

  return result;
}

int64_t day14_2(ifstream &&in) {
  int64_t result = 0;

  return result;
}

int64_t day15_1(ifstream &&in) {
  int64_t result = 0;

  return result;
}

int64_t day15_2(ifstream &&in) {
  int64_t result = 0;

  return result;
}

int64_t day16_1(ifstream &&in) {
  int64_t result = 0;

  return result;
}

int64_t day16_2(ifstream &&in) {
  int64_t result = 0;

  return result;
}

int64_t day17_1(ifstream &&in) {
  int64_t result = 0;

  return result;
}

int64_t day17_2(ifstream &&in) {
  int64_t result = 0;

  return result;
}

int64_t day18_1(ifstream &&in) {
  int64_t result = 0;

  return result;
}

int64_t day18_2(ifstream &&in) {
  int64_t result = 0;

  return result;
}

int64_t day19_1(ifstream &&in) {
  int64_t result = 0;

  return result;
}

int64_t day19_2(ifstream &&in) {
  int64_t result = 0;

  return result;
}

int64_t day20_1(ifstream &&in) {
  int64_t result = 0;

  return result;
}

int64_t day20_2(ifstream &&in) {
  int64_t result = 0;

  return result;
}

int64_t day21_1(ifstream &&in) {
  int64_t result = 0;

  return result;
}

int64_t day21_2(ifstream &&in) {
  int64_t result = 0;

  return result;
}

int64_t day22_1(ifstream &&in) {
  int64_t result = 0;

  return result;
}

int64_t day22_2(ifstream &&in) {
  int64_t result = 0;

  return result;
}

int64_t day23_1(ifstream &&in) {
  int64_t result = 0;

  return result;
}

int64_t day23_2(ifstream &&in) {
  int64_t result = 0;

  return result;
}

int64_t day24_1(ifstream &&in) {
  int64_t result = 0;

  return result;
}

int64_t day24_2(ifstream &&in) {
  int64_t result = 0;

  return result;
}

int64_t day25_1(ifstream &&in) {
  int64_t result = 0;

  return result;
}

int64_t day25_2(ifstream &&in) {
  int64_t result = 0;

  return result;
}

// if each ( goes up one floor and each ) goes down one floor, what floor do we end up on?
int64_t day1_1(ifstream &&in) {
  int64_t floor = 0;
  char c;
  while (in >> c) {
    if (c == '(') {
      ++floor;
    }
    if (c == ')') {
      --floor;
    }
  }
  return floor;
}

// on which step do we reach floor -1?
int64_t day1_2(ifstream &&in) {
  int64_t floor = 0;
  int64_t step = 0;
  char c;
  while (in >> c) {
    if (c == '(') {
      ++floor;
      ++step;
    }
    if (c == ')') {
      --floor;
      ++step;
    }
    if (floor < 0) {
      break;
    }
  }
  return step;
}

// given LxWxH triples, find the total surface area of corresponding boxes, plus the surface area of the smallest side of each box
int64_t day2_1(ifstream &&in) {
  int64_t result = 0;
  auto dims = split(split(slurp(in)), "x");
  for (auto dim : dims) {
    auto vals = map_to_num(dim);
    auto a = vals[0] * vals[1];
    auto b = vals[2] * vals[1];
    auto c = vals[2] * vals[0];
    result += 2 * (a + b + c) + min({a, b, c});
  }
  return result;
}

// find the total volume of the corresponding boxes, plus the perimeter of the smallest side of each
int64_t day2_2(ifstream &&in) {
  int64_t result = 0;
  auto dims = split(split(slurp(in)), "x");
  for (auto dim : dims) {
    auto vals = map_to_num(dim);
    auto a = 2 * (vals[0] + vals[1]);
    auto b = 2 * (vals[1] + vals[2]);
    auto c = 2 * (vals[2] + vals[0]);
    result += vals[0] * vals[1] * vals[2] + min({a, b, c});
  }
  return result;
}

// given ^>v< arrows indicating navigation of a square lattice, how many distinct coordinates are visited?
int64_t day3_1(ifstream &&in) {
  int64_t result = 0;
  set<vector<int>> seen;
  vector<int> pos = {0, 0};

  seen.insert(pos);
  ++result;

  char c;
  while (in >> c) {
    switch (c) {
    case '>': pos[0]++; break;
    case '<': pos[0]--; break;
    case '^': pos[1]++; break;
    case 'v': pos[1]--; break;
    }
    if (seen.insert(pos).second) {
      ++result;
    }
  }
  return result;
}

// two santas now interpret those arrows in turn; how many distinct coordinates are visited?
int64_t day3_2(ifstream &&in) {
  int64_t result = 0;
  set<vector<int>> seen;
  vector<vector<int>> both = {{0, 0}, {0, 0}};
  int which = 0;

  seen.insert(both[which]);
  ++result;

  char c;
  while (in >> c) {
    if (strchr("<>^v", c) == nullptr) {
      continue;
    }
    auto &pos = both[which % 2];
    ++which;

    switch (c) {
    case '>': pos[0]++; break;
    case '<': pos[0]--; break;
    case '^': pos[1]++; break;
    case 'v': pos[1]--; break;
    }
    if (seen.insert(pos).second) {
      ++result;
    }
  }
  return result;
}

// what number should be appended to the input to get an MD5 checksum that, as a hex string, starts with 5 zeroes?
int64_t day4_1(ifstream &&in) {
  string key = slurp(in);
  for (int i = 1; ; ++i) {
    string guess = key + to_string(i);
    auto md = MD5((unsigned char *)guess.c_str(), guess.length(), nullptr);
    if (md[0] + md[1] == 0 && md[2] < 0x10) {
      return i;
    }
  }
  return -1;
}

// now 6 zeroes
int64_t day4_2(ifstream &&in) {
  string key = slurp(in);
  for (int i = 1; ; ++i) {
    string guess = key + to_string(i);
    auto md = MD5((unsigned char *)guess.c_str(), guess.length(), nullptr);
    if (md[0] + md[1] + md[2] == 0) {
      return i;
    }
  }
  return -1;
}

// how many lines have at least 3 vowels, some letter appearing twice in a row, and none of the substrings "ab", "cd", "pq", or "xy"?
int64_t day5_1(ifstream &&in) {
  int64_t result = 0;

  string line;
  while (getline(in, line)) {
    int vowels = 0;
    char last = '\0';
    bool foundPair = false;
    for (char c : line) {
      if (strchr("aeiou", c) != nullptr) {
        vowels++;
      }
      if (c == last) {
        foundPair = true;
      }
      last = c;
    }
    if (vowels < 3 || !foundPair) {
      continue;
    }
    if (line.find("ab") != string::npos ||
      line.find("cd") != string::npos ||
      line.find("pq") != string::npos ||
      line.find("xy") != string::npos) {
      continue;
    }
    ++result;
  }

  return result;
}

// how many lines have a 2 character substring appearing twice without overlap, and a letter appearing twice with one letter between?
int64_t day5_2(ifstream &&in) {
  int64_t result = 0;

  string line;
  while (getline(in, line)) {
    bool foundPair = false;
    bool foundSplit = false;
    for (int i = 1; i < line.length(); ++i) {
      if (line.find(line.substr(i - 1, 2), i + 1) != string::npos) {
        foundPair = true;
      }
      if (i + 1 < line.length() && line[i - 1] == line[i + 1]) {
        foundSplit = true;
      }
    }
    if (foundPair && foundSplit) {
      ++result;
    }
  }

  return result;
}

// given instructions of the form "turn on", "turn off", or "toggle" inclusive coordinate ranges, how many positions end up on?
int64_t day6_1(ifstream &&in) {
  static bool field[1000][1000] = {};
  string line;
  while (getline(in, line)) {
    auto tokens = split(line, " ");
    auto action = -1;
    if (tokens[0] == "turn") {
      tokens.erase(tokens.begin());
      if (tokens[0] == "on") {
        action = 0;
      } else if (tokens[0] == "off") {
        action = 1;
      }
    } else if (tokens[0] == "toggle") {
      action = 2;
    }
    auto start = map_to_num(split(tokens[1], ","));
    auto end = map_to_num(split(tokens[3], ","));
    for (auto i = start[0]; i <= end[0]; ++i) {
      for (auto j = start[1]; j <= end[1]; ++j) {
        switch (action) {
        case 0: field[i][j] = true; break;
        case 1: field[i][j] = false; break;
        case 2: field[i][j] = !field[i][j]; break;
        }
      }
    }
  }
  int64_t result = 0;
  for (int i = 0; i < 1000; i++) {
    for (int j = 0; j < 1000; j++) {
      if (field[i][j]) {
        ++result;
      }
    }
  }
  return result;
}

// now interpret those instructions as add one, subtract one (minimum zero), and add two; what's the total sum?
int64_t day6_2(ifstream &&in) {
  static int field[1000][1000] = {};
  string line;
  while (getline(in, line)) {
    auto tokens = split(line, " ");
    auto action = -1;
    if (tokens[0] == "turn") {
      tokens.erase(tokens.begin());
      if (tokens[0] == "on") {
        action = 0;
      } else if (tokens[0] == "off") {
        action = 1;
      }
    } else if (tokens[0] == "toggle") {
      action = 2;
    }
    auto start = map_to_num(split(tokens[1], ","));
    auto end = map_to_num(split(tokens[3], ","));
    for (auto i = start[0]; i <= end[0]; ++i) {
      for (auto j = start[1]; j <= end[1]; ++j) {
        switch (action) {
        case 0: ++field[i][j]; break;
        case 1: if (field[i][j] > 0) --field[i][j]; break;
        case 2: field[i][j] += 2; break;
        }
      }
    }
  }
  int64_t result = 0;
  for (int i = 0; i < 1000; i++) {
    for (int j = 0; j < 1000; j++) {
      result += field[i][j];
    }
  }
  return result;
}

int64_t(*const DAYS[25][2])(ifstream &&in) = {
  {day1_1, day1_2},
  {day2_1, day2_2},
  {day3_1, day3_2},
  {day4_1, day4_2},
  {day5_1, day5_2},
  {day6_1, day6_2},
  {day7_1, day7_2},
  {day8_1, day8_2},
  {day9_1, day9_2},
  {day10_1, day10_2},
  {day11_1, day11_2},
  {day12_1, day12_2},
  {day13_1, day13_2},
  {day14_1, day14_2},
  {day15_1, day15_2},
  {day16_1, day16_2},
  {day17_1, day17_2},
  {day18_1, day18_2},
  {day19_1, day19_2},
  {day20_1, day20_2},
  {day21_1, day21_2},
  {day22_1, day22_2},
  {day23_1, day23_2},
  {day24_1, day24_2},
  {day25_1, day25_2},
};

int main() {
  report(DAYS[DAY - 1][PART - 1](input(2015, DAY)));
}
