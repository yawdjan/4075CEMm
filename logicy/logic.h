#include <iostream>
#include <conio.h>
#include <vector>
#include <map>
#include <cstdlib>
#include <algorithm>
#include <stdlib.h>

// functionname_variablename is the format I will be using throughout
// I originally had the idea to change the player characters/letters each round but then I just decided to use kill index

std::string prelude = " It's almost night and everyone is securing their homes, you're feeling particularly infuriated by someone in the estate existence and you're thinking to yourself, that person should die tonight. ";

class characters
{
private:
    static int num_of_players; /*num_of_players*/
    static std::array<char, 13> letters1;

public:
    std::string chartype;
    static int advan_num;
    static int other_num;
    static int dis_num; // these three are going to be used in the child classes to separate them.

    characters(int number, int num2, int num3, int num4, std::string chartype)
    {
        /*Total number of players in the game. Will make it so advantaged and disavantaged and no trait are children to this class*/
        num_of_players = number;
        advan_num = num2;
        other_num = num3;
        dis_num = num4;
        chartype = chartype;
    }

    static int get_num_of_player()
    {
        return num_of_players;
    }

    static std::array<char, 13> get_letter_array()
    {
        return letters1;
    }
};
std::array<char, 13> characters::letters1 = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm'};
int characters::num_of_players = 0;
int characters::advan_num = 0;
int characters::other_num = 0;
int characters::dis_num =0;

class advantaged : public characters
{
private:
    static int counter; // used to help get characters from array so they follow in the right alphabetical order
    static std::map<char, std::string> advan_char;

public:
    static int i; // to help with indexing

    int players;   /*advantaged players doesn't share only*/
    char charsletter;
    std::string name; // character name
    std::vector<std::string> chars1{"The Chemist", "The Sherrif", "The IT guy", "yes ", "no "};
    advantaged(int number, int num2, int num3, int num4 ) : characters(number, num2, num3, num4, "advantaged")
    {
        if(i < num2 )
        {
        std::array<char, 13> letters{'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm'};
        advan_char[letters[i]] = chars1[i];
        name = advan_char[letters[i]];
        charsletter = letters[i];
        i++;
        counter++;
        }
    }

    static std::map<char, std::string> get_advan_char()
    {
        return advan_char;
    }

    static int get_counter()
    {
        return counter;
    }

    static void advan_remove( advantaged& thechar)
    {
        counter --;
        advan_char.erase(thechar.charsletter);
        i--;
    }

    void removename()
    {
        chars1.erase(chars1.begin()+i);
    }

    void display() // remember to remove
    {
        std::cout << charsletter << std::endl;
        std::cout << name << std::endl;
    }
};
int advantaged::i = 0;
int advantaged::counter = 0;
std::map<char, std::string> advantaged::advan_char;

class disadvantaged : public characters
{
private:
    static int counter; // used to help get characters from array so they follow in the right alphabetical order
    static std::map<char, std::string> disadvantaged_char;

public:
    static int j; // to help with indexing

    int players;   /*advantaged players only*/
    char charsletter;
    std::string name; // character name
    std::vector<std::string> chars2{"The Dementia Patient", "The Ashawo", " yh", " nah"};
    disadvantaged(int number, int num2, int num3, int num4 ) : characters(number, num2, num3, num4,"disadvantaged")
    {
        if (j< num4)
        {
        std::array<char, 13> letters{'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm'};
        disadvantaged_char[letters[j + advantaged::get_counter()]] = chars2[j];
        name = disadvantaged_char[letters[j + advantaged::get_counter()]];
        charsletter = letters[j + advantaged::get_counter()];
        j++;
        counter++;
        }
    }

    static void disadvan_remove( disadvantaged& thechar)
    {
        counter --;
        disadvantaged_char.erase(thechar.charsletter);
        j--;
    }

    void removename()
    {
        chars2.erase(chars2.begin()+j);
    }

    static std::map<char, std::string> get_disadvantaged_char()
    {
        return disadvantaged_char;
    }

    static int get_counter()
    {
        return counter;
    }

    void display() // remember to remove
    {
        std::cout << charsletter << std::endl;
        std::cout << name << std::endl;
    }
};
int disadvantaged::j = 0;
int disadvantaged::counter = 0;
std::map<char, std::string> disadvantaged::disadvantaged_char;

class notrait : public characters
{
private:
    static std::map<char, std::string> notrait_char;

public:
    static int k; // to help with indexing

    int players; /*advantaged players only doesn't share*/
    char charsletter;
    std::string name; // character name
    std::vector<std::string> chars3{"The College student", "Clinton", "Segun", "Bobby"};
    notrait(int number, int num2, int num3, int num4 ) : characters(number, num2, num3, num4, "no_trait")
    {
        if(k< num3)
        {
        std::array<char, 13> letters{'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm'};
        notrait_char[letters[k + advantaged::get_counter() + disadvantaged::get_counter()]] = chars3[k];
        name = notrait_char[letters[k + advantaged::get_counter() + disadvantaged::get_counter()]];
        charsletter = letters[k + advantaged::get_counter() + disadvantaged::get_counter()];
        k++;
        }
    }

    static void no_remove( notrait& thechar)
    {
        notrait_char.erase(thechar.charsletter);
        k--;
    }

    void removename()
    {
        chars3.erase(chars3.begin()+k);
    }

    static std::map<char, std::string> get_notrait_char()
    {
        return notrait_char;
    }

    void display() // remember to remove
    {
        std::cout << charsletter << std::endl;
        std::cout << name << std::endl;
    }
};
int notrait::k = 0;
std::map<char, std::string> notrait::notrait_char;

char get_keyboard_input() // acquires keyboard input
{
    std::cout << "Who do you want to kill???" << std::endl;
    if (_kbhit) // so is only acts when keyboard is hit
    {
        return _getch(); // to getkeyboard input
    }
    return 'z'; // else the function would be faulty but hopefully this will never run
}

int tokillnum(char tokill_letter)
{
    int tokill_num;

    if (tokill_letter >= 'a' && tokill_letter <= 'm') // check for valid letter
    {
        // to get number of players still in the game
        int players_in_game = tokill_letter - 'a';
        if (players_in_game > characters::get_num_of_player()) // to check if key pressed maps to a player that's still alive
        {
            return tokillnum(get_keyboard_input());
        }
        else
        {
            std::string tokill_chartype;
            std::string tokill_charname;
            std::array<char, 13> maptogetletters = characters::get_letter_array();

            for (int abc = 0; abc <= advantaged::get_counter() - 1; abc++)
            {
                std::map<char, std::string> maptogetdetails1 = advantaged::get_advan_char();

                if (tokill_letter == maptogetletters[abc])
                {
                    tokill_charname = maptogetdetails1[maptogetletters[abc]];
                    return abc;
                }
            }

            for (int abc = 0; abc <= disadvantaged::get_counter() - 1; abc++)
            {
                std::map<char, std::string> maptogetdetails2 = disadvantaged::get_disadvantaged_char();

                if (tokill_letter == maptogetletters[abc+5])
                {
                    tokill_charname = maptogetdetails2[maptogetletters[abc]];
                    return abc;
                }
            }

            for (int abc = 0; abc <= characters::get_num_of_player() - advantaged::get_counter() - disadvantaged::get_counter() - 1; abc++)
            {
                std::map<char, std::string> maptogetdetails3 = notrait::get_notrait_char();

                if (tokill_letter == maptogetletters[abc+9])
                {
                    tokill_charname = maptogetdetails3[maptogetletters[abc]];
                    return abc;
                }
            }

            return tokill_num; // function will be changed and edited to it's proper form dfully it is only like this to test functionality
        }
    }
    return tokillnum(get_keyboard_input());
}

std::string tokillchar(char tokill_letter)
{
    int tokill_num;
    char endletter = 'm'; 
    if (tokill_letter >= 'a' && tokill_letter <= endletter) // check for valid letter

    //also couldn't put in function to reduce this evrytime a kill is made and therefore makes it recursive
    {
        endletter --;
        // to get number of players still in the game
        int players_in_game = tokill_letter - 'a';
        if (players_in_game > characters::get_num_of_player()) // to check if key pressed maps to a player that's still alive
        {
            return tokillchar(get_keyboard_input());
        }
        else
        {
            std::string tokill_chartype;
            std::string tokill_charname;
            std::array<char, 13> maptogetletters = characters::get_letter_array();

            for (int abc = 0; abc <= advantaged::get_counter() - 1; abc++)
            {
                std::map<char, std::string> maptogetdetails1 = advantaged::get_advan_char();

                if (tokill_letter == maptogetletters[abc])
                {
                    tokill_charname = maptogetdetails1[maptogetletters[abc]];
                    return "advantaged";
                }
            }

            for (int abc = 0; abc <= disadvantaged::get_counter() - 1; abc++)
            {
                std::map<char, std::string> maptogetdetails2 = disadvantaged::get_disadvantaged_char();

                if (tokill_letter == maptogetletters[abc+5])
                {
                    tokill_charname = maptogetdetails2[maptogetletters[abc+5]];
                    return "disadvantaged";
                }
            }

            for (int abc = 0; abc <= characters::get_num_of_player() - advantaged::get_counter() - disadvantaged::get_counter() - 1; abc++)
            {
                std::map<char, std::string> maptogetdetails3 = notrait::get_notrait_char();

                if (tokill_letter == maptogetletters[abc+9])
                {
                    tokill_charname = maptogetdetails3[maptogetletters[abc+9]];
                    return "notrait";
                }
            }

            return tokill_chartype; // function will be changed and edited to it's proper form dfully it is only like this to test functionality
        }
    }
    return tokillchar(get_keyboard_input());
}

std::string what_happened(advantaged thecharacter, int whathappened_num)
{
    if (std::find(thecharacter.chars1.begin(), thecharacter.chars1.end(), thecharacter.chars1[whathappened_num]) != thecharacter.chars1.end())
    {
    thecharacter.removename();
    if (0 + (rand() % 1) == 0)
    {
    return "You killed" + thecharacter.name;
    }
    if (thecharacter.name == "The Chemist")
    {
        std::cout << thecharacter.name + " killed you with poison gas.";
    }
    if (thecharacter.name == "The Sherrif")
    {
        std::cout << +" shot you down.";
    }
    if (thecharacter.name == "The IT guy")
    {
        std::cout << thecharacter.name + " exposed you and trapped you in your own house tp later be executed.";
    }
    std::cout<< "You were killed by " + thecharacter.name;
    std::abort();
    }
    return "doesn't kill";
}

std::string what_happened(disadvantaged thecharacter, int whathappened_num)
{   
    if (std::find(thecharacter.chars2.begin(), thecharacter.chars2.end(), thecharacter.chars2[whathappened_num]) != thecharacter.chars2.end())
    {
    thecharacter.removename();
    if (0 + (rand() % 2) == 1)
    {
        return "You killed " + thecharacter.name;
    }
    if (thecharacter.name == "The Dementia Patient")
    {
        return "You killed " + thecharacter.name + " and a Caretaker";
    }
    if (thecharacter.name == "The Ashawo")
    {
        return "You killed " + thecharacter.name + "and their Client";
    }
    return "You killed 2 people";
    }
    return "doesn't kill";
}

void what_happened(notrait thecharacter, int whathappened_num)
{
    if (std::find(thecharacter.chars3.begin(), thecharacter.chars3.end(), thecharacter.chars3[whathappened_num]) != thecharacter.chars3.end())
    {
    thecharacter.removename();
    std::cout << "You Killed " + thecharacter.name;
    }
}

void nextround(int num_of_players, int advan_num, int other_num, int dis_num)
{
    if (num_of_players <= 0)
    {
        std::cout << "Game Over! No players left." << std::endl;
        return;
    }
    std::cout << "\nYou feel the urge to kill again,\n it has been a few nights since your last kill and you decided tonight will be perfect to strike again.\n There are only ";
    std::cout <<num_of_players ;
    std::cout <<" players left." << std::endl;
    std::cout << advan_num << std::endl;
    std::cout << other_num << std::endl;
    
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
    std::cout << "Congrats!! You won the game.";
}