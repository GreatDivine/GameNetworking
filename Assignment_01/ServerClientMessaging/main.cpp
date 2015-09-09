#include <stdio.h>
#include "RakPeerInterface.h"
#include <iostream>
#include <string>

#define MAX_CLIENTS 10
#define SERVER_PORT 60000

int main()
{
	//std::string str = "";
	//RakNet::RakPeerInterface *peer = RakNet::RakPeerInterface::GetInstance();
	//bool isServer;

	//std::cout << "(C)lient or (S)erver?" << std::endl;
	//std::getline(std::cin, str);

	//if ((str[0] == 'c') || (str[0] == 'C'))
	//{
	//	RakNet::SocketDescriptor sd;
	//	peer->Startup(1, &sd, 1);
	//	isServer = false;
	//}

	//else
	//{
	//	RakNet::SocketDescriptor sd(SERVER_PORT, 0);
	//	peer->Startup(MAX_CLIENTS, &sd, 1);
	//	isServer = true;
	//}

	//RakNet::RakPeerInterface::DestroyInstance(peer);

	return 0;
}