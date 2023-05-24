#ifndef FIXED_HPP
# define FIXED_HPP
#include <iostream>

class Fixed {
	public:
		Fixed(void);
		Fixed(int const value);
		Fixed(float const value);
		Fixed(Fixed const & src);
		~Fixed(void);

		Fixed & operator=(Fixed const & rhs);

		int getRawBits(void) const;
		void setRawBits(int const raw);
		float toFloat(void) const;
		int toInt(void) const;
		static Fixed min(Fixed& a, Fixed& b);
		static Fixed min(const Fixed& a, const Fixed& b);
		static Fixed max(Fixed& a, Fixed& b);
		static Fixed max(const Fixed& a, const Fixed& b);



		bool operator==(const Fixed& rhs) const;
		bool operator!=(const Fixed& rhs) const;
		bool operator<(const Fixed& rhs) const;
		bool operator>(const Fixed& rhs) const;
		bool operator<=(const Fixed& rhs) const;
		bool operator>=(const Fixed& rhs) const;

		Fixed operator+(const Fixed& rhs) const;
		Fixed operator-(const Fixed& rhs) const;
		Fixed operator*(const Fixed& rhs) const;
		Fixed operator/(const Fixed& rhs) const;

		Fixed& operator++();         // Pre-increment
		Fixed operator++(int);       // Post-increment
		Fixed& operator--();         // Pre-decrement
		Fixed operator--(int);       // Post-decrement

	private:
		int _fixedPointValue;
		static const int _fractionalBits = 8;
};

std::ostream & operator<<(std::ostream & os, const Fixed & rhs);
#endif
