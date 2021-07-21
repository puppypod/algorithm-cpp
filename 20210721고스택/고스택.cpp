#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

struct cmd {
	string str;
	long long num = 0;
};

bool NUM(vector<long long>& v, long long n) {
	if (abs(n) > 1000000000) return false;
	v.push_back(n);
	return true;
}
bool POP(vector<long long>& v) {
	if (!v.empty()) v.pop_back();
	else return false;
	
	return true;
}
bool INV(vector<long long>& v) {
	if (!v.empty()) v[(int)v.size() - 1] = -v[(int)v.size() - 1];
	else return false;

	return true;
}
bool DUP(vector<long long>& v) {
	if (!v.empty()) {
		long long num = v.back();
		v.push_back(num);
	} 
	else return false;

	return true;
}
bool SWP(vector<long long>& v) {
	if (v.size() >= 2) {
		long long first = v.back(); v.pop_back();
		long long second = v.back(); v.pop_back();
		v.push_back(first);
		v.push_back(second);
	}
	else return false;

	return true;
}
bool ADD(vector<long long>& v) {
	if (v.size() >= 2) {
		long long first = v.back(); v.pop_back();
		long long second = v.back(); v.pop_back();
		long long sum = first + second;
		if (abs(sum) > 1000000000) return false;
		v.push_back(first + second);
	}
	else return false;

	return true;
}
bool SUB(vector<long long>& v) {
	if (v.size() >= 2) {
		long long first = v.back(); v.pop_back();
		long long second = v.back(); v.pop_back();
		long long sum = second - first;
		if (abs(sum) > 1000000000) return false;
		v.push_back(second - first);
	}
	else return false;

	return true;
}
bool MUL(vector<long long>& v) {
	if (v.size() >= 2) {
		long long first = v.back(); v.pop_back();
		long long second = v.back(); v.pop_back();
		long long sum = first * second;
		if (abs(sum) > 1000000000) return false;
		v.push_back(first * second);
	}
	else return false;

	return true;
}
bool DIV(vector<long long>& v) {
	if (v.size() >= 2) {
		long long first = v.back(); v.pop_back();
		if (first == 0LL) return false;
		long long second = v.back(); v.pop_back();
		long long sum = second / first;
		if (abs(sum) > 1000000000) return false;
		v.push_back(sum);
	}
	else return false;

	return true;
}
bool MOD(vector<long long>& v) {
	if (v.size() >= 2) {
		long long first = v.back(); v.pop_back();
		if (first == 0) return false;
		long long second = v.back(); v.pop_back();
		
		long long sum = second % first;
		if (abs(sum) > 1000000000) return false;
		v.push_back(sum);
	}
	else return false;

	return true;
}
int main()
{
	string inputStr;
	cin >> inputStr;

	while (inputStr != "QUIT") {
		vector<cmd> strArr;
		while (inputStr != "END") {
			cmd tmp;
			tmp.str = inputStr;
			if (inputStr == "NUM") {
				long long number; cin >> number;
				tmp.num = number;
				
			}
			
			strArr.push_back(tmp);

			cin >> inputStr;
		}
		vector<long long> v;
		long long number; cin >> number;
		for (int i = 0; i < number; i++) {
			long long tmp; cin >> tmp;
			v.push_back(tmp);
		}
		bool flag = true;
		for (long long n : v) {
			vector<long long> st;
			st.push_back(n);
			flag = true;
			
			for (cmd tmp : strArr) {
				string s = tmp.str;
				long long num = tmp.num;
				if (s == "NUM") { if (!NUM(st, num)) flag = false; }
				else if (s == "POP"){ if (!POP(st)) flag = false; }
				else if (s == "INV"){ if (!INV(st)) flag = false; }
				else if (s == "DUP") { if (!DUP(st))flag = false; }
				else if (s == "SWP") { if (!SWP(st)) flag = false; }
				else if (s == "ADD") { if (!ADD(st)) flag = false; }
				else if (s == "SUB") { if (!SUB(st)) flag = false; }
				else if (s == "MUL") { if (!MUL(st)) flag = false; }
				else if (s == "DIV") { if (!DIV(st)) flag = false; }
				else if (s == "MOD") { if (!MOD(st)) flag = false; }

				if (!flag) break;
			}
			if (st.size()==1 && flag) {
				cout << st.back() << '\n';
			}
			else {
				cout << "ERROR" << '\n';
			}
			
		}
		cout << '\n';
		cin >> inputStr;
	}
}