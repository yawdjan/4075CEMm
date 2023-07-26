#include <iostream>
#include "raylib.h"
#include "raymath.h"
#include "avatar.h"

using namespace std;
int main()
{
    const int screenWidth = 1000;
    const int screenHeight = 800;
    const int charSpeed = 3;
    int counter = 0;
    int frameNum = 9;
    int delayCounter = 0;
    int delay = 5;
    int heightNum = 4;
    
    InitWindow(screenWidth, screenHeight, "KILLER ON THE LOOSE");
    SetTargetFPS(60);

    Image main_Character = LoadImage("C:/Users/tariq/OneDrive/Desktop/programming/C++ project/professor_walk_cycle_no_hat.png");
    Texture2D mainCharacter  = LoadTextureFromImage(main_Character);

    Image house = LoadImage("C:/Users/tariq/OneDrive/Desktop/programming/C++ project/House1.jpg");
    Texture2D main_house = LoadTextureFromImage(house);

    int frameWidth = main_Character.width/frameNum;
    int frameHeight = main_Character.height/heightNum;

    Rectangle position = {0.0f, 0.0f, float(frameWidth), float(frameHeight)};
    Vector2 placement = {screenWidth/2,screenHeight/2};
    Vector2 movement = {0.0f, 0.0f};
    
    while (!WindowShouldClose())
    {
        delayCounter++;
        if( delayCounter > delay )
        {
            delayCounter = 0;
            counter++;
            counter %= frameNum;
            position.x = float(frameWidth) * counter;
            if(IsKeyDown(KEY_UP))
            {     
                position.y = float(mainCharacter.height);          
                movement.y = -charSpeed;                   
            }
            else if(IsKeyDown(KEY_DOWN))
            {
                position.y = 2 * float(frameHeight);                    
                movement.y = charSpeed;                  
            }
            else if(IsKeyDown(KEY_LEFT))
            {
                position.y = float(frameHeight);
                movement.x = -charSpeed;
            }
            else if(IsKeyDown(KEY_RIGHT))
            {
                position.y = 3 * float(frameHeight);
                movement.x = charSpeed;
            }
            else
            {
                movement.x = 0;
                movement.y = 0;
                position.x = 0;
            }
        }
        placement = Vector2Add(placement, movement);

        BeginDrawing();
            ClearBackground(BLACK);
            DrawTextureRec(mainCharacter, position, placement, RAYWHITE);
            DrawTexture(main_house, screenWidth/2, screenHeight/2, RAYWHITE);
        EndDrawing();        
    }
    UnloadTexture(mainCharacter);
    CloseWindow();
    return 0;
}