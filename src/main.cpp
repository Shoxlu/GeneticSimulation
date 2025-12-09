#include <main.h>
#include <Graphic/Window/Window.h>
#include <Utils/Error/error.h>

int main(){
    printf("Hello world\n");
    Window window(600, 1000, nullptr, nullptr);
    window.SetTitle("Genetic Simulation");
    while (!window.WindowClosed())
    {
        window.UpdateTest();
    }
    window.TermintateWindow();

    return 0;
}