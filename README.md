# coding_corner
A playground for general coding tomfoolery

This library is using modern cmake based on the following tutorial for all C++ code:
https://github.com/schweitzer/modern-cmake-tutorial/tree/master

## Building the code

The code can be build by using the following commands

```bash
cmake -B build  -DCMAKE_BUILD_TYPE=Release
cmake --build build -j 20
```

If you want review or have more control over the settings, you can use the following commands
```bash
cd build
ccmake ../ # Provides a cmake curses environment to modify settings
```

## Testing the code
Navigate to the build directory and using the following commands
```bash
ctest                           # Runs all the tests
ctest -R <test_name>            # Runs a specific test
ctest --verbose -R <test_name>  # Runs a specific test with verbose output
```
