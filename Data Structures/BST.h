#ifndef _BST_H_
#define _BST_H_

#include<iostream>
#include<vector>

typedef int Comparable;

struct BinaryNode{
	Comparable element;
	BinaryNode* left;
	BinaryNode* right;

	BinaryNode(const Comparable& theElement, BinaryNode* lt=nullptr, BinaryNode* rt=nullptr);
	BinaryNode(Comparable&& theElement, BinaryNode* lt=nullptr, BinaryNode* rt=nullptr);
};

class BinarySearchTree{
public:
	BinarySearchTree();
	BinarySearchTree(const BinarySearchTree& rhs);
	BinarySearchTree(BinarySearchTree&& rhs);
	BinarySearchTree(std::vector<Comparable>& vec);
	~BinarySearchTree();

	const Comparable& findMin() const;
	const Comparable& findMax() const;
	bool contains(const Comparable& x) const;
	bool isEmpty() const;
	void printTree(std::ostream& out = std::cout) const;

	void makeEmpty();
	void insert(const Comparable& x);
	void insert(Comparable&& x);
	void remove(const Comparable& x);

	BinarySearchTree& operator= (const BinarySearchTree& rhs);
	BinarySearchTree& operator= (BinarySearchTree&& rhs);

private:
	BinaryNode* root;

	void insert(const Comparable& x, BinaryNode*& t);
	void insert(Comparable&& x, BinaryNode*& t);
	void remove(const Comparable& x, BinaryNode*& t);
	BinaryNode* findMin(BinaryNode* t) const;
	BinaryNode* findMax(BinaryNode* t) const;
	bool contains(const Comparable& x, BinaryNode* t) const;
	void makeEmpty(BinaryNode*& t);
	void printTree(BinaryNode* t, std::ostream& out) const;

	BinaryNode* clone(BinaryNode* t) const;
};

#endif