#include "Header.h"
//definition of functions.
//function to perform particular task (Add, Search, Update, Delete) mobile data.
void sales_system::selection(void) {
	sales_system m;
	cout << "Welcome to our Mobile Shop" << endl << endl;
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
		m.add_data();
		break;
	}
	case 's':
	case 'S': {
		m.search_data();
		break;
	}
	case 'u':
	case 'U': {
		m.update_data();
		break;
	}
	case 'd':
	case 'D': {
		m.delete_data();
		break;
	}
	case 'e':
	case 'E': {
		exit(0);
	}
	}//end of switch statement.
}//end of selection function.

//function to add mobile data.
void sales_system::add_data(void) {
	sales_system m;
	//creating or opening (if exist) sales file in binary mode.
	ofstream sales_file;
	sales_file.open("sales_sytem.bin", ios::binary | ios::app);
	if (sales_file.is_open()) {
		cout << "\nYou have entered in a sales file." << endl;
		int i = 0;
		char condition;
		do {
			i++;
			cout << "\nEntering the data of mobile " << i << endl;
			cout << "Mobile Name : ";
			cin >> m.mobile_name;
			sales_file << "Mobile name : " << m.mobile_name << endl;
			cout << "Model : ";
			cin >> m.model;
			sales_file << "Model : " << m.model << endl;
			cout << "Price : ";
			cin >> m.price;
			sales_file << "Price : " << m.price << endl;
			cout << "Camera in MP(mega pixel) : ";
			cin >> m.camera;
			sales_file << "Camera in MP(mega pixel) : " << m.camera << endl;
			cout << "Battery in (mAh) : ";
			cin >> m.battery;
			sales_file << "Battery in (mAh) : " << m.battery << endl;
			cout << "Availability  of Messaging (Yes / No) : ";
			cin >> m.messaging;
			sales_file << "Availability  of messaging (Yes / No) : " << m.messaging << endl;
			cout << "Availability  of Audio & Video player (Yes / No) : ";
			cin >> m.audio_video;
			sales_file << "Availability  of Audio & Video player (Yes / No) : " << m.audio_video << endl;
			cout << "Availability  of Torch (Yes / No) : ";
			cin >> m.torch;
			sales_file << "Availability  of Torch (Yes / No) : " << m.torch << endl;
			/*sales_file.seekp(0, ios::end);
			sales_file.write((const char *)&m, sizeof(sales_system));*/
			cout << "\nDo you want to add the data of more mobiles (y / n) : ";
			cin >> condition;
		} while (condition != 'n' && condition != 'N');//end of do-while loop.
	}
	else {
		cout << "\nSales file has not opened." << endl;
	}
	sales_file.close();//closing sales file that was opened.
}//end of add function.

//function to perform searching from the existed mobile data.
void sales_system::search_data(void) {
	sales_system m;
	string search;
	char condition;
	int counter = 0;
	//reading file in binary mode that is already created.
	ifstream sales_file;
	sales_file.open("sales_system.bin", ios::binary | ios::in);
	if (sales_file.is_open()) {
		if (sales_file.good()) {

			do {
				cout << "\nEnter the name of the mobile whose data you want to search : ";
				cin >> search;
				//bringing the pointer at beginning position.
				sales_file.seekg(0, ios::beg);
				//read data from sales file until the loop is working.
				while (sales_file.read((char*)&m, sizeof(sales_system))) {
					//check to search mobile data via mobile name.
					if (m.mobile_name.length() == search.length()) {
						for (int i = 0; i < m.mobile_name.length(); i++) {
							if (m.mobile_name[i] == search[i]) {
								counter++;
							}
							else if (m.mobile_name[i] != search[i]) {
								counter = 0;
								break;
							}
						}
					}
					else {
						counter = 0;
					}
					//if mobile name found then showing its data.
					if (counter == m.mobile_name.length()) {
						int i = 0;
						i++;
						cout << "\nSearched the data of Mobile " << i << endl;
						cout << "Mobile Name : " << m.mobile_name << endl;
						cout << "Model : " << m.model << endl;
						cout << "Price : " << m.price << endl;
						cout << "Camera in MP(mega pixel) : " << m.camera << endl;
						cout << "Battery in (mAh) : " << m.battery << endl;
						cout << "Availability  of Messaging (Yes / No) : " << m.messaging << endl;
						cout << "Availability  of Audio & Video player (Yes / No) : " << m.audio_video << endl;
						cout << "Availability  of Torch (Yes / No) : " << m.torch << endl;
						cout << "Do you want to search the data of more mobiles (y / n) : ";
						cin >> condition;
					}
					else {
						cout << "\nMobile data not found" << endl;
						cout << "Do you want to search the data of more mobiles (y / n) : ";
						cin >> condition;
					}
				}
			} while (condition != 'n' && condition != 'N');//end of do-while loop.
		}
	}
	else {
		cout << "\nSales file has not opened." << endl;
	}
	sales_file.close();//closing sales file.
}//end of search function.

//function to update data.
void sales_system::update_data(void) {
	sales_system m;
	string update;
	char condition;
	int counter = 0;
	//opening sales file in reading and writing mode.
	fstream sales_file;
	sales_file.open("sales_system.bin", ios::binary | ios::in | ios::out);
	if (sales_file.is_open()) {
		if (sales_file.good()) {
			do {
				cout << "\nEnter the name of the mobile whose data you want to update : ";
				cin >> update;
				//bringing the pointer at the beginning position.
				sales_file.seekg(0, ios::beg);
				//read data from sales file until the loop is working.
				while (sales_file.read((char*)&m, sizeof(sales_system))) {
					//check to find mobile data via its name to update data.
					if (m.mobile_name.length() == update.length()) {
						for (int i = 0; i < m.mobile_name.length(); i++) {

							if (m.mobile_name[i] == update[i]) {
								counter++;
							}
							else if (m.mobile_name[i] != update[i]) {
								counter = 0;
								break;
							}
						}
					}
					else {
						counter = 0;
					}
					//if mobile(whose data is being updated) found then here
					//its data will be updated by getting data form user.
					if (counter == m.mobile_name.length()) {
						int i = 0;
						i++;
						cout << "\nUpdating the data of Mobile " << i << endl;
						cout << "Enter Mobile Name : ";
						cin >> m.mobile_name;
						cout << "Model : ";
						cin >> m.model;
						cout << "Price : ";
						cin >> m.price;
						cout << "Camera in MP(mega pixel) : ";
						cin >> m.camera;
						cout << "Battery in (mAh) : ";
						cin >> m.battery;
						cout << "Availability  of Messaging (Yes / No) : ";
						cin >> m.messaging;
						cout << "Availability  of Audio & Video player (Yes / No) : ";
						cin >> m.audio_video;
						cout << "Availability  of Torch (Yes / No) : ";
						cin >> m.torch;
						sales_file.seekp(-sizeof(m), ios::cur);
						sales_file.write((const char*)&m, sizeof(sales_system));
						cout << "\nDo you want to update the data of more mobiles (y / n) : ";
						cin >> condition;
					}
					else {
						cout << "\nMobile data not found to be updated." << endl;
						cout << "Do you want to update the data of more mobiles (y / n) : ";
						cin >> condition;
					}
				}
			} while (condition != 'n' && condition != 'N');//end of while loop.
		}
	}
	else {
		cout << "Sales file has not opened." << endl;
	}
	sales_file.close();//closing sales file.
}//end of update function.

//function to delete data of mobile.
void sales_system::delete_data(void) {
	sales_system m;
	string delte;
	char condition;
	int counter = 0;
	//reading file in binary mode that is already created.
	fstream sales_file;
	sales_file.open("sales_system.bin", ios::binary | ios::in | ios::out);
	if (sales_file.is_open()) {
		if (sales_file.good()) {

			do {
				cout << "Enter the name of the mobile whose data you want to delete : ";
				cin >> delte;
				//bringing the pointer at the beginning position.
				sales_file.seekg(0, ios::beg);
				//read data from sales file until the loop is working.
				while (sales_file.read((char*)&m, sizeof(sales_system))) {
					//check to find mobile data via its name to be delete.
					if (m.mobile_name.length() == delte.length()) {
						for (int i = 0; i < m.mobile_name.length(); i++) {

							if (m.mobile_name[i] == delte[i]) {
								counter++;
							}
							else if (m.mobile_name[i] != delte[i]) {
								counter = 0;
								break;
							}
						}
					}
					else {
						counter = 0;
					}
					//if mobile data found then here it will skip the found data
					//and will write the rest of data in sales file.
					if (counter != m.mobile_name.length()) {
						//bringing the pointer at the beginning position of the
						//sales file where data found to be deleted.
						sales_file.seekp(-sizeof(m), ios::cur);
						//writing the rest of data in sales file and skipping(deleting) the data that was found.
						sales_file.write((const char*)&m, sizeof(sales_system));
						cout << "\nMobile data has deleted." << endl;
						cout << "Do you want to delete the data of more mobiles (y / n) : ";
						cin >> condition;
					}
					else {
						cout << "\nMobile data not found to be deleted." << endl;
						cout << "Do you want to delete the data of more mobiles (y / n) : ";
						cin >> condition;
					}
				}
			} while (condition != 'n' && condition != 'N');//end of do-while loop.
		}
	}
	else {
		cout << "\nSales file has not opened." << endl;
	}
	sales_file.close();//closing sales file.
}//end of delete function.
