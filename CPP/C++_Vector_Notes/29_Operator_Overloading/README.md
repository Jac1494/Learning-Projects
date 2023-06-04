List of operator can be overloaded
------------------------------------

1. Binary arithmatic => + , - , * , / , %
2. Unary Arithmatic  => ++ , --
3. Assignment        => = , += , /= , *= , -= , %= , &= , |=, ^=
4. Bitwise           => & , | , ! , >> , << , ~ , ^
5. Dereferencing     => ->
6. Dynamic memory    => new , delete
7. Subscript         => []
8. Function call     => ()
9. Logical           => && , || , !
10. Relational       => > , < , == , != , <= , >=
11. Others           => >>= , <<=

List of operator can be overloaded only through member function (Not with friend function)
--------------------------------------------------------------------------------------------
1. =  (Assignment)
2. () (Function call)
3. [] (Substripting)
4. -> (Arrow)

List of operator can be overloaded only through friend function ( Not with member function)
--------------------------------------------------------------------------------------------
1. "<<"  (Insertion)
2. ">>"  (Extraction)

List of operator can't be overloaded 
--------------------------------------
1. . (dot) => Member selection operator
2. .(*) => Member selection through pointer to member operator
3. sizeof 
      // Reason:- there are built-in operator ,such as incrementing poiner into a array implicity depend on it.
      // Example:- 
      // int a[10];
      // int *p = &a[3];
      // char *q = &a[3];
      // p++; // P is incremented by 4 bytes;
      // q++; // Q is incremented by 1 bytes;
      
4. :: (Scope Resolution)
      // Reason:- One could imagine allowing overloading of x::y , where x is object not namespace or class.
      // Then :: operator could not be given a new and different meaning by the programing without violating 
      // basic language rule.
5. ?: (Condition Operator)
