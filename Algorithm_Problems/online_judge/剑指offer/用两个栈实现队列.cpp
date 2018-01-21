//用两个栈实现一个队。声明如下，且支持在尾部插入节点和队列头部删除节点的功能。

/*
设置两个栈stack_one / stack_two.
往stack_one插入数据，删除数据时，当stack_two为空，则stack_one
中的数据依次弹出并压入stack_two，栈顶的元素即队首，当stack_two
不为空，则当前栈顶元素即队首
*/

#include<stack>

using std::stack;

template<typename T>
class StackQueue {
public:
	StackQueue() = default;
	void appendTail(const T& node);
	T deleteHead();
	~StackQueue() = default;
private:
	stack<T> stack_one;
	stack<T> stack_two;
};

template<typename T>
void StackQueue<T>::appendTail(const T & node)
{
	stack_one.push(node);
}

template<typename T>
T StackQueue<T>::deleteHead()
{
	if (stack_one.empty() && stack_two.empty())
		throw std::exception("The queue is empty.");
	if (stack_two.empty()) {
		while (!stack_one.empty()) {
			stack_two.push(stack_one.top());
			stack_one.pop();
		}
	}

	T node = stack_two.top();
	stack_two.pop();
	return node;
}
