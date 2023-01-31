#include <winsock2.h>
#include <winsock.h>
#include <ws2tcpip.h>
#include <stdio.h>

// #pragma comment(lib, "Ws2_32.lib") //MinGW不支持#pragma

WSADATA wsadata;
int main()
{
    int iResult;
    iResult = WSAStartup(MAKEWORD(2, 2), &wsadata);
    if (iResult != 0)
    {
        printf("WSAStartup failed: %d\n", iResult);
    }
    
    return 0;
}