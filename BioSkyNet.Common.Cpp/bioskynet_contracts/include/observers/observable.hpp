#ifndef Observable_Included
#define Observable_Included

#include "iobservable.hpp"
#include <concurrent_containers.hpp>

namespace contracts
{
	namespace observers
	{
		
		template <typename T>
		class Observable : public IObservable<T>
		{
		public:
			virtual ~Observable() {}

			void subscribe(T* observer) override
			{
				std::lock_guard<std::recursive_mutex> lock(mutex_);
				if (!has_observer(observer))
					observers_.push_back(observer);
			}

			void unsubscribe(T* observer) override
			{
				std::lock_guard<std::recursive_mutex> lock(mutex_);
				if (has_observer(observer))
					observers_.remove(observer);
			}

			bool has_observer(T* observer) override
			{
				std::lock_guard<std::recursive_mutex> lock(mutex_);
				return std::find(  observers_.begin(), observers_.end(), observer)
					              != observers_.end();
				
			}

			size_t count() const override
			{
				std::lock_guard<std::recursive_mutex> lock(mutex_);
				return observers_.size();
			}

			void unsubscribe_all() override
			{
				std::lock_guard<std::recursive_mutex> lock(mutex_);
				observers_.clear();
			}			

		protected:
			std::vector<T*> observers_;
			//concurrent::containers::ConcurrentVector<T*> observers_;
		private:
			Observable(const Observable& other) = delete;
			Observable& operator=(const Observable&) = delete;

			mutable std::recursive_mutex mutex_;
		};
		
		/*
		template <typename T>
		class Observable //: public IObservable<T>
		{
		public:
			virtual ~Observable() {}

			void subscribe(T* observer) 
			{
				std::lock_guard<std::recursive_mutex> lock(mutex_);
				if (!has_observer(observer))
					observers_.push_back(observer);
			}

			void unsubscribe(T* observer) 
			{
				std::lock_guard<std::recursive_mutex> lock(mutex_);
				if (has_observer(observer))
					observers_.remove(observer);
			}

			bool has_observer(T* observer) 
			{
				std::lock_guard<std::recursive_mutex> lock(mutex_);
				return observers_.contains(observer);
			}

			size_t count() const 
			{
				std::lock_guard<std::recursive_mutex> lock(mutex_);
				return observers_.size();
			}

			void unsubscribe_all() 
			{
				std::lock_guard<std::recursive_mutex> lock(mutex_);
				observers_.clear();
			}

			template <>
			void on_error()
			{
				std::lock_guard<std::recursive_mutex> lock(mutex_);
				observers_.clear();
			}

			void on_next()
			{
				std::lock_guard<std::recursive_mutex> lock(mutex_);
				observers_.clear();
			}

			void on_state()
			{
				std::lock_guard<std::recursive_mutex> lock(mutex_);
				observers_.clear();
			}

		//protected:
			//concurrent::containers::ConcurrentVector<T*> observers_;
		private:
			Observable(const Observable& other) = delete;
			Observable& operator=(const Observable&) = delete;

			std::vector<T*> observers_;

			mutable std::recursive_mutex mutex_;
		};
		*/
	}
}

#endif

