#include <screen.h>
#include <keypad.h>

#define TO_STR(ch) ( ( ((ch) >= 0 ) && ((ch) <= 9) )? (48 + (ch)) : ('a' + ((ch) - 10)) )

int main() {
    clear_screen();
    set_color(WHITE, BLACK);
    set_cursor(29, 15);
    /* put_char('H');
    put_char('e');
    put_char('l');
    put_char('l');
    put_char('o');
    put_char('!'); */
    puts("Hello!");
    
    uint8_t f, b;
    get_color(&f, &b);
    
    set_color(RED, BLACK);
    puts("\x1\x2");
    set_color(f, b);
    
    keypad_init();
    while (1) {
        uint8_t k = keypad_getkey();
        set_cursor(2, 1);
        put_char(TO_STR(k & 0xf));
        set_cursor(3, 1);
        put_char(TO_STR((k & 0xf0) >> 4));
        if (k != 0) {
            set_cursor(10, 15);
            puts("Key press");
        }
    }

    return 0;
}
