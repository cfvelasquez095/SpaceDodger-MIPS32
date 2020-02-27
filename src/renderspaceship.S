.globl render_spaceship

.extern put_char
.extern set_color
.extern set_cursor
.extern ship

.text

render_spaceship:
    addi	$sp, $sp, -4
    sw		$ra, 0($sp)

    addi    $a0, $zero, 0x3     # CYAN
    addi    $a1, $zero, 0x0     # BLACK

    jal     set_color           # set_color(LIGHT_BLUE, BLACK)

    la      $s3, ship
    lb      $a0, 1($s3)         # $a0 (row) = ship.pos_y
    lb      $a1, 0($s3)         # $a1 (col) = ship.pos_x

    jal     set_cursor

    ori     $a0, $zero, 219
    jal     put_char
    ori     $a0, $zero, 220
    jal     put_char
    ori     $a0, $zero, 221
    jal     put_char

    la      $s3, ship
    lb      $a0, 1($s3)         # $a0 (row) = ship.pos_y
    addi    $a0, $a0, 1         # portal_row + 1
    lb      $a1, 0($s3)         # $a1 (col) = ship.pos_x

    jal     set_cursor

    ori     $a0, $zero, 222
    jal     put_char
    ori     $a0, $zero, 223
    jal     put_char
    ori     $a0, $zero, 224
    jal     put_char

    move    $s3, $zero
    move    $a0, $zero
    move    $a1, $zero

    lw		$ra , 0($sp)
    addi	$sp, $sp, 4

    jr		$ra