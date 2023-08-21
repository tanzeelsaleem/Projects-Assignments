#include"Header.h"
//definition of functions.
//function for infix notation to postfix notaion.
void infix2postfix(char infix[]) {
	stack <char> obj;
	string output;
	for (int i = 0; i < sizeof(infix); i++) {
		//if operator or paranthesis not found then put the values on output.
		if (infix[i] != '(' && infix[i] != ')' && infix[i] != '*' && infix[i] != '/' && infix[i] != '+' && infix[i] != '-') {
			output += infix[i];
		}
		//if any operator or paranthesis found in the indexes then according to their precedence perform function. 
		else if (infix[i] == '(' || infix[i] == ')' || infix[i] == '*' || infix[i] == '/' || infix[i] == '+' || infix[i] == '-') {
			//check for the starting paranthesis.
			if (infix[i] == '(') {
				obj.push(infix[i]);
			}
			//check for the closing paranthesis.
			if (infix[i] == ')') {
				char t;
				if (!obj.empty()) {
					t = obj.top();
				}
				if (t != '(') {
					do {
						obj.pop();
						output += t;
						if (!obj.empty()) {
							t = obj.top();
						}
					} while (t != '(');
					obj.pop();
				}
			}

			//check for the operator + and -
			if (infix[i] == '+' || infix[i] == '-') {
				if (obj.empty()) {
					obj.push(infix[i]);
				}
				else {
					if ((!obj.empty())) {
						char t;
						t = obj.top();

						if (t == '*' || t == '/') {
							obj.pop();
							output += t;
						}
						else {
							do {
								if (t == '+' || t == '-') {
									obj.pop();
									output += t;
								}
							} while (!obj.empty());

						}
						obj.push(infix[i]);
					}

				}
			}

			//check for the operator * and /
			if (infix[i] == '*' || infix[i] == '/') {
				if (obj.empty()) {
					obj.push(infix[i]);
				}
				else {
					if ((!obj.empty())) {
						char t;
						t = obj.top();
						do {
							if (t == '*' || t == '/') {
								obj.pop();
								output += t;
								if (!obj.empty()) {
									t = obj.top();
								}
								else {
									break;
								}

							}
						} while (t == '*' || t == '/');

						obj.push(infix[i]);
					}
				}
			}
		}
	}

	//if arry has finished then loop for the poping of operators that are in the stack.
	do {
		char t;
		if (!obj.empty()) {
			t = obj.top();
		}
		else {
			break;
		}
		output += t;
		obj.pop();
	} while (!obj.empty());//poping until stack is not empty.

	cout << "Result : " << output << endl;
}

//function for postfix notation evalution.
void postfix_evaluation(char postfix[]) {
	stack <char> obj;
	int size = sizeof(postfix);
	for (int i = 0; i < size; i++) {

		//push the values to stack until no operator found.
		if (postfix[i] != '*' && postfix[i] != '/' && postfix[i] != '+' && postfix[i] != '-') {
			//character to integer.
			int val;
			val = postfix[i] - 48;
			obj.push(val);
		}

		//if operator found.
		else {
			//check for the multiplication operator "*"
			if (postfix[i] == '*') {
				int t, t1, t2;
				t2 = obj.top();
				obj.pop();
				t1 = obj.top();
				obj.pop();
				t = t1 * t2;
				if (i < size - 1) {
					obj.push(t);
				}
				else {
					if (obj.empty())
						cout << "Result : " << t;
				}
			}

			//check for the division operator "/"
			else if (postfix[i] == '/') {
				int t, t1, t2;
				t2 = obj.top();
				obj.pop();
				t1 = obj.top();
				obj.pop();
				t = t1 / t2;
				if (i < size - 1) {
					obj.push(t);
				}
				else {
					if (obj.empty())
						cout << "Result : " << t;
				}
			}

			//check for the addition operator "+"
			else if (postfix[i] == '+') {
				int t, t1, t2;
				t2 = obj.top();
				obj.pop();
				t1 = obj.top();
				obj.pop();
				t = t1 + t2;
				if (i < size - 1) {
					obj.push(t);
				}
				else {
					if (obj.empty())
						cout << "Result : " << t;
				}
			}

			//check for the subtraction operator "-"
			else if (postfix[i] == '-') {
				int t, t1, t2;
				t2 = obj.top();
				obj.pop();
				t1 = obj.top();
				obj.pop();
				t = t1 - t2;
				if (i < size - 1) {
					obj.push(t);
				}
				else {
					if (obj.empty())
						cout << "Result : " << t;
				}
			}
		}
	}
}

//function for checking brackets.
void bracket_check(char brackets[])
{
	stack <char> obj;
	int i = 0, clue = 0;
	string message;
	do {
		//if any starting bracket found then push it to the stack.
		if (brackets[i] == '(' || brackets[i] == '{' || brackets[i] == '[') {
			obj.push(brackets[i]);
			clue = 1;
		}

		//check if the stack is empty or not.
		if (obj.empty() || !obj.empty()) {
			//if there is closing curly bracket.
			if (brackets[i] == '}') {
				if (obj.top() == '{') {
					obj.pop();
				}
				else
					message += " there is no starting curly bracket '{' ";
				break;
			}
			//if there is closing square bracket.
			if (brackets[i] == ']') {
				if (obj.top() == '[') {
					obj.pop();
				}
				else
					message += " there is no starting square bracket '[' ";
				break;
			}
			//if there is closing small bracket.
			if (brackets[i] == ')') {
				if (obj.top() == '(') {
					obj.pop();
				}
				else
					message += " there is no starting small bracket '(' ";
				break;
			}
		}

		//else check if the stack is empty or not.
		else if (!obj.empty() || obj.empty()) {
			//if there is starting curly bracket.
			if (brackets[i] == '{') {
				if (obj.top() == '}') {
					obj.pop();
				}
				else
					message += " there is no closing curly bracket '}' ";
				break;
			}
			//if there is starting square bracket.
			if (brackets[i] == '[') {
				if (obj.top() == ']') {
					obj.pop();
				}
				else
					message += " there is no closing square bracket ']' ";
				break;
			}
			//if there is starting small bracket.
			if (brackets[i] == '(') {
				if (obj.top() == ')') {
					obj.pop();
				}
				else
					message += " there is no closing small bracket ')' ";
				break;
			}
		}
		else {
			break;
		}

		i++;
	} while (i < sizeof(brackets));

	//if stack is empty and clue 1(mean starting bracket found in the top indexes).
	if ((obj.empty()) && (clue == 1)) {
		cout << "Bracket are balanced!" << endl;
	}
	else {
		cout << "Brackets are unbalanced because" << message << endl;
	}

}