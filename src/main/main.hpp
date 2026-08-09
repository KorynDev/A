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

#define W_TITLE "A"
#define W_FPS 144

#define W_COLOR BEIGE

#define T_WIDTH 16
#define T_HEIGHT 16

#ifndef STRUCTS

template<typename T>
struct Stats {
    std::string name;
    T value;
};
std::vector<Stats<std::string>> statsvars;

template<typename T>
struct inventory {
    std::string name;
    T value;
    Texture2D icon;
};
std::vector<inventory<std::string>> inventoryvars;

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

template<typename T>
inline void AddVar(std::string var, T val) {
    Eco::RegisterNewVar({.name = var, .value = val});
}

template<typename T>
inline void AddInvItem(std::string varinv, T val, Texture2D icon) {
    Inventory_n::RegisterNewInvItem({.name = varinv, .value = val, .icon = icon});
}

#endif

#ifndef CLASSES

class World {};

class Player {
public:
    float x;
    float y;

    float health;
    float ratio;

    void player_movement();
    void player_health();

    float GetGravity() const { return gravity_p; }
private:
    float gravity_p = 198.4;
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