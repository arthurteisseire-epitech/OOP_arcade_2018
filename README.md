# Arcade

Arcade is a simulation of an arcade machine.\
You can plug games as dynamic libraries in games/ directory. If you want to create your own game, follow documentation in doc/arcade.pdf.\
Graphical libraries are also plugable as dynamic libraries in lib/ directory.
Qt5, SFML and libcaca are available.

## Install

### With Nix (easy)

If you don't have nix yet run `curl -L https://nixos.org/nix/install | sh` and read output messages.
```shell script
nix-shell shell.nix  # This will install all dependencies in a new environment
cmake .
make
```

### Manually

Install the following dependencies:
- gcc or clang
- cmake
- qt5
- sfml
- libcaca
- make sure qt5, sfml and libcaca libraries are available in your library path



## USAGE

`./arcade lib/lib_arcade_[graphical_libname].so`

You must provide a graphical libraries. Qt5, SFML are available.
Games are automatically found in games/ directory.

## Documentation

Read the pretty documentation at doc/arcade.pdf
