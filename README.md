[![Build
Status](https://travis-ci.com/Deftextra/regexEngine.svg?branch=master)](https://travis-ci.com/Deftextra/regexEngine)

# Regex engine implementation
The aim of this project is to create a regex engine using
Thompson's construction:
https://en.wikipedia.org/wiki/Thompson%27s_construction


## Building project

### project structure
There are three empty folders: `lib`, `bin` and `include` which are populated
by `Make install`.

To build to project, from the project root directory run the following commands:

```bash
> rm -rf build && mkdir build
> git submodule init && git submodule update
> cd build
> cmake ...
> make && make install
```
