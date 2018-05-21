#include "00_header.h"

int main()
{

    FILE* fp;
    const int DIV = 1000;
    const int N   = 2;
    const char str[] = "D01_graph1";
    
    FileOpera(fp,DIV,N,strlen(str),str);
    return 0;
}