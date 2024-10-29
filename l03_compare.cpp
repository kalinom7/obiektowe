#include <iostream>

bool compare(const char *text1,const  char *text2)
{
    while(*text1 != '\0' && *text2 != '\0')
    {
        if(*text1 < *text2) return true;

        else if(*text1 > *text2) return false;
        text1++;
        text2++;
    }    
    if(*text1 == '\0' && *text2 != '\0') return true;
    return false;

}

int main()
{
    std::cout << std::boolalpha << compare("ez", "einstein");
    std::cout << std::endl;

    return 0;
}