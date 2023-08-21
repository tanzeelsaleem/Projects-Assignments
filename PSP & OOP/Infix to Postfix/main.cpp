#include"Header.h"
//main funciton.
int main(int argc, char* argv[]) {

	if (argc >= 1) {

	    //bracket_check(argv[1]);
		postfix_evaluation(argv[1]);
		//infix2postfix(argv[1]);
	}
	system("PAUSE");
	return 0;
}//end of main function.