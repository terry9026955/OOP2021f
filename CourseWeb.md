Welcome to the course website of OOP 2021 fall. The source code we wrote in the class will be available here. You can check history tab on the top of this page to see the content of each week. Notably, the teaching materials and methods are credited to Prof. Yu Chin Cheng at CSIE, NTUT. For any inquires, please email shchen@ntut.edu.tw with title [物件導向程式設計]_姓名_學號_班級. Formal format is required in the email. You can find your [**Grades**](https://docs.google.com/spreadsheets/d/1dP1KPtEw2mkf2xmfuVnBfRT9bgkF2TV1E2GNmS0f9YI/edit?usp=sharing) here for each HW.

### Week 18 1/21 - Online Computer midterm

- Schedule to take palce during 08:00 to 12:00. 
- If you cannot attend due to schedule conflict, send me an email by 01/16.
- Join individial chatroom through MS Teams on PC
- Join groupd chatroom through MS Teams on your cellphone
- Teacher will be available until 11:30 (Have to attend meeting at 12:00)
- TA will be available till the end of the exam

### Week 18 1/17 - Hand-written midterm

- Two classroom and here are the seat plan. [六教 327](https://css-gitlab.csie.ntut.edu.tw/109000000/oop2021f/-/blob/master/0.%20Course%20Material/OOP%E8%80%83%E8%A9%A6%E9%85%8D%E7%BD%AE%E5%9C%961PDF_1_.pdf) & [六教626](https://css-gitlab.csie.ntut.edu.tw/109000000/oop2021f/-/blob/master/0.%20Course%20Material/OOP%E8%80%83%E8%A9%A6%E9%85%8D%E7%BD%AE%E5%9C%962PDF.pdf)

### Week 17 1/14 - No class. Please use this period of time to finish HW.

### Week 17 1/10 - File I/O and Main function with input parameters

### Week 16 1/7 - Command line argument processing

- [HW08](https://css-gitlab.csie.ntut.edu.tw/109000000/oop2021f_hw)
- argument processing ```int main (int argc, char * argv[])```
  - argc is the number of arguments in the command line
  - argv[0]: string representing program name
  - argv[i]: ith argument, i = 1, ..., argc-1
- writing shapes to file
  - All Shapes need a name: default
    - protected default constructor for Shape
  - toString() as a virtual member function of Shape, derived classes, and MathVector
    - std::[stringstream](https://www.cplusplus.com/reference/sstream/stringstream/) ss;
    - streams, insertion operator <<, extraction operator >>
    - overloading stream extraction operator std::operator <<
    - overloaded operator << works for stringstream
- reading shapes from file
  - we will do this without considering error handling (we assume the data is correct in format)
- test data
```
triangle
0 0
3 0
3 4
polygon
5
0 0
2 0
2 4
2 5
0 4
```

- typedef a pointer to function for storing lambda
```
typedef bool (*Comp) (Shape * former, Shape * latter);
```

### Week 16 1/3 - Template functions

- [HW07](https://css-gitlab.csie.ntut.edu.tw/109000000/oop2021f_hw/-/tree/909fbea81531b95e6f7eb14836f0c75e513dc7f0)
- templates
  - class: std::vector is a array-like container for any type
    - std::vector, std::vector, std::vectorstd::string, etc.
  - function: write a function that exchanges two objects of the same type
    - exchange, exchange

### Week 15 12/31 - No class due to national holiday

### Week 15 12/27 - Handing out medterm exam sheets

### Week 14 12/24 - Refactoring & Fixing Memory Leak & App Class

### Week 14 12/20 - Virtual destructor & Memory Leak

__Constructor and destructors in inheritance and polymorphism and their relation to memory leak__

- A main design use of OO is polymorphism
- but polymorphism is very often enabled through use of pointer
  - base class pointer pointing to a derived class instance
  - calling virtual function through the base class pointer
- the use of pointer to enable polymorphism has potential memory leak
  - for example, class App _owns_ several Shapes
  - owning means when App terminates, all shapes are destroyed
  - App sort the the Shapes, e.g., by area
  - In implementation, we could use
```
std::vector<Shape *> shapes;
```
  - So when App terminates, we have to make sure that all shapes are destroyed
  - this involves calling the right destructors through deleting the pointers in the vector

- before that, let's see how constructor behaves under inheritance
  - In constructing a Square, a Shape is first constructed
    - default constructor of Shape is called if not specified
    - specify the constructor to be used with _constructor member initializer list_
  - (Testing idea) observing the sequence of constructor call through static data members and managing it with static member function
    - [static members](https://www.geeksforgeeks.org/static-keyword-cpp/): a static member of a class is a unique member
      - initialized outside of the class;
      - accessed through class scope operator; or through an instance of the class ( shared by all instances of the class);
      - is inherited by subclass through inheritance

- On to destructor
  - given that Square inherits Shape, when Square object's lifetime ends, ~Square is called and then ~Shape is called
  - same happens when deleting a Square pointer
  - BUT NOT SO when deleting through Shape pointer unless the destructor of Shape is virtual

- on to App
  - vector of pointers to Shape seems to be the only choice because we need polymorphism (sort)
    - with lambda (anonymous function)
  - must have ~App();
  - without virtual destructor in Shape, ~App() will only delete the Shape part, potentially leaking memory.

### Week 13 12/17 - Polymorphism

- Sorting triangles, circles and polygons
  - Elements in an vector (or array) must be of the same type. What type should we put in for ??? Triangle? Polygon? Or what?
  - "A Triangle is a Shape" and "a Polygon is a Shape". So:
    - Create a Shape class with operations to compute area and perimeter
    - derive (inherit) Triangle from Shape
    - Shape is a base (parent) class; Triangle is a derive class
    - repeat for Polygon
  - but when we get an element out, it must have the right operations:
Triangle uses Triangle::area() and Polygon uses Polygon::area()
    - do this by declare Shape::area() to be virtual
    - in Triangle::area(), put in keyword override
  - To have Triangle and Polygon behaves as a Shape inside the random access container, one must use either a pointer or a reference to Shape
- **Polymorphism**: the capability of std::sort to treat Triangle and Polygon as Shape objects and still able to call the correct area and perimeter function requires three things:
  - Base class Shape with virtual (or pure virtual) are and perimeter;
  - derive Triangle and Polygon publicly from Shape and override area and perimeter; and
  - Triangle objects amd Polygon objects are accessed through pointer to Shape or reference to Shape

### Week 13 12/13 - Constructor in drvied class

- Different ways of inheritance: public & private & protected
  - [Link](https://openhome.cc/Gossip/CppGossip/protectedPrivateInheritance.html)
- Constructor initializer list
  - To call base class constructor
  - To initialize local private variable
  - [Link](https://kwcheng0119.pixnet.net/blog/post/43384290)

### Week 12 12/10 - Inheritance & virtual function

Suggesting reading : CH 15
- Base class v.s. Drvied class
- Virtual function
  - Member function definition starting with `virtual` and ending with `const = 0`
  - To tell the compiler that this is a **pure virtual function**
  - Class that contains virtual function are **abstract class**

### Week 12 12/6 - Factory

- factory to ensure that inly polygons with ccw-sorted vertices are created
  - Simple Factory Pattern [Link](https://www.itread01.com/content/1543452122.html)
  - ordinary function
  - static member function
  - make polygon constructor private
- Factory Method
  - An interface for creating objects in a superclass, but allows subclasses to alter the type of objects
  - [Link](https://refactoring.guru/design-patterns/factory-method)

### Week 11 12/3 - Dealing with design issues

- [HW05](https://css-gitlab.csie.ntut.edu.tw/109000000/oop2021f_hw) You're required to submit HW05 to your gitlab project and trigger Jenkins and shuold have blue light for both HW and TA jobs to get all points for HW05.
- std:sort 
  - ascending or descending
  - three ways to compare:
    - default (element must support "operator <")
    - by function
    - by object with overloaded operator ()
- Design issues
  - sort vertices counter-clockwise around the centroid of a convex polygon

### Week 11 11/29 - Convex Polygon: representation and computation

- Test driven development TDD:
1. design test data
2. write a test first
3. write code to make it pass
4. pass all tests
- representation: ConvexPolygon --> MathVector
  - first assume the order of vertices are as required
  - [Link](http://htsicpp.blogspot.com/2014/10/convex-polygon.html)
- Perimeter of rectangle
  - What we did wrong previously?
  - Not checking the test cases
  - Vertices are not sorted
- std:sort 
  - [Link](https://en.cppreference.com/w/cpp/algorithm/sort)

### Week 10 11/26 - Online Computer midterm

### Week 10 11/22 - Hand-written midterm

- Take place at 626 and 327 -> [Seating plan](https://css-gitlab.csie.ntut.edu.tw/109000000/oop2021f/-/blob/master/0.%20Course%20Material/OOP%E6%9C%9F%E4%B8%AD%E8%80%83%E5%BA%A7%E4%BD%8D.pdf)

### Week 9 11/15 - More about operator overloadding & Default constructor is not always there

- Overloading operator '<' and '>'
- Default constructor will 'not' be generated automatically
  - When there is another constructor with some passed parameters
  - When a fix-sized array of the defined object is decleared
  - When a variable-sized array is decleared
  - When template class is been used
- [HW04](https://css-gitlab.csie.ntut.edu.tw/109000000/oop2021f_hw) You're required to submit HW03 to your gitlab project and trigger Jenkins and shuold have blue light for both HW and TA jobs to get all points for HW04.

### Week 8 11/12 - Vector (with BBPOS & IRS)

- Template class
  - allows functions and classes to operate with generic types.
  - allows a function or class to work on many different data types without being rewritten for each one.
- Vector
  - sequence containers representing arrays that can change in size.
  - [Link1](https://shengyu7697.github.io/std-vector/)、[Link2](https://cplusplus.com/reference/vector/vector/?kw=vector)

### Week 7 11/05 - Continue The triangle class & new (with BBPOS & IRS)

- Four questions to ask when writing a member function
  - what is the name?
  - what are the arguments?
  - what is the return type?
  - is it a constant?
- Tiring of douplicated codes when writing test cases?
  - [test fixture](https://github.com/google/googletest/blob/master/docs/primer.md#test-fixtures-using-the-same-data-configuration-for-multiple-tests-same-data-multiple-tests)
- Please be aware of the type checking when overloadding operator +
- **You shuold see error when calling a non-constant member function from a constant object**

### Week 7 11/01 - The triangle class

[HW03](https://css-gitlab.csie.ntut.edu.tw/109000000/oop2021f_hw) You're required to submit HW03 to your gitlab project and trigger Jenkins and shuold have blue light for both HW and TA jobs to get all points for HW03.

- Triangle:
  - three vertices, each of which is a 2d vector
  - perimeter

### Week 6 10/29 - More about Copy constructor & Copy assignment (with BBPOS & IRS)

Suggesting reading : [PL C++](https://www.cplusplus.com/articles/y8hv0pDG/) & [Extract Methods for refactoring](https://refactoring.com/catalog/extractFunction.html)

- copy assignment
  - right associative w = u = v; => w = (u = v);
  - return by reference
  - the this pointer
  - automatically generated if not defined shallow copy not deep copy
- constructors are overloadable
  - default constructor: the constructor that takes no parameters
  - copy constructor: the constructor that takes an object of the same class
  - one is given by C++ when not defined: shallow copy not deep copy
  -other constructors are defined as needed (e.g., MathVector(int, double *))

Example



      class MyClass obj1, obj2;
      class MyClass obj3(obj1);     //Calls Copy Constructor
      class MyClass obj4 = obj1;    //Calls Copy Constructor
      obj1 = obj2;                  //Calls Copy Assignment Operator

### Week 6 10/25 - Passed by reference v.s. Passed by value with a pointer

[HW02](https://css-gitlab.csie.ntut.edu.tw/109000000/oop2021f_hw) You're required to submit HW02 to your gitlab project and trigger Jenkins and shuold have blue light for both HW and TA jobs to get all points for HW02. 

- In today's class, we see the difference between passed by reference and passed by value with a pointer.
- Copy assignment.

### Week 5 10/22 - Addressof operator v.s. Reference

Suggesting reading : CH 10

- Syntax for computation, want to have
  - w = u + v
  - w = a * v
  - w = a * u + b * v
- What is this? It's a pointer
- The concept of reference
  - Avoid copy constructor when passing by reference
  - Must be initialized when declaring
- What is the difference of following operators?


      double *p, v; 
      p = &v; // & Addressof operator
      *p = 12; // * dereferencing operator
      
      int r; 
      int &xp = r; // reference

### Week 5 10/18 - Why copy constructor is not called when returning an object?

- [copy elision](https://en.wikipedia.org/wiki/Copy_elision#Return_value_optimization)
  - A compiler optimization to avoid unnecessary copying of objects.
  - [Common forms of copy elision](https://stackoverflow.com/questions/12953127/what-are-copy-elision-and-return-value-optimization/12953150#12953150)
- [using gdb](https://codertw.com/%E7%A8%8B%E5%BC%8F%E8%AA%9E%E8%A8%80/551505/) to find out segmentation fault

### Week 4 10/15 - Looking back on the math vector problem with Class

Suggesting reading : CH 7 & [Class](http://www.cplusplus.com/doc/tutorial/classes/)

- Solve problem with MathVector class
  - two pieces of data wrapped together
  - new and delete operations
  - constructor
  - destructor
  - make wrapped members (data and behavior)
- Function overloading
- Copy constructor - may be called in the following cases: 
  1. When an object of the class is returned by value. 
  2. When an object of the class is passed (to a function) by value as an argument. 
  3. When an object is constructed based on another object of the same class. 
  4. When the compiler generates a temporary object.

### Week 4 10/11 - No Class

### Week 3 10/8 - Continue the math vector problem

Suggesting reading : [Slide](https://css-gitlab.csie.ntut.edu.tw/109000000/oop2021f/-/blob/master/0.%20Course%20Material/OOP_Week_4.pdf) & CH 3

[HW01](https://css-gitlab.csie.ntut.edu.tw/109000000/oop2021f_hw) You're required to submit HW01 to your gitlab project and trigger Jenkins and shuold have blue light for both HW and TA jobs to get all points for HW01. 

**Problem III** Let _u_, _v_ be n-dimensional vectors. Write a program to calculate add u to v to obtain _u_ + _v_

**Problem IV** Let _u_, _v_ be n-dimensional vectors and _a_, _b_ be real numbers. Write a program to calculate _a_ _u_ + _b_ _v_

- Handle exception
- Pointer
  - *a, a[], &a
- runtime model of program
  - data, text, stack, heap
- memory allocation/deallocation from heap
  - new operator: allocating space from heap
  - delete operator: de-allocating space from heap
  - memory leak: allocated space NOT de-allocated when it's done used

### Week 3 10/4 - Continue the math vector problem

Suggesting reading : [Slide](https://css-gitlab.csie.ntut.edu.tw/109000000/oop2021f/-/blob/master/0.%20Course%20Material/OOP_Week_3.pdf)

**Problem II** Let _v_ be a n-dimensional vector and _a_ be a real number. Write a program to calculate its scalar multiplication _a_ _v_.

**C++ (version 11)**
- [function](http://www.cplusplus.com/doc/tutorial/functions/)
- C argument passing: ONLY call by value
- memory model of variables in C/C++
  - model of variable
  - model of an array

### Week 2 10/1 - The math vector problem

Suggesting reading : Make sure you read those links below & [Slide](https://css-gitlab.csie.ntut.edu.tw/109000000/oop2021f/-/blob/master/0.%20Course%20Material/OOP_Makefile.pdf)

**Problem I** Let v a n-dimensional vector. Write a program to calculate its length | v |.

If you're not familiar with vector, read [here](https://en.wikipedia.org/wiki/Vector_space).

**Problem solving**

- understanding the problem
- devising a plan
- carrying out the plan
- looking back

**Engineering practices**

- write [makefile](https://css-gitlab.csie.ntut.edu.tw/109000000/oop2021f/-/blob/master/0.%20Course%20Material/OOP_Makefile.pdf)
- Engineering: add test folder
- Engineering + programming: write first vector test for length
- Git useful scenarios
  - Add .gitignore file to bin folder to avoid uploading compiled files
  - clone a repo: git clone
  - get new result from repo: git pull
  - incorporate current work: add, commit, and push
  - [reset all changes after last commit in git](https://stackoverflow.com/questions/4630312/reset-all-changes-after-last-commit-in-git)

**C++ (version 11)**

- Precedence of Operator
- Enum v.s. Strong Enum (Class)
- How soruce code are compiled (with makefile)

### Week 2 9/27 - Getting started

Suggesting reading : following links & [Slide](https://css-gitlab.csie.ntut.edu.tw/109000000/oop2021f/-/blob/master/0.%20Course%20Material/OOP_Week_2.pdf) & CH 2

In this semester, 3 things will be given to assist you in your future career.
- [How To Solve It](http://htsicpp.blogspot.com/2014/08/introducing-how-to-solve-it-cpp.html) (Proposed by George Pólya)
- C++ (version 11)
- Engineering practices (unit testing, [version control](https://css-gitlab.csie.ntut.edu.tw/109000000/oop2021f/-/blob/master/0.%20Course%20Material/2_More_Info_About_Git.pdf), make, incremental development, test driven development, pair programming, and mob programming, [using Linux cmds](https://ubuntu.com/tutorials/command-line-for-beginners#1-overview))

Reference
- Text book
- [cplusplus.com](https://www.cplusplus.com/)
- [googletest](https://github.com/google/googletest/blob/master/docs/primer.md)

We will solve a few problems together through the practices of "How To Solve It". 

**Problem** Ask users to input two vectors and give the inner product. We are requied tell the user whether to continue and stop.

      [1, 0] · [1, 1] = 1,
      [1, 1, 0] · [0, 1, 1] = 1, and
      [1, 0] · [1, 1, 0] => undefined.

**Our plan** [Inner product, round 1](http://htsicpp.blogspot.com/2014/08/inner-product-round-1.html)

**C++ (version 11)**

- Namespace
- [String Class](https://www.cplusplus.com/reference/string/string/?kw=string)

### Week 1 - Introduction & Environment 

Setup Suggesting reading : CH 1

[Slides of Introduction](https://css-gitlab.csie.ntut.edu.tw/109000000/oop2021f/-/blob/master/0.%20Course%20Material/OOP_Week_1.pdf) / [Slides of HW00](https://css-gitlab.csie.ntut.edu.tw/109000000/oop2021f/-/blob/master/0.%20Course%20Material/HW00_OOP_Environment_Setup.pdf) / [Report template for HW00](https://css-gitlab.csie.ntut.edu.tw/109000000/oop2021f/-/blob/master/0.%20Course%20Material/OOP_HW00_109000000.docx) _(UPDATED on 09/28)_

You're required to submit the report for part 1 of HW00 to i study. If you do not have a student account from NTUT. Please send your homework to shchen@ntut.edu.tw with title [物件導向程式設計]_姓名_學號_班級_HW00. Your file name shuold be "OOP_HW00_109000000.pdf".

Gitlab and Jenkins are now available for logging in. If you are 隨班附讀, please check your assigned id [here](https://docs.google.com/spreadsheets/d/1dP1KPtEw2mkf2xmfuVnBfRT9bgkF2TV1E2GNmS0f9YI/edit?usp=sharing). Please remeber to change your password right after logging in. _(UPDATED on 09/28)_
