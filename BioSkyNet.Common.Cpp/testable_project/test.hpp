#include <threadable.hpp>
#include <mutex>

class Test : public utils::Threadable
{
public:
	Test(){}
protected:
	void run() override {

	}

private:
	Test(const Test& other) = delete;
	Test& operator=(const Test&) = delete;

	mutable std::recursive_mutex mutex_;
};
