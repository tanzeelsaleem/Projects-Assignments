#include<iostream>
using namespace std;

template<typename T>
struct node {
	T data;
	node<T>* next;
};

template <typename T>
class queue {
private:
	node <T> * rare;
public:
	queue() {
		rare = NULL;
	}

	void push(const T& val) {
		node <T>* temp;
		temp = new node <T>;
		temp->data = val;
		if (rare == NULL) {
			temp->next = temp;
			rare = temp;
		}
		else {
			temp->next = rare->next;
			rare->next = temp;
			rare = temp;
		}
	}

	void pop() {
		if (rare == NULL) {
			throw "Queue Underflow!";
		}
		node <T>* temp;
		temp = rare->next;
		if (rare->next == temp->next) {
			delete temp;
			rare = NULL;
		}
		else {
			rare->next = temp->next;
			delete temp;
		}
	}

	T front_element() const {
		if (empty()) {
			throw "Queue is empty!";
		}
		return rare->next->data;
	}

	bool empty() const {
		return rare == NULL;
	}

	void make_empty() {
		while (!empty()) {
			pop();
		}
	}

	bool full() const {
		node<T>* temp;
		temp = new node<T>;
		if (temp == NULL) {
			return true;
		}
		else {
			delete temp;
			return false;
		}
	}

	~queue() {
		make_empty();
	}

};

//driver function.
int main() {

	queue<int>queue_obj;
	try {
		queue_obj.push(6);
		queue_obj.push(5);
		queue_obj.push(7);
		queue_obj.push(10);
	}
	catch (const char* msg) {
		cout << msg << endl;
	}

	while (!queue_obj.empty()) {
		int val;
		val = queue_obj.front_element();
		queue_obj.pop();
		cout << val << endl;
	}

	return 0;
}