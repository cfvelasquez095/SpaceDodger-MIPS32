.globl init_game

.extern lives
.extern portal_countdown
.extern ship
.extern portal_p
.extern e_ship1
.extern e_ship2
.extern e_ship3
.extern e_ship4
.extern e_ship5
.extern enemy_ships

.text

init_game:
    addi	$sp, $sp, -4
    sw		$ra, 0($sp)

    la      $s0, lives              # load player's lives in $s0
    li      $s1, 3
    sw      $s1, 0($s0)             # initialize lives in 3

    la      $s2, portal_countdown   # load portal's countdown in $s0
    li      $s3, 100
    sw      $s3, 0($s2)             # initialize the portal's cd in 300

    la      $s1, enemy_ships        # load the address for enemy_ships[]

    la      $s5, ship               # load ship struct in $s0
    move    $t0, $zero
    addi    $t0, $t0, 4
    sb		$t0, 0($s5)		        # ship.pos_x = 4
    move    $t0, $zero
    addi    $t0, 15
    sb      $t0, 1($s5)             # ship.pos_y = 15

    la      $s5, portal_p           # load portal_p struct in $s0
    move    $t0, $zero
    addi    $t0, $t0, 40
    sb		$t0, 0($s5)		        # portal_p.pos_x = 40
    move    $t0, $zero
    addi    $t0, 15
    sb      $t0, 1($s5)             # portal_p.pos_y = 15

    la      $s0, e_ship1            # load e_ship1 struct in $s0
    move    $t0, $zero
    addi    $t0, $t0, 64
    sb	    $t0, 0($s0)		        # e_ship1.pos_x = 64
    sb      $t0, 0($s1)
    move    $t0, $zero
    addi    $t0, 10
    sb      $t0, 1($s0)             # e_ship1.pos_y = 10
    sb      $t0, 1($s1)             # enemy_ships[0] = e_ship1;

    la      $s0, e_ship2            # load e_ship2 struct in $s0
    move    $t0, $zero
    addi    $t0, $t0, 58
    sb		$t0, 0($s0)		        # e_ship2.pos_x = 58
    sb      $t0, 2($s1)
    move    $t0, $zero
    addi    $t0, 15
    sb      $t0, 1($s0)             # e_ship2.pos_y = 15
    sb      $t0, 3($s1)             # enemy_ships[1] = e_ship2;

    la      $s0, e_ship3            # load e_ship3 struct in $s0
    move    $t0, $zero
    addi    $t0, $t0, 70
    sb	    $t0, 0($s0)		        # e_ship3.pos_x = 70
    sb      $t0, 4($s1)
    move    $t0, $zero
    addi    $t0, 20
    sb      $t0, 1($s0)             # e_ship3.pos_y = 20
    sb      $t0, 5($s1)             # enemy_ships[2] = e_ship3;
    
    la      $s0, e_ship4            # load e_ship4 struct in $s0
    move    $t0, $zero
    addi    $t0, $t0, 76
    sb	    $t0, 0($s0)		        # e_ship4.pos_x = 76
    sb      $t0, 6($s1)
    move    $t0, $zero
    addi    $t0, 13
    sb      $t0, 1($s0)             # e_ship4.pos_y = 13
    sb      $t0, 7($s1)             # enemy_ships[3] = e_ship4;

    la      $s0, e_ship5            # load e_ship5 struct in $s0
    move    $t0, $zero
    addi    $t0, $t0, 52
    sb      $t0, 0($s0)		        # e_ship5.pos_x = 52
    sb      $t0, 8($s1)
    move    $t0, $zero
    addi    $t0, 18
    sb      $t0, 1($s0)             # e_ship5.pos_y = 18
    sb      $t0, 9($s1)             # enemy_ships[4] = e_ship5;

    move    $s0, $zero
    move    $s1, $zero
    move    $s2, $zero
    move    $s3, $zero
    move    $s5, $zero

    lw		$ra , 0($sp)
    addi	$sp, $sp, 4

    jr		$ra