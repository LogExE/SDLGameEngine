
#include <fstream>

#include "Game.hpp"

int main(int argc, char **argv)
{
    Game game;

    std::ifstream in("netset.txt");
    {
        bool host;
        std::string ip;
        int port;
        in >> host >> ip >> port;
        game.set_net_params(host, ip, port);
    }

    game.run();

    return 0;
}