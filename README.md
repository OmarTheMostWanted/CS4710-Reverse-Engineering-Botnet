# Reverse Engineering Botnet (Bot123)

## Analysis Methods
### Reverse Engineering and Decompiling
### Virus Total Report
### Dynamic Analysis
#### Any.run Results
The results of running the program on Any.run can be found [here](https://any.run/report/3b1be8499ec382dfafbc496a73dea2794f6dd201b3e46a4128c7fcd88e8c17c2/32322955-6166-4ee8-9440-baa59267c993), when using a proxy a slightly different result can be found [here](https://any.run/report/963a062aa8d6950fa219284859f9c6dc527eb69480b78fd614bd6959d604e7a1/e10b7092-359e-45eb-957a-d520ce6a8e28)

#### GDB Results

## Interseting Parts in the Decompiled Code

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

## Bot behaviour

## Python Remake
