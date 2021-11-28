#pragma once

#define WIN32_LEAN_AND_MEAN             // Exclude rarely-used stuff from Windows headers

#define CPPHTTPLIB_OPENSSL_SUPPORT
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
extern "C" {
#include <Windows.h>
}

using namespace std;

string slurp(ifstream &in);
ifstream input(int year, int day);

vector<string> split(const string& input, const string& regex = "\n");
vector<vector<string>> split(const vector<string>& input, const string& regex = "\n");

vector<int64_t> map_to_num(const vector<string>& vec);

vector<vector<size_t>> permutations(size_t start, size_t end);
vector<vector<size_t>> permutations(size_t n);
void permutations(size_t start, size_t end, function<void(vector<size_t>&&)> callback);
void permutations(size_t n, function<void(vector<size_t>&&)> callback);

// partitions of max units into count contiguous sets
vector<vector<size_t>> partitions(size_t max, size_t count);
void partitions(size_t max, size_t count, function<void(vector<size_t> &&)> callback);

struct prime_factor_t {
	int64_t p;
	int count;
};

// calls the callback on each prime in order; return true when done
void primes(function<bool(int64_t)> callback);
vector<prime_factor_t> prime_factors(int64_t num);
vector<int64_t> factorize(int64_t num);

int64_t sum(vector<int64_t> vec);
int64_t product(vector<int64_t> vec);

template <typename T, typename C>
unordered_map<T, int> histogram(C container) {
	unordered_map<T, int> result;
	for (T one : container) {
		++result[one];
	}
	return result;
}

void copy(string s);
void report(const string& s);

template <typename T>
void report(T n) {
	report(to_string(n));
}
