# Build bTox from source


------
## Build Deps
### c-toxcore [(github)](https://github.com/TokTok/c-toxcore)
### Install
```
sudo apt install libtoxcore2 libtoxcore-dev
```
### OR Build
```
git clone https://github.com/TokTok/c-toxcore
cd c-toxcore
mkdir _build && cd _build
cmake ..
make
sudo make install
```
------

### libsodim [(github)](https://github.com/jedisct1/libsodium)
### Install
```
sudo apt install libsodium23 libsodium-dev
```
### OR Build
```
git clone https://github.com/jedisct1/libsodium 
cd libsodim
./configure
make && make check
sudo make install
```
------
## Build bTox
```
git clone https://github.com/Naster17/btox 
cd btox 
make
```

