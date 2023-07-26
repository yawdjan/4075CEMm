#include "startgamebutton.h"
#include <memory>  // for shared_ptr, __shared_ptr_access
#include <string>  // for operator+, to_string
#include "ftxui/dom/node.hpp" // for render
#include "ftxui/component/captured_mouse.hpp"  // for ftxui
#include "ftxui/component/component.hpp"  // for Button, Horizontal, Renderer
#include "ftxui/component/component_base.hpp"      // for ComponentBase
#include "ftxui/component/screen_interactive.hpp"  // for ScreenInteractive
#include "ftxui/dom/elements.hpp"  // for separator, gauge, text, Element, operator|, vbox, border

using namespace ftxui;



int main() {

    std::string label;

    // auto button = Button("Start Game", start_game );
    
    auto text_renderer = Renderer([] {
        return text("Welcome to death row Game") | color(Color::Red) | bold;
        });

    auto topFrame = Container::Horizontal(
        {
           text_renderer 
            //Button("aaaa", [&] {})
        }
    );
   // std::string start_game(); {
    //    auto name = text_renderer;
     //   name = Renderer([] {
     //       return text("Death row game name changed");
    //        });
   // }; 

    auto middleFrame = Container::Horizontal(
        {
            Button("Start Game", start_game)
        }
    );

    auto baseFrame = Container::Horizontal(
        {
           Button("ccc", [&] {}),
             Button("ddd", [&] {})
        }
    );

    auto layout = Container::Vertical(
        {
            topFrame,
            middleFrame | hcenter ,
            baseFrame
        });
    auto component = Renderer(layout, [&] {
        return vbox({
                topFrame->Render() | center,
                // separator(),
                middleFrame->Render() | hcenter,
                //separator(),
                // baseFrame->Render(),
            }) | center;
        });
    

    auto screen = ScreenInteractive::Fullscreen();
    screen.Loop(component);
    return 0;
}