#include <iostream>
#include <cstdlib>

int main(int argc, char *argv[]){

    if(argc != 2)
    {
        return -1;
    }
    int number = std::stoi(argv[1]);



    bool *primary = (bool*)std::malloc((number+1)* sizeof(bool));
    for(int a = 0; a<=number ; a++)
    {
        *(primary + a) = true;
    }
    *primary = 0;
    *(primary + 1) = 0;
    for(int a = 2 ; a*a <= number; a++)
    {
        if(*(primary+a) == true)
        {
             for(int b = a * a ; b<=number ; b = b + a)
             {
                *(primary+b) = false;
             }
        }
       
    }
    
    for(int i = 0; i<=number; i++)
    {
        if(*(primary + i)==true)
        {
            std::cout<<i<<" ";
        }
    }
    std::free(primary);
    
    
    
    return 0;
}