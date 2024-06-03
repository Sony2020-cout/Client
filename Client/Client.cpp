#include <iostream>
#pragma comment(lib, "ws2_32.lib")
#include <WinSock2.h>
#pragma warning(disable: 4996)

using namespace std;

int main() {

	WSAData wsaData;
	WORD DLLVersion = MAKEWORD(2, 1);//запрашиваемая версия библиотеки winsock
	if (WSAStartup(DLLVersion, &wsaData) != 0) {
		cout << "Error" << endl;
		exit(1);
	}

	SOCKADDR_IN addr;
	int sizeOfAddr = sizeof(addr);
	addr.sin_addr.s_addr = inet_addr("127.0.0.1");
	addr.sin_port = htons(1111);
	addr.sin_family = AF_INET;

	SOCKET connection = socket(AF_INET, SOCK_STREAM,NULL);
	if (connect(connection, (SOCKADDR*)&addr, sizeof(addr)) != 0) {
		cout << "Error: failed connect to server.\n";
		return 1;
	}
	cout << "Connected!\n";


	system("pause");
	return 0;

}