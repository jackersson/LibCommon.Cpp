#ifndef CommandsDataModel_INCLUDED
#define CommandsDataModel_INCLUDED

#include <vector>
#include "mutations.hpp"

namespace data_model
{	
	class CommitResponse
	{
	public:
		void add(const MutationResult& entity)
		{
			mutations_.push_back(entity);
		}

		std::vector<MutationResult>::const_iterator begin() const
		{
			return mutations_.cbegin();
		}

		std::vector<MutationResult>::const_iterator end() const
		{
			return mutations_.cend();
		}

		void clear() {
			mutations_.clear();
		}

		size_t size() const	{
			return mutations_.size();
		}

	private:
		std::vector<MutationResult> mutations_;
	};

	class CommitRequest
	{
	public:
		void add(const Mutation& entity)
		{
			mutations_.push_back(entity);
		}

		std::vector<Mutation>::const_iterator begin() const
		{
			return mutations_.cbegin();
		}

		std::vector<Mutation>::const_iterator end() const
		{
			return mutations_.cend();
		}

		void clear() {
			mutations_.clear();
		}

	private:
		std::vector<Mutation> mutations_;
	};	

	class BiometricRequest
	{

	};

	class BiometricResponse
	{
	};



}

#endif