/*
Math constants:-
- Mathematical constants including PI, Euler's number, etc. defined in the <numbers> header.
- Now with C++20 there is support for pi in the standard with mathematical constants, residing 
  in the namespace std::numbers:
    inline constexpr double pi = pi_v<double>();
- But wait there is more, alongside pi you also get inverse pi and inverse sqrt pi. 
  The full list of supported constants:

    pi, inv_pi, inv_sqrtpi
    e ("Eulers number")
    log2e & log10e
    ln2 & ln10
    sqrt2 & sqrt3 + inv_sqrt3
    egamma (Euler Mascheroni constant)
    phi (golden ratio)

- These are also provided as variable template (*_v, e.g. phi_v), the standard specializes 
  these for float, double and long double. For a non standard type you could create your own specialization.    
*/

#include <cmath>
#include <iomanip>
#include <iostream>
#include <limits>
#include <numbers>
#include <string_view>
#include <functional>

using std::placeholders::_2;
template <class T>
constexpr auto operator^(T base, decltype(_2)) { return base * base; }

int main()
{
	using namespace std::numbers;

	std::cout << "The answer is " <<
		(((std::sin(e)^_2) + (std::cos(e)^_2)) + 
		 std::pow(e, ln2) + std::sqrt(pi) * inv_sqrtpi +
		 ((std::cosh(pi)^_2) - (std::sinh(pi)^_2)) +
		 sqrt3 * inv_sqrt3 * log2e * ln2 * log10e * ln10 *
		 pi * inv_pi + (phi * phi - phi)) *
		((sqrt2 * sqrt3)^_2) << '\n';

	auto egamma_aprox = [] (unsigned const iterations) {
		long double s{}, m{2.0};
		for (unsigned c{2}; c != iterations; ++c, ++m) {
			const long double t{ std::riemann_zeta(m) / m };
			(c & 1) == 0 ? s += t : s -= t;
		}
		return s;
	};

	constexpr std::string_view γ {"0.577215664901532860606512090082402"};

	std::cout 
		<< "γ as 10⁶ sums of ±ζ(m)/m   = "
		<< egamma_aprox(1'000'000) << '\n'  // 0.577215
		<< "γ as egamma_v<float>       = "
		<< std::setprecision(std::numeric_limits<float>::digits10 + 1)
		<< egamma_v<float> << '\n'          // 0.5772157
		<< "γ as egamma_v<double>      = "
		<< std::setprecision(std::numeric_limits<double>::digits10 + 1)
		<< egamma_v<double> << '\n'         // 0.5772156649015329
		<< "γ as egamma_v<long double> = "
		<< std::setprecision(std::numeric_limits<long double>::digits10 + 1)
		<< egamma_v<long double> << '\n'    // 0.5772156649015328606
		<< "γ with " << γ.length() - 1 << " digits precision = " << γ << '\n'; // γ with 34 digits precision = 0.577215664901532860606512090082402

	return 0;
}
