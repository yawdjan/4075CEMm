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

std::string str =
"Lorem Ipsum is simply dummy text of the printing and typesetting "
"industry. Lorem Ipsum has been the industry's standard dummy text "
"ever since the 1500s, when an unknown printer took a galley of type "
"and scrambled it to make a type specimen book.";


int story_line() {

	//killer button 
	auto killer_button = Button("You are the killer", [&] {}, ButtonOption::Animated(Color::Red));

	//STORY Line text

	auto story_line = Renderer( [&] {
		return vbox({
			window(text("StorY Line: "), paragraphAlignLeft(str)),
			// text("Te story line goes here, explanation on who the killer is th vfhebhuyfhusdvfhsdgf]")
			});
		});
	
	//next page button 

	//	Button(""

	auto top_frame = Container::Horizontal({
		killer_button | center,
	
		});
	auto middle_frame = Container::Horizontal({
		
		story_line
		});

	auto footer_frame = Container::Horizontal({
		Button("Get Started",  [&] {}, ButtonOption::Animated(Color::GrayLight))

		});

	auto layout = Container::Vertical({
		top_frame,
		middle_frame,
		footer_frame
		// footer_frame

		});
	auto component = Renderer(layout, [&] {
		return vbox({
			top_frame->Render() | hcenter,
			middle_frame->Render() | align_right,
			footer_frame ->Render() |hcenter
			}) | center;
		});

	auto screen = ScreenInteractive::Fullscreen();
	screen.Loop(component);
	return 0;
}
