#include <stdio.h>
#include <arpa/inet.h>
#include <string.h>

int main(void){
    struct in_addr addr1, addr2, addr3;
    char *str;
    char buf1[20], buf2[20], buf3[20];

    addr1.s_addr = htonl(0x1020304);
    addr2.s_addr = htonl(0xc0a80101);
    addr3.s_addr = htonl(0xffffffff);

    str = inet_ntoa(addr1);
    memcpy(buf1, str, strlen(str));

    strcpy(buf2, inet_ntoa(addr2));

    strcpy(buf3, inet_ntoa(addr3));

    printf("%#lx -> %s \n", (long)addr1.s_addr, buf1);
    printf("%#lx -> %s \n", (long)addr2.s_addr, buf2);
    printf("%#lx -> %s \n", (long)addr3.s_addr, buf2);

    return 0;
}
