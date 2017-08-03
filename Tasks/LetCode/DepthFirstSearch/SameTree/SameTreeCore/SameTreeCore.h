//
// Created by robgrzel on 03.08.17.
//

#ifndef MYTESTING_SAMETREE_H
#define MYTESTING_SAMETREE_H


#include <cstdio>

struct TreeNode {
	int val;
	TreeNode * left;
	TreeNode * right;
	
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};

namespace Tree {
	
	
	class SameTree {
			/*
			 Given two binary trees, write a function to check if they are equal or not.
			 Two binary trees are considered equal if they are structurally identical
			 and the nodes have the same value.
			 */
		public:
			bool isSameTree(TreeNode * p, TreeNode * q) {
			
			}
	};
};


#endif //MYTESTING_SAMETREE_H
