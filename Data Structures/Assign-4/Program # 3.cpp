#include<iostream>
using namespace std;

template<typename T>
class queue {
private:
	int rear_index, front_index, size;
	T* data;
public:
	queue(int s = 3) {
		size = s + 1;
		rear_index = front_index = 0;
		data = new T[size];
	}

	~queue() {
		delete[]data;
	}

	void push(const T& val) {
		if (full())
			throw "\nQueue has been full. So, you can't add more patient!";
		rear_index = (rear_index + 1) % size;
		data[rear_index] = val;
	}

	void pop() {
		if (empty())
			throw "\nQueue has been Empty!";
		front_index = (front_index + 1) % size;
	}

	T front() {
		if (empty())
			throw "\nQueeu is empty!";
		return data[(front_index + 1) % size];
	}

	bool empty() const {
		return rear_index == front_index;
	}

	bool full() const {
		return (rear_index + 1) % size == front_index;
	}

};

//driver function.
int main() {

	int size, q, s, patient;
	char condition;
	cout << "\t\tWelcome to XYZ Hospital!\n" << endl;
	cout << "Enter number of Queue's you want to make: ";
	cin >> size;
	queue<int>queue_obj[size];
	do {
		cout << "\nIn which queue you want to push patient: ";
		cin >> q;
		if (queue_obj[q - 1].full()) {
			cout << "\nQueue " << q << " is full!" << endl;
		}
		else {
			if (q > size) {
				cout << "\nThis queue doesn't exist!" << endl;
			}
			else {
				cout << "\nAdding Patient number in queue " << q << endl;
				do {
					try {
						cout << endl;
						cin >> patient;
						queue_obj[q - 1].push(patient);
						cout << "\nWanna add more patient [y/n]? ";
						cin >> condition;
					}
					catch (const char* msg) {
						cout << msg << endl;
						break;
					}
				} while (condition != 'n' && condition != 'N');
			}
		}
		cout << "\nDo you want to add more patient in another queue's [y/n]: ";
		cin >> condition;
	} while (condition != 'n' && condition != 'N');

	do {
		cout << "\nIn which queue you want to remove patient: ";
		cin >> q;
		if (q > size) {
			cout << "\nThis queue doesn't exist!" << endl;
		}
		else {
			cout << "\nRemoving patient from Queue " << q << endl << endl;
			do {
				try {
					int val;
					val = queue_obj[q - 1].front();
					queue_obj[q - 1].pop();
					cout << "Patient number " << val << " has been removed from queue " << q << "! " << endl;
				}
				catch (const char* msg) {
					cout << msg << endl;
					break;
				}
				cout << "\nWanna remove more patient [y/n]? ";
				cin >> condition;
			} while (condition != 'n' && condition != 'N');
		}
		cout << "\nDo you want to remove more patient from other queue's [y/n]: ";
		cin >> condition;

	} while (condition != 'n' && condition != 'N');

	return 0;
}