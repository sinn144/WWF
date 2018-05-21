#include "00_header.h"

int main()
{

    FILE* fp;
    const int DIV = 100;
    const int N   = 3;
    const int M   = 3;
    const char str[] = "D01_graph";
    
    FileOpera(fp,DIV,N,M,strlen(str),str);
    return 0;
}