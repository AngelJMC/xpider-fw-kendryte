# xpider-fw-kendryte


## Compile project

```bash
mkdir kendryte-freertos-sdk/build && cd kendryte-freertos-sdk/build
cmake .. -DPROJ=xpider -DTOOLCHAIN=/opt/riscv-toolchain/bin && make
```


## Program to K210  

For fast programming usin kflash ( https://github.com/kendryte/kflash.py )

```bash
kflash -b 3000000 -B dan hello_world.bin
```