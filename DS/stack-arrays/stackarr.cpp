#include<iostream>
#include<ctype.h>
using namespace std;
int *s;
int top, size;
struct stack {
	int *s,top, size;
};
class _stack_ {
	struct stack sta;
public:
	_stack_();
	void push(int);
	int pop(); //element deletion
	int peek(); //just sees the topmost element
	bool IsEmpty();
	bool IsFull();
	~_stack_();
	void getsize(int);
	void display();
};
_stack_::_stack_() {
	sta.top = -1;
	sta.s = NULL;
	sta.size = 0;
}
void _stack_::getsize(int n) {
	sta.size = n;
	sta.s = new int[n];
}
bool _stack_::IsFull() {
	return ((sta.size - 1) == sta.top);
}
bool _stack_::IsEmpty() {
	return(sta.top == -1);
}
void _stack_::push(int ele) {
	if (!IsFull()) {
		sta.top++;
		sta.s[sta.top] = ele; //sta.s[++sta.top]=ele;
	}
	else
		cout << "stack is full";
}
int _stack_::pop() {
	if (!IsEmpty()) {
		int temp=-999;
		temp = sta.s[sta.top]; //temp=sta.s[sta.top--]
		sta.top--;
		return temp;
		//return (sta.s[sta.top--]);
	}
	else
	{	cout << "stack is empty";
	return -1;
}
}
int _stack_::peek() {
	if (!IsEmpty()) {
		return sta.s[sta.top];
	}
	else
	{
		cout << "Stack is empty";
		return -1;
	}
}
_stack_::~_stack_() {
	delete sta.s;
}
void _stack_::display() {
	if (!IsEmpty()) {
		cout << "The stack is :\n";
		for (int i = sta.top; i >=0; i--) {
			cout << sta.s[i]<<"\t";
		}
	}
	else
		cout << "Stack is empty";
}
int main() {
	struct _stack_ s1;
	int arr_size, choice, stack_ele, flag = 0,x=0;
	cout << "Enter the size of the stack\n";
	//do{
	//cin >> arr_size;
	if(!(cin >> arr_size)){
	//if(!x){
	//cin.get();
	//if (cin.failbit){
		flag = 1;
		cout << "Invalid value. Enter integer value for size of stack";
		cin >> flag;
	}
	else{
		flag = 0;
		s1.getsize(arr_size);
		//cout << "XX";
	}
	
	if (0 == flag) {
		do {
			cout << "Menu :1)Push\n2)Pop\n3)Get Top\n4)Display\nEnter your choice::";
			if((std::cin >> (choice))){
				switch (choice)
				{
				case 1: {
					cout << "Enter element to be pushed";
					if((std::cin >> stack_ele))
						s1.push(stack_ele);
					else
						cout << "Invalid integer element";
					break;
				}
				case 2: {
					stack_ele = s1.pop();
					if (stack_ele != -1) {
						cout << "The element popped is :" << stack_ele;
					}
					break;
				}
				case 3: {
					stack_ele = s1.peek();
					if (stack_ele != -1)
						cout << "The top of stack is :" << stack_ele;
					break;
				}
				case 4: {
					s1.display();
					break;
				}
				default: {
					cout << "Invalid option";
					break;
				}
				}
			}
			else {
				cout << "Invalid choice";
				break;
			}
			cout << "\nEnter 0 to perform another operation";
			std::cin >> choice;
		} while (choice == 0);
	}
	//cout << "TT";
	cin >> x;
	getchar();
		return 0;
	}