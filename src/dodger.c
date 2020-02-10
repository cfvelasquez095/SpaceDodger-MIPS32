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
int lives, portal_countdown;

void init_game();
void init_portal();
void render_hud();
void render_level();
void render_spaceship();
void spaceship_logic(uint8_t key);
void spaceship_collision();
void render_flank_enemies(enemy_ship *e);
void render_central_enemy(enemy_ship *e);
void enemies_logic();
void winning_transition(uint8_t key);
void gameover();
void render_game();

void init_game()
{
    lives = 3;
    portal_countdown = 300;

    // Player Spaceship
    ship.pos_x = 4;
    ship.pos_y = 15;

    // Portal
    portal_p.pos_x = 40;
    portal_p.pos_y = 15;

    // Enemy Ships
    e_ship1.pos_x = 64;
    e_ship1.pos_y = 10;

    e_ship2.pos_x = 58;
    e_ship2.pos_y = 15;

    e_ship3.pos_x = 70;
    e_ship3.pos_y = 20;

    e_ship4.pos_x = 76;
    e_ship4.pos_y = 13;

    e_ship5.pos_x = 52;
    e_ship5.pos_y = 18;

    enemy_ships[0] = e_ship1;
    enemy_ships[1] = e_ship2;
    enemy_ships[2] = e_ship3;
    enemy_ships[3] = e_ship4;
    enemy_ships[4] = e_ship5;
}

void init_portal()
{
    set_color(LIGHT_BLUE, BLACK);
    uint8_t portal_col = portal_p.pos_x;
    uint8_t portal_row = portal_p.pos_y;

    set_cursor(portal_row, portal_col);
    put_char(239);
    put_char(240);
    put_char(241);
    set_cursor(portal_row + 1, portal_col);
    put_char(242);
    put_char(243);
    put_char(244);
    set_cursor(portal_row + 2, portal_col);
    put_char(245);
    put_char(246);
    put_char(247);
}

void render_hud()
{
    set_color(BRIGHT_WHITE, BLACK);
    set_cursor(1, 34);
    puts("Space Dodger");
    set_cursor(3, 8);
    puts("Lives: ");
    for (uint8_t i = 1; i <= lives; i++)
    {
        set_color(YELLOW, BLACK);
        put_char(3);
        put_char(' ');
    }
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
    uint8_t ship_posx = ship.pos_x;
    uint8_t ship_posy = ship.pos_y;
    for(uint8_t i = 0; i < 5; i++){
        if(ship_posy == enemy_ships[i].pos_y){
            if(ship_posx <= enemy_ships[i].pos_x && ship_posx+1 >= enemy_ships[i].pos_x){
                ship.pos_x = 4;
                ship.pos_y = 13;
                lives--;
            }
        }
    }
}

void render_flank_enemies(enemy_ship *e)
{
    set_color(LIGHT_RED, BLACK);

    set_cursor(e->pos_y, e->pos_x);
    put_char(225);
    put_char(226);
    put_char(227);
    set_cursor(e->pos_y + 1, e->pos_x);
    put_char(228);
    put_char(229);
    put_char(230);
}

void render_flank_enemies2(enemy_ship *e)
{
    set_color(LIGHT_GREEN, BLACK);

    set_cursor(e->pos_y, e->pos_x);
    put_char(225);
    put_char(226);
    put_char(227);
    set_cursor(e->pos_y + 1, e->pos_x);
    put_char(228);
    put_char(229);
    put_char(230);
}

void render_central_enemy(enemy_ship *e)
{
    set_color(YELLOW, BLACK);

    set_cursor(e->pos_y, e->pos_x);
    put_char(232);
    put_char(233);
    put_char(234);
    set_cursor(e->pos_y + 1, e->pos_x);
    put_char(235);
    put_char(236);
    put_char(237);
}

void enemies_logic()
{
    uint8_t e1_x, e2_x, e3_x, e4_x, e5_x;

    e1_x = enemy_ships[0].pos_x;
    e2_x = enemy_ships[1].pos_x;
    e3_x = enemy_ships[2].pos_x;
    e4_x = enemy_ships[3].pos_x;
    e5_x = enemy_ships[4].pos_x;

    // Enemy ship 1
    if (e1_x > 1)
    {
        enemy_ships[0].pos_x--;
        enemy_ships[0].pos_x--;
    } else if (e1_x <= 1)
    {
        enemy_ships[0].pos_x = 79;
    }  

    // Enemy ship 2
    if (e2_x > 1)
    {
        enemy_ships[1].pos_x--;
        enemy_ships[1].pos_x--;
    } else if (e2_x <= 1)
    {        
        enemy_ships[1].pos_x = 70;
    }

    // Enemy ship 3
    if (e3_x > 1)
    {
        enemy_ships[2].pos_x--;
        enemy_ships[2].pos_x--;
    } else if (e3_x <= 1)
    {
        enemy_ships[2].pos_x = 79;
    }

    // Enemy ship 4
    if (e4_x > 1)
    {
        enemy_ships[3].pos_x--;
        enemy_ships[3].pos_x--;
    } else if (e4_x <= 1)
    {        
        enemy_ships[3].pos_x = 73;
    }

    // Enemy ship 5
    if (e5_x > 1)
    {
        enemy_ships[4].pos_x--;
        enemy_ships[4].pos_x--;
    } else if (e5_x <= 1)
    {        
        enemy_ships[4].pos_x = 73;
    }
    
}

void winning_transition(uint8_t key)
{
    clear_screen();
    render_hud();
    render_level();
    render_spaceship();
    init_portal();
    switch (key)
    {
    case 2:
        if (ship.pos_x < 37)
        {
            ship.pos_x++;
        }
        break;
    
    default:
        break;
    }  
    if (ship.pos_x == 37)
    {
        set_cursor(10, 30);
        set_color(LIGHT_GREEN, BLACK);
        puts("Mission Accomplished");
    }
    
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
        ship.pos_x = 4;
        ship.pos_y = 15;
        lives += 3;
    }
}

void render_game()
{
    if(lives == 0 && portal_countdown != 0){
        gameover();
    }else if(portal_countdown == 0){
        winning_transition(keypad_getkey());
    }else{
        clear_screen();
        render_hud();
        render_level();
        render_spaceship();
        render_flank_enemies(&enemy_ships[0]);
        render_flank_enemies(&enemy_ships[2]);
        render_central_enemy(&enemy_ships[1]);
        render_flank_enemies2(&enemy_ships[3]);
        render_flank_enemies2(&enemy_ships[4]);
        enemies_logic();
        portal_countdown--;
    }
}