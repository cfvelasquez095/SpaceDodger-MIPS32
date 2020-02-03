#include <screen.h>
#include <keypad.h>

typedef struct spaceship
{
    uint8_t pos_x;
    uint8_t pos_y;
} spaceship;

typedef struct enemy_ship
{
    uint8_t pos_x;
    uint8_t pos_y;
} enemy_ship;

typedef struct portal
{
    uint8_t pos_x;
    uint8_t pos_y;
} portal;

struct spaceship ship;
struct portal portal_p;
struct enemy_ship enemy_ships[5];
struct enemy_ship e_ship1, e_ship2, e_ship2, e_ship3, e_ship4, e_ship5;
uint8_t current_row, current_col;
uint8_t lives;

void init_game();
void init_portal();
void render_hud();
void render_level();
void render_spaceship();
void spaceship_logic(uint8_t key);
void spaceship_collision();
void render_enemies();
void enemies_logic();
void gameover();
void render_game();

void init_game()
{
    lives = 3;

    // Player Spaceship
    ship.pos_x = 2;
    ship.pos_y = 15;

    // Enemy Ships
    e_ship1.pos_x = 30;
    e_ship1.pos_y = 15;

    e_ship2.pos_x = 35;
    e_ship2.pos_y = 10;

    e_ship3.pos_x = 23;
    e_ship3.pos_y = 20;

    e_ship4.pos_x = 42;
    e_ship4.pos_y = 15;

    e_ship5.pos_x = 27;
    e_ship5.pos_y = 12;

    enemy_ships[0] = e_ship1;
    enemy_ships[1] = e_ship2;
    enemy_ships[2] = e_ship3;
    enemy_ships[3] = e_ship4;
    enemy_ships[4] = e_ship5;
}

void init_portal()
{

}

void render_hud()
{
    set_color(BRIGHT_WHITE, BLACK);
    set_cursor(3, 8);
    puts("Lives: ");
    set_cursor(1, 34);
    puts("Space Dodger");
}

void render_level()
{
    set_color(MAGENTA, BLACK);
    current_row = 6;
    current_col = 1;
    set_cursor(current_row, current_col);

    for (uint8_t i = current_col; i < 79; i++)
    {
        put_char(176);
    }

    current_row = 25;
    set_cursor(current_row, current_col);
    
    for (uint8_t i = current_col; i < 79; i++)
    {
        put_char(176);
    }
}

void render_spaceship()
{
    set_color(CYAN, BLACK);
    uint8_t ship_col = ship.pos_x;
    uint8_t ship_row = ship.pos_y;

    set_cursor(ship_row, ship_col);
    put_char(219);
    put_char(220);
    put_char(221);
    set_cursor(ship_row + 1, ship_col);
    put_char(222);
    put_char(223);
    put_char(224);
}

void spaceship_logic(uint8_t key)
{
switch (key)
    {
    case 3: //Down Movement
        if (ship.pos_y+1 != 23)
        {
            ship.pos_y++;
        }
        break;
    case 4: //Up Movement
        if (ship.pos_y-1 != 7)
        {
            ship.pos_y--;
        }
        break;
    default:
        break;
    }
}

void spaceship_collision()
{

}

void render_enemies()
{

}

void enemies_logic()
{

}

void gameover()
{
    clear_screen();
    render_hud();
    render_level();
    set_cursor(15, 36);
    set_color(RED, BLACK);
    puts("Game Over");
    set_cursor(16, 27);
    puts("Continue? (Spacebar - Yes)");
    if (keypad_getkey() == 8)
    {
        ship.pos_x = 40;
        ship.pos_y = 12;
        lives += 3;
    }
}

void render_game()
{
    if(lives == 0){
        gameover();
    }else{
        clear_screen();
        render_hud();
        render_level();
        render_spaceship();
    }
}