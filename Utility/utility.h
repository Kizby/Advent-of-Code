#pragma once

#define WIN32_LEAN_AND_MEAN             // Exclude rarely-used stuff from Windows headers

#define CPPHTTPLIB_OPENSSL_SUPPORT
#pragma warning(push, 0)
#include "httplib.h"
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
