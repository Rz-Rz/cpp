#ifndef FIXED_HPP
# define FIXED_HPP

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

	private:
		int _fixedPointValue;
		static const int _fractionalBits = 8;
};
#endif
