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
	if (regex == "") {
		vs result;
		// special case, just return the characters as substrings
		for (char c : input) {
			result.push_back(string(1, c));
		}
		return result;
	}
	// passing -1 as the submatch index parameter performs splitting
	std::regex re(regex);
	sregex_token_iterator
		first{ input.begin(), input.end(), re, -1 },
		last;
	// for most delimiters, an empty first element is worthless; empty lines are sometimes meaningful tho
	if (regex != "\n" && *first == "") {
		++first;
	}
	return { first, last };
}

vector<vs> split(const vs& input, const string& regex) {
	vector<vs> result;
	if (regex == "") {
		// special case, just return the characters as substrings
		for (auto str : input) {
			result.push_back({});
			for (char c : str) {
				result[result.size() - 1].push_back(string(1, c));
			}
		}
		return result;
	}
	// passing -1 as the submatch index parameter performs splitting
	std::regex re(regex);
	for (const auto& line : input) {
		sregex_token_iterator
			first{ line.begin(), line.end(), re, -1 },
			last;
		result.push_back({ first, last });
	}
	return result;
}

vi map_to_num(const vs &vec) {
	vi result;
	result.resize(vec.size());
	transform(vec.begin(), vec.end(), result.begin(), [](const string &s) { return s.empty() ? 0 : stoll(s); });
	return result;
}

vector<vi> map_to_num(const vector<vs> &vec) {
	vector<vi> result;
	result.resize(vec.size());
	transform(vec.begin(), vec.end(), result.begin(), [](const vs &v) { return map_to_num(v); });
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

int64_t min(vi vec) {
	int64_t result = vec[0];
	for (int i = 1; i < vec.size(); ++i) {
		if (vec[i] < result) {
			result = vec[i];
		}
	}
	return result;
}

int64_t max(vi vec) {
	int64_t result = vec[0];
	for (int i = 1; i < vec.size(); ++i) {
		if (vec[i] > result) {
			result = vec[i];
		}
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

int64_t parse_BITS_int(const vector<bool> &bits, size_t &index, size_t size) {
	int64_t result = 0;
	if (size > 0) {
		for (size_t i = 0; i < size; ++i) {
			result <<= 1;
			result += bits[index++];
		}
		return result;
	}
	bool next;
	do {
		next = bits[index++];
		result <<= 4;
		result += parse_BITS_int(bits, index, 4);
	} while (next);
	return result;
}

BITS_packet_t parse_BITS_packet(const vector<bool> &bits, size_t &index, int64_t version) {
	const bool verbose = false;
	BITS_packet_t result;
	result.version = parse_BITS_int(bits, index, 3);
	if (verbose) cout << result.version << endl;
	result.type = parse_BITS_int(bits, index, 3);
	if (verbose) cout << result.type << endl;
	switch (result.type) {
	case 4:
	{
		if (verbose) cout << "Literal: ";
		result.result = parse_BITS_int(bits, index);
		if (verbose) cout << result.result << endl;
		break;
	}
	default:
	{
		if (!bits[index++]) {
			size_t length = parse_BITS_int(bits, index, 15);
			if (verbose) cout << "Raw: " << length << endl;
			size_t finish = index + length;
			while (index < finish) {
				auto packet = parse_BITS_packet(bits, index, version);
				if (version == -1 || packet.version <= version) {
					result.subpackets.push_back(packet);
				}
			}
		} else {
			size_t subpacket_count = parse_BITS_int(bits, index, 11);
			if (verbose) cout << "Subpackets: " << subpacket_count << endl;
			for (int i = 0; i < subpacket_count; ++i) {
				auto packet = parse_BITS_packet(bits, index, version);
				if (version == -1 || packet.version <= version) {
					result.subpackets.push_back(packet);
				}
			}
		}
		if (version > -1 && version > result.version) {
			return result;
		}
		switch (result.type) {
		case 0:
		{
			for (auto packet : result.subpackets) {
				result.result += packet.result;
			}
			break;
		}
		case 1:
		{
			result.result = 1;
			for (auto packet : result.subpackets) {
				result.result *= packet.result;
			}
			break;
		}
		case 2:
		{
			result.result = result.subpackets[0].result;
			for (int i = 0; i < result.subpackets.size(); ++i) {
				result.result = min(result.result, result.subpackets[i].result);
			}
			break;
		}
		case 3:
		{
			result.result = 0;
			for (auto packet : result.subpackets) {
				result.result = max(result.result, packet.result);
			}
			break;
		}
		case 5:
		{
			result.result = result.subpackets[0].result > result.subpackets[1].result;
			break;
		}
		case 6:
		{
			result.result = result.subpackets[0].result < result.subpackets[1].result;
			break;
		}
		case 7:
		{
			result.result = result.subpackets[0].result == result.subpackets[1].result;
			break;
		}
		}
	}
	}
	return result;
}

BITS_packet_t parse_BITS_packet_sum(const vector<bool> &bits, size_t &index, int64_t &sum) {
	vector<BITS_packet_t> queue{parse_BITS_packet(bits, index)};
	for (int i = 0; i < queue.size(); ++i) {
		sum += queue[i].version;
		for (int j = 0; j < queue[i].subpackets.size(); ++j) {
			queue.push_back(queue[i].subpackets[j]);
		}
	}
	return queue[0];
}
