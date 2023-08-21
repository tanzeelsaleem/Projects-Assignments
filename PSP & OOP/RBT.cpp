#include<iostream>
#include<list>
using namespace std;

template<typename T>
struct BNode {
	T data;
    T color;
	BNode<T>* left, * right, * parent;
};

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
		node->parent = node->left = node->right = NULL;
        node->color = "red";
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
                        node->parent = root;
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
            Tree_fixing(node);
		}
	}//end of insert function.

     void Tree_fixing(BNode<T>* check) {
            while(check->parent->color == "red") {
                BNode<T>* grandparent = check->parent->parent;
                BNode<T>* uncle = root;
                if(check->parent == grandparent->left) {
                    if(grandparent->right) { 
                        uncle = grandparent->right; 
                    }
                    if(uncle->color == "red"){
                        check->parent->color = "black";
                        uncle->color = "black";
                        grandparent->color = "red";
                        if(grandparent->data != root->data){ 
                            check = grandparent; }
                        else { 
                            break; 
                        }
                    }
                    else if(check == grandparent->left->right) {
                       LeftRotate(check->parent);
                    }
                    else {
                        check->parent->color = "balck";
                        grandparent->color = "red";
                        RightRotate(grandparent);
                        if(grandparent->data != root->data){ 
                            check = grandparent; 
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
                        check->parent->color = "black";
                        uncle->color = "black";
                        grandparent->color = "black";
                        if(grandparent->data != root->data){ 
                            check = grandparent; 
                        }
                        else { 
                            break; 
                        }
                    }
                    else if(check == grandparent->right->left){
                        RightRotate(check->parent);
                    }
                    else {
                        check->parent->color = "black";
                        grandparent->color = "red";
                        LeftRotate(grandparent);
                        if(grandparent->data != root->data){ 
                            check = grandparent; 
                        }
                        else { 
                            break; 
                        }
                    }
                }
            }
            root->color = "black";
        }

        void LeftRotate( BNode<T>* node) {
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

        void RightRotate( BNode<T>* node) {
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

};