#ifndef MutationDataModel_INCLUDED
#define MutationDataModel_INCLUDED

#include <string>
#include "visit_record.hpp"
#include "entity.hpp"

namespace data_model
{	
	class MutationResult
	{
	public:
		explicit MutationResult(const Key& key
			, const std::string& error = "")
			: id_(key), error_(error) {}

		const Key& id() const {
			return id_;
		}

		const std::string& error() const {
			return error_;
		}

	private:
		Key         id_;
		std::string error_;
	};

	enum MutationType
	{
		NoneMutationType
		, InsertMutation
		, UpdateMutation
		, DeleteMutation
	};

	class Mutation
	{
	public:
		Mutation(const Entity& entity, MutationType type)
		{
			type_ = type;
			switch (type)
			{
			case NoneMutationType: break;
			case InsertMutation:
				inserted_ = entity;
				break;
			case UpdateMutation:
				updated_ = entity;
				break;
			case DeleteMutation:
				deleted_ = entity;
				break;
			default: break;
			}
		}

		MutationType type() const {
			return type_;
		}

		const Entity& inserted() const {
			return inserted_;
		}

		const Entity& updated() const {
			return updated_;
		}

		const Entity& deleted() const {
			return deleted_;
		}

	private:
		MutationType type_;
		Entity inserted_;
		Entity updated_;
		Entity deleted_;
	};
}

#endif