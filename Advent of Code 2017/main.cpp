#include "../Utility/pch.h"

using namespace std;

const int64_t DAY = 2;
const int64_t PART = 1;

int64_t day2_1(ifstream &&in) {
  int64_t result = 0;

  return result;
}

int64_t day2_2(ifstream &&in) {
  int64_t result = 0;

  return result;
}

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

// sum of digits that match the next digit in a *circular* list
int64_t day1_1(ifstream &&in) {
  int last = 0;
  int64_t result = 0;
  auto line = slurp(in);
  for (char c : line) {
    if (c == last) {
      result += c - '0';
    }
    last = c;
  }
  if (last == line[0]) {
    result += last - '0';
  }

  return result;
}

// sum of digits that match the opposing digit in a *circular* list
int64_t day1_2(ifstream &&in) {
  int last = 0;
  int64_t result = 0;
  auto line = slurp(in);
  int pos = 0;
  for (char c : line) {
    if (c == line[(pos++ + line.size() / 2) % line.size()]) {
      result += c - '0';
    }
    last = c;
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
  report(DAYS[DAY - 1][PART - 1](input(2017, DAY)));
}
