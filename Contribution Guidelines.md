# Contribution Guidelines
Please follow these guidelines if you would like to contribute to this project.
___
## Before you begin
The first thing you wanna do is send me an email over at himan2104@gmail.com so that I can add you to the list of contributors (which is for my reference). Next we can discuss a few specifics and I can give you a walkthrough of the already existing codebase.
___
## Coding Style
While contributing to this project please try to maintain a similar coding style as the project. This will make it easier for me to review your code. Currently the styling is not robust since most of the codebase is old. I shall try to update the styling as soon as possible.

Styling reference for class names
~~~C++
class MyClass { }; 
~~~

Styling reference for variables
~~~C++ 
type _var_name; //for private vars [e.g. _animation_clip]
type tVarName; //for public vars [e.g. bIsRunning]
~~~

Styling reference for functions
~~~C++
void MyFunc(params); //for public functions [e.g. StartAnimation()]
void func_name(params); //for private functions [e.g. destroy_object()]
~~~

Code Sample
~~~C++
class MyClass
{
    public:
        MyClass();
        ~MyClass();

        Foo();
        Bar(params);

        MyFunc();
        
        bool bIsActive;

    private:
        int _lucky_number
        std::string _name;

        void destroy_object();
};
~~~
___
## Writing completely new systems
When writing new systems, features or plugins for the engine, sharing a well written document about the design and end goal of the system would be greatly appreciated. This will help keep everyone involved in the project on the same page. Note that this isn't a mandatory task but will help us out in the future. You may choose to skip this if the system being implemented is a very minor piece of software that can be easily explained in the comments.