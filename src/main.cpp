#include <main.h>
#include <Core/Engine.hpp>



int main(){
    Engine engine(600, 1000);
    engine.Start();
    engine.Terminate();
    return 0;
}