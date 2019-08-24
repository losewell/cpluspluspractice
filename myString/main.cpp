#include "myString.h"
#include <iostream>

int main(void)
{
    myString str_1("lushiwei");
    myString str_2("majuli");
    myString str_3("luguoqingkjhklh");

    myString tmp_1(str_1);
    myString tmp_2 = str_2;
    myString tmp_3(str_3);

    str_1.printstr();
    str_2.printstr();
    str_3.printstr();

    tmp_1.printstr();
    tmp_2.printstr();
    tmp_3.printstr();

    myString s1 = str_1.mycpy(str_2);
    myString s2 = str_2.mycat(str_2.mycpy(str_3));

    s1.printstr();
    s2.printstr();

    return 0;
}
