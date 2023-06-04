
# Introduction to Iterators in C++

- An iterator is an object (like a pointer) that points to an element inside the container. We can use iterators to move through the contents of the container.
- They can be visualized as something similar to a pointer pointing to some location and we can access the content at that particular location using them. 
- Iterators play a critical role in connecting algorithm with containers along with the manipulation of data stored inside the containers. The most obvious form of an iterator is a pointer. A pointer can point to elements in an array and can iterate through them using the increment operator (++)
- But, all iterators do not have similar functionality as that of pointers. Depending upon the functionality of iterators they can be classified into five categories, as shown in the diagram below with the outer one being the most powerful one and consequently the inner one is the least powerful in terms of functionality.


![delete](https://user-images.githubusercontent.com/31218470/226183169-01e71c75-c211-48c3-a7f4-d1ca179c9b5e.jpg)



- Now each one of these iterators are not supported by all the containers in STL, different containers support different iterators, The whole list is as given below:

|  Container        |  Types of Iterator Supported  | 
| :---------------: | ----------------------------- | 
| 	Vector		 	| Random-Access					| 
| 	List		 	| Bidirectional 				| 
| 	Deque		 	| Random-Access					| 
| 	Map		 		| Bidirectional 				|
| 	MultiMap	    | Bidirectional 				|
| 	Set		        | Bidirectional 				|
| 	MultiSet	    | Bidirectional 				|
| 	Stack		    | No iterator supported 		|
| 	Queue		    | No iterator supported 		|
| 	Priority-Queue	| No iterator supported 		|

Types of iterators
------------------
**1. Input Iterators**
- They are the weakest of all the iterators and have very limited functionality. They can only be used in a single-pass algorithms, i.e., those algorithms which process the container sequentially, such that no element is accessed more than once.

**2. Output Iterators**
- Just like input iterators, they are also very limited in their functionality and can only be used in single-pass algorithm, but not for accessing elements, but for being assigned elements.

**3. Forward Iterator**
- They are higher in the hierarchy than input and output iterators, and contain all the features present in these two iterators. But, as the name suggests, they also can only move in a forward direction and that too one step at a time.

**4. Bidirectional Iterators**
- They have all the features of forward iterators along with the fact that they overcome the drawback of forward iterators, as they can move in both the directions, that is why their name is bidirectional.

**5. Random-Access Iterators**
- They are the most powerful iterators. They are not limited to moving sequentially, as their name suggests, they can randomly access any element inside the container. They are the ones whose functionality are same as pointers.
![delete](https://user-images.githubusercontent.com/31218470/226197184-1de2dd30-436b-4da0-9daa-96367e4ed9de.jpg)
