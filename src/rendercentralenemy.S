.globl render_central_enemy

.extern put_char
.extern set_color
.extern set_cursor
.extern enemy_ships

.text

render_central_enemy:
    addi	$sp, $sp, -4
    sw		$ra, 0($sp)

    addi    $a0, $zero, 0xe     # YELLOW
    addi    $a1, $zero, 0x0     # BLACK

    jal     set_color           # set_color(YELLOW, BLACK)

    la      $s3, enemy_ships
    lb      $a0, 3($s3)         # $a0 (row) = e->pos_y
    lb      $a1, 2($s3)         # $a1 (col) = e->pos_x

    jal     set_cursor

    ori     $a0, $zero, 232
    jal     put_char
    ori     $a0, $zero, 233
    jal     put_char
    ori     $a0, $zero, 234
    jal     put_char

    la      $s3, enemy_ships
    lb      $a0, 3($s3)         # $a0 (row) = e->pos_y
    addi    $a0, $a0, 1         # e->pos_y + 1
    lb      $a1, 2($s3)         # $a1 (col) = e->pos_x

    jal     set_cursor

    ori     $a0, $zero, 235
    jal     put_char
    ori     $a0, $zero, 236
    jal     put_char
    ori     $a0, $zero, 237
    jal     put_char

    move    $s3, $zero
    move    $a0, $zero
    move    $a1, $zero

    lw		$ra , 0($sp)
    addi	$sp, $sp, 4

    jr		$ra