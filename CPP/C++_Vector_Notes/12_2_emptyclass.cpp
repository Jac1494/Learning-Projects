https://www.geeksforgeeks.org/why-is-the-size-of-an-empty-class-not-zero-in-c/

Why is the size of an empty class not zero?
To ensure that the addresses of two different objects will be different. 
For the same reason, "new" always returns pointers to distinct objects. 
Consider:

	class Empty { };

	void f()
	{
		Empty a, b;
		if (&a == &b) cout << "impossible: report error to compiler supplier";

		Empty* p1 = new Empty;
		Empty* p2 = new Empty;
		if (p1 == p2) cout << "impossible: report error to compiler supplier";
	}	

There is an interesting rule that says that an empty base class need not be represented by a separate byte:
	struct X : Empty {
		int a;
		// ...
	};

	void f(X* p)
	{
		void* p1 = p;
		void* p2 = &p->a;
		if (p1 == p2) cout << "nice: good optimizer";
	}
This optimization is safe and can be most useful. It allows a programmer to use empty classes 
to represent very simple concepts without overhead. Some current compilers provide this "empty base class optimization".
