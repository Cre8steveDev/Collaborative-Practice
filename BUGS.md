# Some bugs to Have fun with

- (command)[echo "hbtn_ls" | ./hsh]

[GOT]:
(stdout)[Requirements.txt
TEST_SUITE
execute.c
extra_execute.c
free_array.c
get_full_path.c
getpath.c
hbtn_ls
hsh
main_shell copy
main_shell.c
runchecker.bash
shell
shell.h
string_functions
test.txt
tokenize_input.c
zerror.c
](Length: 216)
(stderr)[](Length: 0)
(status)[0]

[EXPECTED]:
(stdout)[](Length: 0)
(stderr)[./hsh: 1: hbtn_ls: not found
](Length: 29)
(status)[127]

## CHECK 27 OF TASK 3

In this check, the PATH is removed and you're expected not to execute the command even if it exists on your current directory, but it is not prefixed with ./

## Suggested Fix:

- If the Path is == NULL && strcmp(args[0], "hbtn_ls) == 0 && args[1] == NULL && args[0][0] != '.' && args[0][0] != '/'

## EXIT STATUS IS NOT RECOGNIZING CURRENT ERRNO VALUE

- Exit status when exit is entered is not correct.
- FIND AND FIX THE BUG AND RAISE A PULL REQUEST
