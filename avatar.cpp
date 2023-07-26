#include "raylib.h"
#include "avatar.h"

int main()
{
    const int screenWidth = 1000;
    const int screenHeight = 800;

    InitWindow(screenWidth, screenHeight, "KILLER ON THE LOOSE");
    Avatar Avatar1(64, 64, "C:/Users/tariq/OneDrive/Desktop/programming/C++ project/professor_walk_cycle_no_hat.png",screenWidth,screenHeight, 9*screenWidth/20, 7*screenHeight/20);
    Avatar Avatar2(160, 160, "C:/Users/tariq/OneDrive/Desktop/programming/C++ project/adelina-bunget-character4.png", screenWidth, screenHeight, 11*screenWidth/20, 7*screenHeight/20);
    Avatar Avatar3(32, 49, "C:/Users/tariq/OneDrive/Desktop/programming/C++ project/warrior.png", screenWidth, screenHeight, 13*screenWidth/20, 7*screenHeight/20);

    SetTargetFPS(60);

    while (!WindowShouldClose())
    {

        BeginDrawing();

        ClearBackground(BLACK);
        DrawText("CHOOSE YOUR KILLERS ATTRIBUTES!!", 50, 100, 40, WHITE);
        Avatar1.run();
        Avatar3.run();
        EndDrawing();
    }                                           
    CloseWindow();
    return 0;
}

/*    character = LoadImage("C:/Users/tariq/OneDrive/Desktop/programming/C++ project/professor_walk_cycle_no_hat.png");
    picOfChar = {0.0f, 0.0f, float(characters.width)/9, float(characters.height)/4 };
    VecOfChar = {};
    DrawTextureRec(characters, picOfChar, VecOfChar, WHITE);


Avatar2::Avatar2()
{
    character = LoadImage("C:/Users/tariq/OneDrive/Desktop/programming/C++ project/warrior.png");
    picOfChar = {0.0f, 0.0f, float(characters.width)/4, float(characters.height)/4 };
    VecOfChar = {};
    DrawTextureRec(characters, picOfChar, VecOfChar, WHITE);
}

Avatar3::Avatar3()
{
    character = LoadImage("C:/Users/tariq/OneDrive/Desktop/programming/C++ project/adelina-bunget-character4.jpg");
    picOfChar = {0.0f, 0.0f, float(characters.width)/6, float(characters.height)/4 };
    VecOfChar = {};
    DrawTextureRec(characters, picOfChar, VecOfChar, WHITE);
}
*/
// main menu code screen creation code:
// DrawRectangleLines(0, 200, 500, 600, RED);
// if( IsKeyDown(KEY_RIGHT) )
//{
//     DrawRectangleLines.x++
//     if(DrawRectangleLines.x > end of selection)
//     {
//         DrawRectangleLines.x = 0
//     }
// }

// if( isKeyDown(KEY_ENTER) )
//{
//   display "loading into the game..." for 5 seconds
//   then load into the game with that selected character.
// }
//