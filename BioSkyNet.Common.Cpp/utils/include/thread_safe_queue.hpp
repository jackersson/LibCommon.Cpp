#ifndef THREADSAFEQUEUE_HPP
#define THREADSAFEQUEUE_HPP

#include <atomic>
#include <mutex>
#include <queue>

namespace utils
{
	template <typename T>
	class ThreadSafeQueue
	{
	public:
		~ThreadSafeQueue(void)
		{
			invalidate();
		}

		bool try_pop(T& out)
		{
			std::lock_guard<std::mutex> lock{ mutex_ };
			if (queue_.empty() || !valid_)
				return false;
			out = std::move(queue_.front());
			queue_.pop();
			return true;
		}

		bool wait_pop(T& out)
		{
			std::unique_lock<std::mutex> lock{ mutex_ };
			condition_.wait(lock, [this]()
			{
				return !queue_.empty() || !valid_;
			});

			if (!valid_)
				return false;

			out = std::move(queue_.front());
			queue_.pop();
			return true;
		}

		void push(T value)
		{
			std::lock_guard<std::mutex> lock{ mutex_ };
			queue_.push(std::move(value));
			condition_.notify_one();
		}

		bool empty(void) const
		{
			std::lock_guard<std::mutex> lock{ mutex_ };
			return queue_.empty();
		}

		void clear(void)
		{
			std::lock_guard<std::mutex> lock{ mutex_ };
			while (!queue_.empty())
				queue_.pop();

			condition_.notify_all();
		}

		void invalidate(void)
		{
			std::lock_guard<std::mutex> lock{ mutex_ };
			valid_ = false;
			condition_.notify_all();
		}

		bool is_valid(void) const
		{
			std::lock_guard<std::mutex> lock{ mutex_ };
			return valid_;
		}

	private:
		std::atomic_bool valid_{ true };
		mutable std::mutex mutex_;
		std::queue<T> queue_;
		std::condition_variable condition_;
	};
}

#endif