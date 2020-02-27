.globl init_portal

.extern put_char
.extern set_color
.extern set_cursor
.extern portal_p

.text

init_portal:
    addi	$sp, $sp, -4
    sw		$ra, 0($sp)

    addi    $a0, $zero, 0x9     # LIGHT_BLUE
    addi    $a1, $zero, 0x0     # BLACK

    jal     set_color           # set_color(LIGHT_BLUE, BLACK)

    la      $s3, portal_p
    lb      $a0, 1($s3)         # $a0 (row) = portal_p.pos_y
    lb      $a1, 0($s3)         # $a1 (col) = portal_p.pos_x

    jal     set_cursor

    ori     $a0, $zero, 239
    jal     put_char
    ori     $a0, $zero, 240
    jal     put_char
    ori     $a0, $zero, 241
    jal     put_char

    la      $s3, portal_p
    lb      $a0, 1($s3)         # $a0 (row) = portal_p.pos_y
    addi    $a0, $a0, 1         # portal_row + 1
    lb      $a1, 0($s3)         # $a1 (col) = portal_p.pos_x

    jal     set_cursor

    ori     $a0, $zero, 242
    jal     put_char
    ori     $a0, $zero, 243
    jal     put_char
    ori     $a0, $zero, 244
    jal     put_char

    la      $s3, portal_p
    lb      $a0, 1($s3)         # $a0 (row) = portal_p.pos_y
    addi    $a0, $a0, 2         # portal_row + 2
    lb      $a1, 0($s3)         # $a1 (col) = portal_p.pos_x

    jal     set_cursor

    ori     $a0, $zero, 245
    jal     put_char
    ori     $a0, $zero, 246
    jal     put_char
    ori     $a0, $zero, 247
    jal     put_char

    move    $s3, $zero
    move    $a0, $zero
    move    $a1, $zero

    lw		$ra , 0($sp)
    addi	$sp, $sp, 4

    jr		$ra