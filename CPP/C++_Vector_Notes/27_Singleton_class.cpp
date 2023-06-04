/*
Singleton class:-
--------------
- Singleton design pattern is a software design principle that is used 
  to restrict the instantiation of a class to one object. This is useful 
  when exactly one object is needed to coordinate actions across the system. 
- For example, if you are using a logger, that writes logs to a file, 
  you can use a singleton class to create such a logger. You can create 
  a singleton class using the following code.

*/
#include <iostream>
using namespace std;
class Singleton {
   static Singleton *instance;
   int data;
   // Private constructor so that no objects can be created.
   Singleton() {
      data = 0;
   }
   public:
   /*
	getInstance() is a static method that returns an
	instance when it is invoked. It returns the same
	instance if it is invoked more than once as an instance
	of Singleton class is already created. It is static
	because we have to invoke this method without any object
	of Singleton class and static method can be invoked
	without object of class

	As constructor is private so we cannot create object of
	Singleton class without a static method as they can be
	called without objects. We have to create an instance of
	this Singleton class by using getInstance() method.
   */
      static Singleton *getInstance() {
         if (!instance)
         instance = new Singleton;
         return instance;
      }
   int getData() {
      return this -> data;
   }
   void setData(int data) {
      this -> data = data;
   }
};
// Initialize pointer to zero so that it can be initialized 
// in first call to getInstance
Singleton *Singleton::instance = 0;
int main(){
   Singleton *s = s->getInstance();
   cout << s->getData() << endl;        // 0
   s->setData(100);
   cout << s->getData() << endl;        // 100
   return 0;
}