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

## Check if you are success
```
cd ../userprog
user@user-VirtualBox:~/nachos/project3-part2/nachos-4.0/code/threads$ ./nachos 
A: remaining 2
A: remaining 1
A: remaining 0
C: remaining 6
C: remaining 5
C: remaining 4
C: remaining 3
C: remaining 2
C: remaining 1
C: remaining 0
B: remaining 8
B: remaining 7
B: remaining 6
B: remaining 5
B: remaining 4
B: remaining 3
B: remaining 2
B: remaining 1
D: remaining 2
D: remaining 1
D: remaining 0
B: remaining 0
No threads ready or runnable, and no pending interrupts.
Assuming the program completed.
Machine halting!

Ticks: total 400, idle 60, system 340, user 0
Disk I/O: reads 0, writes 0
Console I/O: reads 0, writes 0
Paging: faults 0
Network I/O: packets received 0, sent 0

```
