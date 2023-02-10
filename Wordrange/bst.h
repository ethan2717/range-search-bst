// Filename: bst.h
//
// Header file for the class BST that represents a binary search tree
//
// Ethan Yeung, Nov 2022

#ifndef BST_H
#define BST_H

#include <string>

using namespace std;

class Node {
	public:
		string key;
		Node *left, *right, *parent;

		Node() {
			left = right = parent = NULL;
		}

		Node(string val) {
			key = val;
			left = right = parent = NULL;
		}
};

class BST {
	private:
		Node *root;
	public:
		BST();
		void insert(string);
		void insert(Node *, Node *);
		Node *find(string);
		Node *find(Node *, string);
		int range(string, string);
		int range(Node *, string, string, int &);
};

#endif