#include "main/main.hpp"

void Player::player_movement(float dt) {
    if (IsKeyDown(KEY_W)) y += speed * dt;
    if (IsKeyDown(KEY_A)) x -= speed * dt;
    if (IsKeyDown(KEY_D)) x += speed * dt;
    if (IsKeyDown(KEY_S)) y -= speed * dt;
}

// void Player::player_health() {
//     health = 100;
//     ratio = 2;
//     combined = (health / ratio) - 10; // should go down in smooth percentages;

//     if (health > 100) {
//         std::cout << "pp" << std::endl;
//     }
// }

void Player::draw_health_bar() {
    // 1. Draw your background placeholder
    DrawRectangle(0, 630, 360, 40, BROWN);
    
    // 2. Set spacing variables
    float startX = 2.0f;    // Left padding from the edge of the screen
    float startY = 618.0f;   // Top position (slightly adjusted so 64x64 fits beautifully)
    float spacing = 32.0f;   // Horizontal gap between each heart (Minecraft hearts overlap slightly)

    // 3. Single loop to draw hearts horizontally
    for (int i = 0; i < max_hearts; i++) {
        // Calculate a unique X position for every single heart
        float currentX = startX + (i * spacing);

        DrawTexturePro(
            heart_005,
            Rectangle{0.0f, 0.0f, (float)heart_005.width, (float)heart_005.height},
            Rectangle{currentX, startY, 64.0f, 64.0f}, // Uses currentX instead of hardcoded 0
            Vector2{0.0f, 0.0f},
            0.0f,
            WHITE
        );
    }
}
