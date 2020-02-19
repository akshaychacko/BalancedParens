
#include <deque>
#include <iostream>
using namespace std;


bool isBalanced() {
	deque<char> structure;
	char input = ' ';
	while (cin >> input) {
		if (input != ' ') {
			if (input == '[' || input == '(' || input == '{') {
				structure.push_front(input);
			}

			///	else if ((input == ']' && structure.front() == '[') || (input == ')' && structure.front() == '(') || (input == '}' && structure.front() == '}')) {
			else if ((input == ']') || (input == ')') || (input == '}')) {
				char curr = structure.front();
				structure.pop_front();
				switch (input) {
				case ')' :
					if (curr != '(') {
						return false;
					}
				break;
				case '}' :
					if (curr != '{') {
						return false;
					}
				break;
				case ']':
					if (curr != '[') {
						return false;
					}
				break;
				}		
			}
		}
	}

	if (!structure.empty()) {
		return false;
	}
	return true;
}

int main() {

	if (isBalanced()) {
		cout << "Balanced";
	}
	else {
		cout << "Not balanced";
	}
}
