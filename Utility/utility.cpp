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
vs split(const string& input, const string& regex) {
	// passing -1 as the submatch index parameter performs splitting
	std::regex re(regex);
	sregex_token_iterator
		first{ input.begin(), input.end(), re, -1 },
		last;
	return { first, last };
}

vector<vs> split(const vs& input, const string& regex) {
	// passing -1 as the submatch index parameter performs splitting
	std::regex re(regex);
	vector<vs> result;
	for (const auto& line : input) {
		sregex_token_iterator
			first{ line.begin(), line.end(), re, -1 },
			last;
		result.push_back({ first, last });
	}
	return result;
}

vi map_to_num(const vs& vec) {
	vi result;
	result.resize(vec.size());
	transform(vec.begin(), vec.end(), result.begin(), [](const string& s) { return s.empty() ? 0 : stoll(s); });
	return result;
}

vi get_nums(ifstream &in, const string &regex) {
	return map_to_num(split(slurp(in), regex));
}

vector<vz> permutations(size_t start, size_t end) {
	vector<vz> result;
	permutations(start, end, [&result](vz &&vec) {
		result.push_back(move(vec));
		});
	return result;
}

vector<vz> permutations(size_t n) {
	return permutations(0, n);
}

void permutations(size_t start, size_t end, function<void(vz&&)> callback) {
	if (start >= end) {
		callback({});
		return;
	}
	permutations(start, end - 1, [end, callback](vz &&base) {
		for (int i = 0; i <= base.size(); ++i) {
			auto next = base;
			next.insert(next.begin() + i, end - 1);
			callback(move(next));
		}
		});
}

void permutations(size_t n, function<void(vz&&)> callback) {
	permutations(0, n, callback);
}

vector<vz> partitions(size_t max, size_t count) {
	vector<vz> result;
	partitions(max, count, [&result](vz &&vec) {
		result.push_back(move(vec));
		});
	return result;
}

void partitions(size_t max, size_t count, function<void(vz &&)> callback) {
	if (count == 1) {
		callback({max});
		return;
	}
	for (size_t i = 0; i <= max; ++i) {
		partitions(max - i, count - 1, [i, callback](vz &&base) {
			base.push_back(i);
			callback(move(base));
			});
	}
}

void primes(function<bool(int64_t)> callback) {
	static vi prime_cache = {2, 3};

	for (int i = 0; i < prime_cache.size(); ++i) {
		if (callback(prime_cache[i])) {
			return;
		}
	}

	bool done = false;
	for (int64_t next = prime_cache[prime_cache.size() - 1] + 2; !done; next += 2) {
		bool is_prime = true;
		for (auto i = 1; i < prime_cache.size() && prime_cache[i] * prime_cache[i] <= next; ++i) {
			if (next % prime_cache[i] == 0) {
				is_prime = false;
				break;
			}
		}
		if (is_prime) {
			prime_cache.push_back(next);
			done = callback(next);
		}
	}
}

vector<prime_factor_t> prime_factors(int64_t num) {
	vector<prime_factor_t> result = {};
	int64_t work = num;
	primes([&result, &work](int64_t p) {
		if (p * p > work) {
			if (work > 1) {
				result.push_back({.p = work, .count = 1});
			}
			return true;
		}

		int count = 0;
		while (work % p == 0) {
			++count;
			work /= p;
		}
		result.push_back({p, count});
		return false;
		});
	return result;
}

vi factorize(int64_t num) {
	vi result = {};
	auto primes = prime_factors(num);
	vector<int> counts(primes.size());
	bool done = false;
	while (!done) {
		int64_t next = 1;
		for (int i = 0; i < counts.size(); ++i) {
			for (int j = 0; j < counts[i]; ++j) {
				next *= primes[i].p;
			}
		}
		result.push_back(next);

		done = true;
		for (int i = 0; i < counts.size(); ++i) {
			if (counts[i] < primes[i].count) {
				++counts[i];
				done = false;
				break;
			}
			counts[i] = 0;
		}
	}
	return result;
}

int64_t sum(vi vec) {
	int64_t result = 0;
	for (int i = 0; i < vec.size(); ++i) {
		result += vec[i];
	}
	return result;
}

int64_t product(vi vec) {
	int64_t result = 1;
	for (int i = 0; i < vec.size(); ++i) {
		result *= vec[i];
	}
	return result;
}

vector<vi> choose(int64_t n, int64_t k) {
	if (k == 0) {
		return {{}};
	}
	vector<vi> result = {};
	for (int64_t i = n - k; i >= 0; --i) {
		for (auto c : choose(i, k - 1)) {
			c.push_back(i);
			result.push_back(c);
		}
	}
	return result;
}

void copy(string s)
{
	if (s.size() > 200) {
		// probably don't want to copy this...
		cout << "String is too long: " << s.size() << endl;
		return;
	}
	{
		{
			ifstream last_result("../last_result.txt");
			if (slurp(last_result) == s) {
				cout << "DUPLICATE!" << endl;
				return;
			}
		}
		{
			ofstream last_result("../last_result.txt");
			last_result << s;
		}
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