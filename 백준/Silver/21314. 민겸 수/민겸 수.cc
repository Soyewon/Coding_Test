#include <vector>
#include <string>
#include <iostream>

using namespace std;

string GetMax(string s) {
	string result = "";

	int i = 0;
    int end = 0;
	while (i < s.size()) {
		if (s[i] == 'M') {
			end = i;
			while (end < s.size()) {
				if (s[end] == 'M')
                    end++;
				else break;
			}

			if (end == s.size()) {
				for (int len = 0; len < end - i; len++) {
					result += "1";
				}
			}
			else {
				result += "5";
				for (int len = 0; len < end - i; len++) {
					result += "0";
				}
			}

			i = end + 1;
		}
		else {
			result += "5";
			i++;
		}
	}

	return result;
}

string GetMin(string s) {
	string result = "";

	int i = 0;
	while (i < s.size()) {
		if (s[i] == 'M') {
			int end = i;
			while (end < s.size()) {
				if (s[end] == 'M') 
                    end++;
				else break;
			}

			result += "1";
			end--;

			for (int len = 0; len < end - i; len++) {
				result += "0";
			}

			i = end + 1;
		}
		else {
			result += "5";
			i++;
		}
	}

	return result;
}

int main() {
	string s;
	cin >> s;
    
	cout << GetMax(s) << '\n';
	cout << GetMin(s);
    return 0;
}