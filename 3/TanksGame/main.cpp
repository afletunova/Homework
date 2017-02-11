#include <iostream>
#include <string>

#include "vendor/easylogging++.h"
#include "Game.h"
#include "ServerNetworkManager.h"
#include "ClientNetworkManager.h"
using namespace std;

INITIALIZE_EASYLOGGINGPP

int main()
{
    LOG(INFO) << "My first info log using default logger";

    int input = 0;
    cout << "Enter 1 to choose Server or 2 to choose Client: " << endl;
    cin >> input;

    while (input != 0 && input != 1 && input != 2)
    {
        cout << "Please, try again or enter 0 to Exit" << endl;
        cin >> input;
    }

    Game *game;

    if (input == 0)
        return 0;
    else
    {
        if (input == 1)
        {
            int port = 0;
            cout << "Enter port: " << endl;
//            cin >> port;
            port = 4000;
            cout << "Waiting for a client connection" << endl;

            ServerNetworkManager *networkManager = new ServerNetworkManager;
            networkManager->start(port);
            game = new Game(networkManager, true);
        } else if (input == 2)
        {
            string serverIP;
            int port = 0;
            cout << "Enter server IP: " << endl;
//            cin >> serverIP;
            serverIP = "127.0.0.1";
            cout << "Enter port: " << endl;
//            cin >> port;
            port = 4000;
            ClientNetworkManager *networkManager = new ClientNetworkManager;
            if (networkManager->connect(serverIP, port))
            {
                cout << "Connected" << endl;
                game = new Game(networkManager, false);
            }
            else
            {
                cout << "Could not connect to server" << endl;
                delete networkManager;
                return 1;
            }
        }
        game->start();
    }
    return 0;
}