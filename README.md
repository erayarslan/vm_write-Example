# vm_write-Example

MemoryHacking-MacOSX

## victim output

> pid#(value)[addr]

## attacker params

```cpp
#define PID 1030
#define ADDR 0x7fff51e24bac

int value = 123456;
```

> Victim Info's <3

## usage

```sh
$ gcc victim.c -o victim 
$ gcc attacker.c -o attacker
$ ./victim
$ sudo ./attacker
```

> Attacker Boy Need ROOT!

## license

fuck it.