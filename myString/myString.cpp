#include "myString.h"
#include <cstring>
#include <iostream>


allocator<char> myString::alloc_str;

myString::myString(const char *s)
{
    auto newstr = alloc_n_copy(s, s + strlen(s));
    start = newstr.first;
    last = cap = newstr.second;
}

myString::myString(const myString &str)
{
    auto newstr = alloc_n_copy(str.begin(), str.end());
    start = newstr.first;
    last = cap = newstr.second;
}

myString::~myString() { free(); }

myString&
myString::operator=(const myString &str)
{
    auto tmpstr = alloc_n_copy(str.begin(), str.end());
    free();
    start = tmpstr.first;
    last = cap = tmpstr.second;
    return *this;
}

pair<char*, char*>
myString::alloc_n_copy(const char *b, const char *e)
{
    auto data = alloc_str.allocate(e - b);

    auto i = data;
    for (auto p = b; p != e; ++p)
        alloc_str.construct(i++, *p);

    return {data, i};
}

myString&
myString::mycat(const myString &str)
{
    chk_cat_alloc(str);

    uninitialized_copy(str.begin(), str.end(), last);
    return *this;
}

myString&
myString::mycpy(const myString& str)
{
    chk_cpy_alloc(str);

    uninitialized_copy(str.begin(), str.end(), begin());
    return *this;
}

void myString::chk_cat_alloc(const myString &str)
{
    if ( size() + str.size() >= capacity())
        reallocate(size() + str.size());
}

void myString::chk_cpy_alloc(const myString &str)
{
    if (size() <= str.size())
        reallocate(str.size());
}

void myString::free()
{
    if (start) {
        for (auto p = last; p != start;)
            alloc_str.destroy(--p);

        alloc_str.deallocate(start, cap - start);
    }
}

void myString::printstr()
{
    for (auto p = start; p != last; ++p) {
        std::cout << *p;
    }
    std::cout << std::endl;
}

void myString::reallocate(size_t n)
{
    auto newcapacity = n ? 2 * n : 1;

    auto newdata = alloc_str.allocate(newcapacity);

    auto dest = newdata;
    auto st = start;
    for (size_t i = 0; i != size(); ++i)
        alloc_str.construct(dest++, std::move(*st++));

    free();

    start = newdata;
    last = dest;
    cap = start + newcapacity;
}
