#include "main.hpp"

int main() {
    InitWindow(W_WIDTH, W_HEIGHT, W_TITLE);
    SetConfigFlags(FLAG_VSYNC_HINT | FLAG_MSAA_4X_HINT);
    // gonna test load smth;
    loadalltextures();
    SetTargetFPS(W_FPS);

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(W_COLOR);
        DrawTexturePro(
            food_001,
            Rectangle{0, 0, (float)food_001.width, (float)food_001.height},
            Rectangle{W_WIDTH / W_CALC_WIDTH, W_HEIGHT / W_CALC_HEIGHT, 128, 128},
            Vector2{0, 0},
            0.0f,
            WHITE
        );
        EndDrawing();
    }

    unloadalltextures();
    CloseWindow();
    return 0;
}