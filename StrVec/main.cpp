#include "StrVec.h"
#include <iostream>

int main(void)
{
    initializer_list<string> ils{"lushiwei", "majuli", "luguoqing"};
    StrVec s1(ils);
    StrVec s2(s1);
    StrVec s3 = s2;

    s1.push_back("mahua");
    s2.push_back("majingqing");
    s3.push_back("wangjunyu");

    for (auto s1_it = s1.begin(); s1_it != s1.end(); ++s1_it) {
        cout << *s1_it << " ";
    }
    cout << endl;

    for (auto s2_it = s2.begin(); s2_it != s2.end(); ++s2_it) {
        cout << *s2_it << " ";
    }
    cout << endl;

    for (auto s3_it = s3.begin(); s3_it != s3.end(); ++s3_it) {
        cout << *s3_it << " ";
    }
    cout << endl;

    return 0;
}
