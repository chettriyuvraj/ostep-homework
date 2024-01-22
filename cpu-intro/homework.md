# Homework

Solutions to homework questions at the back of [Process: The Abstraction](https://pages.cs.wisc.edu/~remzi/OSTEP/cpu-intro.pdf) chapter

## Question 1

Run process-run.py with the following flags: -l 5:100,5:100.
What should the CPU utilization be (e.g., the percent of time the
CPU is in use?) Why do you know this? Use the -c and -p flags to
see if you were right.

Answer:
- The CPU utilization should be 100 percent.
- The chances of a CPU instruction is 100 percent for both, so P1 will run first, issue all CPU instructions and as soon as it gets done, P2 will go from READY to RUNNING and do the same. There is no chance of an I/O instruction so the CPU will be occupied all the time.
- I was right :)

## Question 2

Now run with these flags: ./process-run.py -l 4:100,1:0.
These flags specify one process with 4 instructions (all to use the
CPU), and one that simply issues an I/O and waits for it to be done.
How long does it take to complete both processes? Use -c and -p
to find out if you were right

Answer:
- It should take 4 units to complete the first process.
- Second process goes to RUN:io (1 unit) + time for io to finish => 4 seconds + 1 second + IO time
- No I was wrong
    - Second process goes to RUN:io (1 unit) + IO time (5 units) + RUN: io_done (1 unit)  = 11 units

## Question 3

Switch the order of the processes: -l 1:0,4:100. What happens
now? Does switching the order matter? Why? (As always, use -c
and -p to see if you were right)

- First process will issue a RUN:io (1 unit)
- Second process will start executing and complete (4 units)
- Switch back to process for RUN:io_done (1 unit)
- Total runtime = 1 + 4 + 1 = 6 units
- Yes it does matter as we have managed to shave off the IO_time by doing CPU work in that time
- Slightly wrong:
    - The process 2 completes in 4 seconds, but IO for process 1 has 1 second remaining
    - So we have an additional second of wait where no CPU is utilized => Total time = 7 seconds

## Question 4

We’ll now explore some of the other flags. One important flag is
-S, which determines how the system reacts when a process issues an I/O. With the flag set to SWITCH ON END, the system
will NOT switch to another process while one is doing I/O, instead waiting until the process is completely finished. What happens when you run the following two processes (-l 1:0,4:100
-c -S SWITCH ON END), one doing I/O and the other doing CPU
work?

Answer:
- The first process issues a RUN:io (1 unit). It then starts performing io, during which we are blocked because of are new policy (5 units). Finally a RUN:io_complete is issued (1 unit).
- We now switch to our second process, which uses the CPU entirely for it's designated time (4 units)
- The total time is: 1 + 5 + 1 + 4 = 11 units
- I am correct :)

## Question 5

Now, run the same processes, but with the switching behavior set
to switch to another process whenever one is WAITING for I/O (-l
1:0,4:100 -c -S SWITCH ON IO). What happens now? Use -c
and -p to confirm that you are right.

- I think this would be the default behaviour that we encountered in question 3
- I am correct :)

## Question 6

One other important behavior is what to do when an I/O completes. With -I IO RUN LATER, when an I/O completes, the process that issued it is not necessarily run right away; rather, whatever was running at the time keeps running. What happens when
you run this combination of processes? (./process-run.py -l
3:0,5:100,5:100,5:100 -S SWITCH ON IO -c -p -I
IO RUN LATER) Are system resources being effectively utilized?

- Process 1 starts with a RUN:io (1 unit)
- Process 2 executes (5 units)
- Process 1's IO is complete, it issues RUN:io_done(1 unit), then another RUN:io (1 unit)
- Process 3 executes (5 units)
- Process 1's IO is complete, it issues RUN:io_done(1 unit), then another RUN:io (1 unit) 
- Process 4 executes (5 units)
- Process1's IO is complete, it issues RUN: io_done(1 unit)
- Total Time = 1 + 5 + (1 + 1) + 5 + (1 + 1) + 5 + 1 = 21 units
- Yes system resources are effectively utilized as CPU is busy all the time and IO is busy most of the time.

- I was wrong:
    - The CPU actually continues on it's normal course and comes back to the IO right at the end
    - My wrong answer made me realize that the actual answer != good resources of the CPU since IO is free a lot of the times
    - Stats: 
        - Total Time 31
        - Stats: CPU Busy 21 (67.74%)
        - Stats: IO Busy  15 (48.39%)

## Question 7

Now run the same processes, but with -I IO RUN IMMEDIATE set,
which immediately runs the process that issued the I/O. How does
this behavior differ? Why might running a process that just completed an I/O again be a good idea?

Answer
- My wrong answer to the previous question + reasoning, would be the right answer to this one
- Compare the stats:
    - Stats: 
        - Total Time 21
        - Stats: CPU Busy 21 (100.00%)
        - Stats: IO Busy  15 (71.43%)

## Question 8

Now run with some randomly generated processes using flags -s
1 -l 3:50,3:50 or -s 2 -l 3:50,3:50 or -s 3 -l 3:50,
3:50. See if you can predict how the trace will turn out. What happens when you use the flag -I IO RUN IMMEDIATE versus that
flag -I IO RUN LATER? What happens when you use the flag -S
SWITCH ON IO versus -S SWITCH ON END?

Answer:
- Since something like 3:50, 3:50 shouldn't be deterministic (right?), how am I supposed to figure the trace.
- What does a random seed mean?
