#include <cstdlib>
#include <iostream>

char *insert(char *text1, int index, const char *text2)
{
    size_t length1 = 0;
    while (*(text1+length1)!= '\0') {
        length1++;
    }
    size_t length2 = 0;
     
     while(*(text2+length2) != '\0'){
        length2++;
     }
     size_t final_length = length1 + length2;

     text1 = (char*)std::realloc(text1, (final_length+1)*sizeof(char));

     for (size_t i = length1; i > index; i--) {
        *(text1 +i + length2 -1) = *(text1+i-1);
    }

    for (size_t i = 0; i < length2; i++) {
        *(text1 + index + i) = *(text2 + i);
    }
    return text1;

}





int main() {
char *string = (char*)std::calloc(1, sizeof(char));

string = insert(string, 0, "diary");
string = insert(string, 2, "ction");
std::cout << string << std::endl;
std::free(string);

return 0;
}
