    .name "test"
    .comment "let's do some fucked up shit"

        sti r1, %:live, %1
        sti r1, %:child, %1
        sti r1, %:parent, %1
live:   live %69
        ld %69, r2
        ld %1, r3
        fork %:child
parent: live %69
        ldi %:die, %1, r5
        aff r5 #E
        st r5, r6
        aff r6 #E
        and %0, %0, r10
        zjmp %:die
child:  live %69
        add r2, r3, r5
        aff r5 #F
        sub r2, r3, r5
        aff r5 #D
        and r2, %64, r5
        aff r5 #@
        or %64, %64, r5
        aff r5 #@
        xor %64, %0, r5
        aff r5 #@
        xor %0, %0, r6
die:    live %69
