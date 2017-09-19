#include <iostream>     // std::cout
#include <algorithm>    // std::find_if
#include <vector>       // std::vector
#include <functional>
#include <ostream>
#include <sstream>
#include <iterator>
#include <future>
#include<array>

void do_tasks(std::size_t count, std::function<void(std::size_t start, std::size_t finish)> task) {
	auto thread_count = std::thread::hardware_concurrency();
	if (thread_count <= 0) thread_count = 1;

	std::vector<std::future<void>> threads(thread_count - 1);

	auto get_task = [=](std::size_t index) {
		auto start = count * index / thread_count;
		auto finish = count * (index + 1) / thread_count;
		// std::cout << "from " << start << " to " << finish << "\n";
		return [task, start, finish] { task(start, finish); };
	};
	for (auto& thread : threads) {
		auto index = &thread - threads.data();
		thread = std::async(std::launch::async, get_task(index));
	}
	get_task(threads.size())();
	for (auto& thread : threads) {
		thread.get();
	}
}

int main() {
	std::array< int, 100 > arr = { {} };
	do_tasks(100, [&arr](auto start, auto end) {
		for (auto i = start; i != end; ++i) {
			for (unsigned j = 0; j < i; ++j) {
				arr[i]++;
			}
		}
	});
	for (auto& e : arr) {
		if (e != (&e - arr.data()))
			std::cout << e << "!=" << (&e - arr.data()) << "\n";
	}
}