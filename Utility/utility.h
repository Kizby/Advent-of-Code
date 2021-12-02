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

typedef vector<int64_t> vi;
typedef vector<size_t> vz;
typedef vector<string> vs;

string slurp(ifstream &in);
ifstream input(int year, int day);

vs split(const string& input, const string& regex = "\n");
vector<vs> split(const vs& input, const string& regex = "\n");

vi map_to_num(const vs& vec);
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

vector<vi> choose(int64_t n, int64_t k);

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
