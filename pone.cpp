#include <iostream>
#include <cassert>
#include <array>

//We should probably make a little namespace for all of this.
//number of character
//operator overloading
//move operator
//unit tests
//Std::Vector

//Make some tests, do some of the operator overloading thingy. 
//Possible questions - Are size_t and int kinda interchangable?
//Why is my << operator not working.
//Should I use vector<char>
//At what point should I use rule of 5
//why is << a non member function
//Should operator += return mystring&
//Should I use size_t or int
//What is this about at in []?


void read(char* buf, int size)
{
    char* max_p = buf + size;

	for(char c = getchar(); c != '\n' && buf <= max_p - 1; c = getchar(), ++buf)
	{
		*buf = c;
	}
	*buf = 0;
}

class Mystring
{
private:
public:
    Mystring()
    {
        str_array[0] = '\0';
    }
    //Copy Constructor
    Mystring(const Mystring& str)
    {
        const char* str_ptr = str.str_array.data();
        int count = 0;
        for(;*str_ptr != '\0' && count <= max_length; ++str_ptr)
        {
            str_array[count] = *str_ptr;
            ++count;
        }
        str_array[count] = '\0';
    }

    Mystring(const char a[])
    {
        const char* str_ptr = a;
        int count = 0;
        for(;*str_ptr != '\0' && count <= max_length ; ++str_ptr)
        {
           str_array[count] = *str_ptr;
           ++count;
        }
         str_array[count] = '\0';
    }

    Mystring& operator=(const Mystring& a) //we're altering the lhs and not the rhs
    {

        const char* str_ptr = a.str_array.data();
        int count = 0;
        for(;*str_ptr != '\0' && count <= max_length; ++str_ptr)
        {
           str_array[count] = *str_ptr;
           ++count;
        }

        //The *this-> syntax shit is trippy.
        str_array[count] = '\0';
        return *this;
    }
    char operator[](size_t i)
    {
        return str_array[i];
    }
    bool operator==(const Mystring& add) const
    {
        //We need to have two pointers to each and literally just check/loop through each
        const char* lhs_pointer = str_array.data();
        const char* rhs_pointer = add.str_array.data();

        if (length() == add.length())
        {
            for(;*lhs_pointer != '\0' || *rhs_pointer != '\0'; ++lhs_pointer, ++rhs_pointer)
            {
                if (*lhs_pointer != *rhs_pointer )
                {
                    return false;
                }
            }
            return true;
        }
        else
        {
            return false;
        }
    }
    //std::ostream& operator<<(std::ostream& os, const Mystring str)
    {

    }
    bool operator!=(const Mystring& add) const
    {
        if (*this == add)
        {
            return false;
        }
        else
        {
            return true;
        }
    }
    Mystring operator+(const Mystring& add)
    {
        Mystring final_result;
        const char* p = str_array.data();
        char* final_pointer = final_result.str_array.data();
        for(;*p != '\0'; ++p,++final_pointer)
        {
            *final_pointer = *p;
        }

        //Now we want to add the right side.
        const char* sp = add.str_array.data();
        for(;*sp != '\0'; ++sp,++final_pointer)
        {
            *final_pointer = *sp;
        }
        
        *(final_pointer)= '\0';

        return Mystring(final_result);
    }

    Mystring operator+=(const Mystring& add)
    {
        //Now we want to add to the current *this string
        //We need to find the end of the string
        int lhs_length = length();
        //char* p = str_array.data();
        //I literally just need to add to the end of the array. FFS!!!
        
        //rhs 
        const char* sp = add.str_array.data();
        //end is where we start in the lhs string
        char* end = str_array.data();
        for( end += lhs_length; *sp != '\0'; ++end,++sp )
        {
            *end = *sp;
        }
        *end = '\0';
        return *this;

    }
    size_t length() const
    {
        //Maybe have a variable to store the size in the string?
        size_t count = 0;
        const char* p = str_array.data();
        for(;*p != '\0'; p++)
        {
            ++count;
        }
        return count;
    }
    void print()
    {
        char* p = str_array.data();
        for(;*p != '\0' ; ++p)
        {
            std::cout << *p;
        }
   }
    static constexpr int max_length{100};
    std::array<char,max_length> str_array;

};

int main()
{
    //check default initialization

    //check Copy Constructor
    Mystring a("Hello");
    Mystring b("Hello");
    //a += b; a.print();
    assert(a == b);

    std::cout << a[3];




    return 0;
}

