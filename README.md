# <ins>simple shell</ins></span>
![img.png](img.png)
## <ins>*Resources*
### <ins>*_Read or watch:_*
* ### [unix shell](https://intranet.alxswe.com/rltoken/f0YU9TAhniMXWlSXtb64Yw)
* ### [Thompson shell](https://intranet.alxswe.com/rltoken/7LJOp2qP7qHUcsOK2-F3qA)
* ### [ken thompson](https://intranet.alxswe.com/rltoken/wTSu31ZP1f7fFTJFgRQC7w)
* ### [Everything you need to know to start coding your own shell concept page](https://intranet.alxswe.com/concepts/64)
## <ins>*_PID & PPID_*
**A process is an instance of an executing program, that has a unique process ID. This process ID is used by many functions and system calls to interact with and manipulate processes. In order to retrieve the current process’ ID, you can use the system call getpid (man 2 getpid):**
![img_1.png](img_1.png)
* ###  **Note in the example above, that every time you run the program, a new process is created, and its ID is different.**
##### *Each process has a parent: the process that created it. It is possible to get the PID of a parent process by using the getppid system call (man 2 getppid), from within the child process*
### <ins>Exercises
#### <ins>0.getppid
**_Write a program that prints the PID of the parent process. Run your program several times within the same shell. It should be the same. Does echo $$ print the same value? Why?_**
#### <ins>1./proc/sys/kernel/pid_max
**_Write a shell script that prints the maximum value a process ID can be._**
### <ins>Arguments
#### The command line arguments are passed through the main function: int main(int ac, char **av);
* **av is a NULL terminated array of strings**
* **ac is the number of items in av**
#### av[0] usually contains the name used to invoke the current program. av[1] is the first argument of the program, av[2] the second, and so on.
### <ins>Exercises
