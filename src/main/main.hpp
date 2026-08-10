#pragma once

#include <raylib.h>
#include <raymath.h>

#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
#include <vector>

#define W_WIDTH 1280
#define W_HEIGHT 720

#define W_CALC_WIDTH 2 - 45
#define W_CALC_HEIGHT 2 - 80

#define W_TITLE "A"
#define W_FPS 144

#define W_COLOR BEIGE

#define T_WIDTH 16
#define T_HEIGHT 16

#ifndef STRUCTS

struct Animation {
    int first_frame;
    int last_frame;
    int cur;
};

template<typename T>
struct Stats {
    std::string name;
    T value;
};
inline std::vector<Stats<std::string>> statsvars;

template<typename T>
struct inventory {
    std::string name;
    T value;
    Texture2D icon;
};
inline std::vector<inventory<std::string>> inventoryvars;

struct ShopStr {
    int in_stock;
    int restock_time;
    int max_shop_items;
    #define SH_WIDTH 400
    #define SH_HEIGHT 600
    #define MAX_CUR_ITEMS_STOCK 14 // 14 items in stock out of 32 total items; (msg for later me its better to switch to rand())
};

#endif

#ifndef ENUMS

enum ShopTypes {
    SELL,
    BUY,
    NONE,
};

#endif

#ifndef NAMESPACES

namespace Eco {
    inline void RegisterNewVar(Stats<std::string>& data) { statsvars.push_back(data); }
}

namespace Inventory_n {
    inline void RegisterNewInvItem(inventory<std::string>& invdata) { inventoryvars.push_back(invdata); }
}

#endif

#ifndef INLINE_FUNCTIONS
    #ifndef ECONOMY
        template<typename T>
        inline void AddVar(std::string var, T val) {
            Eco::RegisterNewVar({.name = var, .value = val});
        }
    #endif
    #ifndef INVENTORY
        template<typename T>
        inline void AddInvItem(std::string varinv, T val, Texture2D icon) {
            Inventory_n::RegisterNewInvItem({.name = varinv, .value = val, .icon = icon});
        }
    #endif
#endif

#ifndef CLASSES

class World {
public:

private:
};

class Player {
public:
    float x;
    float y;
    float speed;
    int max_hearts = 10;

    void player_movement(float dt);
    void player_health();

    void draw_health_bar();

    float GetGravity() const { return gravity_p; }
    float GetHealth() const { return health; }
    float GetRatio() const { return ratio; }
    float GetCombined() const { return combined; }
private:
    float gravity_p = 198.4;
    float health;
    float ratio;
    float combined;
};

class Inventory {
public:
    int maxitems;
    #define INV_WIDTH 400
    #define INV_HEIGHT 600
    #define INV_SLOTS 32
private:
    inventory<std::string>& inventory_str;
};

class Shop {
public:
    void create_shops(); // global shop generation;
    void create_shop_ui(); // shop ui creation;

    bool is_sell_shop;
    bool is_normal_shop;

    void shop_connections(); // shop input handling;
    void shop_selling(); // shop sell handling;
    void shop_buy(); // shop buy handling;
private:
    ShopTypes ShopTypes{ShopTypes::NONE};
    ShopStr *sh;
};

#endif

#ifndef SPC_DEFINES

// deadass forgor, i still cant fucking remember what i needa write here btw.

#endif

#ifndef TEXTURES

inline Texture2D food_001;
inline Texture2D red_coin_002;
inline Texture2D apple_003;
inline Texture2D gold_coin_004;
inline Texture2D heart_005;

#endif

#ifndef TEXTURE_LOADING

inline void loadalltextures() {
    food_001 = LoadTexture("assets/icons/food-001.png");
    red_coin_002 = LoadTexture("assets/icons/red-coin-002.png");
    apple_003 = LoadTexture("assets/icons/apple-003.png");
    gold_coin_004 = LoadTexture("assets/icons/gold-coin-004.png");
    heart_005 = LoadTexture("assets/icons/heart-005.png");
}

inline void unloadalltextures() {
    UnloadTexture(food_001);
    UnloadTexture(red_coin_002);
    UnloadTexture(apple_003);
    UnloadTexture(gold_coin_004);
    UnloadTexture(heart_005);
}

#endif