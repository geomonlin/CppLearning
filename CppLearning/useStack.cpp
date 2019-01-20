#include "useStack.h"
#include"useStack.h"

void use_stack()
{
	stack<int> st;
	for (int i = 0; i < 10; i++) {
		st.push(i);
	}
	cout << "size = " << st.size() << endl;
	for (int i = 0; i < 10; i++) {
		cout << "top = " << st.top() << endl;
		st.pop();
	}
	cout << "size = " << st.size() << endl;
}
