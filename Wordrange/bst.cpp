// Filename: bst.cpp
//
// Contains the class BST that represents a binary search tree.
//
// Ethan Yeung, Nov 2022

#include "bst.h"
#include <cstdlib>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>

using namespace std;

BST :: BST() {
	root = NULL;
}

void BST :: insert(string val) {
	if (find(val)) {
		return;
	}
	Node *to_insert = new Node(val);
	if (!root) {
		root = to_insert;
	} else {
		insert(root, to_insert);
	}
}

void BST :: insert(Node *start, Node *to_insert) {
	if (!start) {
		return;
	}
	if (to_insert->key <= start->key) {
		if (!(start->left)) {
			start->left = to_insert;
			to_insert->parent = start;
			return;
		} else {
			insert(start->left, to_insert);
			return;
		}
	} else {
		if (!(start->right)) {
			start->right = to_insert;
			to_insert->parent = start;
			return;
		} else {
			insert(start->right, to_insert);
			return;
		}
	}
}

Node *BST :: find(string val) {
	return find(root, val);
}

Node *BST :: find(Node *start, string val) {
	if (!start || start->key == val) {
		return start;
	}
	if (val < start->key) {
		return find(start->left, val);
	} else {
		return find(start->right, val);
	}
}

int BST :: range(string first, string last) {
	int count = 0;
	return range(root, first, last, count);
}

int BST :: range(Node *start, string first, string last, int &count) {
	if (!start) {
		return 0;
	}
	range(start->left, first, last, count);
	if (start->key >= first && start->key <= last) {
		count++;
	}
	range(start->right, first, last, count);
	return count;
}