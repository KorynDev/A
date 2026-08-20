#include "main.hpp"

auto DrawGround() -> void {
    for (int x = 0; x < W_WIDTH; x++) { 
        if (x >= W_WIDTH) x = W_WIDTH;
        for (int y = 0; y < W_HEIGHT; y++) {
            if (y >= W_HEIGHT) y = W_HEIGHT;
            DrawRectangle(x, y, 50, 50, BROWN);
        }
    }
}

int main() {
    InitWindow(W_WIDTH, W_HEIGHT, W_TITLE);
    SetConfigFlags(FLAG_VSYNC_HINT | FLAG_MSAA_4X_HINT);
    SetExitKey(KEY_Q);
    // gonna test load smth;
    loadalltextures();
    Player plr;
    SetTargetFPS(W_FPS);

    while (!WindowShouldClose()) {
        float dt = GetFrameTime();
        BeginDrawing();
        ClearBackground(W_COLOR);
        DrawGround();
        plr.draw_health_bar();
        EndDrawing();
    }

    unloadalltextures();
    CloseWindow();
    return 0;
}