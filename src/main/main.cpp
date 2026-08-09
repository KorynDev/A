#include "main.hpp"

int main() {
    InitWindow(W_WIDTH, W_HEIGHT, W_TITLE);
    SetTargetFPS(W_FPS);

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(W_COLOR);
        DrawCircle(400, 500, 20, RED);
        EndDrawing();
    }

    CloseWindow();
    return 0;
}