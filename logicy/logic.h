#include <iostream>
#include <conio.h>
#include <vector>
#include <map>
#include <cstdlib>
#include <typeinfo>

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
    float advan_num;
    float other_num; // these two are going to be used in the child classes to separate them.

    characters(int number, float num2, float num3, std::string chartype)
    {
        /*Total number of players in the game. Will make it so advantaged and disavantaged and no trait are children to this class*/
        num_of_players = number;
        advan_num = num2;
        other_num = num3;
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

    ~characters()
    {
        num_of_players--;
    }
};
std::array<char, 13> characters::letters1 = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm'};
int characters::num_of_players = 0;

class advantaged : public characters
{
private:
    static int counter; // used to help get characters from array so they follow in the right alphabetical order
    static std::map<char, std::string> advan_char;
    std::array<std::string, 5> chars1{"The Chemist", "The Sherrif", "The IT guy", "yes ", "no "};

public:
    static int i; // to help with indexing

    int players;   /*advantaged players doesn't share only*/
    int killindex; // this number will determine whether the player or the killer gets killed 1 and 0 respectively
    char charsletter;
    std::string name; // character name
    advantaged(int number, float num2, float num3) : characters(number, num2, num3, "advantaged")
    {
        std::array<char, 13> letters{'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm'};
        advan_char[letters[i]] = chars1[i];
        name = advan_char[letters[i]];
        charsletter = letters[i];
        killindex = (rand() % 1);
        i++;
        counter++;
    }

    static std::map<char, std::string> get_advan_char()
    {
        return advan_char;
    }

    static int get_counter()
    {
        return counter;
    }

    std::string what_happened()
    {
        if (killindex == 0)
            return "You killed " + name;
        if (name == "The Chemist")
            return name + " killed you with poison gas.";
        if (name == "The Sherrif")
            return name + " shot you down.";
        if (name == "The IT guy")
            return name + " exposed you and trapped you in your own house tp later be executed.";
        return "You were killed!!!";
    }

    void display() // remember to remove
    {
        std::cout << charsletter << std::endl;
        std::cout << name << std::endl;
    }

    /*~advantaged()
    {
        characters::~characters();
        i--;
    }*/
};
int advantaged::i = 0;
int advantaged::counter = 0;
std::map<char, std::string> advantaged::advan_char;

class disadvantaged : public characters
{
private:
    static int counter; // used to help get characters from array so they follow in the right alphabetical order
    static std::map<char, std::string> disadvantaged_char;
    std::array<std::string, 4> chars2{"The Dementia Patient", "The Ashawo", " yh", " nah"};

public:
    static int j; // to help with indexing

    int players;   /*advantaged players only*/
    int killindex; // to decide whether just this character or this character and another character gets killed when chosen 1 and 2 respectively
    char charsletter;
    std::string name; // character name
    disadvantaged(int number, float num2, float num3) : characters(number, num2, num3, "disadvantaged")
    {
        std::array<char, 13> letters{'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm'};
        disadvantaged_char[letters[j + advantaged::get_counter()]] = chars2[j];
        name = disadvantaged_char[letters[j + advantaged::get_counter()]];
        charsletter = letters[j + advantaged::get_counter()];
        killindex = 1 + (rand() % 2);
        j++;
        counter++;
    }

    static std::map<char, std::string> get_disadvantaged_char()
    {
        return disadvantaged_char;
    }

    static int get_counter()
    {
        return counter;
    }

    std::string what_happened()
    {
        if (killindex == 1)
            return "You killed " + name;
        if (name == "The Dementia Patient")
            return "You killed " + name + " and a Caretaker";
        if (name == "The Ashawo")
            return "You killed " + name + "and their Client";
        return "You killed 2 people";
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
    std::array<std::string, 4> chars3{"The College student", "Clinton", "Segun", "Bobby"};

public:
    static int k; // to help with indexing

    int players; /*advantaged players only doesn't share*/
    char charsletter;
    std::string name; // character name
    notrait(int number, float num2, float num3) : characters(number, num2, num3, "no_trait")
    {
        std::array<char, 13> letters{'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm'};
        notrait_char[letters[k + advantaged::get_counter() + disadvantaged::get_counter()]] = chars3[k];
        name = notrait_char[letters[k + advantaged::get_counter() + disadvantaged::get_counter()]];
        charsletter = letters[k + advantaged::get_counter() + disadvantaged::get_counter()];
        k++;
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

// function to kill gets who to kill, the actual function that kills will be put within the various classes
char get_keyboard_input() // acquires keyboard input
{
    if (_kbhit) // so is only acts when keyboard is hit
    {
        return _getch(); // to getkeyboard input
    }
    return 'z'; // else the function would be faulty but hopefully this will never run
}

char tokill()
{
    std::cout << "Who do you want to kill???" << std::endl;
    char tokill_letter = get_keyboard_input();

    if (tokill_letter >= 'a' && tokill_letter <= 'm') // check for valid letter
    {
        // to get number of players still in the game
        int players_in_game = tokill_letter - 'a';
        if (players_in_game > characters::get_num_of_player()) // to check if key pressed maps to a player that's still alive
        {
            return tokill();
        }
        else
        {
            int tokill_num;
            std::string tokill_chartype;
            std::string tokill_charname;
            std::array<char, 13> maptogetletters = characters::get_letter_array();

            for (int abc = 0; abc < advantaged::get_counter() - 1; abc++)
            {
                std::map<char, std::string> maptogetdetails1 = advantaged::get_advan_char();

                if (tokill_letter == maptogetletters[abc])
                {
                    tokill_charname = maptogetdetails1[maptogetletters[abc]];
                    tokill_chartype = "advantaged";
                    tokill_num = abc;
                }
            }

            for (int abc = 0; abc < disadvantaged::get_counter() - 1; abc++)
            {
                std::map<char, std::string> maptogetdetails2 = disadvantaged::get_disadvantaged_char();

                if (tokill_letter == maptogetletters[abc])
                {
                    tokill_charname = maptogetdetails2[maptogetletters[abc]];
                    tokill_chartype = "disadvantaged";
                    tokill_num = abc;
                }
            }

            for (int abc = 0; abc < characters::get_num_of_player() - advantaged::get_counter() - disadvantaged::get_counter() - 1; abc++)
            {
                std::map<char, std::string> maptogetdetails3 = notrait::get_notrait_char();

                if (tokill_letter == maptogetletters[abc])
                {
                    tokill_charname = maptogetdetails3[maptogetletters[abc]];
                    tokill_chartype = "notrait";
                    tokill_num = abc;
                }
            }

            if (tokill_chartype == "advantaged")
            {
                if (tokill_num == 1)
                {
                    // code is supposed to retun what happened and also supposed to return kill index
                }
            }
            if (tokill_chartype == "disadvantaged")
            {
            }
            if (tokill_chartype == "notrait")
            {
            }

            return 'z'; // function will be changed and edited to it's proper form dfully it is only like this to test functionality
        }
    }
    return tokill();
}
