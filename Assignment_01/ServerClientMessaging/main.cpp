#include <stdio.h>
#include <iostream>
#include <string>

#include "RakPeerInterface.h"
#include "MessageIdentifiers.h"

#define MAX_CLIENTS 10
#define SERVER_PORT 60000

int main()
{
	std::string str = "";
	RakNet::RakPeerInterface *peer = RakNet::RakPeerInterface::GetInstance();
	bool isServer;
	RakNet::Packet *packet;

	std::cout << "(C)lient or (S)erver?" << std::endl;
	std::getline(std::cin, str);

	if ((str[0] == 'c') || (str[0] == 'C'))
	{
		RakNet::SocketDescriptor sd;
		peer->Startup(1, &sd, 1);
		isServer = false;
	}

	else
	{
		RakNet::SocketDescriptor sd(SERVER_PORT, 0);
		peer->Startup(MAX_CLIENTS, &sd, 1);
		isServer = true;
	}

	if (isServer)
	{
		std::cout << "Starting the server." << std::endl;
		peer->SetMaximumIncomingConnections(MAX_CLIENTS);
	}
	else
	{
		std::cout << "Enter server IP or hit enter for default: 127.0.0.1" << std::endl;
		std::getline(std::cin, str);
		if (str == "")
		{
			str = "127.0.0.1";
		}

		std::cout << "Starting the client." << std::endl;
		peer->Connect(str.c_str(), SERVER_PORT, 0, 0);
	}

	while (1)
	{
		for (packet = peer->Receive(); packet; peer->DeallocatePacket(packet), packet = peer->Receive())
		{
			switch (packet->data[0])
			{
			case ID_REMOTE_DISCONNECTION_NOTIFICATION:
				std::cout << "Another client has dosconnected" << std::endl;
				break;
			case ID_REMOTE_CONNECTION_LOST:
				std::cout << "Another client has lost the connection" << std::endl;
				break;
			case ID_REMOTE_NEW_INCOMING_CONNECTION:
				std::cout << "Another client has connected" << std::endl;
				break;
			case ID_CONNECTION_REQUEST_ACCEPTED:
				std::cout << "Our connection request has been accepted." << std::endl;
				break;
			case ID_NEW_INCOMING_CONNECTION:
				std::cout << "A connection is incoming." << std::endl;
				break;
			case ID_NO_FREE_INCOMING_CONNECTIONS:
				std::cout << "The server is full." << std::endl;
				break;
			case ID_DISCONNECTION_NOTIFICATION:
				if (isServer)
				{
					std::cout << "A client has disconnected." << std::endl;
				}
				else 
				{
					std::cout << "We have been disconnected." << std::endl;
				}
				break;
			default:
				printf("Message with identifier %i has arrived. \n", packet->data[0]);
				break;
			}
		}
	}

	RakNet::RakPeerInterface::DestroyInstance(peer);

	return 0;
}