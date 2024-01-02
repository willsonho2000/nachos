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

* Random
```
cd ../userprog
user@user-VirtualBox:~/nachos/nachos-4.0/code/userprog$ ./nachos -e ../test/matmult -e ../test/sort
Schedule Type: RR
Total threads number is 2
Thread ../test/matmult is executing.
Thread ../test/sort is executing.
 Number of pages of ../test/matmult is 54
 Number of pages of ../test/sort is 46
return value: 7220
return value: 1023
No threads ready or runnable, and no pending interrupts.
Assuming the program completed.
Machine halting!

Ticks: total 33436022, idle 15697721, system 53630, user 17684671
Disk I/O: reads 875, writes 911
Console I/O: reads 0, writes 0
Paging: faults 875
Network I/O: packets received 0, sent 0
```

* Fisrt-In-First-Out (FIFO) Algorithm
```
cd ../userprog
user@user-VirtualBox:~/nachos/nachos-4.0/code/userprog$ ./nachos -e ../test/matmult -e ../test/sort
Schedule Type: RR
Total threads number is 2
Thread ../test/matmult is executing.
Thread ../test/sort is executing.
 Number of pages of ../test/matmult is 54
 Number of pages of ../test/sort is 46
return value: 7220
return value: 1023
No threads ready or runnable, and no pending interrupts.
Assuming the program completed.
Machine halting!

Ticks: total 53245022, idle 35455664, system 103850, user 17685508
Disk I/O: reads 1712, writes 1748
Console I/O: reads 0, writes 0
Paging: faults 1712
Network I/O: packets received 0, sent 0
```

* Least Recently Used (LRU) Algorithm (Not Perfect)
```
cd ../userprog
user@user-VirtualBox:~/nachos/nachos-4.0/code/userprog$ ./nachos -e ../test/matmult -e ../test/sort
Schedule Type: RR
Total threads number is 2
Thread ../test/matmult is executing.
Thread ../test/sort is executing.
 Number of pages of ../test/matmult is 54
 Number of pages of ../test/sort is 46
return value: 7220
return value: 1023
No threads ready or runnable, and no pending interrupts.
Assuming the program completed.
Machine halting!

Ticks: total 32077022, idle 14338599, system 53750, user 17684673
Disk I/O: reads 877, writes 913
Console I/O: reads 0, writes 0
Paging: faults 877
Network I/O: packets received 0, sent 0
```

Check out r11222007_project3_part1.pdf for details.