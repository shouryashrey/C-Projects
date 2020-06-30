#include <iostream>
using namespace std;
#include <unistd.h>
int main()
{
    if(fork()&& fork()) {
        fork();
    }
    if(fork()||fork()) {
    }
    printf("GATE\n");
    return 0;
}
