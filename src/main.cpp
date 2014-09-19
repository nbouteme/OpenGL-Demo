#include <Application.hpp>

int main(int argc, char *argv[])
{
    (void) argc;
    (void) argv;
    Application::getSingleton()->run();
    return 0;
}
