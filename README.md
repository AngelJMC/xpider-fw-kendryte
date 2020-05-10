# xpider-fw-kendryte


## Compile project

```bash
mkdir build && cd build
cmake .. -DTOOLCHAIN=/opt/riscv-toolchain/bin
make
```


## Program to K210  

For fast programming usin kflash ( https://github.com/kendryte/kflash.py )

```bash
kflash -b 3000000 -B dan xpider-fw-kendryte.bin
```