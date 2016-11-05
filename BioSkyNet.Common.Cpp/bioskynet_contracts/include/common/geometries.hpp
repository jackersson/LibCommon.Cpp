#ifndef Geometries_INCLUDED
#define Geometries_INCLUDED
#include <utility>

namespace contracts
{
	namespace geometries
	{
		//Interfaces
		class IPosition
		{
		public:
			virtual ~IPosition() {}

			virtual float x() const = 0;
			virtual float y() const = 0;
		};
		
		class IBox
		{
		public:
			virtual ~IBox() {}

			virtual const IPosition& origin() const = 0;
			virtual const IPosition& end   () const = 0;

			virtual int size() const = 0;
		};

		//Implementation
		class Position : public IPosition
		{
		public:
			explicit Position(const IPosition& pos) 
				:	par_(pos.x(), pos.y()) {}

			Position(float x, float y) :par_(x, y) {}

			float x() const override {
				return par_.first;
			}

			float y() const override {
				return par_.second;
			}

		private:
			std::pair<float, float> par_;
		};

		class Box : public IBox
		{
		public:
			Box(const IPosition& origin, const IPosition& end)
				: par_(Position(origin), Position(end))
		  {}

			const IPosition& origin() const override  {
				return par_.first;
		  }
			const IPosition& end   () const override {
				return par_.second;
		  }
		private:
			std::pair<Position, Position> par_;
		};
		

	}
}

#endif