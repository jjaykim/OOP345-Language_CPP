# Workshop 5: Functions and Error Handling
In this workshop, you code a function object and a lambda expression, and handle exceptions.

You are to create a class template that manages a family of collection of objects of type T. This template's client can register a callback function (an observer) that will be called every time a new item is added successfully to a collection.

Your design works with collections of books and collections of movies, both loaded from files. The file information contains mistakes:

You are to create a lambda expression that fixes the price information about a book
You are to create a function object (functor) that fixes some spelling mistakes in the descriptions and titles for books or movies.
In case of exceptional circumstances, your design generates exceptions and subsequently handles them

the functor loads the misspelled words from a file, but if that file is missing, generates an exception.
iterating over the collection using indices, your design generates an exception if an index is invalid.


## Learning
- design and code a templated class that allocates and deallocates dynamic memory
- design and code a function object
- design and code a lambda expression
- code a member function that receives the address of a callback function to execute
- throw exceptions of different types
- distinguish exception types from one another