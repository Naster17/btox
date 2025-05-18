# BranchTox - bTox
Tox client with branch support features. Create branches like in forum!

# Build Deps
## c-toxcore [(github)](https://github.com/TokTok/c-toxcore)
### Install
```
sudo apt install libtoxcore2 libtoxcore-dev
```
### Build
```
git clone https://github.com/TokTok/c-toxcore
cd c-toxcore
mkdir _build && cd _build
cmake ..
make
sudo make install
```
------

## libsodim [(github)](https://github.com/jedisct1/libsodium)
### Install
```
sudo apt install libsodium23 libsodium-dev
```
### Build
```
git clone https://github.com/jedisct1/libsodium 
cd libsodim
./configure
make && make check
sudo make install
```
