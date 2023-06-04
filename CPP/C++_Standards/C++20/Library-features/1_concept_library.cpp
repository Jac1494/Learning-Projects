/*
Concepts library
Concepts are also provided by the standard library for building more complicated concepts. Some of these include:

Core language concepts:

same_as - specifies two types are the same.
derived_from - specifies that a type is derived from another type.
convertible_to - specifies that a type is implicitly convertible to another type.
common_with - specifies that two types share a common type.
integral - specifies that a type is an integral type.
default_constructible - specifies that an object of a type can be default-constructed.
Comparison concepts:

boolean - specifies that a type can be used in Boolean contexts.
equality_comparable - specifies that operator== is an equivalence relation.
Object concepts:

movable - specifies that an object of a type can be moved and swapped.
copyable - specifies that an object of a type can be copied, moved, and swapped.
semiregular - specifies that an object of a type can be copied, moved, swapped, and default constructed.
regular - specifies that a type is regular, that is, it is both semiregular and equality_comparable.
Callable concepts:

invocable - specifies that a callable type can be invoked with a given set of argument types.
predicate - specifies that a callable type is a Boolean predicate.

*/
#include <concepts>
#include <iostream>

class A {};

class B: public A {};

class C: private A{};

int main() {
	// std::derived_from == true only for public inheritance or exact same class
	static_assert( std::derived_from<B, B> == true );      // same class: true
	static_assert( std::derived_from<int, int> == false ); // same primitive type: false
	static_assert( std::derived_from<B, A> == true );      // public inheritance: true
	static_assert( std::derived_from<C, A> == false );     // private inheritance: false

	// std::is_base_of == true also for private inheritance
	static_assert( std::is_base_of_v<B, B> == true );      // same class: true
	static_assert( std::is_base_of_v<int, int> == false ); // same primitive type: false
	static_assert( std::is_base_of_v<A, B> == true );      // public inheritance: true
	static_assert( std::is_base_of_v<A, C> == true );      // private inheritance: true

	std::cout << "Concept Library\n";
	return 0;
}
