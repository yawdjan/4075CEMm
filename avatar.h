#include <iostream>
#pragma once
using namespace std;

class Avatar
{
public:
    Image character;
    Texture2D characters;
    int characterWidth;
    int characterHeight;
    int screenHeight;
    int screenWidth;
    int posx;
    int posy;

    Avatar( int wideness, int heightness, const char* _character, int _screenWidth, int _screenHeight, int _posx, int _posy)
    {
        characterWidth = wideness;
        characterHeight = heightness;
        character = LoadImage(_character);
        ImageCrop(&character, (Rectangle){wideness,heightness,wideness,heightness});
        ImageResize(&character, 100, 100);
        characters = LoadTextureFromImage(character);
        UnloadImage(character);
        screenHeight = _screenHeight;
        screenWidth = _screenWidth;
        posx = _posx;
        posy = _posy;
        
    };
    void run()
    {
        DrawTexture(characters, posx, posy, WHITE);
        DrawRectangleLines(posx, posy, character.width, character.height, DARKGRAY);
    }
    
};

/*Avatar Avatar1( 9, 4,"C:/Users/tariq/OneDrive/Desktop/programming/C++ project/professor_walk_cycle_no_hat.png", {0.0f, 0.0f, float(1/9), float(1/4)}, {0.0f, 0.0f},  WHITE);
Avatar Avatar2( 6, 4, "C:/Users/tariq/OneDrive/Desktop/programming/C++ project/adelina-bunget-character.jpg", {0.0f, 0.0f, float(1/6), float(1/4)}, {0.0f, 0.0f}, WHITE);
Avatar Avatar3( 4, 4, "C:/Users/tariq/OneDrive/Desktop/programming/C++ project/warrior.png", {0.0f, 0.0f, float(1/4), float(1/4)}, {0.0f, 0.0f}, WHITE);*/