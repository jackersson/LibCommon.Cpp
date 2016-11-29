#ifndef THREADPOOL_HPP
#define THREADPOOL_HPP

#include "thread_safe_queue.hpp"

#include <algorithm>
#include <atomic>
#include <functional>
#include <memory>
#include <thread>
#include <type_traits>
#include <vector>

namespace utils
{
	class ThreadPool
	{	
	public:
		ThreadPool(void)
			:ThreadPool{ std::max(std::thread::hardware_concurrency(), 2u) - 1u }
		{	}
				
		explicit ThreadPool(const std::uint32_t numThreads)
			:done_{ false },
			work_queue_{},
			threads_{}
		{
			try
			{
				for (std::uint32_t i = 0u; i < numThreads; ++i)
				{
					threads_.emplace_back(&ThreadPool::worker, this);
				}
			}
			catch (...)
			{
				destroy();
				throw;
			}
		}
			
		ThreadPool(const ThreadPool& rhs) = delete;	
		ThreadPool& operator=(const ThreadPool& rhs) = delete;

		~ThreadPool(void)
		{
			destroy();
		}

		void submit_nowait(std::function<void()> func)
		{	
			work_queue_.push(func);
		}

		size_t size() const
		{
			return threads_.size();
		}

	private:	
		void worker(void)
		{
			while (!done_)
			{
				std::function<void()> pTask;
				if (work_queue_.wait_pop(pTask))
				{
					pTask();
				}
			}
		}

		void destroy(void)
		{
			done_ = true;
			work_queue_.invalidate();
			for (auto& thread : threads_)
			{
				if (thread.joinable())
				{
					thread.join();
				}
			}
		}

		std::atomic_bool done_;
		ThreadSafeQueue<std::function<void()>> work_queue_;
		std::vector<std::thread> threads_;
	};

	namespace default_thread_pool
	{
		/**
		* Get the default thread pool for the application.
		* This pool is created with std::thread::hardware_concurrency() - 1 threads.
		*/
		inline ThreadPool& thread_pool(void)
		{
			static ThreadPool defaultPool;
			return defaultPool;
		}

		/*
		template <typename Func, typename... Args>
		auto submit_job(Func&& func, Args&&... args)
		{
			return getThreadPool().submit(std::forward<Func>(func), std::forward<Args>(args)...);
		}
		*/
		template <typename Func, typename... Args>
		auto submit_job_nowait(Func&& func, Args&&... args)
		{
			return thread_pool().submit_nowait(std::forward<Func>(func), std::forward<Args>(args)...);
		}

	}
}

#endif