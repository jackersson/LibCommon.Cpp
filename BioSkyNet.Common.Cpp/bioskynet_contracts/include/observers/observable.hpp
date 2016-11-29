#ifndef Observable_Included
#define Observable_Included

#include "iobservable.hpp"
#include <algorithm>
#include <mutex>
#include <vector>


namespace contracts
{
	namespace observers
	{		
		template <typename T>
		class Observable : public IObservable<T>
		{
		public:
			Observable() {}
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
				observers_.erase(
					std::remove( observers_.begin()
						         , observers_.end()
						         , observer), observers_.end());	
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

			void notify(std::function<void(std::vector<T*>&)> func)
			{
				std::lock_guard<std::recursive_mutex> lock(mutex_);
				func(observers_);
			}

		protected:
			std::vector<T*> observers_;

		private:
			Observable(const Observable& other) = delete;
			Observable& operator=(const Observable&) = delete;

			mutable std::recursive_mutex mutex_;
		};		
	}
}

#endif

