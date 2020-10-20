# DateBenchmark

little project to benchmark the date library

The project is self-contained. All dependencies are provided in `lib`.

- The library to benchmark is the [date/timezone library](https://github.com/HowardHinnant/date).
  - More info on the library can be found in the [wiki](https://github.com/HowardHinnant/date/wiki).
    - Documentation for [date](https://howardhinnant.github.io/date/date.html).
    - Documentation for [tz](https://howardhinnant.github.io/date/tz.html).
- [Speed issue](https://github.com/HowardHinnant/date/issues/453) on github.

To build and run tests, use the provided `Makefile`, which hides the horror of `cmake` with some `Make` horror.

Type `make` to see available commands:

```
$ make
For convenience

Available make targets:
make env          # show environment variables
make gen          # setup build configuration
make bld          # build tests
make test         # run tests
make cln          # clean current build environment
```

Some quick benchmarks: the c++17 version which has string_view is way faster but still shitty.

```
# c++11 MacOS 10

[ RUN      ] date.bench1
lookup: every call: time used 2976707 us
lookup: once      : time used 736749 us
[       OK ] date.bench1 (3713 ms)

# c++11 Linux 5.4.7



# c++17 MacOS 10

[ RUN      ] date.bench1
lookup: every call: time used 1353521 us
lookup: once      : time used 748987 us
[       OK ] date.bench1 (2103 ms)

# c++17 linux 5.4.7
[ RUN      ] date.bench1
lookup: every call: time used 1522165 us
lookup: once      : time used 579763 us
[       OK ] date.bench1 (2102 ms)
[----------] 1 test from date (2102 ms total)

```

With the local tzdb, massive improvements

```
# c++11

[ RUN      ] date.bench1
lookup: every call: time used 15674 us
lookup: once      : time used 19601 us
[       OK ] date.bench1 (35 ms)

[ RUN      ] date.bench1
lookup: every call: time used 18517 us
lookup: once      : time used 23297 us
[       OK ] date.bench1 (42 ms)

# c++17 MacOS 10

[ RUN      ] date.bench1
lookup: every call: time used 20116 us
lookup: once      : time used 16479 us
[       OK ] date.bench1 (37 ms)

# c++17 linux 5.4.7

[ RUN      ] date.bench1
lookup: every call: time used 8267 us
lookup: once      : time used 9719 us
[       OK ] date.bench1 (18 ms)
[----------] 1 test from date (18 ms total)

```


