#include <iostream>
using namespace std;

template <typename T>
struct node {
	T data;
	node <T>* next;
};

template <typename T>
class list {
private:
	node <T>* head, * it;
	int n;
public:
	list() {
		head = NULL;
		it = NULL;
		n = 0;
	}

	~list() {
		make_empty();
	}

	void insert(const T& val) {
		node <T>* temp;
		temp = new node<T>;
		temp->data = val;
		
		if (head == NULL) {
			node <T>* temp2;
			temp2 = new node<T>;
			temp2->next = temp;
			temp->next = temp2;
		}
		else {
			temp->next = head->next;
			head->next = temp;
		}
		head = temp;
		n++;
	}

	bool find(const T& val) const {
		node<T>* temp;
		temp = head;
		while (temp != NULL) {
			if (temp->data == val) {
				return true;
			}
			temp = temp->next;
		}
		return false;
	}

	bool update(const T& old_val, const T& new_val) {
		node<T>* temp;
		temp = head;
		while (temp != NULL) {
			if (temp->data == old_val) {
				temp->data = new_val;
				return true;
			}
			temp = temp->next;
		}
		return false;
	}

	bool erase(const T& val) {
		if (head == NULL)
			return false;
		node <T>* temp;
		temp = head;

		if (temp->data == val) {
			head = temp->next;
			delete temp;
			n--;
			return true;
			exit(0);
		}

		while (temp->next != NULL) {
			if (temp->next->data == val) {
				node <T>* to_del;
				to_del = temp->next;
				temp->next = to_del->next;
				delete to_del;
				n--;
				return true;
				exit(0);
			}
			temp = temp->next;
		}

		return false;
	}

	bool empty() const {
		return head == NULL;
	}

	bool full() const {
		return false;
	}

	void make_empty() {
		node <T>* temp;
		while (head->next == it->next) {
			temp = head;
			head = temp->next;
			delete temp;
		}
		head = NULL;
		n = 0;
	}

	int length() const {
		return n;
	}

	void reset() {
		it = head->next;
	}

	bool is_last() const {
		return head->next == it->next;
	}

	T get_next() {
		if (is_last()) {
			throw("value couldn't found!");
		}
		T val;
		val = it->next->data;
		it = it->next;
		return val;
	}


};

int main() {

	list <char> obj;
	char val;
	obj.insert('J');
	obj.insert('Y');
	obj.insert('D');
	obj.insert('G');
	obj.insert('K');
	obj.insert('T');
	obj.reset();
	while (!obj.is_last()) {
		val = obj.get_next();
		cout << val << " ";
	}

	cout << endl;

	char v = 'K';
	if (obj.find(v)) {
		cout << v << " has been Found!" << endl;
	}
	else {
		cout << v << " Not found!" << endl;
	}
	
	cout << endl;

	return 0;
}