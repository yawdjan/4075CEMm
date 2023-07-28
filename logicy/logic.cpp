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

    int other_num = 0;
    int advan_num = 0;
    int dis_num = 0;

    if (num_of_players == 13)
    {
        other_num = 4;
    }
    if (num_of_players == 11)
    {
        other_num = 4;
    }
    if (num_of_players == 12)
    {
        other_num = 3;
    }
    if (num_of_players == 10)
    {
        other_num = 3;
    }
    if (num_of_players == 8)
    {
        other_num = 3;
    }
    if (num_of_players == 7)
    {
        other_num = 2;
    }

    if (num_of_players >= 9)
    {
        dis_num = 3;
        if (num_of_players >= 10)
        {
            advan_num = 4;
            if (num_of_players >= 12)
            {
                advan_num = 5;
                dis_num = 4;
            }
        }
    }
    else
    {
        advan_num = 3;
        dis_num = 2;
    }

    advantaged aone(num_of_players, advan_num, other_num, dis_num);

    advantaged atwo(num_of_players, advan_num, other_num, dis_num);

    advantaged athree(num_of_players, advan_num, other_num, dis_num);

    advantaged afour(num_of_players, advan_num, other_num, dis_num);

    advantaged afive(num_of_players, advan_num, other_num, dis_num);

    disadvantaged done(num_of_players, advan_num, other_num, dis_num);

    disadvantaged dtwo(num_of_players, advan_num, other_num, dis_num);

    disadvantaged dthree(num_of_players, advan_num, other_num, dis_num);

    disadvantaged dfour(num_of_players, advan_num, other_num, dis_num);

    notrait one(num_of_players, advan_num, other_num, dis_num);

    notrait two(num_of_players, advan_num, other_num, dis_num);

    notrait three(num_of_players, advan_num, other_num, dis_num);

    notrait four(num_of_players, advan_num, other_num, dis_num);

    std::cout << advan_num << std::endl;
    std::cout << other_num << std::endl;
    std::cout << dis_num << std::endl;

    // for the player
    std::string story, story_cont, objective, note;
    story = "A new estate was created two months ago and " + num_of_players;
    story_cont = " moved in 2 weeks after. It has been two months since the last tenants moving in and there has been a killing every 2 weeks. The tenants are not allowed to move out till the killer is found and no one wants to move in because of the killings, You are the killer. ";
    objective = " objective - target all the people in the estate";
    note = " note - most of the residents in the estate have ways to defend themselves.";
    /*we display this is  hte window and use the gui as a skin for this logic  */

    // after running tokill(no) subtract no from 1

    // I do not remember why I did advanatged the other way round was probably experimenting a way to make my code shorter and more efficient and it didn't work going to leave it that way in case I later get another idea

    char tokill_letter = get_keyboard_input();
    std::cout << tokillchar(tokill_letter) << std::endl;
    std::cout << tokillnum(tokill_letter) << std::endl;
    std::cout << tokill_letter << std::endl;
    if (tokillchar(tokill_letter) == "advantaged")
    {
        num_of_players --;
        advan_num --;
        if (tokillnum(tokill_letter) == 0)
        {
            what_happened(aone,0);
            aone.removename();
        }
        if (tokillnum(tokill_letter) == 1)
        {
            what_happened(atwo,1);
            atwo.removename();
        }
        if (tokillnum(tokill_letter) == 2)
        {
            what_happened(athree,2);
            athree.removename();
        }
        if (tokillnum(tokill_letter) == 3)
        {
            what_happened(afour,3);
            afour.removename();
        }
        if (tokillnum(tokill_letter) == 4)
        {
            what_happened(afive,4);
            afive.removename();
        }
    }
    if (tokillchar(tokill_letter) == "disadvantaged")
    {
        num_of_players--;
        dis_num --;
        if (tokillnum(tokill_letter) == 0)
        {
            what_happened(done,0);
            done.removename();
        }
        if (tokillnum(tokill_letter) == 1)
        {
            what_happened(dtwo,1);
            dtwo.removename();
        }
        if (tokillnum(tokill_letter) == 2)
        {
            what_happened(dthree,2);
            dthree.removename();
        }
        if (tokillnum(tokill_letter) == 3)
        {
            what_happened(dfour,3);
            dfour.removename();
        }
    }
    if (tokillchar(tokill_letter) == "notrait")
    {
        num_of_players --;
        other_num --;
        if (tokillnum(tokill_letter) == 0)
        {
            //initial plan was to make it kill two people here but my implementation wasn't succesful.
            what_happened(one,0);
            one.removename();
            one.display();
        }
        if (tokillnum(tokill_letter) == 1)
        {
            what_happened(two,1);
            two.removename();
            two.display();
        }
        if (tokillnum(tokill_letter) == 2)
        {
            what_happened(three,2);
            three.removename();
            three.display();
        }
        if (tokillnum(tokill_letter) == 3)
        {
            what_happened(four,3);
            four.removename();
            four.display();
        }
    }

    advantaged::advan_remove(aone);
    advantaged::advan_remove(atwo);
    advantaged::advan_remove(athree);
    advantaged::advan_remove(afour);
    advantaged::advan_remove(afive);

    disadvantaged::disadvan_remove(done);
    disadvantaged::disadvan_remove(dtwo);
    disadvantaged::disadvan_remove(dthree);
    disadvantaged::disadvan_remove(dfour);

    notrait::no_remove(one);
    notrait::no_remove(two);
    notrait::no_remove(three);
    notrait::no_remove(four);

    if (num_of_players > 1)
    {
        nextround(num_of_players, advan_num, other_num, dis_num);
    }
    return 0;
}