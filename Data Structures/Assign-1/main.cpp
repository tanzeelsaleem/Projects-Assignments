#include "Header.h"
//main function
int main() {
	//opening sales file in reading mode if exist otherwise create it.
	ifstream sales_file("sales_system.bin", ios::binary);
	if (sales_file.is_open()) {
		string data;
		getline(sales_file, data);
		cout << "\nShowing the data that was present in the sales file.\n\n" << data;
		cout << "file doesn't exist so creating file";
	}
	else if (!sales_file.is_open()) {
		cout << "file doesn't exist so creating file";
		ofstream sales_file("sales_system.bin", ios::binary | ios::trunc);
		if (sales_file.is_open()) {
			cout << "Now sales file has created." << endl;
		}
		sales_file.close();//closing sales file.
	}

	sales_system m;
	m.selection();
	system("PAUSE");
	return 0;
}//end of main function.
