//Template Instantiation 

/*
The templates are written in a generic way, which means that it’s a general implementation irrespective of the data type. 
As per the data type provided, we need to generate a concrete class for each data type.

For Example, if we have a template sort algorithm, we may generate a concrete class for sort<int>, another class for sort<float>, etc. 
This is called instantiation of the template.

We substitute the template arguments (actual data types) for the template parameters in the definition of the template class.

For Example,

template <class T>
class sort {};

When we pass <int> data type, the compiler substitutes the data type <int> for ‘T’ so that the sorting algorithm becomes sort<int>.

Every time when we use template class or function, there is a need for an instance when we pass a particular data type. 
If this instance is not already present, the compiler creates one with the particular data type. This is the implicit instantiation.

One drawback of implicit instantiation is that the compiler generates instance class only for the arguments that are used currently. 
This means if we want to generate a library of instances ahead of the usage of these instances, we need to go for explicit instantiation.

An example of Template declaration is given below:

template class Array(T)
Can be explicitly instantiated as:

template class Array<char>
When a class is instantiated, all its members are also instantiated.
