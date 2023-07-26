#include <iostream>
#include <functional>
#include <string>
#include "storyline.h"
#include <ftxui/screen/color.hpp>
#include <ftxui/dom/linear_gradient.hpp>
#include <utility>
#include <string>
#include "ftxui/component/component_options.hpp"
#include "ftxui/component/component.hpp"
#include "ftxui/component/screen_interactive.hpp"
#include "ftxui/screen/screen.hpp"
#include "ftxui/dom/node.hpp" 
#include "ftxui/component/component_base.hpp"
#include "ftxui/dom/elements.hpp"
#include <vector>


using namespace ftxui;


std::string player_name() {

	std::vector<std::string> name = {
	 "Select Player Name","SM", "Clinton", "Keon", "Tariq"
	};

	int selected_0 = 0;
	int selected_1 = 1;
	int selected_2 = 2;
	int selected_3 = 3;
	int selected_4 = 4;

	// scope and render for player name input
	std::string player_names;

	Component playerinout = Input(&player_names, "Player Name Here");

	auto player_name_renderer = Renderer(playerinout, [&] {
		return vbox({
			text("Create A new Player " + player_names),
			separator(),
			hbox(text("Player Name :"), playerinout->Render()),
			}) | border;
		});
	//end scope for player input 


	//The frame layout scope
	auto top_frame = Container::Horizontal({
		Dropdown(&name, &selected_0),


		});

	auto mid_frane = Container::Horizontal({
		player_name_renderer,

		});
	auto footer_frame = Container::Horizontal({
			Button("Get Started",  story_line, ButtonOption::Animated(Color::GrayLight))
		});

	auto layout = Container::Vertical({
			top_frame | center,
			mid_frane,
			footer_frame
		});

	auto whole_frame = Renderer(layout, [&] {
		return vbox({
					top_frame->Render() | hcenter,
					mid_frane->Render(),
					footer_frame->Render() | hcenter

			}) | center;

		});

	auto screen = ScreenInteractive::Fullscreen();
	screen.Loop(whole_frame);
	return player_names;
}