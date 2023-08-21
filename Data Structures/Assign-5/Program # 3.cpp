#include<iostream>
#include<list>
#include<string>
#include<fstream>
using namespace std;

//structure for the data of Mobiles
struct sales_system {
	string mobile_name = " ";
	int model = 0;
	int price = 0;
	float camera = 0.0;
	int battery = 0;
	string messaging = "NULL";
	string audio_video = "NULL";
	string torch = "NULL";

	bool operator == (const sales_system &obj) const {
		return mobile_name == obj.mobile_name;
	}

	friend ostream& operator << (ostream& out, const sales_system& s) {
		out << "Mobile Name: " << s.mobile_name << "\t\tModel: " << s.model << "\t\tPrice: " << s.price << "\t\tCamera: " << s.camera
			<< "\t\tBattery: " << s.battery << "\t\tMessaging: " << s.messaging << "\t\tAudio and video" << s.audio_video
			<< "Torch: " << s.torch << endl;
		return out;
	}

	friend istream& operator >> (istream& in, sales_system& s) {
		cout << "Mobile Name: ";           in >> s.mobile_name;
		cout << "Model: ";                 in >> s.model;
		cout << "Price: ";                 in >> s.price;
		cout << "Camera: ";                in >> s.camera;
		cout << "Battery: ";               in >> s.battery;
		cout << "Messaging: ";             in >> s.messaging;
		cout << "Audio and Video: ";       in >> s.audio_video;
		cout << "Torch: ";                 in >> s.torch;
		return in;
	}
};

//find function to search the mobile data.
template<typename T>
bool find(const list<T>& obj, T& val) {
	typename list<T>::const_iterator itr;
	for (itr = obj.begin(); itr != obj.end(); itr++) {
		if (val == *itr) {
			val = *itr;
			return true;
		}
	}
	return false;
}

//display function to display the data of mobiles.
template<typename T>
void display(const list<T>& l) {
	typename list<T>::const_iterator itr;

	for (itr = l.begin(); itr != l.end(); itr++) {
		cout << *itr << endl;
	}
	cout << endl;
}

//update function to update mobile data.
template<typename T>
bool update(list<T>& obj, T& val) {
	typename list<T>::const_iterator itr; 
	for (itr = obj.begin(); itr != obj.end(); itr++) {
		if (val == *itr) {
			cin >> val;
			val = *itr;
			return true;
		}
	}
	return false;
}

//erase function to delete mobile data.
template<typename T>
bool erase(list<T>& obj, const T& val) {
	typename list<T>::const_iterator itr;
	for (itr = obj.begin(); itr != obj.end(); itr++) {
	    T name;
		name = *itr;
		if (name == val) {
			obj.erase(itr);
			return true;
		}
	}
	return false;
}

// add record function to add mobile data.
void add_record(list<sales_system>& temp) {
	sales_system obj;
	char ch = NULL;
	fstream sales_file("sales_system.bin", ios::app | ios::binary);
	if (sales_file.is_open()) {
		do {
			cin >> obj;
			sales_file.write((const char*)&obj, sizeof(sales_system));
			sales_file.flush();
			temp.push_back(obj);
			cout << "\nDo you want to add more record (Y / N)";
			cin >> ch;
		} while (ch != 'n' && ch != 'N');
	}
}

//selection function to parform particular tasks.
void selection(list <sales_system>& temp) {
	cout << "\nWelcome to our Mobile Shop" << endl << endl;
	cout << "Please press the following keys to perform these actions" << endl;
	cout << "For adding data of mobile phone please press : A" << endl;
	cout << "For searching mobile phone please press : S" << endl;
	cout << "For updating mobile phone data please press : U" << endl;
	cout << "For deleting some mobile phone data please press : D" << endl;
	cout << "For exiting press : E" << endl << endl;
	//switch statement.
	switch (getchar()) {
	case 'a':
	case 'A': {
		add_record(temp);
		break;
	}
	case 's':
	case 'S': {
		sales_system obj;
		cout << "\nEnter mobile name to search mombile data: ";
		cin >> obj.mobile_name;
		if (find(temp, obj)) {
			cout << "\nData found" <<endl << obj << endl;
		}
		else {
			cout << "Data not found!" << endl;
		}
		break;
	}
	case 'u':
	case 'U': {
		sales_system obj;
		cout << "\nEnter mobile name to update mombile data: ";
		cin >> obj.mobile_name;
		if (update(temp, obj)) {
			cout << "\nData has been updated" << endl << obj << endl;
		}
		else {
			cout << "Data not found to update!" << endl;
		}
		fstream sales_file("sales_system.bin", ios::binary | ios::out);
		if (sales_file.good()) {
			while (true) {
				sales_file.write((const char*)&temp, sizeof(temp));
				sales_file.flush();
			}
		}
		sales_file.close();
		break;
	}
	case 'd':
	case 'D': {
		sales_system obj;
		cout << "\nEnter mobile name to delete mombile data: ";
		cin >> obj.mobile_name;
		if (erase(temp,obj)) {
			cout << "\nData has been deleted" << endl << obj << endl;
		}
		else {
			cout << "Data not found to delete!" << endl;
		}
		fstream sales_file("sales_system.bin", ios::binary | ios::out);
		if (sales_file.good()) {
			while (true) {
				sales_file.write((const char*)&temp, sizeof(temp));
				sales_file.flush();
			}
		}
		sales_file.close();
		break;
	}
	case 'e':
	case 'E': {
		exit(0);
	}
	default: {
		cout << "You have pressed an incorrect key!" << endl;
		break;
	}
	}//end of switch statent.
}

int main() {

	sales_system sales_obj;
	list<sales_system> list_obj;
	//opening file in reading mode.
	fstream sales_file("sales_system.bin", ios::binary | ios::in);
	if (sales_file.good()) {
		while (!sales_file.eof()) {
			sales_file.read((char*)&sales_obj, sizeof(sales_system));
			//reading data from file and pushing it in list.
			if (sales_file.gcount() > 0) {
				list_obj.push_back(sales_obj);
			}
		}
	}
	//if file doesn't exist then creating new file.
	else {
		cout << "file doesn't exist so creating file" << endl;
		fstream sales_file("sales_system.bin", ios::binary | ios::trunc);
		sales_file.close();
	}
	selection(list_obj);
	//display(list_obj);
	exit(0);
}