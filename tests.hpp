#include "pone.cpp"
#include <cassert>
void test_default()
{
	Mystring str;
    assert(str.length() == 0);
}
void test_con()
{
    Mystring str("Hello");
    assert(str.length() == 5);
    assert(str[0] == 'H');
    assert(str[4] == 'o');
}
void test_assignment()
{
    Mystring a("Hello");
    Mystring b("World");
    b = a;
    assert(b == a);
    assert(b == Mystring("Hello"));
}
void test_equality()
{
    Mystring a("Hello");
    Mystring b("Hello");
    Mystring c("World");
    assert(a == b);
    assert(a != c);
}

void test_index()
{
    Mystring str("Hello");
    assert(str[0] == 'H');
}

void test_plus()
{
    Mystring a("Hello");
    Mystring b(" World");

    Mystring result = a + b;

    assert(result == Mystring("Hello World"));

}

void test_plus_equals()
{
    Mystring a("Hello");
    Mystring b(" World");

    a += b;

    assert(a == Mystring("Hello World"));
}

void test_all()
{
    test_default();
    test_con();
    test_equality();
    test_index_operator();
    test_plus();
    test_plus_equals();
}
