**Roadmap vm**

# structure

1. parsing arguments -> input in vm_t
2. initialisation arena (vm) + flags
3. init champions into arena
4. launch

at each step -> if failed free memory

# parsing

### get dump-nbr cycle

-

# initialisation arena

- default


# initalisation champions

### load champions into arena
- if arena is to small -> error meassage  (summ of the size of each champion's size)
- (optionnal?) check validity of flags (same id, instruction overlapping) [ID, load_adress]
- init first process

# game loop (launch)

### - get current instruction of each process
- if instruction byte is not valid, set cmd to NULL WILL BE VERIFIED
- set countdown to the corresponding intruction

### - execute the instruction
- if the instruction is NULL (kill the process | set do dead)
- otherwise if the countdown is 0 **execute the instruction**
- else do nothing ((skip))

### - cleanup
- check if a process is dead () -> free
- check if a player is dead (process count == 0) -> free
- if there is only one player left setwin
- if nbr_live is >= crr_live decrease cycle_am by cycle_delta

### - Dump
- if flag print status
