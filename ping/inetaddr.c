#include <stdio.h>
#include <arpa/inet.h>

int main(void){
    char *addr1 = "1.2.3.4";
    char *addr2 = "192.168.1.1";
    char *addr3 = "255.255.255.255";
    in_addr_t data;

    data = inet_addr(addr1);
    printf(" %s -> %#lx \n", addr1, (long)data);

    data = inet_addr(addr2);
    printf(" %s -> %#lx \n", addr2, (long)data);

    data = inet_addr(addr3);
    printf(" %s -> %#lx \n", addr3, (long)data);

    return 0;
}
