#include <screen.h>
#include <keypad.h>

#define TO_STR(ch) ( ( ((ch) >= 0 ) && ((ch) <= 9) )? (48 + (ch)) : ('a' + ((ch) - 10)) )

int main() {
    clear_screen();

    init_game();
    render_spaceship();    
    keypad_init();
    while (1) {
        spaceship_logic(keypad_getkey());
        spaceship_collision();
        delay_ms(100);
        render_game();
    }

    return 0;
}
