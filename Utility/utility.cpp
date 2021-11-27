// Utility.cpp : Defines the functions for the static library.
//

#include "pch.h"

using namespace std;
using namespace httplib;

// from https://stackoverflow.com/a/116083
string slurp(ifstream& in) {
	stringstream out;
	while (in >> out.rdbuf());
	string s = out.str();
	auto last_non_whitespace = s.find_last_not_of("\n\r ");
	return s.substr(0, last_non_whitespace + 1);
}

void fetch(int year, int day, string where) {
	ifstream session("../session.txt");
	Client cli("https://adventofcode.com");
	cli.set_default_headers({
		{"cookie", "session=" + slurp(session)}
		});
	string path = "/" + to_string(year) + "/day/" + to_string(day) + "/input";
	if (auto res = cli.Get(path.c_str())) {
		if (res->status == 200) {
			ofstream fout(where);
			fout << res->body;
			fout.close();
		}
		else {
			cout << "Status was: " << res->status << endl;
		}
	}
	else {
		auto err = res.error();
		cout << err << endl;
	}
}

ifstream input(int year, int day) {
	auto filename = "../input/" + to_string(year) + "-" + to_string(day) + ".txt";
	if (!filesystem::exists(filename)) {
		fetch(year, day, filename);
	}
	return ifstream(filename);
}

// from https://stackoverflow.com/a/9437426
vector<string> split(const string& input, const string& regex) {
	// passing -1 as the submatch index parameter performs splitting
	std::regex re(regex);
	sregex_token_iterator
		first{ input.begin(), input.end(), re, -1 },
		last;
	return { first, last };
}

vector<vector<string>> split(const vector<string>& input, const string& regex) {
	// passing -1 as the submatch index parameter performs splitting
	std::regex re(regex);
	vector<vector<string>> result;
	for (const auto& line : input) {
		sregex_token_iterator
			first{ line.begin(), line.end(), re, -1 },
			last;
		result.push_back({ first, last });
	}
	return result;
}

vector<int64_t> map_to_num(const vector<string>& vec) {
	vector<int64_t> result;
	result.resize(vec.size());
	transform(vec.begin(), vec.end(), result.begin(), [](const string& s) { return s.empty() ? 0 : stoll(s); });
	return result;
}

vector<vector<size_t>> permutations(size_t start, size_t end) {
	vector<vector<size_t>> result;
	permutations(start, end, [&result](vector<size_t> &&vec) {
		result.push_back(move(vec));
		});
	return result;
}

vector<vector<size_t>> permutations(size_t n) {
	return permutations(0, n);
}

void permutations(size_t start, size_t end, function<void(vector<size_t>&&)> callback) {
	if (start >= end) {
		callback({});
		return;
	}
	permutations(start, end - 1, [end, callback](vector<size_t> &&base) {
		for (int i = 0; i <= base.size(); ++i) {
			auto next = base;
			next.insert(next.begin() + i, end - 1);
			callback(move(next));
		}
		});
}


void permutations(size_t n, function<void(vector<size_t>&&)> callback) {
	permutations(0, n, callback);
}

void copy(string s)
{
	if (s.size() > 200) {
		// probably don't want to copy this...
		cout << "String is too long: " << s.size() << endl;
		return;
	}

	// Open the clipboard, and empty it. 
	if (!OpenClipboard(NULL))
		return;
	EmptyClipboard();

	// Copy text using the CF_TEXT format. 
	// Allocate a global memory object for the text. 
	HGLOBAL hglbCopy = GlobalAlloc(GMEM_MOVEABLE,
		(s.size() + 1) * sizeof(TCHAR));
	if (hglbCopy == NULL) {
		// failed to get memory
		CloseClipboard();
		return;
	}

	// Lock the handle and copy the text to the buffer. 
	LPTSTR lptstrCopy = (LPTSTR)GlobalLock(hglbCopy);
	if (lptstrCopy == NULL) {
		// failed to lock memory
		CloseClipboard();
		return;
	}

	memcpy(lptstrCopy, s.c_str(), s.size() * sizeof(TCHAR));
	lptstrCopy[s.size()] = '\0';
	GlobalUnlock(hglbCopy);

	// Place the handle on the clipboard. 
	SetClipboardData(CF_TEXT, hglbCopy);

	// Close the clipboard. 
	CloseClipboard();
}

void report(const string& s) {
	cout << s << endl;
	copy(s);
}