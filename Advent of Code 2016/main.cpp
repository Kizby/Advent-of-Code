#include "../Utility/pch.h"

using namespace std;

const int64_t DAY = 3;
const int64_t PART = 1;

int64_t day3_1(ifstream &&in) {
  int64_t result = 0;

  return result;
}

int64_t day3_2(ifstream &&in) {
  int64_t result = 0;

  return result;
}

int64_t day4_1(ifstream &&in) {
  int64_t result = 0;

  return result;
}

int64_t day4_2(ifstream &&in) {
  int64_t result = 0;

  return result;
}

int64_t day5_1(ifstream &&in) {
  int64_t result = 0;

  return result;
}

int64_t day5_2(ifstream &&in) {
  int64_t result = 0;

  return result;
}

int64_t day6_1(ifstream &&in) {
  int64_t result = 0;

  return result;
}

int64_t day6_2(ifstream &&in) {
  int64_t result = 0;

  return result;
}

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

// given directions of the form R5 or L17, navigate a grid; how many blocks away do you end up?
int64_t day1_1(ifstream &&in) {
  vi pos = {0, 0};
  vector<vi> dirs = {
    {1, 0},
    {0, 1},
    {-1, 0},
    {0, -1},
  };
  int dir = 0;
  for (auto &token : split(slurp(in), ", ")) {
    auto dist = stoll(token.substr(1));
    switch (token[0]) {
    case 'R': dir = (dir + 1) % 4; break;
    case 'L': dir = (dir + 3) % 4; break;
    }
    pos[0] += dirs[dir][0] * dist;
    pos[1] += dirs[dir][1] * dist;
    cout << token << ": " << pos[0] << ", " << pos[1] << endl;
  }
  int64_t result = abs(pos[0]) + abs(pos[1]);

  return result;
}

// what's the first coordinate you traverse twice?
int64_t day1_2(ifstream &&in) {
  vi pos = {0, 0};
  vector<vi> dirs = {
    {1, 0},
    {0, 1},
    {-1, 0},
    {0, -1},
  };
  int dir = 0;
  set<vi> seen = {{0, 0}};
  for (auto &token : split(slurp(in), ", ")) {
    auto dist = stoll(token.substr(1));
    switch (token[0]) {
    case 'R': dir = (dir + 1) % 4; break;
    case 'L': dir = (dir + 3) % 4; break;
    }
    for (int i = 0; i < dist; ++i) {
      pos[0] += dirs[dir][0];
      pos[1] += dirs[dir][1];
      if (!seen.insert(pos).second) {
        return abs(pos[0]) + abs(pos[1]);
      }
    }
    cout << token << ": " << pos[0] << ", " << pos[1] << endl;
  }
  int64_t result = abs(pos[0]) + abs(pos[1]);

  return result;
}

// navigate a numpad, give the code
int64_t day2_1(ifstream &&in) {
  string result = "";
  vi pos = {1, 1};
  vector<vi> nums = {
    {1, 2, 3},
    {4, 5, 6},
    {7, 8, 9},
  };
  for (auto s : split(slurp(in))) {
    for (auto c : s) {
      switch (c) {
      case 'U': --pos[0]; if (pos[0] < 0) pos[0] = 0; break;
      case 'D': ++pos[0]; if (pos[0] > 2) pos[0] = 2; break;
      case 'L': --pos[1]; if (pos[1] < 0) pos[1] = 0; break;
      case 'R': ++pos[1]; if (pos[1] > 2) pos[1] = 2; break;
      }
    }
    result += to_string(nums[pos[0]][pos[1]]);
  }

  report(result);
  exit(0);
}

// larger numpad
int64_t day2_2(ifstream &&in) {
  string result = "";
  vi pos = {3, 1};
  vector<vi> nums = {
    {0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 1, 0, 0, 0},
    {0, 0, 2, 3, 4, 0, 0},
    {0, 5, 6, 7, 8, 9, 0},
    {0, 0, 10, 11, 12, 0},
    {0, 0, 0, 13, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0},
  };
  for (auto s : split(slurp(in))) {
    for (auto c : s) {
      switch (c) {
      case 'U': --pos[0]; if (nums[pos[0]][pos[1]] == 0) ++pos[0]; break;
      case 'D': ++pos[0]; if (nums[pos[0]][pos[1]] == 0) --pos[0]; break;
      case 'L': --pos[1]; if (nums[pos[0]][pos[1]] == 0) ++pos[1]; break;
      case 'R': ++pos[1]; if (nums[pos[0]][pos[1]] == 0) --pos[1]; break;
      }
    }
    string next = to_string(nums[pos[0]][pos[1]]);
    if (next.size() > 1) {
      next = string(1, next[1] - '0' + 'A');
    }
    result += next;
  }

  report(result);
  exit(0);
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
  report(DAYS[DAY - 1][PART - 1](input(2016, DAY)));
}
