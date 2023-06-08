#include "Fixed.hpp"


class Point {
	public:
		Point(void);
		Point(const Point& src);
		Point(const float x, const float y);
		~Point(void);

		Point& operator=(const Point& rhs);
		bool operator==(const Point& rhs) const;

		friend std::ostream & operator<<(std::ostream & os, const Point & rhs);

		float getX(void) const;
		float getY(void) const;

	private:
		Fixed const _x;
		Fixed const _y;
};

bool bsp( Point const a, Point const b, Point const c, Point const point );
