// C
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<ctype.h>
#define MAX 1000
int stack[MAX];
int top = -1;

void push(int x) {
	if (top < MAX - 1) {
		top++;
		stack[top] = x;
	}
}

void calculate(char x) {
	if (top >= 1) {
		if (x == '+') {
			stack[top - 1] = stack[top - 1] + stack[top];
		}
		if (x == '-') {
			stack[top - 1] = stack[top - 1] - stack[top];
		}
		if (x == '*') {
			stack[top - 1] = stack[top - 1] * stack[top];
		}
		if (x == '/') {
			stack[top - 1] = stack[top - 1] / stack[top];
		}
		top--;
	}
}

int main() {
	char express[100];
	gets(express);

	int len = strlen(express);

	for (int i = 0; i < len; i++) {
		if (express[i] != ' ') {
			if (isdigit(express[i])&&isdigit(express[i+1])&&!isdigit(express[i+2])) {
				int value = (express[i] - '0') * 10 + express[i+1] - '0';
				push(value);
				i++;
			} else if (isdigit(express[i])&&!isdigit(express[i+1])) {
				int value = express[i] - '0';
				push(value);
			}
			else {
				calculate(express[i]);
			}
		}
	}

	printf("%d", stack[0]);


	return 0;
}

//C++
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<cctype>
using namespace std;

#define MAX 1000
int stack[MAX];
int top = -1;
int num = 0, operator_num = 0;


void push(int x) {
	if (top < MAX - 1) {
		top++;
		stack[top] = x;
		num++;
	}
}

void calculation(char x) {
	if(top>=1) {
		if (x == '+') {
			stack[top - 1] = stack[top - 1] + stack[top];
		}
		if (x == '-') {
			stack[top - 1] = stack[top - 1] - stack[top];
		}
		if (x == '*') {
			stack[top - 1] = stack[top - 1] * stack[top];
		}
		if (x == '/') {
			stack[top - 1] = stack[top - 1] / stack[top];
		}
		top--;
	}
}

int main()
{
	string expression;
	getline(cin, expression);

	if (expression == "0")return 0;

	int len = expression.length();

	for (int i = 0; i < len; i++) {
		if (expression[i] != ' ') {
			if (isdigit(expression[i]) && isdigit(expression[i + 1]) && !isdigit(expression[i + 2])) {
				int value = (expression[i] - '0') * 10 + expression[i + 1] - '0';
				push(value);
				i++;
			}
			else if (isdigit(expression[i]) && !isdigit(expression[i + 1])) {
				int value = expression[i] - '0';
				push(value);
			}
			else {
				calculation(expression[i]);
				operator_num++;
			}
		}
	}
	if (num == operator_num+1) {
		cout << stack[0] << endl;
	}
	else {
		cout << "Invalid expression" << endl;
	}

	return 0;
}


//OOP version

#include<iostream>
#include<string>
#include<cctype>
#define MAX 10000
using namespace std;

// Postfix Expression Calculate
class PEC {
private:
	int stack[MAX];
	int top;
	int nn, cn;
	string expression;
public:
	PEC() : top(-1), nn(0), cn(0) {
		cout << "The postfix expression calculating program\n" << endl;
	}

	void enterExpression() {
		cout << "Enter the postfix exrpession >> ";
		getline(cin, expression);
	}

	void push(int x) {
		if (top < MAX - 1) {
			top++;
			stack[top] = x;
			nn++;
		}
	}

	void calculation(char x) {
		if (top >= 1) {
			if (x == '+') {
				stack[top - 1] = stack[top - 1] + stack[top];
			}
			if (x == '-') {
				stack[top - 1] = stack[top - 1] - stack[top];
			}
			if (x == '*') {
				stack[top - 1] = stack[top - 1] * stack[top];
			}
			if (x == '/') {
				stack[top - 1] = stack[top - 1] / stack[top];
			}
			top--;
		}
		cn++;
	}

	void solve() {
		int len = expression.length();

		for (int i = 0; i < len; i++) {
			if (expression[i] != ' ') {
				if (isdigit(expression[i]) && isdigit(expression[i + 1]) && !isdigit(expression[i + 2])) {
					int x = (expression[i] - '0') * 10 + (expression[i + 1] - '0');
					push(x);
					i++;
				}
				else if (isdigit(expression[i]) && !isdigit(expression[i + 1])) {
					int x = (expression[i] - '0');
					push(x);
				}
				else {
					calculation(expression[i]);
				}
			}
		}
		nn - 1 == cn ? cout << stack[0] << endl : cout << "Invalid expression" << endl;
	}
	~PEC() {
		for (int i = 0; i <= top; i++)stack[i] = 0;
		top = -1, cn = 0, nn = 0;
	}
};


int main()
{

	PEC Pssion;

	Pssion.enterExpression();

	Pssion.solve();

	return 0;
}
