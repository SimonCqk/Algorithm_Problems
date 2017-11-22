#include<future>
#include<thread>

template<typename Func,typename... Args>
auto spawn_task(Func&& func, Args&&... args)
->std::future<std::result_of_t<Func(Args...)>>
{
	using return_type = std::result_of_t<Func(Args...)>;
	std::packaged_task<return_type(Args&&...)>
		task(std::move(func));
	auto res(task.get_future());
	std::thread th(std::move(task), std::move(Args...));
	th.detach();
	return res;
}