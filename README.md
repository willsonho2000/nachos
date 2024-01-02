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
```
cd ../userprog
user@user-VirtualBox:~/nachos/nachos-4.0/code/userprog$ ./nachos -e ../test/test1 -e ../test/test2
Total threads number is 1
Thread ../test/test1 is executing.
Print integer:9
Print integer:8
Print integer:7
Print integer:6
return value:0
No threads ready or runnable, and no pending interrupts.
Assuming the program completed.
Machine halting!

Ticks: total 200, idle 66, system 40, user 94
Disk I/O: reads 0, writes 0
Console I/O: reads 0, writes 0
Paging: faults 0
Network I/O: packets received 0, sent 0
```


Check out r11222007_project1.pdf for details.