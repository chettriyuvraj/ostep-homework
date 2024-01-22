# Homework

## Question 1

Write a program that calls fork(). Before calling fork(), have the
main process access a variable (e.g., x) and set its value to something (e.g., 100). What value is the variable in the child process?
What happens to the variable when both the child and parent change
the value of x?

Answer:

- Both parent and child have their own copy of memory which is not affected when the other modifies it. This holds true for both local and global variables. There is also something called copy_on_write i.e initially they may share the same memory but as soon as it is touched to modify by either process, a copy is created.


## Question 2

Write a program that opens a file (with the open() system call)
and then calls fork() to create a new process. Can both the child
and parent access the file descriptor returned by open()? What
happens when they are writing to the file concurrently, i.e., at the
same time?

Answer:
- Have written a convoluted program.
- Yes, file descriptors are shared. 
When they are conccurently 


## Question 3

Write another program using fork(). The child process should
print “hello”; the parent process should print “goodbye”. You should
try to ensure that the child process always prints first; can you do
this without calling wait() in the parent?

Answer:
- Return to this after revising Exceptional Control Flow
- This is possible using some sort of killing signal


## Question 4

Write a program that calls fork() and then calls some form of
exec() to run the program /bin/ls. See if you can try all of the
variants of exec(), including (on Linux) execl(), execle(),
execlp(), execv(), execvp(), and execvpe(). Why do
you think there are so many variants of the same basic call?

Answer:

- Simply called some different variants of exec without fork
- Understood the utility of forking and exec-ing
- Reason for having so many variants is plain old flexibility

## Question 5

Now write a program that uses wait() to wait for the child process
to finish in the parent. What does wait() return? What happens if
you use wait() in the child?

Answer:

- If there is nothing to wait for - wait(NULL) will return -1 and exit.
- Created program to wait in both child and parent and print return values.
- Find out about other wait family functions such as waitpid etc


## Question 6

Write a slight modification of the previous program, this time using waitpid() instead of wait(). When would waitpid() be
useful?

- wait() is a case of waitpid()
- waitpid() offers more flexibility
- read waitpid() doc

## Question 7

 Write a program that creates a child process, and then in the child
closes standard output (STDOUT FILENO). What happens if the child
calls printf() to print some output after closing the descriptor?

- Similar to other variables, file descriptors are shared using copy-to-write i.e. same 'copy' is shared until the variable is modified
at which point it is finally copied.
- So closing fd in child process will have no impact on parent.

## Question 8

Write a program that creates two children, and connects the standard output of one to the standard input of the other, using the
pipe() system call.

- Done!
- Learnt a bit about the pipe() call.
- Unused file descriptors closed because each time we fork, a copy of the p[] array is created.
- p[1] is for writing to and p[0] is for reading from.
- Doesn't matter if a descriptor to the same write/read end is closed in one process - the descriptor to it in another process remains unaffected.
References:
    - https://tldp.org/LDP/lpg/node11.html
    - https://linuxhint.com/pipe_system_call_c/
    - https://stackoverflow.com/questions/40584034/when-and-why-do-i-have-to-close-pipe