#include "main.hpp"

int main() {
    InitWindow(W_WIDTH, W_HEIGHT, W_TITLE);
    SetConfigFlags(FLAG_VSYNC_HINT | FLAG_MSAA_4X_HINT);
    // gonna test load smth;
    loadalltextures();
    Player plr;
    SetTargetFPS(W_FPS);

    while (!WindowShouldClose()) {
        float dt = GetFrameTime();
        BeginDrawing();
        ClearBackground(W_COLOR);
        plr.draw_health_bar();
        EndDrawing();
    }

    unloadalltextures();
    CloseWindow();
    return 0;
}