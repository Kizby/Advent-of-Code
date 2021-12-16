#pragma once

#define WIN32_LEAN_AND_MEAN             // Exclude rarely-used stuff from Windows headers
#pragma warning(disable : 4996)

#define CPPHTTPLIB_OPENSSL_SUPPORT
#define OPENSSL_NO_DEPRECATED_3_0
#pragma warning(push, 0)
#include "httplib.h"
#include "picojson.h"
#pragma warning(pop)

#include <fstream>
#include <iostream>
#include <string>
#include <filesystem>
#include <set>
#include <deque>
#include <sstream>
#include <algorithm>
#include <functional>
extern "C" {
#include <Windows.h>
}

using namespace std;

typedef vector<int64_t> vi;
typedef vector<size_t> vz;
typedef vector<string> vs;

typedef set<int64_t> si;
typedef set<string> ss;

string slurp(ifstream &in);
ifstream input(int year, int day);

vs split(const string& input, const string& regex = "\n");
vector<vs> split(const vs& input, const string& regex = "\n");

vi map_to_num(const vs& vec);
vector<vi> map_to_num(const vector<vs> &vec);
vi get_nums(ifstream &in, const string& regex = "\n");

vector<vz> permutations(size_t start, size_t end);
vector<vz> permutations(size_t n);
void permutations(size_t start, size_t end, function<void(vz&&)> callback);
void permutations(size_t n, function<void(vz&&)> callback);

// partitions of max units into count contiguous sets
vector<vz> partitions(size_t max, size_t count);
void partitions(size_t max, size_t count, function<void(vz &&)> callback);

struct prime_factor_t {
	int64_t p;
	int count;
};

// calls the callback on each prime in order; return true when done
void primes(function<bool(int64_t)> callback);
vector<prime_factor_t> prime_factors(int64_t num);
vi factorize(int64_t num);

int64_t sum(vi vec);
int64_t product(vi vec);
int64_t min(vi vec);
int64_t max(vi vec);

vector<vi> choose(int64_t n, int64_t k);

template <typename T>
vector<vector<T>> grid(size_t rows, size_t columns, T value) {
	return vector(rows, vector(columns, value));
}

template <typename T, typename C>
unordered_map<T, int> histogram(C container) {
	unordered_map<T, int> result;
	for (T one : container) {
		++result[one];
	}
	return result;
}

template <typename T>
set<T> set_union(const set<T> &a, const set<T> &b) {
	const auto &needles = a.size() > b.size() ? b : a;
	auto haystack = a.size() > b.size() ? a : b;
	for (const auto &element : needles) {
		haystack.insert(element);
	}
	return haystack;
}

template <typename T>
set<T> set_intersect(const set<T> &a, const set<T> &b) {
	set<T> result;
	const auto &needles = a.size() > b.size() ? b : a;
	const auto &haystack = a.size() > b.size() ? a : b;
	for (const auto &element : needles) {
		if (haystack.contains(element)) {
			result.insert(element);
		}
	}
	return result;
}

template <typename T>
bool subset(const set<T> &a, const set<T> &b) {
	if (b.size() > a.size()) {
		return false;
	}
	for (const auto &element : b) {
		if (!a.contains(element)) {
			return false;
		}
	}
	return true;
}

template <typename T>
set<T> set_diff(const set<T> &a, const set<T> &b) {
	set<T> result;
	for (const auto &element : a) {
		if (!b.contains(element)) {
			result.insert(element);
		}
	}
	return result;
}

template <typename T>
set<T> set_sym_diff(const set<T> &a, const set<T> &b) {
	set<T> result;
	for (const auto &element : a) {
		if (!b.contains(element)) {
			result.insert(element);
		}
	}
	for (const auto &element : b) {
		if (!a.contains(element)) {
			result.insert(element);
		}
	}
	return result;
}


template <typename T>
struct CellPointer {
  vector<vector<T>> &backing_grid;
  size_t row;
  size_t col;
  CellPointer(const CellPointer &other) = default;
  CellPointer(vector<vector<T>> &backing_grid, size_t row, size_t col) : backing_grid(backing_grid), row(row), col(col) {}
  T &operator*() {
    return backing_grid[row][col];
  }
  T &operator()(vector<vector<T>> &grid) {
    return grid[row][col];
  }
};

template<typename T>
class CellIterator {
  vector<vector<T>> &backing_grid;
  size_t row;
  size_t col;

  CellIterator(vector<vector<T>> &backing_grid, size_t row, size_t col) : backing_grid(backing_grid), row(row), col(col) {}

public:
  CellIterator(vector<vector<T>> &backing_grid) : CellIterator(backing_grid, 0, 0) {}

  CellIterator begin() {
    row = 0;
    col = 0;
    return *this;
  }
  CellIterator end() {
    return CellIterator(backing_grid, backing_grid.size(), 0);
  }
  CellIterator &operator++() {
    ++col;
    if (col >= backing_grid.size() == 0 ? 0 : backing_grid[0].size()) {
      col = 0;
      ++row;
    }
    return *this;
  }
  bool operator!=(const CellIterator &other) {
    return &backing_grid != &other.backing_grid || row != other.row || col != other.col;
  }
  CellPointer<T> operator*() {
    return CellPointer{backing_grid, row, col};
  }
};

template<typename T>
CellIterator<T> cells(vector<vector<T>> &source) {
  return CellIterator(source);
}

template<typename T>
vector<CellPointer<T>> adjacent(CellPointer<T> cell, bool cardinal = true) {
  vector<CellPointer<T>> result;
  if (cell.row > 0) {
    result.push_back(CellPointer<T>{cell.backing_grid, cell.row - 1, cell.col});
    if (!cardinal) {
      if (cell.col > 0) {
        result.push_back(CellPointer<T>{cell.backing_grid, cell.row - 1, cell.col - 1});
      }
      if (cell.col < cell.backing_grid[0].size() - 1) {
        result.push_back(CellPointer<T>{cell.backing_grid, cell.row - 1, cell.col + 1});
      }
    }
  }
  if (cell.col > 0) {
    result.push_back(CellPointer<T>{cell.backing_grid, cell.row, cell.col - 1});
  }
  if (cell.col < cell.backing_grid[0].size() - 1) {
    result.push_back(CellPointer<T>{cell.backing_grid, cell.row, cell.col + 1});
  }
  if (cell.row < cell.backing_grid.size() - 1) {
    result.push_back(CellPointer<T>{cell.backing_grid, cell.row + 1, cell.col});
    if (!cardinal) {
      if (cell.col > 0) {
        result.push_back(CellPointer<T>{cell.backing_grid, cell.row + 1, cell.col - 1});
      }
      if (cell.col < cell.backing_grid[0].size() - 1) {
        result.push_back(CellPointer<T>{cell.backing_grid, cell.row + 1, cell.col + 1});
      }
    }
  }
  return result;
}

template<typename T>
vector<vector<T>> concat_right(vector<vector<T>> a, vector<vector<T>> b, T fill = T{}) {
  if (a.size() == 0) {
    return b;
  }
  if (b.size() == 0) {
    return a;
  }
  auto result = a;
  while (b.size() > result.size()) {
    result.push_back(vector(a[0].size(), fill));
  }
  for (int i = 0; i < b.size() || i < result.size(); ++i) {
    result[i].resize(a[0].size() + b[0].size(), fill);
    for (int j = 0; j < b[0].size(); ++j) {
      if (i < b.size()) {
        result[i][a[0].size() + j] = b[i][j];
      }
    }
  }
  return result;
}

template<typename T>
vector<vector<T>> concat_down(vector<vector<T>> a, vector<vector<T>> b, T fill = T{}) {
  if (a.size() == 0) {
    return b;
  }
  if (b.size() == 0) {
    return a;
  }
  auto result = a;
  if (b[0].size() > result[0].size()) {
    for (auto &row : result) {
      row.resize(b[0].size(), fill);
    }
  }
  for (auto row : b) {
    row.resize(result[0].size(), fill);
    result.push_back(row);
  }
  return result;
}

template<typename T>
vector<vector<T>> transform(const vector<vector<T>> &in, function<T(T)> map) {
  vector<vector<T>> result;
  for (size_t i = 0; i < in.size(); ++i) {
    result.push_back({});
    for (size_t j = 0; j < in[i].size(); ++j) {
      result[i].push_back(map(in[i][j]));
    }
  }
  return result;
}

void copy(string s);
void report(const string& s);

template <typename T>
void report(T n) {
	report(to_string(n));
}

struct BITS_packet_t {
  int64_t version = 0;
  int64_t type = 0;
  vector<BITS_packet_t> subpackets;
  int64_t result = 0;
};

int64_t parse_BITS_int(const vector<bool> &bits, size_t &index, size_t size = 0);
BITS_packet_t parse_BITS_packet(const vector<bool> &bits, size_t &index, int64_t version = -1);
BITS_packet_t parse_BITS_packet_sum(const vector<bool> &bits, size_t &index, int64_t &sum);
