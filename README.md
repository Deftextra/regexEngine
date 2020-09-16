[![Build
Status](https://travis-ci.com/Deftextra/regexEngine.svg?branch=master)](https://travis-ci.com/Deftextra/regexEngine)

# Regex engine implementation
The aim of this project is to create a regular expression engine using
[Thompson's construction](https://en.wikipedia.org/wiki/Thompson%27s_construction)

At the current stage in development, the engine converts each regex expression into its corresponding non deterministic finite automata and supports only text directed matching.

## Possible additional features.
* Regex-directed matching features, such as look back and capture groups.

## Usage

### Development
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
or you can run the script [build.sh](build.sh) to execute a clean build.

### Engine
Currently we have the ``class NDFA`` which a converts a regular expression to an automata
by passing the regular expression as an argument:

```c++
std::string regex = "a*|a*b"
NDFA corrosponding_automata{regex};

std::string text1 {"aaaaaaaa"};
std::string text2 {"aaaaaaaab"};
std::string text3 {"bb"};

std::cout << corrosponding_automata.match(text); // prints true
std::cout << corrosponding_automata.match(text); // prints true
std::cout << corrosponding_automata.match(text3) // prints false
```






