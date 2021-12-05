#include "../Utility/pch.h"

using namespace std;

const int64_t DAY = 6;
const int64_t PART = 1;

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

// how many measurements are higher than the previous one?
int64_t day1_1(ifstream &&in) {
  int64_t last = 0;
  int count = 0;
  for (auto a : map_to_num(split(slurp(in)))) {
    if (a > last) {
      ++count;
    }
    last = a;
  }
  return count - 1;
}

// now with a three-day sliding window
int64_t day1_2(ifstream &&in) {
  vector<int64_t> last = {0, 0, 0};
  int count = 0;
  int pos = 0;
  int64_t prev = 0;
  for (auto a : map_to_num(split(slurp(in)))) {
    last[pos++ % 3] = a;
    if (pos > 3 && sum(last) > prev) {
      ++count;
    }
    prev = sum(last);
    //cout << prev << endl;
  }
  return count;
}

// parse forward/up/down directions to find the final position of the submarine
int64_t day2_1(ifstream &&in) {
  string line;
  vector<int64_t> pos = {0, 0};
  while (getline(in, line)) {
    auto tokens = split(line, " ");
    switch (tokens[0][0]) {
    case 'f': pos[0] += stoll(tokens[1]); break;
    case 'u': pos[1] -= stoll(tokens[1]); break;
    case 'd': pos[1] += stoll(tokens[1]); break;
    }
  }
  int64_t result = product(pos);

  return result;
}

// reinterpret up and down as changing the "aim" of the sub
int64_t day2_2(ifstream &&in) {
  string line;
  vector<int64_t> pos = {0, 0};
  int64_t aim = 0;
  while (getline(in, line)) {
    auto tokens = split(line, " ");
    switch (tokens[0][0]) {
    case 'f': pos[0] += stoll(tokens[1]); pos[1] += stoll(tokens[1]) * aim; break;
    case 'u': aim -= stoll(tokens[1]); break;
    case 'd': aim += stoll(tokens[1]); break;
    }
  }
  int64_t result = product(pos);

  return result;
}

// product of number composed of most common bits and number composed of least common bits
int64_t day3_1(ifstream &&in) {
  int64_t result = 0;
  auto lines = split(slurp(in));
  vi sum(lines[0].size());
  for (int i = 0; i < lines.size(); ++i) {
    //cout << lines[i] << endl;
    for (int j = 0; j < lines[i].size(); ++j) {
      if (lines[i][j] == '1') {
        sum[j]++;
      }
    }
  }
  int64_t epsilon = 0;
  for (int i = 0; i < sum.size(); ++i) {
    cout << sum[i] << " ";
    result <<= 1;
    epsilon <<= 1;
    if (sum[i] > lines.size() / 2) {
      result += 1;
    } else if (sum[i] < lines.size() / 2) {
      epsilon += 1;
    }
  }

  return result * epsilon;
}

// iteratively keep values with most common bit until one remains; multiply them
int64_t day3_2(ifstream &&in) {
  int64_t result = 0;
  auto lines = split(slurp(in));// "00100    11110    10110    10111    10101    01111    00111    11100    10000    11001    00010    01010", " +");//slurp(in));
  vi sum(lines[0].size());
  for (int i = 0; i < lines.size(); ++i) {
    //cout << lines[i] << endl;
    for (int j = 0; j < lines[i].size(); ++j) {
      if (lines[i][j] == '1') {
        sum[j]++;
      }
    }
  }
  vs oxygen = lines;
  vi sumox = sum;
  vs co2 = lines;
  vi sumco2 = sum;
  for (int j = 0; j < sum.size(); ++j) {
    vs next_oxygen;
    vs next_co2;
    if (oxygen.size() > 1) {
      for (int i = 0; i < oxygen.size(); ++i) {
        if ((sumox[j] < oxygen.size() / 2.) != (oxygen[i][j] == '1')) {
          next_oxygen.push_back(oxygen[i]);
        }
      }
      sumox = vi(sum.size());
      oxygen = next_oxygen;
      for (int i = 0; i < oxygen.size(); ++i) {
        for (int k = 0; k < oxygen[i].size(); ++k) {
          if (oxygen[i][k] == '1') {
            sumox[k]++;
          }
        }
      }
    }
    if (co2.size() > 1) {
      for (int i = 0; i < co2.size(); ++i) {
        if ((sumco2[j] >= co2.size() / 2.) != (co2[i][j] == '1')) {
          next_co2.push_back(co2[i]);
        }
      }
      sumco2 = vi(sum.size());
      co2 = next_co2;
      for (int i = 0; i < co2.size(); ++i) {
        for (int k = 0; k < co2[i].size(); ++k) {
          if (co2[i][k] == '1') {
            sumco2[k]++;
          }
        }
      }
    }
  }
  //cout << oxygen[0] << " " << co2[0] << endl;
  return stoll(oxygen[0], nullptr, 2) * stoll(co2[0], nullptr, 2);
}

// which bingo board wins first?
int64_t day4_1(ifstream &&in) {
  string line;
  getline(in, line);
  auto draws = map_to_num(split(line, ","));
  vector<vector<vi>> boards;
  while (getline(in, line)) {
    vector<vi> board;
    for (int i = 0; i < 5; ++i) {
      getline(in, line);
      board.push_back(map_to_num(split(line, " +")));
    }
    boards.push_back(board);
  }

  int64_t result = 0;
  set<int64_t> seen;
  for (auto draw : draws) {
    seen.insert(draw);
    for (auto board : boards) {
      bool wonRow = true;
      bool wonCol = true;
      for (int i = 0; i < 5; ++i) {
        wonRow = true;
        wonCol = true;
        for (int j = 0; j < 5; ++j) {
          if (!seen.contains(board[i][j])) {
            wonRow = false;
          }
          if (!seen.contains(board[j][i])) {
            wonCol = false;
          }
        }
        if (wonRow || wonCol) {
          break;
        }
      }
      if (wonRow || wonCol) {
        for (int i = 0; i < 5; ++i) {
          for (int j = 0; j < 5; ++j) {
            if (!seen.contains(board[i][j])) {
              result += board[i][j];
            }
          }
        }
        return result * draw;
      }
    }
  }

  return result;
}

// which bingo board wins last?
int64_t day4_2(ifstream &&in) {
  //in = ifstream("../TextFile1.txt");
  string line;
  getline(in, line);
  auto draws = map_to_num(split(line, ","));
  vector<vector<vi>> boards;
  while (getline(in, line)) {
    vector<vi> board;
    for (int i = 0; i < 5; ++i) {
      getline(in, line);
      while (line[0] == ' ') {
        line = line.substr(1);
      }
      board.push_back(map_to_num(split(line, " +")));
    }
    boards.push_back(board);
  }

  int64_t result = 0;
  set<int64_t> seen;
  set<vector<vi>> victors;
  for (auto draw : draws) {
    seen.insert(draw);
    for (auto board : boards) {
      if (victors.contains(board)) {
        continue;
      }
      bool wonRow = true;
      bool wonCol = true;
      for (int i = 0; i < 5; ++i) {
        wonRow = true;
        wonCol = true;
        for (int j = 0; j < 5; ++j) {
          if (!seen.contains(board[i][j])) {
            wonRow = false;
          }
          if (!seen.contains(board[j][i])) {
            wonCol = false;
          }
        }
        if (wonRow || wonCol) {
          break;
        }
      }
      if (wonRow || wonCol) {
        victors.insert(board);
        if (victors.size() == boards.size()) {
          for (int i = 0; i < 5; ++i) {
            for (int j = 0; j < 5; ++j) {
              if (!seen.contains(board[i][j])) {
                result += board[i][j];
              }
            }
          }
          return result * draw;
        }
      }
    }
  }

  return result;
}

// draw horizontal and vertical lines, count how many points are covered by more than one
int64_t day5_1(ifstream &&in) {
  //in = ifstream("../TextFile2.txt");
  int64_t result = 0;
  set<vi> seen;
  auto tokens = split(split(slurp(in)), "(,)|( -> )");
  vector<vi> coords;
  vi bounds = {0, 0, 0, 0};
  for (int i = 0; i < tokens.size(); ++i) {
    coords.push_back(map_to_num(tokens[i]));
    if (coords[i][0] < bounds[0]) {
      bounds[0] = coords[i][0];
    }
    if (coords[i][0] > bounds[2]) {
      bounds[2] = coords[i][0];
    }
    if (coords[i][1] < bounds[1]) {
      bounds[1] = coords[i][1];
    }
    if (coords[i][1] > bounds[3]) {
      bounds[3] = coords[i][1];
    }
    if (coords[i][2] < bounds[0]) {
      bounds[0] = coords[i][0];
    }
    if (coords[i][2] > bounds[2]) {
      bounds[2] = coords[i][0];
    }
    if (coords[i][3] < bounds[1]) {
      bounds[1] = coords[i][1];
    }
    if (coords[i][3] > bounds[3]) {
      bounds[3] = coords[i][1];
    }
  }
  vector<vi> map;
  for (auto i = bounds[0]; i <= bounds[2]; ++i) {
    map.push_back(vi(bounds[3] - bounds[1] + 1));
  }
  for (int i = 0; i < coords.size(); ++i) {
    if (coords[i][0] == coords[i][2]) {
      for (int j = min(coords[i][1], coords[i][3]); j <= max(coords[i][1], coords[i][3]); ++j) {
        ++map[coords[i][0] - bounds[0]][j - bounds[1]];
      }
    }
    if (coords[i][1] == coords[i][3]) {
      for (int j = min(coords[i][0], coords[i][2]); j <= max(coords[i][0], coords[i][2]); ++j) {
        ++map[j - bounds[0]][coords[i][1] - bounds[1]];
      }
    }
  }
  for (int i = 0; i < map.size(); ++i) {
    for (int j = 0; j < map[i].size(); ++j) {
      if (map[i][j] > 1) {
        ++result;
      }
    }
  }

  return result;
}

// now 1:1 diagonal lines as well
int64_t day5_2(ifstream &&in) {
  //in = ifstream("../TextFile2.txt");
  int64_t result = 0;
  set<vi> seen;
  auto tokens = split(split(slurp(in)), "(,)|( -> )");
  vector<vi> coords;
  vi bounds = {0, 0, 0, 0};
  for (int i = 0; i < tokens.size(); ++i) {
    coords.push_back(map_to_num(tokens[i]));
    if (coords[i][0] < bounds[0]) {
      bounds[0] = coords[i][0];
    }
    if (coords[i][0] > bounds[2]) {
      bounds[2] = coords[i][0];
    }
    if (coords[i][1] < bounds[1]) {
      bounds[1] = coords[i][1];
    }
    if (coords[i][1] > bounds[3]) {
      bounds[3] = coords[i][1];
    }
    if (coords[i][2] < bounds[0]) {
      bounds[0] = coords[i][0];
    }
    if (coords[i][2] > bounds[2]) {
      bounds[2] = coords[i][0];
    }
    if (coords[i][3] < bounds[1]) {
      bounds[1] = coords[i][1];
    }
    if (coords[i][3] > bounds[3]) {
      bounds[3] = coords[i][1];
    }
  }
  vector<vi> map;
  for (auto i = bounds[0]; i <= bounds[2]; ++i) {
    map.push_back(vi(bounds[3] - bounds[1] + 1));
  }
  for (int i = 0; i < coords.size(); ++i) {
    if (coords[i][0] == coords[i][2]) {
      for (int j = min(coords[i][1], coords[i][3]); j <= max(coords[i][1], coords[i][3]); ++j) {
        ++map[coords[i][0] - bounds[0]][j - bounds[1]];
      }
    } else if (coords[i][1] == coords[i][3]) {
      for (int j = min(coords[i][0], coords[i][2]); j <= max(coords[i][0], coords[i][2]); ++j) {
        ++map[j - bounds[0]][coords[i][1] - bounds[1]];
      }
    } else {
      // diagonal
      auto dx = coords[i][2] - coords[i][0];
      dx /= abs(dx);
      auto dy = coords[i][3] - coords[i][1];
      dy /= abs(dy);
      for (int j = 0; j <= abs(coords[i][0] - coords[i][2]); ++j) {
        ++map[coords[i][0] + dx * j - bounds[0]][coords[i][1] + dy * j - bounds[1]];
      }
    }

  }
  for (int i = 0; i < map.size(); ++i) {
    for (int j = 0; j < map[i].size(); ++j) {
      if (map[i][j] > 1) {
        ++result;
      }
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
  report(DAYS[DAY - 1][PART - 1](input(2021, DAY)));
}
