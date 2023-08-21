//header file
#include<iostream>
#include<string>
#include<fstream>
using namespace std;
struct sales_system {
	string mobile_name = "NULL";
	int model = 0;
	int price = 0;
	float camera = 0.0;
	int battery = 0;
	string messaging = "NULL";
	string audio_video = "NULL";
	string torch = "NULL";
	void selection();
	void add_data();
	void search_data();
	void update_data();
	void delete_data();

};//end of header file's function.