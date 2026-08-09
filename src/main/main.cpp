#include "main.hpp"

int main() {
    InitWindow(W_WIDTH, W_HEIGHT, W_TITLE);
    // gonna test load smth;
    Texture2D food_001 = LoadTexture("assets/icons/food-001.png");
    SetTargetFPS(W_FPS);

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(W_COLOR);
        DrawTexturePro(
            food_001,
            Rectangle{0, 0, (float)food_001.width, (float)food_001.height},
            Rectangle{400, 500, 128, 128},
            Vector2{0, 0},
            0.0f,
            WHITE
        );
        EndDrawing();
    }

    UnloadTexture(food_001);
    CloseWindow();
    return 0;
}