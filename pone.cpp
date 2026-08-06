// Type your code here, or load an example.

#include <iostream>
#include <cassert>
#include <array>

//We should probably make a little namespace for all of this.


//Array doesn't get demoted down to a pointer or something like that.
class string
{
private:
public:
    string()
    {
        str_array[0] = '\0';
    }
    //Copy Constructor
    string(string& str)
    {
        char* str_ptr = str.str_array.data();
        int count = 0;
        for(;*str_ptr != '\0'; ++str_ptr)
        {
            str_array[count] = *str_ptr;
            ++count;
        }
        str_array[count] = '\0';
    }

    string(char a[])
    {
        char* str_ptr = a;
        int count = 0;
        for(;*str_ptr != '\0'; ++str_ptr)
        {
           str_array[count] = *str_ptr;
           ++count;
        }
         str_array[count] = '\0';
    }

    string& operator=(string& a) //we're altering the lhs and not the rhs
    {

        char* str_ptr = a.str_array.data();
        int count = 0;
        for(;*str_ptr != '\0'; ++str_ptr)
        {
           str_array[count] = *str_ptr;
           ++count;
        }

        //The *this-> syntax shit is trippy.
        return *this;
    }
    size_t length()
    {

        return 0;
    }
    void print()
    {
        char* p = str_array.data();
        for(;*p != '\0'; ++p)
        {
            std::cout << *p;
        }
    }

    std::array<char,100> str_array;

};

int main()
{
    //check default initialization

    //check Copy Constructor

    char p[] = "Hello World";
    //string b(p);

    string a(p);
    string b(a);

    a = b;
    a.print();

\
    return 0;
}
