#include "../Utility/pch.h"

using namespace std;

const int64_t DAY = 13;
const int64_t PART = 1;

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

struct day7_connection {
  string in1;
  string in2;
  string op;
};

uint16_t calculate(string which, const unordered_map<string, day7_connection> &wires, unordered_map<string, uint16_t> &cache) {
  if (!cache.contains(which)) {
    if (isdigit(which[0])) {
      return (uint16_t)stoull(which);
    }
    auto command = wires.at(which);
    if (command.op == "STORE") {
      cache[which] = calculate(command.in1, wires, cache);
    } else if (command.op == "NOT") {
      cache[which] = ~calculate(command.in1, wires, cache);
    } else if (command.op == "AND") {
      cache[which] = calculate(command.in1, wires, cache) & calculate(command.in2, wires, cache);
    } else if (command.op == "OR") {
      cache[which] = calculate(command.in1, wires, cache) | calculate(command.in2, wires, cache);
    } else if (command.op == "LSHIFT") {
      cache[which] = calculate(command.in1, wires, cache) << calculate(command.in2, wires, cache);
    } else if (command.op == "RSHIFT") {
      cache[which] = calculate(command.in1, wires, cache) >> calculate(command.in2, wires, cache);
    }
  }
  return cache[which];
}

// given the circuit description, what value is on wire a?
int64_t day7_1(ifstream &&in) {
  unordered_map<string, day7_connection> wires = {};
  for (auto tokens : split(split(slurp(in)), " ")) {
    if (tokens.size() == 3) {
      wires[tokens[2]] = day7_connection{.in1 = tokens[0], .op = "STORE"};
    } else if (tokens.size() == 4) {
      wires[tokens[3]] = day7_connection{.in1 = tokens[1], .op = tokens[0]};
    } else {
      wires[tokens[4]] = day7_connection{.in1 = tokens[0], .in2 = tokens[2], .op = tokens[1]};
    }
  }
  unordered_map<string, uint16_t> cache = {};
  return calculate("a", wires, cache);
}

// override wire b with a's value, then recalculate a
int64_t day7_2(ifstream &&in) {
  unordered_map<string, day7_connection> wires = {};
  for (auto tokens : split(split(slurp(in)), " ")) {
    if (tokens.size() == 3) {
      wires[tokens[2]] = day7_connection{.in1 = tokens[0], .op = "STORE"};
    } else if (tokens.size() == 4) {
      wires[tokens[3]] = day7_connection{.in1 = tokens[1], .op = tokens[0]};
    } else {
      wires[tokens[4]] = day7_connection{.in1 = tokens[0], .in2 = tokens[2], .op = tokens[1]};
    }
  }
  unordered_map<string, uint16_t> cache = {};
  wires["b"] = day7_connection{.in1 = to_string(calculate("a", wires, cache)), .op = "STORE"};
  cache = {};
  return calculate("a", wires, cache);
}

// how many more characters are there in the given escaped representations of strings than in the underlying strings themselves?
int64_t day8_1(ifstream &&in) {
  int64_t result = 0;
  string line;
  while (getline(in, line)) {
    result += 2;
    for (size_t pos = line.find('\\'); pos != string::npos && pos < line.length() - 1; pos = line.find('\\', pos + 2)) {
      if (line[pos + 1] == '\\') {
        ++result;
      } else if (line[pos + 1] == '"') {
        ++result;
      } else if (line[pos + 1] == 'x') {
        result += 3;
      }
    }
  }
  return result;
}

// how many additional characters would be required to escape these strings?
int64_t day8_2(ifstream &&in) {
  int64_t result = 0;
  string line;
  while (getline(in, line)) {
    result += 2;
    for (auto c : line) {
      switch (c) {
      case '"': ++result; break;
      case '\\': ++result; break;
      }
    }
  }
  return result;
}

// travelling salesman, given distances between pairs, what's the shortest route hitting them all?
int64_t day9_1(ifstream &&in) {
  unordered_map<string, unordered_map<string, int64_t>> costs = {};
  vector<string> cities = {};
  for (auto tokens : split(split(slurp(in)), " ")) {
    if (!costs.contains(tokens[0])) {
      cities.push_back(tokens[0]);
    }
    if (!costs.contains(tokens[2])) {
      cities.push_back(tokens[2]);
    }
    costs[tokens[0]][tokens[2]] = costs[tokens[2]][tokens[0]] = stoll(tokens[4]);
  }

  int64_t result = 0;
  for (auto perm : permutations(cities.size())) {
    int64_t dist = 0;
    for (int i = 0; i < perm.size() - 1; ++i) {
      dist += costs[cities[perm[i]]][cities[perm[i + 1]]];
    }
    if (result == 0 || dist < result) {
      result = dist;
    }
  }

  return result;
}

// what's the longest?
int64_t day9_2(ifstream &&in) {
  unordered_map<string, unordered_map<string, int64_t>> costs = {};
  vector<string> cities = {};
  for (auto tokens : split(split(slurp(in)), " ")) {
    if (!costs.contains(tokens[0])) {
      cities.push_back(tokens[0]);
    }
    if (!costs.contains(tokens[2])) {
      cities.push_back(tokens[2]);
    }
    costs[tokens[0]][tokens[2]] = costs[tokens[2]][tokens[0]] = stoll(tokens[4]);
  }

  int64_t result = 0;
  for (auto perm : permutations(cities.size())) {
    int64_t dist = 0;
    for (int i = 0; i < perm.size() - 1; ++i) {
      dist += costs[cities[perm[i]]][cities[perm[i + 1]]];
    }
    if (dist > result) {
      result = dist;
    }
  }

  return result;
}

// find the length of the 40th iteration of a look-and-say sequence
int64_t day10_1(ifstream &&in) {
  string lines[41] = {};
  lines[0] = slurp(in);
  for (int i = 1; i <= 40; ++i) {
    //cout << lines[i - 1] << endl;
    for (int j = 0; j < lines[i - 1].length();) {
      int k = j + 1;
      while (k < lines[i - 1].length() && lines[i - 1][j] == lines[i - 1][k]) ++k;
      lines[i] += to_string(k - j);
      lines[i] += lines[i - 1][j];
      j = k;
    }
  }
  return lines[40].length();
}

// find the length of the 50th iteration
int64_t day10_2(ifstream &&in) {
  string lines[51] = {};
  lines[0] = slurp(in);
  for (int i = 1; i <= 50; ++i) {
    //cout << lines[i - 1] << endl;
    for (int j = 0; j < lines[i - 1].length();) {
      int k = j + 1;
      while (k < lines[i - 1].length() && lines[i - 1][j] == lines[i - 1][k]) ++k;
      lines[i] += to_string(k - j);
      lines[i] += lines[i - 1][j];
      j = k;
    }
  }
  return lines[50].length();
}

// find santa's incrementally next password that meets this policy
int64_t day11_1(ifstream &&in) {
  string password = slurp(in);
  while (true) {
    for (int64_t i = password.length(); i >= 0; --i) {
      if (password[i] < 'z') {
        ++password[i];
        if (password[i] == 'i' || password[i] == 'o' || password[i] == 'l') {
          ++password[i];
        }
        break;
      }
      password[i] = 'a';
    }
    bool hasStraight = false;
    for (int i = 0; i < password.length() - 2; ++i) {
      if (password[i + 1] - password[i] == 1 && password[i + 2] - password[i + 1] == 1) {
        hasStraight = true;
        break;
      }
    }
    if (!hasStraight) {
      continue;
    }
    int pairs = 0;
    for (char c = 'a'; c <= 'z'; ++c) {
      if (password.find(string("") + c + c) != string::npos) {
        ++pairs;
      }
    }
    if (pairs > 1) {
      report(password);
      exit(0);
    }
  }
  return 0;
}

// find the next one after that
int64_t day11_2(ifstream &&in) {
  string password = slurp(in);
  bool foundOne = false;
  while (true) {
    for (int64_t i = password.length() - 1; i >= 0; --i) {
      if (password[i] < 'z') {
        ++password[i];
        if (password[i] == 'i' || password[i] == 'o' || password[i] == 'l') {
          ++password[i];
        }
        break;
      }
      password[i] = 'a';
    }
    bool hasStraight = false;
    for (int i = 0; i < password.length() - 2; ++i) {
      if (password[i + 1] - password[i] == 1 && password[i + 2] - password[i + 1] == 1) {
        hasStraight = true;
        break;
      }
    }
    if (!hasStraight) {
      continue;
    }
    int pairs = 0;
    for (char c = 'a'; c <= 'z'; ++c) {
      if (password.find(string("") + c + c) != string::npos) {
        ++pairs;
      }
    }
    if (pairs > 1) {
      if (!foundOne) {
        foundOne = true;
      } else {
        report(password);
        exit(0);
      }
    }
  }
  return 0;
}

double day12_collect(picojson::value obj, bool ignoreRed = false) {
  double result = 0;
  if (obj.is<double>()) {
    return obj.get<double>();
  } else if (obj.is<picojson::array>()) {
    for (auto elem : obj.get<picojson::array>()) {
      result += day12_collect(elem, ignoreRed);
    }
  } else if (obj.is<picojson::object>()) {
    for (auto elem : obj.get<picojson::object>()) {
      if (ignoreRed && elem.second.is<string>() && elem.second.get<string>() == "red") {
        return 0;
      }
      result += day12_collect(elem.second, ignoreRed);
    }
  }
  return result;
};

int64_t day12_1(ifstream &&in) {
  picojson::value obj;
  picojson::parse(obj, in);

  int64_t result = (int64_t)day12_collect(obj);

  return result;
}

int64_t day12_2(ifstream &&in) {
  picojson::value obj;
  picojson::parse(obj, in);

  int64_t result = (int64_t)day12_collect(obj, true);

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
