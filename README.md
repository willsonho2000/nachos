# Nachos

This project was build successfully in VirtualBox 7.0, ubuntu 16.04 32bit.  
Please flowing the instructions below.


## Dependancy install
```
sudo apt install csh git
```

## Clone the repo and copy usr folder to /usr
```
git clone https://github.com/willsonho2000/nachos.git
cd nachos
sudo cp -r usr /
```

if you want to clone the specific branch.
```
git clone -b <branch_name> https://github.com/willsonho2000/nachos.git
```
or
```
git checkout -b <local_branch_name> origin/<branch_name>
```

## Go to code folder and make
```
cd nachos-4.0/code
make
```

## Executions

### Part1: System Call Implementation
```
cd ../userprog
user@user-VirtualBox:~/nachos/nachos-4.0/code/userprog$ ./nachos -e ../test/test_sleep -e ../test/test_sleep2
Total threads number is 2
Thread ../test/test_sleep is executing.
Thread ../test/test_sleep2 is executing.
Print integer:11
Print integer:0
Print integer:9
Print integer:7
Print integer:2
Print integer:5
Print integer:3
Print integer:4
Print integer:1
return value:0
Print integer:6
Print integer:8
return value:0
No threads ready or runnable, and no pending interrupts.
Assuming the program completed.
Machine halting!

Ticks: total 2100, idle 1533, system 270, user 297
Disk I/O: reads 0, writes 0
Console I/O: reads 0, writes 0
Paging: faults 0
Network I/O: packets received 0, sent 0
```

### Part 2: Scheduling
* Round-Robin (RR) Scheduling
```
user@user-VirtualBox:~/nachos/nachos-4.0/code/threads$ ./nachos RR
Schedule Type: RR
Thread: B, remaining tick: 8.
Thread: B, remaining tick: 7.
Thread: B, remaining tick: 6.
Thread: B, remaining tick: 5.
Thread: B, remaining tick: 4.
Thread: B, remaining tick: 3.
Thread: B, remaining tick: 2.
Thread: B, remaining tick: 1.
Thread: C, remaining tick: 2.
Thread: C, remaining tick: 1.
Thread: C, remaining tick: 0.
Thread: D, remaining tick: 6.
Thread: D, remaining tick: 5.
Thread: D, remaining tick: 4.
Thread: D, remaining tick: 3.
Thread: A, remaining tick: 4.
Thread: A, remaining tick: 3.
Thread: A, remaining tick: 2.
Thread: A, remaining tick: 1.
Thread: A, remaining tick: 0.
Thread: B, remaining tick: 0.
Thread: D, remaining tick: 2.
Thread: D, remaining tick: 1.
Thread: D, remaining tick: 0.
No threads ready or runnable, and no pending interrupts.
Assuming the program completed.
Machine halting!
```

* Priority Scheduling
```
user@user-VirtualBox:~/nachos/nachos-4.0/code/threads$ ./nachos PRIORITY
Schedule Type: Priority
Thread: D, remaining tick: 6.
Thread: D, remaining tick: 5.
Thread: D, remaining tick: 4.
Thread: D, remaining tick: 3.
Thread: D, remaining tick: 2.
Thread: D, remaining tick: 1.
Thread: D, remaining tick: 0.
Thread: B, remaining tick: 8.
Thread: B, remaining tick: 7.
Thread: B, remaining tick: 6.
Thread: B, remaining tick: 5.
Thread: B, remaining tick: 4.
Thread: B, remaining tick: 3.
Thread: B, remaining tick: 2.
Thread: B, remaining tick: 1.
Thread: B, remaining tick: 0.
Thread: A, remaining tick: 4.
Thread: A, remaining tick: 3.
Thread: A, remaining tick: 2.
Thread: A, remaining tick: 1.
Thread: A, remaining tick: 0.
Thread: C, remaining tick: 2.
Thread: C, remaining tick: 1.
Thread: C, remaining tick: 0.
No threads ready or runnable, and no pending interrupts.
Assuming the program completed.
Machine halting!
```
* First-Come First-Served (FCFS) Scheduling
```
user@user-VirtualBox:~/nachos/nachos-4.0/code/threads$ ./nachos FCFS
Schedule Type: FCFS
Thread: A, remaining tick: 4.
Thread: A, remaining tick: 3.
Thread: A, remaining tick: 2.
Thread: A, remaining tick: 1.
Thread: A, remaining tick: 0.
Thread: B, remaining tick: 8.
Thread: B, remaining tick: 7.
Thread: B, remaining tick: 6.
Thread: B, remaining tick: 5.
Thread: B, remaining tick: 4.
Thread: B, remaining tick: 3.
Thread: B, remaining tick: 2.
Thread: B, remaining tick: 1.
Thread: B, remaining tick: 0.
Thread: C, remaining tick: 2.
Thread: C, remaining tick: 1.
Thread: C, remaining tick: 0.
Thread: D, remaining tick: 6.
Thread: D, remaining tick: 5.
Thread: D, remaining tick: 4.
Thread: D, remaining tick: 3.
Thread: D, remaining tick: 2.
Thread: D, remaining tick: 1.
Thread: D, remaining tick: 0.
No threads ready or runnable, and no pending interrupts.
Assuming the program completed.
Machine halting!
```

* Shortest Job First (SJF) Scheduling
```
user@user-VirtualBox:~/nachos/nachos-4.0/code/threads$ ./nachos SJF
Schedule Type: SJF
Thread: C, remaining tick: 2.
Thread: C, remaining tick: 1.
Thread: C, remaining tick: 0.
Thread: A, remaining tick: 4.
Thread: A, remaining tick: 3.
Thread: A, remaining tick: 2.
Thread: A, remaining tick: 1.
Thread: A, remaining tick: 0.
Thread: D, remaining tick: 6.
Thread: D, remaining tick: 5.
Thread: D, remaining tick: 4.
Thread: D, remaining tick: 3.
Thread: D, remaining tick: 2.
Thread: D, remaining tick: 1.
Thread: D, remaining tick: 0.
Thread: B, remaining tick: 8.
Thread: B, remaining tick: 7.
Thread: B, remaining tick: 6.
Thread: B, remaining tick: 5.
Thread: B, remaining tick: 4.
Thread: B, remaining tick: 3.
Thread: B, remaining tick: 2.
Thread: B, remaining tick: 1.
Thread: B, remaining tick: 0.
No threads ready or runnable, and no pending interrupts.
Assuming the program completed.
Machine halting!
```

Check out r11222007_project2.pdf for details.