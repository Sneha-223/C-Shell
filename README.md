## OS Assignment 2
#### Sneha Raghava Raju 
**2020101125**
<br>

## Compiling and Running the Shell

run `make` to generate the executable

run `./run` to run the shell

Use the command `exit` to exit the shell

## Commands

The shell takes the commands listed below. Commands can be seperated by ';' or by the newline character '\n'.

#### cd command
Implemented in **`cd.c`**

- `cd <path>` - changes directory to  path
- `cd` or `cd .` - changes directory to current directory
- `cd ..` - changes directory to the parent directory
- `cd ~` - changes directory to the shell's root directory (i.e the directory the shell is executing from)
- `cd -` - changes directory to the previous directory (i.e the last directory that the shell prompt showed)

#### echo command
Implemented in **`echo.c`**

- `echo` - prints empty line
- `echo <text>` - prints text
- `echo "text     'text2'       "`  - prints:  "text 'text2'"  (i.e handles tabs and spaces)

#### pwd command
Implemented in **`pwd.c`**

- `pwd` - prints absolute path of current directory

#### ls command

Implemented in **`ls.c`**

-  ls takes arguments:  `<flags>` and `<path>` 
- It lists the files of the path mentioned (directory or file). 
- `ls` - if no path is mentioned, lists the files in the current directory
- `ls -l` - displays the files in the long listing format
- `ls -a` - displays all files including hidden files
- `ls -al/-la/-a -l/-l -a` - long listing format of all files including hidden files
- `ls -l <dir1> -a <dir2>` - for any variation of flags and multiple directories, the flags will be applied to all directories (i.e order doesn't matter).

#### Foreground processes
Implemented in **`foregroundprocess.c`**

- The shell waits till the current process finishes executing

#### Background processes
Implemented in **`backgroundprocess.c`**

- `<command> &`  - Using '&' at the end a command invoke a background process
- The process will run in the background and display a message when it exits

#### pinfo command
Implemented in **`pinfo.c`**

- `pinfo` - prints process information of the shell
- `pinfo <pid>` - prints process information of the given pid

#### repeat command
Implemented in **`main.c`**

- `repeat <x> <command> <arg>` - repeats the 'command', with arguments 'args', 'x' number of times
- Eg: `repeat 2 echo hello` will print 'hello' twice

#### exit command
- `exit` - exits the shell

