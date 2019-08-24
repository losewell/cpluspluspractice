#ifndef MYSTRING_H_INCLUDED
#define MYSTRING_H_INCLUDED

#include <string>
#include <utility>
#include <memory>

using namespace std;

class myString {
public:
    myString(): start(nullptr), last(nullptr), cap(nullptr) { }
    myString(const char *);
    myString(const myString& );
    ~myString();

    size_t size() const { return last - start; }
    size_t capacity() const { return cap - start; }
    char *begin() const { return start; }
    char *end()   const { return last; }

    char& operator[](size_t n) { return *(start + n); }
    const char& operator[](size_t n) const { return *(start + n); }
    myString& operator=(const myString& );

    myString& mycpy(const myString& );
    myString& mycat(const myString& );

    void printstr();
private:
    static allocator<char> alloc_str;
    void chk_cat_alloc(const myString& );
    void chk_cpy_alloc(const myString& );
    pair<char*, char*> alloc_n_copy(const char*, const char* );
    void free();
    void reallocate(size_t n);
    char *start;
    char *last;
    char *cap;
};

#endif // MYSTRING_H_INCLUDED
