# sundial

This prints the current epoch time and then the epoch times for the next sunrise and sunset.

Compile using 

```
$ gcc -Wall -o sundial -Wall main.c sundial.c -lm
```
or with **`make`**:
```
$ make
```

Then run 

```
$ ./sundial 35.994 -78.8986 -4 
35.994, -78.899
Currenttime: 1493814410
Sunrise: 1493893312
Sunset: 1493856329
```
