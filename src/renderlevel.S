.globl render_level

.extern put_char
.extern set_color
.extern set_cursor

.text

render_level:
    addi	$sp, $sp, -4
    sw		$ra, 0($sp)

    addi    $a0, $zero, 0x5     # MAGENTA
    addi    $a1, $zero, 0x0     # BLACK

    jal     set_color           # set_color(MAGENTA, BLACK)

    li      $a0, 6              # current_row = 6
    li      $a1, 1              # current_col = 1

    jal     set_cursor          # set_cursor(current_row, current_col)

    li      $s3, 1
    li      $s4, 79
    
for_loop1:
    bge     $s3, $s4, end_loop1
    ori     $a0, $zero, 176
    jal     put_char            # put_char(176)
    addi    $s3, $s3, 1         # i++
    j       for_loop1
end_loop1:
    li      $a0, 25             # current_row = 25
    li      $a1, 1              # current_col = 1
    li      $s3, 1
    jal     set_cursor          # set_cursor(current_row, current_col)
for_loop2:
    bge     $s3, $s4, end_render
    ori     $a0, $zero, 176
    jal     put_char            # put_char(176)
    addi    $s3, $s3, 1         # i++
    j       for_loop2
end_render:
    move    $s3, $zero
    move    $s4, $zero
    move    $a0, $zero
    move    $a1, $zero

    lw		$ra , 0($sp)
    addi	$sp, $sp, 4

    jr		$ra