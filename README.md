# C++ home work

## prepare build files

```sh
# create build files
$ cmake -B build -DCMAKE_EXPORT_COMPILE_COMMANDS=YES
# or for debug support
$ cmake -B build -DCMAKE_EXPORT_COMPILE_COMMANDS=YES -DCMAKE_BUILD_TYPE=Debug
```

## build and run

```sh
# build
$ cd build
$ make
$ ./cpwite

# or run script `watch.sh`. It build, run and repeat if `src/**` has been changed
# It is required install `inotifywait`
$ ./watch.sh
```

## debug by vimspector

About vimspector see https://github.com/puremourning/vimspector

```sh
# create build files for debug support
$ cmake -B build -DCMAKE_EXPORT_COMPILE_COMMANDS=YES -DCMAKE_BUILD_TYPE=Debug
```

Instructions:

-   in vim, open `src/main.cpp`
-   set a breakpoint on main `F9` [see keys map](https://github.com/puremourning/vimspector#human-mode)
-   start the debug session in Vim by hitting the `F5`
-   after debug finished execute `:VimspectorReset` command
