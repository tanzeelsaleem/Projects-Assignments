#include"Header.h"
//main funciton.
int main() {
	const int size1 = 100000;
	const int size2 = 100000;
	
	int unsorted_no[size1];
	int sorted_no[size2];
	
	execution1(unsorted_no, size1);
	execution2(sorted_no, size2);

	system("PAUSE");
	return 0;
}//end of main function.
