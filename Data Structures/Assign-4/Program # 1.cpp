#include<iostream>
using namespace std;

template<typename T>
class queue {
private:
	int rear_index, front_index, size;
	T* data;
public:
	queue(int s = 10) {
		size = s;
		rear_index = front_index = -1;
		data = new T[size];
	}

	~queue() {
		delete[]data;
	}
	queue(const queue<T>& source) {
		delete[]data;
		size = source.size;
		rear_index = source.rear_index;
		front_index = source.front_index;
		data = new T[size];
		for (int i = 0; i < size; i++) {
			data[i] = source.data[i];
		}
	}

	void operator=(const queue<T>& source) {
		delete[]data;
		size = source.size;
		rear_index = source.rear_index;
		front_index = source.front_index;
		data = new T[size];
		for (int i = 0; i < size; i++) {
			data[i] = source.data[i];
		}
	}

	void push_front(const T &val) {
		if (full())
			throw "Queue Ovrflow!";

		front_index++;
		data[front_index] = val;
	}

	void push_rare(const T &val) {
		if (full())
			throw "Queue Ovrflow!";
		if (rear_index == -1) {
			rear_index = size - 1;
		}
		else {
			rear_index--;
		}
		data[rear_index] = val;
	}

	void pop_front() {
		if (empty())
			throw "Queue Underflow!";
		if (front_index > -1) {
			front_index--;
		}
		else {
			front_index = -1;
		}
	}

	void pop_rare() {
		if (empty())
			throw "Queue Underflow!";
		if (rear_index != -1 && rear_index < size) {
			rear_index++;
		}
		else if (rear_index == size - 1) {
			rear_index = -1;
		}
	}

	T front() {
		if (empty())
			throw "Queeu is empty!";
		return data[front_index];
	}

	T rare() {
		if (empty())
			throw "Queeu is empty!";
		return data[rear_index];
	}

	bool empty() const {
		return (front_index == -1 || rear_index == -1);
	}

	bool full() const {
		return (rear_index - front_index == 1 || rear_index == 0 || front_index > size -1);
	}
};

//driver function.
int main() {

	queue<int> queue_obj(4);
	try {
		queue_obj.push_front(1);
		queue_obj.push_rare(2);
		queue_obj.push_rare(3);
		queue_obj.push_front(4);
		queue_obj.push_front(5);
	}
	catch (const char* msg) {
		cout << msg << endl;
	}

	queue<int> queue_obj1;
	queue_obj1 = queue_obj; // = operator overload

	while (!queue_obj.empty()) {
		int val;
		val = queue_obj.front();
		queue_obj.pop_front();
		cout << val << endl;
	}

	cout << endl;

	while (!queue_obj1.empty()) {
		int val;
		val = queue_obj.rare();
		queue_obj.pop_rare();
		cout << val << endl;
	}

	return 0;
}