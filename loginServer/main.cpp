#include "LoginServer.h"

LoginServer gServer;

int main(void) {
    gServer.init();
    bool active = true;
    do {
        active = gServer.onTick();
    } while (active == true);
}