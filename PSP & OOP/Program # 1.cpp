#include <iostream>
using namespace std;

template<typename T>
struct node {
	T data;
	node <T>* next, * previous;
};

template <typename T>
class list {
private:
	node<T>* head, * it;
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
		//insert into an empty list
		if (head == NULL) {
			temp->next = temp->previous = NULL;
			head = temp;
		}
		//insert at the beginning of list
		else if (val < head->data) {
			temp->next = head;
			head->previous = temp;
			head = temp;
		}
		//insert in the middle of list
		else {
			node <T>* ptr;
			ptr = head;
			while (true) {
				if (ptr->next == NULL) {
					temp->next = ptr->next;
					temp->previous = ptr;
					ptr->next = temp;
					break;
				}
				if (val < ptr->next->data) {
					temp->next = ptr->next;
					temp->previous = ptr;
					ptr->next->previous = temp;
					ptr->next = temp;
					break;
				}
				ptr = ptr->next;
			}
		}
		n++;
	}

	bool find(T& val) const {
		node<T>* temp;
		temp = head;
		while (temp != NULL) {
			if (val < temp->data) {
				return false;
			}
			if (temp->data == val) {
				val = temp->data;
				return true;
			}
			temp = temp->next;
		}
		return false;
	}

	bool update(const T& old_val, const T& new_val) {
		if (erase(old_val)) {
			insert(new_val);
			return true;
		}
		else {
			return false;
		}
	}

	bool erase(const T& val) {
		//list empty
		if (head == NULL)
			return false;
		node <T>* temp;
		temp = head;

		//delete the first
		if (temp->data == val) {
			temp->next->previous = NULL;
			head = temp->next;
			delete temp;
			n--;
			return true;
		}

		//delete a node from second to last
		while (temp->next != NULL) {
			if (val < temp->data) {
				return false;
			}
			if (temp->next->data == val) {
				node <T>* to_del;
				to_del = temp->next;
				temp->next = to_del->next;
				temp->next->previous = temp;
				delete to_del;
				n--;
				return true;
			}
			temp = temp->next;
		}
		//value not found
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
		while (head != NULL) {
			temp = head;
			head = temp->next;
			delete temp;
		}
		n = 0;
	}

	int length() const {
		return n;
	}

	void reset() {
		it = head;
	}

	bool is_last() const {
		return it == NULL;
	}

	T get_next() {
		if (is_last()) {
			throw ("Can't find the value!");
		}
		T val;
		val = it->data;
		it = it->next;
		return val;
	}

};

int main() {

	list <char> list_obj;
	char val;
	list_obj.insert('T');
	list_obj.insert('Z');
	list_obj.insert('M');
	list_obj.insert('V');
	//list_obj.update('M', 'N');
	list_obj.reset();
	while (!list_obj.is_last()) {
		val = list_obj.get_next();
		cout << val << " ";
	}
	cout << endl;
	char v = 'Z';
	if (list_obj.find(v)) {
		cout << v << " Found!" << endl;
	}
	else {
		cout << v << " Not found!" << endl;
	}

	return 0;

}