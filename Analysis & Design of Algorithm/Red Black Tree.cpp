#include<iostream>
#include<list>
using namespace std;

template<typename T>
struct BNode {
	T data;
    string color;
	BNode<T>* left, * right, * parent;
};

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

template<typename T>
class red_black_tree {
private:
	BNode<T>* root;
	list<T> list_obj;
public:
	red_black_tree() {
		root = NULL;
	}

	~red_black_tree() {
		make_empty();
	}

	red_black_tree(red_black_tree& to_copy) {
		root = NULL;
		operator=(to_copy);
	}

	void operator=(red_black_tree& to_copy) {
		to_copy.reset();
		while (!to_copy.is_last()) {
			T val;
			val = to_copy.get_next();
			this->insert(val);
		}
	}

	void  make_empty() {
		this->reset();
		while (!this->is_last()) {
			list_obj.pop_back();
		}
	}

	void insert(const T& val) {
		BNode<T>* node;
		node = new BNode<T>;
		node->data = val;
		node->parent = node->left = node->right = NULL;
        node->color = "red";
		if (root == NULL) {
			root = node;
		}
		else {
			BNode<T>* temp;
			temp = root;
			while (temp != NULL) {
				if (val < temp->data) {
					if (temp->left == NULL) {
						temp->left = node;
                        node->parent = root;
						return;
					}
					else {
						temp = temp->left;
					}
				}
				else if (val > temp->data) {
					if (temp->right == NULL) {
						temp->right = node;
                        node->parent = root;
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
            tree_fixing(node);
		}
	}

    void tree_fixing(BNode<T>* node) {
        while(node->parent->color == "red") {
            BNode<T>* grandparent = node->parent->parent;
            BNode<T>* uncle = root;
            if(node->parent == grandparent->left) {
                if(grandparent->right) { 
                    uncle = grandparent->right; 
                }
                if(uncle->color == "red"){
                    node->parent->color = "black";
                    uncle->color = "black";
                    grandparent->color = "red";
                    if(grandparent->data != root->data){ 
                        node = grandparent; }
                    else { 
                        break; 
                    }
                }
                else if(node == grandparent->left->right) {
                    rotation_to_left(node->parent);
                }
                else {
                    node->parent->color = "balck";
                    grandparent->color = "red";
                    rotation_to_right(grandparent);
                    if(grandparent->data != root->data){ 
                        node = grandparent; 
                    }
                    else { 
                        break; 
                    }
                }
            }
            else {
                if(grandparent->left) { 
                    uncle = grandparent->left; 
                }
                if(uncle->color == "red"){
                    node->parent->color = "black";
                    uncle->color = "black";
                    grandparent->color = "black";
                    if(grandparent->data != root->data){ 
                        node = grandparent; 
                    }
                    else { 
                        break; 
                    }
                }
                else if(node == grandparent->right->left){
                    rotation_to_right(node->parent);
                }
                else {
                    node->parent->color = "black";
                    grandparent->color = "red";
                    rotation_to_left(grandparent);
                    if(grandparent->data != root->data){ 
                        node = grandparent; 
                    }
                    else { 
                        break; 
                    }
                }
            }
        }
        root->color = "black";
    }

    void rotation_to_left( BNode<T>* node) {
        BNode<T>* temp;
        if(node->right->left) { 
            temp->right = node->right->left; 
        }
        temp->left = node->left;
        temp->data = node->data;
        temp->color = node->color;
        node->data = node->right->data;

        node->left = temp;
        if(temp->left){ 
            temp->left->parent = temp; 
        }
        if(temp->right){ 
            temp->right->parent = temp; 
        }
        temp->parent = node;
        if(node->right->right){ 
            node->right = node->right->right; 
        }
        else { 
            node->right = NULL; 
        }

        if(node->right){ 
            node->right->parent = node; 
        }
    }

    void rotation_to_right( BNode<T>* node) {
        BNode<T>* temp;
        if(node->left->right){ 
            temp->left = node->left->right; 
        }
        temp->right = node->right;
        temp->data = node->data;
        temp->color = node->color;

        node->data = node->left->data;
        node->color = node->left->color;

        node->right = temp;
        if(temp->left){ 
            temp->left->parent = temp; 
        }
        if(temp->right){ 
            temp->right->parent = temp; 
        }
        temp->parent = node;

        if(node->left->left){ 
            node->left = node->left->left; 
        }
        else { 
            node->left = NULL; 
        }

        if(node->left){ 
            node->left->parent = node; 
        }
    }

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
	}

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
};

int main() {
	red_black_tree<int> first, second;
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
	cout << "\n100 Find: " << first.find(val) << endl;
	cout << "\nFirst tree!" << endl;
	first.reset();
	while (!first.is_last()) {
		cout << first.get_next() << " ";
	}
	cout << endl;

	val = 80;
	second = first; // overload = operator will be called.
	red_black_tree<int>third(second); // copy constructor will be called.
	cout << "\n80 in first tree? Find: " << first.find(val) << endl;
	val = 35;
	cout << "\n35 in second tree? Find: " << second.find(val) << endl;
	val = 10;
	cout << "\n10 in third tree? Find: " << third.find(val) << endl;
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
}