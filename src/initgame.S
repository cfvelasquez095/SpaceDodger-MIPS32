.globl init_game
.extern init_game_c

.text

init_game:
    addi    $sp, $sp, -4
    addi	$sp, $sp, -4
    sw		$ra, 0($sp)     

    jal		init_game_c

    lw		$ra , 0($sp)
    addi	$sp, $sp, 4

    jr		$ra