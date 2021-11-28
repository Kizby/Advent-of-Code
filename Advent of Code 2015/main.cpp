#include "../Utility/pch.h"

using namespace std;

const int64_t DAY = 24;
const int64_t PART = 1;

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

// given preferences for seating partners, maximize happiness
int64_t day13_1(ifstream &&in) {
  map<string, map<string, int64_t>> prefs = {};
  vector<string> names = {};
  for (auto tokens : split(split(slurp(in)), "[ \\.]")) {
    auto value = stoll(tokens[3]);
    if (tokens[2] == "lose") {
      value *= -1;
    }
    if (!prefs.contains(tokens[0])) {
      names.push_back(tokens[0]);
    }
    prefs[tokens[0]][tokens[10]] = value;
    //cout << tokens[0] << " " << tokens[10] << " " << value << endl;
  }

  int64_t result = -10000;
  for (auto perm : permutations(names.size())) {
    int64_t happiness = 0;
    for (auto i = 0; i < names.size(); ++i) {
      happiness += prefs[names[perm[i]]][names[perm[(i + 1) % perm.size()]]];
      happiness += prefs[names[perm[(i + 1) % perm.size()]]][names[perm[i]]];
    }
    if (happiness > result) {
      result = happiness;
    }
  }

  return result;
}

// now include yourself, who is and elicits complete ambivalence
int64_t day13_2(ifstream &&in) {
  map<string, map<string, int64_t>> prefs = {};
  vector<string> names = {"yourself"};
  for (auto tokens : split(split(slurp(in)), "[ \\.]")) {
    auto value = stoll(tokens[3]);
    if (tokens[2] == "lose") {
      value *= -1;
    }
    if (!prefs.contains(tokens[0])) {
      names.push_back(tokens[0]);
      prefs[tokens[0]]["yourself"] = 0;
      prefs["yourself"][tokens[0]] = 0;
    }
    prefs[tokens[0]][tokens[10]] = value;
    //cout << tokens[0] << " " << tokens[10] << " " << value << endl;
  }

  int64_t result = -10000;
  for (auto perm : permutations(names.size())) {
    int64_t happiness = 0;
    for (auto i = 0; i < names.size(); ++i) {
      happiness += prefs[names[perm[i]]][names[perm[(i + 1) % perm.size()]]];
      happiness += prefs[names[perm[(i + 1) % perm.size()]]][names[perm[i]]];
    }
    if (happiness > result) {
      result = happiness;
    }
  }

  return result;
}

// given speeds, how long they can go that speed, and how long they have to rest in between, what's the farthest specified reindeer can get?
int64_t day14_1(ifstream &&in) {
  int64_t result = 0;
  int64_t total = 2503;
  for (auto tokens : split(split(slurp(in)), " ")) {
    auto speed = stoll(tokens[3]);
    auto duration = stoll(tokens[6]);
    auto rest = stoll(tokens[13]);

    int64_t elapsed = 0;
    int64_t distance = 0;
    while (elapsed < total) {
      distance += speed * duration;
      elapsed += duration;
      if (elapsed > total) {
        distance -= speed * (elapsed - total);
        break;
      }
      elapsed += rest;
    }
    if (distance > result) {
      result = distance;
    }
  }

  return result;
}

// who's in the lead for the most seconds of the race?
int64_t day14_2(ifstream &&in) {
  int64_t result = 0;
  vector<vector<int64_t>> reindeer = {};
  for (auto tokens : split(split(slurp(in)), " ")) {
    auto speed = stoll(tokens[3]);
    auto duration = stoll(tokens[6]);
    auto rest = stoll(tokens[13]);
    reindeer.push_back({speed, duration, rest, 0});
  }

  vector<int64_t> pos(reindeer.size());
  vector<int64_t> scores(reindeer.size());
  for (int i = 0; i < 2503; ++i) {
    int64_t best = 0;
    for (int j = 0; j < reindeer.size(); ++j) {
      if (reindeer[j][3] < reindeer[j][1]) {
        pos[j] += reindeer[j][0];
      }
      reindeer[j][3] = (reindeer[j][3] + 1) % (reindeer[j][1] + reindeer[j][2]);
      if (pos[j] > best) {
        best = pos[j];
      }
    }
    for (int j = 0; j < reindeer.size(); ++j) {
      if (pos[j] == best) {
        ++scores[j];
      }
    }
  }

  return *max_element(scores.begin(), scores.end());
}

// given four properties of each ingredient, find highest product of sum of quantity of ingredients adding to 100
int64_t day15_1(ifstream &&in) {
  int64_t total = 100;
  vector<vector<int64_t>> ingredients = {};
  for (auto tokens : split(split(slurp(in)), " ")) {
    ingredients.push_back({stoll(tokens[2]), stoll(tokens[4]), stoll(tokens[6]), stoll(tokens[8])});
  }
  int64_t result = 0;
  // there are four ingredients; no need to generalize
  for (int i = 0; i <= total; ++i) {
    for (int j = i; j <= total; ++j) {
      for (int k = j; k <= total; ++k) {
        int64_t score = 1;
        for (int m = 0; m < ingredients[0].size(); ++m) {
          auto subscore = ingredients[0][m] * i + ingredients[1][m] * (j - i) + ingredients[2][m] * (k - j) + ingredients[3][m] * (total - k);
          if (subscore < 0) {
            subscore = 0;
          }
          score *= subscore;
        }
        if (score > result) {
          result = score;
        }
      }
    }
  }
  /*
  // generalized implementation to test new partition utility
  partitions(total, ingredients.size(), [&result, &ingredients](vector<size_t> &&part) {
    int64_t score = 1;
    for (int i = 0; i < ingredients[0].size(); ++i) {
      int64_t subscore = 0;
      for (int j = 0; j < part.size(); ++j) {
        subscore += ingredients[j][i] * part[j];
      }
      if (subscore < 0) {
        subscore = 0;
      }
      score *= subscore;
    }
    if (score > result) {
      result = score;
    }
    });
    */
  return result;
}

// do the same, but requiring exactly 500 calories
int64_t day15_2(ifstream &&in) {
  int64_t total = 100;
  vector<vector<int64_t>> ingredients = {};
  for (auto tokens : split(split(slurp(in)), " ")) {
    ingredients.push_back({stoll(tokens[2]), stoll(tokens[4]), stoll(tokens[6]), stoll(tokens[8]), stoll(tokens[10])});
  }
  // there are four ingredients; no need to generalize
  int64_t result = 0;
  for (int i = 0; i <= total; ++i) {
    for (int j = i; j <= total; ++j) {
      for (int k = j; k <= total; ++k) {
        int64_t score = 1;
        for (int m = 0; m < ingredients[0].size() - 1; ++m) {
          auto subscore = ingredients[0][m] * i + ingredients[1][m] * (j - i) + ingredients[2][m] * (k - j) + ingredients[3][m] * (total - k);
          if (subscore < 0) {
            subscore = 0;
          }
          score *= subscore;
        }
        auto calories = ingredients[0][4] * i + ingredients[1][4] * (j - i) + ingredients[2][4] * (k - j) + ingredients[3][4] * (total - k);
        if (calories == 500 && score > result) {
          result = score;
        }
      }
    }
  }

  return result;
}

// which Sue is compatible with the goal spec?
int64_t day16_1(ifstream &&in) {
  map<string, int64_t> goal = {
    {"children:", 3},
    {"cats:", 7},
    {"samoyeds:", 2},
    {"pomeranians:", 3},
    {"akitas:", 0},
    {"vizslas:", 0},
    {"goldfish:", 5},
    {"trees:", 3},
    {"cars:", 2},
    {"perfumes:", 1},
  };
  for (auto tokens : split(split(slurp(in)), " ")) {
    bool valid = true;
    for (int i = 2; i < tokens.size(); i += 2) {
      if (goal[tokens[i]] != stoll(tokens[i + 1])) {
        valid = false;
        break;
      }
    }
    if (valid) {
      return stoll(tokens[1]);
    }
  }
  return -1;
}

// same, but some of the specs aren't equality; regex replacement made this quick to implement
int64_t day16_2(ifstream &&in) {
  map<string, function<bool(int64_t)>> goal = {
    {"children:", [](int64_t val) { return 3 == val; }},
    {"cats:", [](int64_t val) { return 7 < val; }},
    {"samoyeds:", [](int64_t val) { return 2 == val; }},
    {"pomeranians:", [](int64_t val) { return 3 > val; }},
    {"akitas:", [](int64_t val) { return 0 == val; }},
    {"vizslas:", [](int64_t val) { return 0 == val; }},
    {"goldfish:", [](int64_t val) { return 5 > val; }},
    {"trees:", [](int64_t val) { return 3 < val; }},
    {"cars:", [](int64_t val) { return 2 == val; }},
    {"perfumes:", [](int64_t val) { return 1 == val; }},
  };
  for (auto tokens : split(split(slurp(in)), " ")) {
    bool valid = true;
    for (int i = 2; i < tokens.size(); i += 2) {
      if (!goal[tokens[i]](stoll(tokens[i + 1]))) {
        valid = false;
        break;
      }
    }
    if (valid) {
      return stoll(tokens[1]);
    }
  }
  return -1;
}

// how many ways can we exactly split 150 units among these containers?
int64_t day17_1(ifstream &&in) {
  auto containers = map_to_num(split(slurp(in)));
  int64_t result = 0;
  for (int i = 0; i < 1 << containers.size(); ++i) {
    int64_t capacity = 0;
    for (int mask = 1, cur = 0; mask < i; mask <<= 1, ++cur) {
      if (mask & i) {
        capacity += containers[cur];
      }
    }
    if (capacity == 150) {
      ++result;
    }
  }
  return result;
}

// what if we require the minimum number of containers?
int64_t day17_2(ifstream &&in) {
  auto containers = map_to_num(split(slurp(in)));
  map<int, int> results = {};
  for (int i = 0; i < 1 << containers.size(); ++i) {
    int64_t capacity = 0;
    int count = 0;
    for (int mask = 1, cur = 0; mask < i; mask <<= 1, ++cur) {
      if (mask & i) {
        capacity += containers[cur];
        ++count;
      }
    }
    if (capacity == 150) {
      ++results[count];
    }
  }
  for (int i = 1; i <= containers.size(); ++i) {
    if (results.contains(i)) {
      return results[i];
    }
  }
  return -1;
}

// implement game of life; count alive cells after 100 generations
int64_t day18_1(ifstream &&in) {
  bool fields[2][100][100];
  {
    string line;
    size_t row = 0;
    while (getline(in, line)) {
      for (int i = 0; i < line.size(); ++i) {
        fields[0][row][i] = (line[i] == '#');
      }
      ++row;
    }
  }
  for (int step = 1; step <= 100; ++step) {
    for (int i = 0; i < 100; ++i) {
      for (int j = 0; j < 100; ++j) {
        int neighbors = 0;
        for (int k = i - 1; k <= i + 1; ++k) {
          for (int l = j - 1; l <= j + 1; ++l) {
            if (k >= 0 && l >= 0 && k < 100 && l < 100 && fields[(step + 1) % 2][k][l]) {
              ++neighbors;
            }
          }
        }
        if (fields[(step + 1) % 2][i][j]) {
          fields[step % 2][i][j] = neighbors == 3 || neighbors == 4;
        } else {
          fields[step % 2][i][j] = neighbors == 3;
        }
      }
    }
  }

  int64_t result = 0;
  for (int i = 0; i < 100; ++i) {
    for (int j = 0; j < 100; ++j) {
      if (fields[100 % 2][i][j]) {
        ++result;
      }
    }
  }
  return result;
}

// same, but force the four corners to always be alive
int64_t day18_2(ifstream &&in) {
  bool fields[2][100][100];
  {
    string line;
    size_t row = 0;
    while (getline(in, line)) {
      for (int i = 0; i < line.size(); ++i) {
        fields[0][row][i] = (line[i] == '#');
      }
      ++row;
    }
  }
  fields[0][0][0] = fields[0][99][0] = fields[0][0][99] = fields[0][99][99] = true;
  for (int step = 1; step <= 100; ++step) {
    for (int i = 0; i < 100; ++i) {
      for (int j = 0; j < 100; ++j) {
        int neighbors = 0;
        for (int k = i - 1; k <= i + 1; ++k) {
          for (int l = j - 1; l <= j + 1; ++l) {
            if ((k == 0 || k == 99) && (l == 0 || l == 99)) {
              ++neighbors;
            } else if (k >= 0 && l >= 0 && k < 100 && l < 100 && fields[(step + 1) % 2][k][l]) {
              ++neighbors;
            }
          }
        }
        if ((i == 0 || i == 99) && (j == 0 || j == 99)) {
          fields[step % 2][i][j] = true;
        } else if (fields[(step + 1) % 2][i][j]) {
          fields[step % 2][i][j] = neighbors == 3 || neighbors == 4;
        } else {
          fields[step % 2][i][j] = neighbors == 3;
        }
      }
    }
  }

  int64_t result = 0;
  for (int i = 0; i < 100; ++i) {
    for (int j = 0; j < 100; ++j) {
      if (fields[100 % 2][i][j]) {
        ++result;
      }
    }
  }
  return result;
}

// how many molecules can be created by one application of a replacement rule?
int64_t day19_1(ifstream &&in) {
  map<string, vector<string>> replacements = {};
  string line;
  while (getline(in, line) && !line.empty()) {
    auto tokens = split(line, " ");
    replacements[tokens[0]].push_back(tokens[2]);
  }

  getline(in, line);
  set<string> molecules = {};
  for (int i = 0; i < line.length(); ++i) {
    for (auto repl : replacements[line.substr(i, 1)]) {
      molecules.insert(line.substr(0, i) + repl + line.substr(i + 1));
    }
    if (i == line.length() - 1) {
      break;
    }
    for (auto repl : replacements[line.substr(i, 2)]) {
      molecules.insert(line.substr(0, i) + repl + line.substr(i + 2));
    }
  }

  return molecules.size();
}

// how many steps does it take to make the target molecule from "e"?
// gave up and checked online; was an underlying pattern (properties of Rn, Y, and Ar) that was more universal than I thought
int64_t day19_2(ifstream &&in) {
  string line;
  while (getline(in, line) && !line.empty());
  getline(in, line);

  int64_t result = -1; // this computation would get rid of the "e" too, so offset by one
  for (int i = 0; i < line.length(); ++i) {
    string element;
    if (i < line.length() - 1 && islower(line[i + 1])) {
      element = line.substr(i, 2);
      ++i;
    } else {
      element = line.substr(i, 1);
    }
    ++result; // always takes at least one step to add an element
    if (element == "Rn") {
      --result; // Rn comes for free
    } else if (element == "Y") {
      result -= 2; // Y comes for free and brings an element with it
    } else if (element == "Ar") {
      --result; // Ar comes for free
    }
  }
  return result;
}

// what's the least number whose sum of factors exceeds one-tenth the target
int64_t day20_1(ifstream &&in) {
  int64_t target = stoll(slurp(in)) / 10;
  for (int64_t i = 1; ; ++i) {
    int64_t result = sum(factorize(i));
    if (result >= target) {
      return i;
    }
  }

  return -1;
}

// now only factors within a factor of 50 of the number, and one-eleventh the target
int64_t day20_2(ifstream &&in) {
  int64_t target = stoll(slurp(in)) / 11;
  for (int64_t i = 1; ; ++i) {
    int64_t result = 0;
    auto factors = factorize(i);
    for (int j = 0; j < factors.size(); ++j) {
      if (i / factors[j] <= 50) {
        result += factors[j];
      }
    }
    if (result >= target) {
      return i;
    }
  }

  return -1;
}

// rpg simulator; what's the cheapest loadout that beats the boss?
int64_t day21_1(ifstream &&in) {
  string line;
  const int boss_hp = (getline(in, line), stol(split(line, " ")[2]));
  const int boss_damage = (getline(in, line), stol(split(line, " ")[1]));
  const int boss_armor = (getline(in, line), stol(split(line, " ")[1]));

  struct item_t {
    string name;
    int cost;
    int damage;
    int armor;
  };
  vector<item_t> weapons = {
    {"Dagger", 8, 4, 0},
    {"Shortsword", 10, 5, 0},
    {"Warhammar", 25, 6, 0},
    {"Longsword", 40, 7, 0},
    {"Greataxe", 74, 8, 0},
  };
  vector<item_t> armors = {
    {"Leather", 13, 0, 1},
    {"Chainmail", 31, 0, 2},
    {"Splintmail", 53, 0, 3},
    {"Bandedmail", 75, 0, 4},
    {"Platemail", 102, 0, 5},
  };
  vector<item_t> rings = {
    {"Damage +1", 25, 1, 0},
    {"Damage +2", 50, 2, 0},
    {"Damage +3", 100, 3, 0},
    {"Defense +1", 20, 0, 1},
    {"Defense +2", 40, 0, 2},
    {"Defense +3", 80, 0, 3},
  };
  for (int budget = 8; ; ++budget) {
    int gold = budget;
    int damage = 0;
    int armor = 0;
    for (int w = 0; w < weapons.size(); ++w) {
      // for each weapon choice
      int goldwc = gold - weapons[w].cost;
      if (goldwc < 0) {
        continue;
      }
      for (int ac = 0; ac <= 1; ++ac) {
        // for each armor count
        for (auto as : choose(armors.size(), ac)) {
          int goldac = goldwc;
          for (auto a : as) {
            goldac -= armors[a].cost;
          }
          if (goldac < 0) {
            continue;
          }
          for (int rc = 0; rc <= 2; ++rc) {
            // for each ring count
            for (auto rs : choose(rings.size(), rc)) {
              int goldrc = goldac;
              for (auto r : rs) {
                goldrc -= rings[r].cost;
              }
              if (goldrc < 0) {
                continue;
              }
              auto total_damage = weapons[w].damage;
              auto total_armor = 0;
              for (auto a : as) {
                total_armor += armors[a].armor;
              }
              for (auto r : rs) {
                total_damage += rings[r].damage;
                total_armor += rings[r].armor;
              }

              // simulate
              auto boss = boss_hp;
              auto player = 100;
              while (player > 0) {
                boss -= max(total_damage - boss_armor, 1);
                if (boss <= 0) {
                  cout << "Weapon: " << weapons[w].name << endl;
                  cout << "Armor:";
                  if (ac > 0) {
                    cout << " " << armors[as[0]].name;
                  }
                  cout << endl << "Rings:";
                  if (rc > 0) {
                    cout << " " << rings[rs[0]].name;
                  }
                  if (rc > 1) {
                    cout << ", " << rings[rs[1]].name;
                  }
                  cout << endl;
                  return budget;
                }
                player -= max(boss_damage - total_armor, 1);
              }
            }
          }
        }
      }
    }
  }
}

// what's the most expensive loadout that doesn't beat the boss?
int64_t day21_2(ifstream &&in) {
  string line;
  const int boss_hp = (getline(in, line), stol(split(line, " ")[2]));
  const int boss_damage = (getline(in, line), stol(split(line, " ")[1]));
  const int boss_armor = (getline(in, line), stol(split(line, " ")[1]));

  struct item_t {
    string name;
    int cost;
    int damage;
    int armor;
  };
  vector<item_t> weapons = {
    {"Dagger", 8, 4, 0},
    {"Shortsword", 10, 5, 0},
    {"Warhammar", 25, 6, 0},
    {"Longsword", 40, 7, 0},
    {"Greataxe", 74, 8, 0},
  };
  vector<item_t> armors = {
    {"Leather", 13, 0, 1},
    {"Chainmail", 31, 0, 2},
    {"Splintmail", 53, 0, 3},
    {"Bandedmail", 75, 0, 4},
    {"Platemail", 102, 0, 5},
  };
  vector<item_t> rings = {
    {"Damage +1", 25, 1, 0},
    {"Damage +2", 50, 2, 0},
    {"Damage +3", 100, 3, 0},
    {"Defense +1", 20, 0, 1},
    {"Defense +2", 40, 0, 2},
    {"Defense +3", 80, 0, 3},
  };
  for (int budget = 356; budget >= 8; --budget) {
    int gold = budget;
    int damage = 0;
    int armor = 0;
    for (int w = 0; w < weapons.size(); ++w) {
      // for each weapon choice
      int goldwc = gold - weapons[w].cost;
      if (goldwc < 0) {
        continue;
      }
      for (int ac = 0; ac <= 1; ++ac) {
        // for each armor count
        for (auto as : choose(armors.size(), ac)) {
          int goldac = goldwc;
          for (auto a : as) {
            goldac -= armors[a].cost;
          }
          if (goldac < 0) {
            continue;
          }
          for (int rc = 0; rc <= 2; ++rc) {
            // for each ring count
            for (auto rs : choose(rings.size(), rc)) {
              int goldrc = goldac;
              for (auto r : rs) {
                goldrc -= rings[r].cost;
              }
              if (goldrc != 0) {
                continue;
              }
              auto total_damage = weapons[w].damage;
              auto total_armor = 0;
              for (auto a : as) {
                total_armor += armors[a].armor;
              }
              for (auto r : rs) {
                total_damage += rings[r].damage;
                total_armor += rings[r].armor;
              }

              // simulate
              auto boss = boss_hp;
              auto player = 100;
              while (true) {
                boss -= max(total_damage - boss_armor, 1);
                if (boss <= 0) {
                  break;
                }
                player -= max(boss_damage - total_armor, 1);
                if (player <= 0) {
                  cout << "Weapon: " << weapons[w].name << endl;
                  cout << "Armor:";
                  if (ac > 0) {
                    cout << " " << armors[as[0]].name;
                  }
                  cout << endl << "Rings:";
                  if (rc > 0) {
                    cout << " " << rings[rs[0]].name;
                  }
                  if (rc > 1) {
                    cout << ", " << rings[rs[1]].name;
                  }
                  cout << endl;
                  return gold;
                }
              }
            }
          }
        }
      }
    }
  }
}

struct day22_state {
  int player = 50;
  int player_mana = 500;
  int player_armor = 0;

  int boss;
  int boss_damage;

  int shield = 0;
  int poison = 0;
  int recharge = 0;

  bool player_turn = true;
};

bool day22_fight(int budget, day22_state state, bool part2 = false) {
  if (state.player_turn && part2) {
    --state.player;
    if (state.player <= 0) {
      return false;
    }
  }

  if (state.shield > 0) {
    --state.shield;
    if (state.shield == 0) {
      state.player_armor = 0;
    }
  }
  if (state.poison > 0) {
    --state.poison;
    state.boss -= 3;
    if (state.boss <= 0) {
      return true;
    }
  }
  if (state.recharge > 0) {
    --state.recharge;
    state.player_mana += 101;
  }

  if (!state.player_turn) {
    state.player -= max(state.boss_damage - state.player_armor, 1);
    if (state.player <= 0) {
      return false;
    }
    state.player_turn = true;
    return day22_fight(budget, state, part2);
  }

  struct spell {
    string name;
    int mana;
  };

  static vector<spell> spells = {
    {"Magic Missile", 53},
    {"Drain", 73},
    {"Shield", 113},
    {"Poison", 173},
    {"Recharge", 229},
  };

  for (int i = 0; i < spells.size(); ++i) {
    if (spells[i].mana <= budget && spells[i].mana <= state.player_mana) {
      auto next_state = state;
      next_state.player_turn = false;
      next_state.player_mana -= spells[i].mana;
      if (spells[i].name == "Magic Missile") {
        next_state.boss -= 4;
      } else if (spells[i].name == "Drain") {
        next_state.player += 2;
        next_state.boss -= 2;
      } else if (state.shield == 0 && spells[i].name == "Shield") {
        next_state.shield = 6;
        next_state.player_armor = 7;
      } else if (state.poison == 0 && spells[i].name == "Poison") {
        next_state.poison = 6;
      } else if (state.recharge == 0 && spells[i].name == "Recharge") {
        next_state.recharge = 5;
      }
      if (next_state.boss <= 0) {
        return true;
      }
      if (day22_fight(budget - spells[i].mana, next_state, part2)) {
        return true;
      }
    }
  }
  return false;
};

// rpg simulator; try every combination of spells to find the minimum budget to win
int64_t day22_1(ifstream &&in) {
  string line;
  const int boss_hp = (getline(in, line), stol(split(line, " ")[2]));
  const int boss_damage = (getline(in, line), stol(split(line, " ")[1]));

  for (int budget = 53; ; ++budget) {
    if (day22_fight(budget, {.boss = boss_hp, .boss_damage = boss_damage})) {
      return budget;
    }
  }
}

// same, but hard mode - take damage every turn
int64_t day22_2(ifstream &&in) {
  string line;
  const int boss_hp = (getline(in, line), stol(split(line, " ")[2]));
  const int boss_damage = (getline(in, line), stol(split(line, " ")[1]));

  for (int budget = 53; ; ++budget) {
    if (day22_fight(budget, {.boss = boss_hp, .boss_damage = boss_damage}, true)) {
      return budget;
    }
  }
}

// implement a simple computer; code computes number of steps in a collatz sequence
int64_t day23_1(ifstream &&in) {
  struct {
    int64_t a;
    int64_t b;
    size_t pos;
  } state = {};
  struct instruction_t {
    string op;
    string in1;
    string in2;
  };
  vector<instruction_t> instructions = {};
  for (auto tokens : split(split(slurp(in)), ",? ")) {
    instruction_t inst = {tokens[0], tokens[1], tokens.size() > 2 ? tokens[2] : ""};
    instructions.push_back(inst);
    //cout << inst.op << " " << inst.in1 << ", " << inst.in2 << endl;
  }

  while (state.pos >= 0 && state.pos < instructions.size()) {
    //cout << "a: " << state.a << ", b: " << state.b << ", pos: " << state.pos << endl;
    auto inst = instructions[state.pos++];
    if (inst.op == "hlf") {
      auto &which = inst.in1 == "a" ? state.a : state.b;
      which /= 2;
    } else if (inst.op == "tpl") {
      auto &which = inst.in1 == "a" ? state.a : state.b;
      which *= 3;
    } else if (inst.op == "inc") {
      auto &which = inst.in1 == "a" ? state.a : state.b;
      ++which;
    } else if (inst.op == "jmp") {
      state.pos = state.pos - 1 + stol(inst.in1);
    } else if (inst.op == "jie") {
      auto &which = inst.in1 == "a" ? state.a : state.b;
      if (which % 2 == 0) {
        state.pos = state.pos - 1 + stol(inst.in2);
      }
    } else if (inst.op == "jio") {
      auto &which = inst.in1 == "a" ? state.a : state.b;
      if (which == 1) {
        state.pos = state.pos - 1 + stol(inst.in2);
      }
    }
  }
  return state.b;
}

// different starting value
int64_t day23_2(ifstream &&in) {
  struct {
    int64_t a;
    int64_t b;
    size_t pos;
  } state = {.a = 1};
  struct instruction_t {
    string op;
    string in1;
    string in2;
  };
  vector<instruction_t> instructions = {};
  for (auto tokens : split(split(slurp(in)), ",? ")) {
    instruction_t inst = {tokens[0], tokens[1], tokens.size() > 2 ? tokens[2] : ""};
    instructions.push_back(inst);
    //cout << inst.op << " " << inst.in1 << ", " << inst.in2 << endl;
  }

  while (state.pos >= 0 && state.pos < instructions.size()) {
    //cout << "a: " << state.a << ", b: " << state.b << ", pos: " << state.pos << endl;
    auto inst = instructions[state.pos++];
    if (inst.op == "hlf") {
      auto &which = inst.in1 == "a" ? state.a : state.b;
      which /= 2;
    } else if (inst.op == "tpl") {
      auto &which = inst.in1 == "a" ? state.a : state.b;
      which *= 3;
    } else if (inst.op == "inc") {
      auto &which = inst.in1 == "a" ? state.a : state.b;
      ++which;
    } else if (inst.op == "jmp") {
      state.pos = state.pos - 1 + stol(inst.in1);
    } else if (inst.op == "jie") {
      auto &which = inst.in1 == "a" ? state.a : state.b;
      if (which % 2 == 0) {
        state.pos = state.pos - 1 + stol(inst.in2);
      }
    } else if (inst.op == "jio") {
      auto &which = inst.in1 == "a" ? state.a : state.b;
      if (which == 1) {
        state.pos = state.pos - 1 + stol(inst.in2);
      }
    }
  }
  return state.b;
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
