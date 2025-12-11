#include <main.h>
#include <Core/Engine.hpp>
#include <Tests/Tests.hpp>
#include <assert.h>

void tests();

int main(){
    tests();
    Engine engine(600, 1000);
    engine.Start();
    engine.Terminate();
    return 0;
}