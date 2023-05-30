        .name "NTML"
        .comment "Bringer of chaos"

                sti r1, %:loop, %1
                sti r1, %:setup_end, %1
                ld %0, r2
                ld %1, r3
                ld %11, r5
loop:           live %69
                add r2, r3, r2
                sub r4, r2, r5
                zjmp %:setup_end
                fork %:loop
                ld %0, r6
                zjmp %:loop
setup_end:      live %69
                ld %0, r6
                zjmp %:setup_end
