#include <iostream>
#include <memory>  // for shared_ptr, __shared_ptr_access
#include <string>  // for operator+, to_string
#include "ftxui/dom/node.hpp" // for render
#include "ftxui/component/captured_mouse.hpp"  // for ftxui
#include "ftxui/component/component_options.hpp"
#include "ftxui/component/component.hpp"  // for Button, Horizontal, Renderer
#include "ftxui/component/component_base.hpp"      // for ComponentBase
#include "ftxui/component/screen_interactive.hpp"  // for ScreenInteractive
#include "ftxui/dom/elements.hpp"  // for separator, gauge, text, Element, operator|, vbox, border
#include "playername.h"
using namespace ftxui;

int start_game() {
    int value = 50;

    //containers

    auto top_frame = Container::Horizontal({


        });

    auto middle_frame = Container::Horizontal(
        {
           // Button(">>Start New Game", [&] {}, ButtonOption::Animated(Color::GreenLight)),
            Button(">>Start New Game", player_name, ButtonOption::Animated(Color::GreenLight)),

        });

    auto footer_frame = Container::Horizontal(
        {
            Button(">>Continue Saved Game", [&] {}, ButtonOption::Animated(Color::BlueLight))
        });

    auto layout = Container::Vertical({

        // top_frame,
        middle_frame | center,
        footer_frame | hcenter

        });

    // componenet to render the layout 

    auto component = Renderer(layout, [&] {
        return vbox({
            middle_frame->Render() | hcenter,
            footer_frame->Render()
            }) | center;

        });

    auto screen = ScreenInteractive::Fullscreen();
    screen.Loop(component);
    return 0;
}
