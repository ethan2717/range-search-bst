// Filename: wordrange.cpp
//
// This is the main wrapper for the BST class.
//
// Usage: ./wordrange <INPUT_FILE> <OUTPUT_FILE>
//
// Ethan Yeung, Nov 2022

#include <iostream>
#include "bst.h"
#include <stack>
#include <stdexcept>
#include <fstream>
#include <array>
#include <vector>
#include <algorithm>
#include <sstream>
#include <cstring>

using namespace std;

int main(int argc, char **argv) {
	if (argc != 3) {
		throw std::invalid_argument("Usage: ./wordrange <INPUT_FILE> <OUTPUT_FILE>");
	}

	ifstream input;
	ofstream output;

	input.open(argv[1]);
	output.open(argv[2]);

	string command, val, val2;
	char *com, *valstr, *op;

	BST myBST;

	while (getline(input, command)) {
		if (command.length() == 0) {
			continue;
		}
		com = strdup(command.c_str());
		op = strtok(com, " \t");

		valstr = strtok(NULL, " \t");
		if (valstr) {
			val = valstr;
		}
		if (strcmp(op, "i") == 0) {
			//cout << "Insert " << val << endl;
			myBST.insert(val);
		}
		if (strcmp(op, "r") == 0) {
			valstr = strtok(NULL, " \t");
			if (valstr) {
				val2 = valstr;
			}
			//cout << "Range from " << val << " to " << val2 << " is " << ans << endl;
			output << myBST.range(val, val2) << endl;
		}
	}
}