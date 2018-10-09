#include "stdafx.h"
#include "BST.h"

BinaryNode::BinaryNode(const Comparable& theElement, BinaryNode* lt, BinaryNode* rt)
	:element{ theElement }, left{ lt }, right{ rt }{

}

BinaryNode::BinaryNode(Comparable&& theElement, BinaryNode* lt, BinaryNode* rt)
: element{ std::move(theElement) }, left{ lt }, right{ rt }{

}

BinarySearchTree::BinarySearchTree() : root{ nullptr }{

}

BinarySearchTree::BinarySearchTree(const BinarySearchTree& rhs) : root{ nullptr } {
	root = clone(rhs.root);
}

BinarySearchTree::BinarySearchTree(BinarySearchTree&& rhs) : root{ nullptr } {
	root = std::move(rhs.root);
}

BinarySearchTree::BinarySearchTree(std::vector<Comparable>& vec) {
	for (Comparable elem : vec) {
		insert(elem);
	}
}

BinarySearchTree::~BinarySearchTree(){
	makeEmpty();
}

const Comparable& BinarySearchTree::findMin() const{
	return findMin(root)->element;
}

const Comparable& BinarySearchTree::findMax() const{
	return findMax(root)->element;
}

bool BinarySearchTree::contains(const Comparable& x) const{
	return contains(x, root);
}

bool BinarySearchTree::isEmpty() const{
	return root == nullptr;
}

void BinarySearchTree::printTree(std::ostream& out) const{
	printTree(root, out);
}

void BinarySearchTree::makeEmpty(){
	makeEmpty(root);
}

void BinarySearchTree::insert(const Comparable& x){
	insert(x, root);
}

void BinarySearchTree::insert(Comparable&& x){
	insert(std::move(x), root);
}

void BinarySearchTree::remove(const Comparable& x){
	remove(x, root);
}

BinarySearchTree& BinarySearchTree::operator= (const BinarySearchTree& rhs){
	return *this;
}

BinarySearchTree& BinarySearchTree::operator= (BinarySearchTree&& rhs){
	return rhs;
}

void BinarySearchTree::insert(const Comparable& x, BinaryNode*& t){
	//private method
	if (t == nullptr){
		t = new BinaryNode(x);
	}
	else if (x < t->element){
		insert(x, t->left);
	}
	else if (x>t->element){
		insert(x, t->right);
	}
	else{
		return;//if values are equal
	}
}

void BinarySearchTree::insert(Comparable&& x, BinaryNode*& t){
	//private method
	if (t == nullptr){
		t = new BinaryNode(std::move(x));
	}
	else if (x < t->element){
		insert(x, t->left);
	}
	else if (x>t->element){
		insert(x, t->right);
	}
	else{
		return;//if values are equal
	}
}

void BinarySearchTree::remove(const Comparable& x, BinaryNode*& t){
	//private method
	if (t == nullptr){
		return;
	}
	if (x<t->element){
		remove(x, t->left);
	}
	else if (x> t->element){
		remove(x, t->right);
	}
	else if (t->left != nullptr && t->right != nullptr){
		t->element = findMin(t->right)->element;
		remove(t->element, t->right);
	}
	else{
		BinaryNode* toBeRemoved = t;
		if (t->left == nullptr){
			t = t->right;
		}
		else{
			t = t->left;
		}
		delete toBeRemoved;
	}
}

BinaryNode* BinarySearchTree::findMin(BinaryNode* t) const{
	//private method
	if (t == nullptr){
		return nullptr;
	}
	//if (t->left == nullptr){
	//	return t;
	//}
	//return findMin(t);
	//tail recursion avoided
	while (t->left != nullptr){
		t = t->left;
	}
	return t;
}

BinaryNode* BinarySearchTree::findMax(BinaryNode* t) const{
	//private method
	if (t == nullptr){
		return nullptr;
	}
	while (t->right != nullptr){
		t = t->right;
	}
	return t;
}

bool BinarySearchTree::contains(const Comparable& x, BinaryNode* t) const{
	//private method
	if (t == nullptr) {
		return false;
	}
	else if (x<t->element){
		return contains(x, t->left);
	}
	else if (x>t->element){
		return contains(x, t->right);
	}
	else{
		return true;
	}
}

void BinarySearchTree::makeEmpty(BinaryNode*& t){
	//private method
	if (t == nullptr){
		return;
	}
	else if (t->left != nullptr){
		delete t->left;
	}
	else if (t->right != nullptr){
		delete t->right;
	}
	else{
		delete t;
	}
}

void BinarySearchTree::printTree(BinaryNode* t, std::ostream& out) const{
	//private method
	//level order traversal
	std::vector<BinaryNode*> numbers;
	int level = 1;
	if (t != nullptr){
		numbers.push_back(t);
	}
	while (numbers.size()){
		std::cout << "level " << level << " : ";
		std::vector<BinaryNode*> temp;
		for (auto node : numbers){
			std::cout << node->element << " ";
			if (node->left != nullptr){
				temp.push_back(node->left);
			}
			if (node->right != nullptr){
				temp.push_back(node->right);
			}
		}
		std::cout << std::endl;
		numbers = std::move(temp);
		++level;
	}
	return;
}

BinaryNode* BinarySearchTree::clone(BinaryNode* t) const{
	//private method
	if (t == nullptr) {
		return nullptr;
	}
	else {
		return new BinaryNode(t->element, clone(t->left), clone(t-> right));
	}
}