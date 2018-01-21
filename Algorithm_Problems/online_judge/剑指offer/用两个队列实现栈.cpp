//用两个队列实现一个栈。声明如下，且支持进栈和出栈操作。

/*
进栈：
两个队列均为空，任意入一队列。
一个队列非空，另一个空，入非空的队列。
出栈：
非空队列的元素依次进入另一个空队列，剩最后一个元素，将其弹出。
*/

#include<queue>

using std::queue;

template<typename T>
class QueueStack {
public:
	QueueStack() = default;
	void push(const T& node);
	T pop();
	~QueueStack() = default;
private:
	queue<T> queue_one;
	queue<T> queue_two;
};

template<typename T>
void QueueStack<T>::push(const T& node)
{
	if (queue_one.empty() && queue_two.empty())
		queue_one.push(node);
	else if (queue_one.empty() && !queue_two.empty())
		queue_two.push(node);
	else if (!queue_one.empty() && queue_two.empty())
		queue_one.push(node);
	else
		throw std::exception("Two queues can not be not empty at the same time.");
}

template<typename T>
T QueueStack<T>::pop()
{
	if (queue_one.empty() && queue_two.empty())
		throw std::exception("The stack is empty.");
	else if (queue_one.empty() && !queue_two.empty()) {
		while (queue_two.size() > 1) {
			queue_one.push(queue_two.front());
		}
		T node = queue_two.front();
		queue_two.pop();
		return node;
	}
	else if (!queue_one.empty() && queue_two.empty()) {
		while (queue_one.size() > 1) {
			queue_two.push(queue_one.front());
		}
		T node = queue_one.front();
		queue_one.pop();
		return node;
	}	
}


