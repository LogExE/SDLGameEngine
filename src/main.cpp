
#include <fstream>

#include "Game.hpp"

int main(int argc, char **argv)
{
    Game game;

    // считывание параметров подключения сети
    {
        std::ifstream in("netset.txt");
        std::string ip;
        int port;
        in >> ip >> port;
        game.set_net_params(ip, port);
    }

    game.run();

    return 0;
}