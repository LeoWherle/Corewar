.name "MyBasicChampion"
.comment "A simple champion"

live_check: 
            live %1
            zjmp %:live
start:
            ld %0, r1      
            sti r1, %:copy, %1 
            add %3, %2, r2  
            sub %4, %5, r3 
            and %6, %7, r4 
            or %8, %9, r5  
            xor %10, %11, r6
            ldi %12, %13, r7 
            aff r7 

copy:
            st r2, %15
            ldi %16, %17, r2
            sti r3, %18, %19 

            live %2
            zjmp %:start
