#include "../Utility/pch.h"

using namespace std;

const int64_t DAY = 17;
const int64_t PART = 1;

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
    if (sum[i] > (int64_t)lines.size() / 2) {
      result += 1;
    } else if (sum[i] < (int64_t)lines.size() / 2) {
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
      for (auto j = min(coords[i][1], coords[i][3]); j <= max(coords[i][1], coords[i][3]); ++j) {
        ++map[coords[i][0] - bounds[0]][j - bounds[1]];
      }
    }
    if (coords[i][1] == coords[i][3]) {
      for (auto j = min(coords[i][0], coords[i][2]); j <= max(coords[i][0], coords[i][2]); ++j) {
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
      for (auto j = min(coords[i][1], coords[i][3]); j <= max(coords[i][1], coords[i][3]); ++j) {
        ++map[coords[i][0] - bounds[0]][j - bounds[1]];
      }
    } else if (coords[i][1] == coords[i][3]) {
      for (auto j = min(coords[i][0], coords[i][2]); j <= max(coords[i][0], coords[i][2]); ++j) {
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

// given fish doing exponential growth, how many after 80 days?
int64_t day6_1(ifstream &&in) {
  int64_t result = 0;
  auto state = map_to_num(split(slurp(in), ","));
  for (int i = 0; i < 80; ++i) {
    cout << i << endl;
    auto size = state.size();
    for (int j = 0; j < size; ++j) {
      if (--state[j] == -1) {
        state[j] = 6;
        state.push_back(8);
      }
    }
  }
  return state.size();
}

// after 256 days?
int64_t day6_2(ifstream &&in) {
  vi counts = {};
  auto days = 256;
  for (int n = 0; n <= days; ++n) {
    int64_t count = 1;
    for (int i = n - 9; i >= 0; i -= 7) {
      count += counts[i];
    }
    counts.push_back(count);
    cout << n << ": " << count << endl;
  }

  int64_t result = 0;
  auto state = map_to_num(split(slurp(in), ","));
  for (int i = 0; i < days; ++i) {
    //cout << i << endl;
    auto size = state.size();
    for (int j = 0; j < size; ++j) {
      if (--state[j] == -1) {
        state[j] = 6;
        result += counts[days - i - 1];
      }
    }
  }
  return state.size() + result;
}

// minimize sum of differences
int64_t day7_1(ifstream &&in) {
  int64_t result = 0;
  auto tokens = map_to_num(split(slurp(in), ","));
  for (int64_t pos = 0; pos < max(tokens); ++pos) {
    int64_t candidate = 0;
    for (auto token : tokens) {
      candidate += abs(pos - token);
    }
    if (result == 0 || candidate < result) {
      result = candidate;
    }
  }
  return result;
}

// minimize sum of triangles of differences; bonus forgetting the formula and adding a fudge factor based on a test case
int64_t day7_2(ifstream &&in) {
  int64_t result = 0;
  auto tokens = map_to_num(split(slurp(in), ","));
  for (int64_t pos = 0; pos < max(tokens); ++pos) {
    int64_t candidate = 0;
    for (auto token : tokens) {
      candidate += (abs(pos - token) + 1) * abs(pos - token);
    }
    if (result == 0 || candidate < result) {
      result = candidate;
    }
  }
  return result / 2;
}

// spot the 1, 4, 7, 8 digits from the active wires in their unlabelled line diagrams
int64_t day8_1(ifstream &&in) {
  int64_t result = 0;
  //in = ifstream("../TextFile1.txt");
  string line;
  vs patterns = {"abcefg", "cf", "acdeg", "acdfg", "bcdf", "abdfg", "abdefg", "acf", "abcdefg", "abcdfg"};
  while (getline(in, line)) {
    auto tokens = split(split(line, "\\|"), " ");
    for (int i = 0; i < tokens[1].size(); ++i) {
      switch (tokens[1][i].size()) {
      case 2:
      case 3:
      case 4:
      case 7:
        ++result;
        cout << tokens[1][i] << endl;
        break;
      }
    }
  }

  return result;
}

// spot the rest of them, return the sum of all the codes
int64_t day8_2(ifstream &&in) {
  int64_t result = 0;
  //in = ifstream("../TextFile1.txt");
  string line;
  vs patterns = {"abcefg", "cf", "acdeg", "acdfg", "bcdf", "abdfg", "abdefg", "acf", "abcdefg", "abcdfg"};
  //abcefg
  //abdefg
  //abcdfg

  //acdeg
  //acdfg
  //abdfg
  while (getline(in, line)) {
    auto tokens = split(split(line, "\\|"), " ");
    for (int i = 0; i < tokens[0].size(); ++i) {
      sort(tokens[0][i].begin(), tokens[0][i].end());
    }
    map<int, string> code;
    while (code.size() < 10) {
      for (int i = 0; i < tokens[0].size(); ++i) {
        switch (tokens[0][i].size()) {
        case 2:
          code[1] = tokens[0][i];
          break;
        case 3:
          code[7] = tokens[0][i];
          break;
        case 4:
          code[4] = tokens[0][i];
          break;
        case 5:
          if (code.contains(1)) {
            if (tokens[0][i].find(code[1][0]) != string::npos && tokens[0][i].find(code[1][1]) != string::npos) {
              code[3] = tokens[0][i];
            } else if (code.contains(3)) {
              char spare = '\0';
              for (char c : tokens[0][i]) {
                if (code[3].find(c) == string::npos) {
                  spare = c;
                  break;
                }
              }
              if (code.contains(4)) {
                if (code[4].find(spare) == string::npos) {
                  code[2] = tokens[0][i];
                } else {
                  code[5] = tokens[0][i];
                }
              }
            }
          }
          break;
        case 6:
          if (code.contains(1)) {
            if (tokens[0][i].find(code[1][0]) == string::npos || tokens[0][i].find(code[1][1]) == string::npos) {
              code[6] = tokens[0][i];
            } else if (code.contains(4)) {
              bool anyMissing = false;
              for (char c : code[4]) {
                if (tokens[0][i].find(c) == string::npos) {
                  anyMissing = true;
                  break;
                }
              }
              if (anyMissing) {
                code[0] = tokens[0][i];
              } else {
                code[9] = tokens[0][i];
              }
            }
          }
          break;
        case 7:
          code[8] = tokens[0][i];
          break;
        }
      }
    }
    int current = 0;
    for (int i = 0; i < tokens[1].size(); ++i) {
      if (tokens[1][i].size() == 0) {
        continue;
      }
      current *= 10;
      sort(tokens[1][i].begin(), tokens[1][i].end());
      for (auto entry : code) {
        if (entry.second == tokens[1][i]) {
          current += entry.first;
          break;
        }
      }
    }
    result += current;
  }

  return result;
}

// day8_2 implemented with set functions to confirm the new utilities work
int64_t day8_2_clean(ifstream &&in) {
  int64_t result = 0;
  string line;
  while (getline(in, line)) {
    auto tokens = split(split(line, "\\|"), " ");
    vector<set<char>> digits;
    vector<set<char>> unknowns;
    for (int i = 0; i < tokens[0].size(); ++i) {
      digits.push_back({tokens[0][i].begin(), tokens[0][i].end()});
    }
    for (int i = 0; i < tokens[1].size(); ++i) {
      unknowns.push_back({tokens[1][i].begin(), tokens[1][i].end()});
    }
    map<int, set<char>> code;
    while (code.size() < 10) {
      for (int i = 0; i < digits.size(); ++i) {
        switch (digits[i].size()) {
        case 2:
          code[1] = digits[i];
          break;
        case 3:
          code[7] = digits[i];
          break;
        case 4:
          code[4] = digits[i];
          break;
        case 5:
          if (code.contains(1)) {
            if (subset(digits[i], code[1])) {
              code[3] = digits[i];
            } else if (code.contains(3)) {
              char spare = *(set_diff(digits[i], code[3]).begin());
              if (code.contains(4)) {
                if (!code[4].contains(spare)) {
                  code[2] = digits[i];
                } else {
                  code[5] = digits[i];
                }
              }
            }
          }
          break;
        case 6:
          if (code.contains(1)) {
            if (!subset(digits[i], code[1])) {
              code[6] = digits[i];
            } else if (code.contains(4)) {
              if (!subset(digits[i], code[4])) {
                code[0] = digits[i];
              } else {
                code[9] = digits[i];
              }
            }
          }
          break;
        case 7:
          code[8] = digits[i];
          break;
        }
      }
    }
    int current = 0;
    for (int i = 0; i < unknowns.size(); ++i) {
      current *= 10;
      for (auto entry : code) {
        if (entry.second == unknowns[i]) {
          current += entry.first;
          break;
        }
      }
    }
    result += current;
  }

  return result;
}

// find all the points in a grid lower than any adjacent point
int64_t day9_1(ifstream &&in) {
  int64_t result = 0;
  vector<vi> map;
  string line;
  int64_t min = 9;
  while (getline(in, line)) {
    map.push_back({});
    for (auto c : line) {
      map[map.size() - 1].push_back(c - '0');
      if (c - '0' < min) {
        min = c - '0';
      }
    }
  }

  for (int i = 0; i < map.size(); ++i) {
    for (int j = 0; j < map.size(); ++j) {
      bool lower = true;
      if (i > 0 && map[i - 1][j] <= map[i][j]) {
        lower = false;
      }
      if (j > 0 && map[i][j - 1] <= map[i][j]) {
        lower = false;
      }
      if (i < map.size() - 1 && map[i + 1][j] <= map[i][j]) {
        lower = false;
      }
      if (j < map.size() - 1 && map[i][j + 1] <= map[i][j]) {
        lower = false;
      }
      if (lower) {
        result += 1 + map[i][j];
      }
    }
  }

  return result;
}

// find the product of the sizes of the three largest basins
int64_t day9_2(ifstream &&in) {
  int64_t result = 0;
  vector<vi> surface;
  string line;
  //in = ifstream("../TextFile3.txt");
  int64_t min = 9;
  while (getline(in, line)) {
    surface.push_back({});
    for (auto c : line) {
      surface[surface.size() - 1].push_back(c - '0');
      if (c - '0' < min) {
        min = c - '0';
      }
    }
  }

  int64_t label = -1;
  bool changed = true;
  while (changed) {
    changed = false;
    for (int i = 0; i < surface.size(); ++i) {
      for (int j = 0; j < surface[i].size(); ++j) {
        if (surface[i][j] == 9) {
          continue;
        }
        bool lower = true;
        int64_t min_neighbor = 9;
        if (i > 0 && surface[i - 1][j] <= surface[i][j]) {
          lower = false;
          if (surface[i - 1][j] < min_neighbor) {
            min_neighbor = surface[i - 1][j];
          }
        }
        if (j > 0 && surface[i][j - 1] <= surface[i][j]) {
          lower = false;
          if (surface[i][j - 1] < min_neighbor) {
            min_neighbor = surface[i][j - 1];
          }
        }
        if (i < surface.size() - 1 && surface[i + 1][j] <= surface[i][j]) {
          lower = false;
          if (surface[i + 1][j] < min_neighbor) {
            min_neighbor = surface[i + 1][j];
          }
        }
        if (j < surface.size() - 1 && surface[i][j + 1] <= surface[i][j]) {
          lower = false;
          if (surface[i][j + 1] < min_neighbor) {
            min_neighbor = surface[i][j + 1];
          }
        }
        if (lower || (min_neighbor < 9 && min_neighbor >= 0)) {
          cout << label << endl;
          surface[i][j] = label--;
          changed = true;
        } else if (surface[i][j] > min_neighbor) {
          surface[i][j] = min_neighbor;
          changed = true;
        }
      }
    }
  }

  map<int64_t, int64_t> counts;
  for (int i = 0; i < surface.size(); ++i) {
    for (int j = 0; j < surface[i].size(); ++j) {
      if (surface[i][j] != 9) {
        ++counts[surface[i][j]];
      }
      cout << (char)((-surface[i][j] % 26) + 'a' - 1);
    }
    cout << endl;
  }

  vi sizes;
  for (auto entry : counts) {
    cout << entry.first << ": " << entry.second << endl;
    sizes.push_back(entry.second);
  }
  sort(sizes.begin(), sizes.end());
  return sizes[sizes.size() - 1] * sizes[sizes.size() - 2] * sizes[sizes.size() - 3];
}

// find the first non-matching bracket on each line
int64_t day10_1(ifstream &&in) {
  int64_t result = 0;

  string line;
  while (getline(in, line)) {
    vector<char> stack;
    bool done = false;
    for (int i = 0; !done && i < line.size(); ++i) {
      switch (line[i]) {
      case '(': stack.push_back(')'); break;
      case '[': stack.push_back(']'); break;
      case '{': stack.push_back('}'); break;
      case '<': stack.push_back('>'); break;
      case ')': if (stack[stack.size() - 1] != line[i]) {
        result += 3;
        done = true;
      } else {
        stack.pop_back();
      }
              break;
      case ']': if (stack[stack.size() - 1] != line[i]) {
        result += 57;
        done = true;
      } else {
        stack.pop_back();
      }
              break;
      case '}': if (stack[stack.size() - 1] != line[i]) {
        result += 1197;
        done = true;
      } else {
        stack.pop_back();
      }
              break;
      case '>': if (stack[stack.size() - 1] != line[i]) {
        result += 25137;
        done = true;
      } else {
        stack.pop_back();
      }
              break;
      }
    }
  }

  return result;
}

// for lines without a non-matching bracket, find the closing sequence
int64_t day10_2(ifstream &&in) {
  int64_t result = 0;

  vi scores;
  string line;
  while (getline(in, line)) {
    vector<char> stack;
    bool done = false;
    for (int i = 0; !done && i < line.size(); ++i) {
      switch (line[i]) {
      case '(': stack.push_back(')'); break;
      case '[': stack.push_back(']'); break;
      case '{': stack.push_back('}'); break;
      case '<': stack.push_back('>'); break;
      case ')': if (stack[stack.size() - 1] != line[i]) {
        done = true;
      } else {
        stack.pop_back();
      }
              break;
      case ']': if (stack[stack.size() - 1] != line[i]) {
        done = true;
      } else {
        stack.pop_back();
      }
              break;
      case '}': if (stack[stack.size() - 1] != line[i]) {
        done = true;
      } else {
        stack.pop_back();
      }
              break;
      case '>': if (stack[stack.size() - 1] != line[i]) {
        done = true;
      } else {
        stack.pop_back();
      }
              break;
      }
    }
    if (!done) {
      int64_t score = 0;
      for (int64_t i = stack.size() - 1; i >= 0; --i) {
        score *= 5;
        switch (stack[i]) {
        case ')': score += 1; break;
        case ']': score += 2; break;
        case '}': score += 3; break;
        case '>': score += 4; break;
        }
      }
      scores.push_back(score);
    }
  }
  ranges::sort(scores);

  return scores[scores.size() / 2];
}

// measure synchronizing flashes in field of brightening energies
int64_t day11_1(ifstream&& in) {
    int64_t result = 0;
    //in = ifstream("../TextFile2.txt");

    vector<vi> energy;
    string line;
    while (getline(in, line)) {
        vi one = {};
        for (char c : line) {
            one.push_back(c - '0');
        }
        energy.push_back(one);
    }

    for (int i = 0; i < 100; ++i) {
        vector<vi> next(energy);
        for (int j = 0; j < next.size(); ++j) {
            for (int k = 0; k < next[j].size(); ++k) {
                cout << (char)('0' + next[j][k]);
                ++next[j][k];
            }
            cout << endl;
        }
        cout << endl;
        bool changed = true;
        while (changed) {
            changed = false;
            for (int j = 0; j < next.size(); ++j) {
                for (int k = 0; k < next[j].size(); ++k) {
                    if (next[j][k] > 9 && energy[j][k] != -1) {
                        energy[j][k] = -1;
                        ++result;
                        changed = true;
                        for (int l = (j > 0 ? j - 1 : j); l < (j < next.size() - 1 ? j + 2 : j + 1); ++l) {
                            for (int m = (k > 0 ? k - 1 : k); m < (k < next.size() - 1 ? k + 2 : k + 1); ++m) {
                                if (l == j && m == k) {
                                    continue;
                                }
                                ++next[l][m];
                            }
                        }
                    }
                }
            }
        }
        for (int j = 0; j < next.size(); ++j) {
            for (int k = 0; k < next[j].size(); ++k) {
                if (next[j][k] > 9) {
                    next[j][k] = 0;
                }
            }
        }
        energy = next;
    }
    return result;
}

// when do they synchronize?
int64_t day11_2(ifstream&& in) {
    int64_t result = 0;
    in = ifstream("../TextFile2.txt");

    vector<vi> energy;
    string line;
    while (getline(in, line)) {
        vi one = {};
        for (char c : line) {
            one.push_back(c - '0');
        }
        energy.push_back(one);
    }

    for (int i = 0;; ++i) {
        vector<vi> next(energy);
        for (int j = 0; j < next.size(); ++j) {
            for (int k = 0; k < next[j].size(); ++k) {
                cout << (char)('0' + next[j][k]);
                ++next[j][k];
            }
            cout << endl;
        }
        cout << endl;
        bool changed = true;
        while (changed) {
            changed = false;
            for (int j = 0; j < next.size(); ++j) {
                for (int k = 0; k < next[j].size(); ++k) {
                    if (next[j][k] > 9 && energy[j][k] != -1) {
                        energy[j][k] = -1;
                        ++result;
                        changed = true;
                        for (int l = (j > 0 ? j - 1 : j); l < (j < next.size() - 1 ? j + 2 : j + 1); ++l) {
                            for (int m = (k > 0 ? k - 1 : k); m < (k < next.size() - 1 ? k + 2 : k + 1); ++m) {
                                if (l == j && m == k) {
                                    continue;
                                }
                                ++next[l][m];
                            }
                        }
                    }
                }
            }
        }
        bool allFlashed = true;
        for (int j = 0; j < next.size(); ++j) {
            for (int k = 0; k < next[j].size(); ++k) {
                if (next[j][k] > 9) {
                    next[j][k] = 0;
                }
                else {
                    allFlashed = false;
                }
            }
        }
        if (allFlashed) {
            return i + 1;
        }
        energy = next;
    }
    return result;
}

// counts paths from start to end that don't pass thru lowercase rooms more than once
int64_t day12_1(ifstream &&in) {
  int64_t result = 0;
  //in = ifstream("../TextFile4.txt");
  map<string, vs> edges;
  for (auto tokens : split(split(slurp(in)), "-")) {
    edges[tokens[0]].push_back(tokens[1]);
    edges[tokens[1]].push_back(tokens[0]);
  }

  vector<set<vs>> paths;
  paths.push_back({{"start"}});
  bool changed = true;
  for (int i = 1; changed; ++i) {
    changed = false;
    paths.push_back({});
    for (auto path : paths[i - 1]) {
      for (auto edge : edges[path[path.size() - 1]]) {
        bool found = false;
        for (int j = 0; islower(edge[0]) && j < path.size(); ++j) {
          if (path[j] == edge) {
            found = true;
            break;
          }
        }
        if (!found) {
          vs next(path);
          next.push_back(edge);
          paths[i].insert(next);
          changed = true;
          if (edge == "end") {
            /*for (auto str : next) {
              cout << str << ",";
            }*/
            cout << endl;
            ++result;
          }
        }
      }
    }
  }

  return result;
}

// counts paths from start to end that don't pass thru lowercase rooms more than once except for one can be visited twice
int64_t day12_2(ifstream &&in) {
  int64_t result = 0;
  //in = ifstream("../TextFile5.txt");
  map<string, vs> edges;
  for (auto tokens : split(split(slurp(in)), "-")) {
    edges[tokens[0]].push_back(tokens[1]);
    edges[tokens[1]].push_back(tokens[0]);
  }

  vector<set<vs>> paths;
  vector<set<vs>> paths_dupd;
  paths.push_back({{"start"}});
  paths_dupd.push_back({});
  bool changed = true;
  for (int i = 1; changed; ++i) {
    changed = false;
    paths.push_back({});
    paths_dupd.push_back({});
    for (auto path : paths[i - 1]) {
      for (auto edge : edges[path[path.size() - 1]]) {
        if (edge == "start") {
          continue;
        }
        int found = 0;
        for (int j = 0; (islower(edge[0]) && found < 2) && j < path.size(); ++j) {
          if (path[j] == edge) {
            if (edge == "end") {
              found = 2;
            }
            ++found;
          }
        }
        if (found < 2) {
          vs next(path);
          next.push_back(edge);
          if (found == 0) {
            paths[i].insert(next);
          } else {
            paths_dupd[i].insert(next);
          }
          changed = true;
          if (edge == "end") {
            /*/for (auto str : next) {
              cout << str << ",";
            }
            cout << endl;*/
            ++result;
            if (result % 10000 == 0) {
              cout << result << " (" << next.size() << ")" << endl;
            }
          }
        }
      }
    }
    for (auto path : paths_dupd[i - 1]) {
      for (auto edge : edges[path[path.size() - 1]]) {
        if (edge == "start") {
          continue;
        }
        int found = 0;
        for (int j = 0; (islower(edge[0]) && found < 2) && j < path.size(); ++j) {
          if (path[j] == edge) {
            ++found;
          }
        }
        if (found < 1) {
          vs next(path);
          next.push_back(edge);
          paths_dupd[i].insert(next);
          changed = true;
          if (edge == "end") {
            /*/for (auto str : next) {
              cout << str << ",";
            }
            cout << endl;*/
            ++result;
            if (result % 10000 == 0) {
              cout << result << " (" << next.size() << ")" << endl;
            }
          }
        }
      }
    }
  }

  return result;
}

// apply a single fold instruction to a field of dots and count them
int64_t day13_1(ifstream &&in) {
  int64_t result = 0;
  string line;
  set<vi> dots;
  while (getline(in, line)) {
    if (line == "") {
      break;
    }
    dots.insert(map_to_num(split(line, ",")));
  }
  set<vi> next;
  getline(in, line);
  int64_t along = stoll(line.substr(13));
  switch (line[11]) {
  case 'x':
    for (auto dot : dots) {
      if (dot[0] < along) {
        next.insert(dot);
      } else {
        next.insert({2 * along - dot[0], dot[1]});
      }
    }
    break;
  case 'y':
    for (auto dot : dots) {
      if (dot[1] < along) {
        next.insert(dot);
      } else {
        next.insert({dot[0], 2 * along - dot[1]});
      }
    }
    break;
  }
  return next.size();
}

// apply a set of fold instructions to a field of dots and render the result to the screen
// (oops, left all the old dots, but the solution is still visible lol)
int64_t day13_2(ifstream &&in) {
  int64_t result = 0;
  string line;
  set<vi> dots;
  while (getline(in, line)) {
    if (line == "") {
      break;
    }
    dots.insert(map_to_num(split(line, ",")));
  }
  set<vi> next;
  while (getline(in, line)) {
    int64_t along = stoll(line.substr(13));
    switch (line[11]) {
    case 'x':
      for (auto dot : dots) {
        if (dot[0] < along) {
          next.insert(dot);
        } else {
          next.insert({2 * along - dot[0], dot[1]});
        }
      }
      break;
    case 'y':
      for (auto dot : dots) {
        if (dot[1] < along) {
          next.insert(dot);
        } else {
          next.insert({dot[0], 2 * along - dot[1]});
        }
      }
      break;
    }
    dots = next;
  }
  for (int y = 0; y < 120; ++y) {
    for (int x = 0; x < 120; ++x) {
      if (dots.contains({x, y})) {
        cout << "#";
      } else {
        cout << " ";
      }
    }
    cout << endl;
  }
  return next.size();
}

// apply a substitution rule 10 times, find difference between most and least common element
int64_t day14_1(ifstream &&in) {
  int64_t result = 0;
  string temp;
  getline(in, temp);
  string line;
  getline(in, line);
  vector<vs> rules;
  while (getline(in, line)) {
    rules.push_back(split(line, " -> "));
  }
  string current = temp;
  for (int i = 0; i < 10; ++i) {
    for (int j = 0; j < current.length() - 1; ++j) {
      for (int k = 0; k < rules.size(); ++k) {
        if (current[j] == rules[k][0][0] && current[j + 1] == rules[k][0][1]) {
          current = current.substr(0, j + 1) + rules[k][1] + current.substr(j + 1);
          ++j;
          break;
        }
      }
    }
  }

  auto histo = histogram<char>(current);
  int min = 9999, max = 0;
  for (auto entry : histo) {
    if (entry.second < min) {
      min = entry.second;
    }
    if (entry.second > max) {
      max = entry.second;
    }
  }
  return max - min;
}

// apply it 40 times (secretly falling back to a digraph frequency chart)
int64_t day14_2(ifstream &&in) {
  int64_t result = 0;
  string temp;
  getline(in, temp);
  string line;
  getline(in, line);
  map<string, string> rules;
  while (getline(in, line)) {
    auto rule = split(line, " -> ");
    rules[rule[0]] = rule[1];
  }
  string current = temp;
  map<string, int64_t> freq;
  for (int j = 0; j < current.length() - 1; ++j) {
    ++freq[current.substr(j, 2)];
  }
  for (int i = 0; i < 40; ++i) {
    map<string, int64_t> nextFreq;
    for (auto entry : freq) {
      if (rules.contains(entry.first)) {
        nextFreq[entry.first.substr(0, 1) + rules[entry.first]] += entry.second;
        nextFreq[rules[entry.first] + entry.first.substr(1, 1)] += entry.second;
      } else {
        nextFreq[entry.first] += entry.second;
      }
    }
    freq = nextFreq;
  }

  map<char, int64_t> histo;
  for (auto entry : freq) {
    histo[entry.first[0]] += entry.second;
  }
  histo[temp[temp.length() - 1]]++;

  int64_t max = -1, min = -1;
  for (auto entry : histo) {
    if (entry.second > max || max == -1) {
      max = entry.second;
    }
    if (entry.second < min || min == -1) {
      min = entry.second;
    }
  }

  return max - min;
}

// find lowest-cost path from top left to bottom right corner of a map
int64_t day15_1(ifstream &&in) {
  int64_t result = 0;
  vector<vi> map;
  string line;
  while (getline(in, line)) {
    map.push_back({});
    for (char c : line) {
      map[map.size() - 1].push_back(c - '0');
    }
  }
  vector<vi> costs;
  for (int i = 0; i < map.size(); ++i) {
    costs.push_back({});
    for (int j = 0; j < map[i].size(); ++j) {
      costs[i].push_back({-1});
    }
  }
  costs[0][0] = 0;
  bool changed = true;
  while (changed) {
    changed = false;
    for (int i = 0; i < map.size(); ++i) {
      for (int j = 0; j < map[i].size(); ++j) {
        if (i > 0 && costs[i - 1][j] != -1 && (costs[i][j] == -1 || costs[i][j] > costs[i - 1][j] + map[i][j])) {
          costs[i][j] = costs[i - 1][j] + map[i][j];
          changed = true;
        }
        if (i < map.size() - 1 && costs[i + 1][j] != -1 && (costs[i][j] == -1 || costs[i][j] > costs[i + 1][j] + map[i][j])) {
          costs[i][j] = costs[i + 1][j] + map[i][j];
          changed = true;
        }
        if (j > 0 && costs[i][j - 1] != -1 && (costs[i][j] == -1 || costs[i][j] > costs[i][j - 1] + map[i][j])) {
          costs[i][j] = costs[i][j - 1] + map[i][j];
          changed = true;
        }
        if (j < map.size() - 1 && costs[i][j + 1] != -1 && (costs[i][j] == -1 || costs[i][j] > costs[i][j + 1] + map[i][j])) {
          costs[i][j] = costs[i][j + 1] + map[i][j];
          changed = true;
        }
      }
    }
  }

  return costs[costs.size() - 1][costs[0].size() - 1];
}

// same, but tesselate the map to 5x5 with mutation
int64_t day15_2(ifstream &&in) {
  int64_t result = 0;
  vector<vi> map;
  string line;
  //in = ifstream("../TextFile1.txt");
  while (getline(in, line)) {
    map.push_back({});
    for (char c : line) {
      map[map.size() - 1].push_back(c - '0');
    }
  }
  auto origi = map.size();
  auto origj = map[0].size();
  for (int i = 0; i < 5; ++i) {
    if (i > 0) {
      for (int j = 0; j < origi; j++) {
        map.push_back({});
      }
    }
    for (int j = 0; j < 5; ++j) {
      if (i == 0 && j == 0) {
        continue;
      }
      if (j > 0) {
        for (int k = 0; k < origi; ++k) {
          for (int l = 0; l < origj; ++l) {
            map[origi * i + k].push_back(map[origi * i + k][origj * (j - 1) + l] % 9 + 1);
          }
        }
      } else {
        for (int k = 0; k < origi; ++k) {
          for (int l = 0; l < origj; ++l) {
            map[origi * i + k].push_back(map[origi * (i - 1) + k][origj * j + l] % 9 + 1);
          }
        }
      }
    }
  }
  vector<vi> costs;
  for (int i = 0; i < map.size(); ++i) {
    costs.push_back({});
    for (int j = 0; j < map[i].size(); ++j) {
      costs[i].push_back({-1});
    }
  }
  costs[0][0] = 0;
  bool changed = true;
  while (changed) {
    changed = false;
    for (int i = 0; i < map.size(); ++i) {
      for (int j = 0; j < map[i].size(); ++j) {
        if (i > 0 && costs[i - 1][j] != -1 && (costs[i][j] == -1 || costs[i][j] > costs[i - 1][j] + map[i][j])) {
          costs[i][j] = costs[i - 1][j] + map[i][j];
          changed = true;
        }
        if (i < map.size() - 1 && costs[i + 1][j] != -1 && (costs[i][j] == -1 || costs[i][j] > costs[i + 1][j] + map[i][j])) {
          costs[i][j] = costs[i + 1][j] + map[i][j];
          changed = true;
        }
        if (j > 0 && costs[i][j - 1] != -1 && (costs[i][j] == -1 || costs[i][j] > costs[i][j - 1] + map[i][j])) {
          costs[i][j] = costs[i][j - 1] + map[i][j];
          changed = true;
        }
        if (j < map.size() - 1 && costs[i][j + 1] != -1 && (costs[i][j] == -1 || costs[i][j] > costs[i][j + 1] + map[i][j])) {
          costs[i][j] = costs[i][j + 1] + map[i][j];
          changed = true;
        }
      }
    }
  }

  return costs[costs.size() - 1][costs[0].size() - 1];
}

int64_t day15_1_clean(ifstream &&in) {
  int64_t result = 0;
  auto map = map_to_num(split(split(slurp(in)), ""));
  auto costs = grid(map.size(), map[0].size(), -1ll);
  costs[0][0] = 0;

  bool changed = true;
  while (changed) {
    changed = false;
    for (auto cell : cells(costs)) {
      for (auto adj : adjacent(cell)) {
        if (*adj == -1) {
          continue;
        }
        auto cost = cell(map) + *adj;
        if (*cell == -1 || cost < *cell) {
          *cell = cost;
          changed = true;
        }
      }
    }
  }
  return costs[costs.size() - 1][costs[0].size() - 1];
}

int64_t day15_2_clean(ifstream &&in) {
  int64_t result = 0;
  //in = ifstream("../TextFile2.txt");
  auto base_map = map_to_num(split(split(slurp(in)), ""));

  auto map = base_map;
  for (int i = 1; i < 5; ++i) {
    base_map = transform<int64_t>(base_map, [](int64_t a) { return (a % 9) + 1; });
    map = concat_right(map, base_map);
  }
  base_map = map;
  for (int j = 1; j < 5; ++j) {
    base_map = transform<int64_t>(base_map, [](int64_t a) { return (a % 9) + 1; });
    map = concat_down(map, base_map);
  }

  auto costs = grid(map.size(), map[0].size(), -1ll);
  costs[0][0] = 0;

  bool changed = true;
  while (changed) {
    changed = false;
    for (auto cell : cells(costs)) {
      for (auto adj : adjacent(cell)) {
        if (*adj == -1) {
          continue;
        }
        auto cost = cell(map) + *adj;
        if (*cell == -1 || cost < *cell) {
          *cell = cost;
          changed = true;
        }
      }
    }
  }
  return costs[costs.size() - 1][costs[0].size() - 1];
}

// sum the versions of all the packets in the given BITS stream
int64_t day16_1(ifstream &&in) {
  int64_t result = 0;
  string line = slurp(in);
  vector<bool> bits;
  for (int i = 0; i < line.size(); ++i) {
    int one = line[i] >= 'A' ? (line[i] - 'A' + 10) : line[i] - '0';
    for (int j = 0; j < 4; j++) {
      bits.push_back((one & 8) != 0);
      //cout << bits[bits.size() - 1];
      one <<= 1;
    }
  }
  size_t index = 0;
  int64_t sum = 0;
  auto packet = parse_BITS_packet_sum(bits, index, sum);
  return sum;
}

// evaluate the result of the given BITS stream
int64_t day16_2(ifstream &&in) {
  int64_t result = 0;
  string line = slurp(in);
  vector<bool> bits;
  for (int i = 0; i < line.size(); ++i) {
    int one = line[i] >= 'A' ? (line[i] - 'A' + 10) : line[i] - '0';
    for (int j = 0; j < 4; j++) {
      bits.push_back((one & 8) != 0);
      //cout << bits[bits.size() - 1];
      one <<= 1;
    }
  }
  size_t index = 0;
  int64_t sum = 0;
  auto packet = parse_BITS_packet_sum(bits, index, sum);
  return packet.result;
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
