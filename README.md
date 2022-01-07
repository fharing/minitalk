## About

The purpose of this project is to code a small data exchange program using UNIX signals.

The project consits of 2 executables the server and the client.
The client must send the string passed as a parameter to the server.
Once the string has been received, the server must print it.
The server has to display the string pretty quickly.
The server should be able to receive strings from several clients in a row without
needing to restart.
The communication between the client and the server is only using UNIX signals.

Bonus list:
- The server acknowledges every message received by sending back a signal to the
client.
- Unicode characters support!

| Program name | server - client |
| :--- | :--- |
| Arguments | a map in format *.ber |
| External functions | write, ft_printf, signal, sigemptyset, sigaddset, sigaction, kill, getpid, malloc, free, pause, sleep, usleep, exit |

## How to use

Clone the repository:
```bash
https://github.com/fharing/minitalk.git
```
Go to the repository and run make:
```bash
make
```
First start the server by calling the executable:
```bash
./server
```

The server will print its PID(process id) to stdout.
Then start the client by calling the executable:
```bash
./client PID-SERVER "STRING TO PASS"
```
