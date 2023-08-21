#include<iostream>
#include<list>
using namespace std;

template<typename T>
struct BNode {
	T data;
	BNode<T>* left, * right;
};

//function to delete node
template <typename T>
void erase_node(BNode<T>*& node) {
	//left node
	if (node->left == NULL && node->right == NULL) {
		delete node;
		node = NULL;
	}
	//node has only left node
	else if (node->left != NULL && node->right == NULL) {
		BNode <T>* temp;
		temp = node;
		node = node->left;
		delete temp;
	}
	//node has only right node
	else if (node->right != NULL && node->left == NULL) {
		BNode<T>* temp;
		temp = node;
		node = node->right;
		delete temp;
	}
	//node has both children
	else {
		BNode<T>* predecessor, * previous;
		previous = NULL;
		predecessor = node->left;
		while (predecessor->right != NULL) {
			previous = predecessor;
			predecessor = predecessor->right;
		}
		node->data = predecessor->data;
		if (previous != NULL) {
			previous->right = predecessor->left;
		}
		else {
			node->left = predecessor->left;
		}
		delete predecessor;
	}
}

//function to traverse tree
template <typename T>
void traverse(BNode<T>* node, list<T>& nodes_list) {
	list< BNode<T>* > temp_list;
	temp_list.push_back(node);
	while (!temp_list.empty()) {
		BNode<T>* temp;
		temp = temp_list.front();
		temp_list.pop_front();
		nodes_list.push_back(temp->data);
		if (temp->left != NULL) {
			temp_list.push_back(temp->left);
		}
		if (temp->right != NULL) {
			temp_list.push_back(temp->right);
		}
	}
}

//Start of Binary Search tree
template<typename T>
class BST {
private:
	BNode<T>* root;
	list<T> list_obj;
public:
	//constructor
	BST() {
		root = NULL;
	}

	//destructor
	~BST() {
		make_empty();
	}

	//copy constructor
	BST(BST& to_copy) {
		root = NULL;
		operator=(to_copy);
	}

	//assignment operator overload
	void operator=(BST& to_copy) {
		to_copy.reset();
		while (!to_copy.is_last()) {
			T val;
			val = to_copy.get_next();
			this->insert(val);
		}
	}

	//make empty function
	void  make_empty() {
		this->reset();
		while (!this->is_last()) {
			list_obj.pop_back();
		}
	}

	//insert function
	void insert(const T& val) {
		BNode<T>* node;
		node = new BNode<T>;
		node->data = val;
		node->left = node->right = NULL;
		if (root == NULL) {
			root = node;
		}
		else {
			BNode<T>* temp;
			temp = root;
			while (temp != NULL) {
				//new node is smaller than temp
				if (val < temp->data) {
					if (temp->left == NULL) {
						temp->left = node;
						return;
					}
					else {
						temp = temp->left;
					}
				}
				//new node is greater than temp
				else if (val > temp->data) {
					if (temp->right == NULL) {
						temp->right = node;
						return;
					}
					else {
						temp = temp->right;
					}
				}
				else {
					throw ("Duplicate keys not allowed!");
				}
			}
		}
	}//end of insert function.

	//find function.
	bool find(const T& val) {
		BNode <T>* node;
		node = root;
		if (node == NULL) {
			return false;
		}
		else if (node->data == val) {
			return true;
		}
		else {
			while (true) {
				if (val < node->data) {
					if (node->left != NULL) {
						if (val == node->left->data) {
							return true;
						}
						else {
							node = node->left;
						}
					}
					else {
						return false;
					}
				}
				else if (val > node->data) {
					if (node->right != NULL) {
						if (val == node->right->data) {
							return true;
						}
						else {
							node = node->right;
						}
					}
					else {
						return false;
					}
				}
			}
		}
	}//end of find function

	//erase function
	bool erase(const T& val) {
		BNode <T>* node;
		node = root;
		if (node == NULL) {
			return false;
		}
		else if (node->data == val) {
			erase_node(node);
			return true;
		}
		else {
			while (true) {
				if (val < node->data) {
					if (node->left != NULL) {
						if (val == node->left->data) {
							erase_node(node->left);
							return true;
						}
						else {
							node = node->left;
						}
					}
					else {
						return false;
					}
				}
				else if (val > node->data) {
					if (node->right != NULL) {
						if (val == node->right->data) {
							erase_node(node->right);
							return true;
						}
						else {
							node = node->right;
						}
					}
					else {
						return false;
					}
				}
			}
		}
	}// end of erase function

	bool is_last() const {
		return list_obj.empty();
	}

	void reset() {
		list_obj = list<T>();
		traverse(root, list_obj);
	}

	T get_next() {
		if (is_last()) {
			throw("Can't get next value!");
		}
		T val;
		val = list_obj.front();
		list_obj.pop_front();
		return val;
	}
};//end of BST class

//driver function
int main() {
	BST<int> first, second;
	first.insert(50);
	first.insert(75);
	first.insert(100);
	first.insert(80);
	first.insert(90);
	first.insert(25);
	first.insert(35);
	first.insert(28);
	first.insert(10);
	first.insert(5);
	first.insert(3);

	int val = 100;
	cout << "\n100 Find: " << first.find(val) << endl;
	val = 100;
	cout << "\n100 Delted: " << first.erase(val) << endl;
	cout << "\n100 Find: " << first.find(val) << endl;
	cout << "\nFirst tree!" << endl;
	first.reset();
	while (!first.is_last()) {
		cout << first.get_next() << " ";
	}
	cout << endl;

	val = 80;
	second = first; // overload = operator will be called.
	BST<int>third(second); // copy constructor will be called.
	cout << "\n80 in first tree? Find: " << first.find(val) << endl;
	val = 35;
	cout << "\n35 in second tree? Find: " << second.find(val) << endl;
	val = 10;
	cout << "\n10 in third tree? Find: " << third.find(val) << endl;
	val = 28;
	cout << "\n28 in second tree? Delted: " << second.erase(val) << endl;
	val = 50;
	cout << "\n50 in third tree ? Delted: " << third.erase(val) << endl;
	cout << "\nSecond tree!" << endl;

	second.reset();
	while (!second.is_last()) {
		cout << second.get_next() << " ";
	}
	cout << endl;

	cout << "\nThird tree!" << endl;
	third.reset();
	while (!third.is_last()) {
		cout << third.get_next() << " ";
	}
	cout << endl;
	return 0;
}//end of driver function