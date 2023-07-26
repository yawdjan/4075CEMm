#include <ftxui/dom/elements.hpp>
#include <ftxui/screen/screen.hpp>
#include <iostream>



int wlcomescreen(void) {
    //using fxtui namespace
    using namespace ftxui;

    //Define Element 
    Element document =
        vbox({
              text("the game") | bold | color(Color::Blue)
            });
        

    //create a screen
    int width = 800;
    int height = 500;

    auto screen =  Screen::Create(Dimension::Fixed(width), Dimension::Fixed(height));
    
    Render(screen, document);

    screen.Print();

    return EXIT_SUCCESS;
}