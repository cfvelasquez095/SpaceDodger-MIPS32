.globl render_game

.extern gameover
.extern winning_transition
.extern keypad_getkey
.extern clear_screen
.extern render_hud
.extern render_level
.extern render_spaceship
.extern render_central_enemy
.extern render_flank_enemies
.extern render_flank_enemies2
.extern enemies_logic
.extern lives
.extern portal_countdown
.extern enemy_ships

.text

render_game:
    addi	$sp, $sp, -4
    sw		$ra, 0($sp)   

    move    $a0, $zero
    la		$s0, enemy_ships            # load the address for enemy_ships[]
    lw		$s1, lives                  # load player's lives into $s1
    lw		$s2, portal_countdown       # load portal_countdown into $s2
check_lives:                            # if( lives == 0 && portal_countdown != 0 )
    bne		$s1, $zero, check_portal	# if lives != 0
    jal		gameover                    # jump to gameover and save position to $ra
    lw		$ra , 0($sp)
    addi	$sp, $sp, 4

    jr		$ra
check_portal:
    bne		$s2, $zero, else_render     # if portal_countdown != 0 then keep playing
    move    $a0, $zero
    la		$a0, keypad_getkey          # load the address for function keypad_getkey() as a param
    jal		winning_transition          # jump to winning_transition and save position to $ra
    lw		$ra , 0($sp)
    addi	$sp, $sp, 4

    jr		$ra
else_render:
    jal     clear_screen                # jump to clear_screen and save position to $ra
    jal     render_hud                  # jump to render_hud and save position to $ra
    jal     render_level                # jump to render_level and save position to $ra
    jal     render_spaceship            # jump to render_spaceship and save position to $ra


    addi	$a0, $s0, 0                 # $a0 = enemy_ships[0]
    jal		render_flank_enemies        # jump to render_flank_enemies and save position to $ra
    addi	$s0, $s0, 2

    addi    $a0, $s0, 0                 # $a0 = enemy_ships[1]
    jal		render_central_enemy        # jump to render_central_enemies and save position to $ra
    addi	$s0, $s0, 2

    addi	$a0, $s0, 0                 # $a0 = enemy_ships[2]
    jal		render_flank_enemies        # jump to render_flank_enemies and save position to $ra
    addi	$s0, $s0, 2

    addi	$a0, $s0, 0                 # $a0 = enemy_ships[3]
    jal		render_flank_enemies2       # jump to render_flank_enemies2 and save position to $ra
    addi	$s0, $s0, 2

    addi	$a0, $s0, 0                 # $a0 = enemy_ships[4]
    jal		render_flank_enemies2       # jump to render_flank_enemies2 and save position to $ra
    addi	$s0, $s0, 2

    jal     enemies_logic               # jump to enemies_logic and save position to $ra

    addi    $s2, $s2, -1                # portal_countdown--

    lw		$ra , 0($sp)
    addi	$sp, $sp, 4

    jr		$ra