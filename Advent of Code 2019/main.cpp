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

// sum of (m/3)-2 for a set of masses
int64_t day1_1(ifstream &&in) {
  int64_t result = 0;
  auto nums = map_to_num(split(slurp(in)));
  for (auto num : nums) {
    result += (num / 3) - 2;
  }

  return result;
}

// additionally, each unit of fuel calculated above needs fuel for itself recursively
int64_t day1_2(ifstream &&in) {
  int64_t result = 0;
  auto nums = map_to_num(split(slurp(in)));
  for (auto num : nums) {
    auto mass = (num / 3) - 2;
    while (mass > 0) {
      result += mass;
      mass = (mass / 3) - 2;
    }
  }

  return result;
}

// eeeeeee, INTCODE!!!!! emulate a simple computer, give its output
int64_t day2_1(ifstream &&in) {
  int64_t result = 0;
  auto nums = get_nums(in, ",");
  nums[1] = 12;
  nums[2] = 2;
  bool done = false;
  for (int i = 0; !done && i < nums.size(); i += 4) {
    //for (int j = 0; j < nums.size(); ++j) {
    //  cout << (j == i ? "!" : "") << nums[j] << " ";
    //}
    //cout << endl;

    switch (nums[i]) {
    case 1: nums[nums[i + 3]] = nums[nums[i + 1]] + nums[nums[i + 2]]; break;
    case 2: nums[nums[i + 3]] = nums[nums[i + 1]] * nums[nums[i + 2]]; break;
    case 99: done = true; break;
    default: cout << "Unhandled opcode " << nums[i] << endl; break;
    }
  }
  return nums[0];
}

// find the inputs that produce the given output
int64_t day2_2(ifstream &&in) {
  int64_t result = 0;
  auto base_nums = get_nums(in, ",");
  for (int i = 0; i < 100; ++i) {
    for (int j = 0; j < 100; ++j) {
      auto nums = base_nums;
      nums[1] = i;
      nums[2] = j;
      bool done = false;
      for (int i = 0; !done && i < nums.size(); i += 4) {
        switch (nums[i]) {
        case 1: nums[nums[i + 3]] = nums[nums[i + 1]] + nums[nums[i + 2]]; break;
        case 2: nums[nums[i + 3]] = nums[nums[i + 1]] * nums[nums[i + 2]]; break;
        case 99: done = true; break;
        default: cout << "Unhandled opcode " << nums[i] << endl; break;
        }
      }
      if (nums[0] == 19690720) {
        return 100 * nums[1] + nums[2];
      }
    }
  }
  return 0;
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
  report(DAYS[DAY - 1][PART - 1](input(2019, DAY)));
}
