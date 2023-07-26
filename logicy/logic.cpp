// This file is to outline the main logic of the game and is what would link to the graphics files.

#include <iostream>
#include <array>
#include "logic.h"

int main()
{
    int num_of_players; /* number of players in the game */
    std::cin >> num_of_players;
    if (num_of_players < 7)
    {
        num_of_players = 7;
    }
    else if (num_of_players > 13)
    {
        num_of_players = 13;
    }

    float advan_num = 0.385 * num_of_players;
    float other_num = 0.308 * num_of_players;
    std::cout << advan_num << std::endl;
    std::cout << other_num << std::endl;

    // for the player
    std::string story, story_cont, objective, note;
    story = "A new estate was created two months ago and " + num_of_players;
    story_cont = " moved in 2 weeks after. It has been two months since the last tenants moving in and there has been a killing every 2 weeks. The tenants are not allowed to move out till the killer is found and no one wants to move in because of the killings, You are the killer. ";
    objective = " objective - target all the people in the estate";
    note = " note - most of the residents in the estate have ways to defend themselves.";
    /*we could use this format to output cout << story << story_cont << endl;
    cout << "\n\n" << objective << "\n" << note << endl;  */

    // after running tokill(no) subtract no from 1

    if (num_of_players >= 12) // to call instances according to how many players exist
    {
        advantaged advan_five(num_of_players, advan_num, other_num);
        advan_five.display();

        advantaged advan_four(num_of_players, advan_num, other_num);
        advan_four.display();

        advantaged advan_three(num_of_players, advan_num, other_num);
        advan_three.display();

        advantaged advan_two(num_of_players, advan_num, other_num);
        advan_two.display();

        advantaged advan_one(num_of_players, advan_num, other_num);
        advan_one.display();
    }
    else if (num_of_players >= 10)
    {
        advantaged advan_four(num_of_players, advan_num, other_num);
        advan_four.display();

        advantaged advan_three(num_of_players, advan_num, other_num);
        advan_three.display();

        advantaged advan_two(num_of_players, advan_num, other_num);
        advan_two.display();

        advantaged advan_one(num_of_players, advan_num, other_num);
        advan_one.display();
    }
    else
    {
        advantaged advan_three(num_of_players, advan_num, other_num);
        advan_three.display();

        advantaged advan_two(num_of_players, advan_num, other_num);
        advan_two.display();

        advantaged advan_one(num_of_players, advan_num, other_num);
        advan_one.display();
    }

    if (num_of_players >= 12)
    {
        disadvantaged disadvan_one(num_of_players, advan_num, other_num);
        disadvan_one.display();

        disadvantaged disadvan_two(num_of_players, advan_num, other_num);
        disadvan_two.display();

        disadvantaged disadvan_three(num_of_players, advan_num, other_num);
        disadvan_three.display();

        disadvantaged disadvan_four(num_of_players, advan_num, other_num);
        disadvan_four.display();
    }
    else if (num_of_players >= 9)
    {
        disadvantaged disadvan_one(num_of_players, advan_num, other_num);
        disadvan_one.display();

        disadvantaged disadvan_two(num_of_players, advan_num, other_num);
        disadvan_two.display();

        disadvantaged disadvan_three(num_of_players, advan_num, other_num);
        disadvan_three.display();
    }
    else
    {
        disadvantaged disadvan_one(num_of_players, advan_num, other_num);
        disadvan_one.display();

        disadvantaged disadvan_two(num_of_players, advan_num, other_num);
        disadvan_two.display();
    }

    if (num_of_players == 13 || num_of_players == 11)
    {
        notrait notrait_one(num_of_players, advan_num, other_num);
        notrait_one.display();

        notrait notrait_two(num_of_players, advan_num, other_num);
        notrait_two.display();

        notrait notrait_three(num_of_players, advan_num, other_num);
        notrait_three.display();

        notrait notrait_four(num_of_players, advan_num, other_num);
        notrait_four.display();
    }
    else if (num_of_players == 12 || num_of_players == 10 || num_of_players == 8)
    {
        notrait notrait_one(num_of_players, advan_num, other_num);
        notrait_one.display();

        notrait notrait_two(num_of_players, advan_num, other_num);
        notrait_two.display();

        notrait notrait_three(num_of_players, advan_num, other_num);
        notrait_three.display();
    }
    else
    {
        notrait notrait_one(num_of_players, advan_num, other_num);
        notrait_one.display();

        notrait notrait_two(num_of_players, advan_num, other_num);
        notrait_two.display();
    }
    // I do not remember why I did advanatged the other way round was probably experimenting a way to make my code shorter and more efficient and it didn't work going to leave it that way in case I later get another idea

    //next call kill function and in kill function ther will be another function which starts everything again or you can choose to separate the function.

    return 0;
}