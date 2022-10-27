# tinyembed
Minimalistic cross-platform tool and `C++` library for embedding small resources into binaries.

## Compilation
You can compile the tool via the usual

    mkdir build
    cd build
    cmake ..
    cmake --build .

## Integration
If you want to add the library to the build of your project, the best way is to set the `tinyembed_DIR` CMake variable to the directory containing the `tinyembed-config.cmake` script. This way, you can then include the library via the

    find_package(tinyembed)

command. This will expose two targets:
-- `tinyembed::tinyembedder` target represents the tool for converting binary data into `C` source code.
-- `tinyembed::tinyembed` target represents the library containing macros for retrieving the data from the source code side.

The package will also provide the `target_embed_resource` CMake macro for embedding a file to a target.

## Usage
To embed a file to your target, add

    target_embed_resource(<target> <symbol> <file>)

to your CMake code. This will embed file `<file>` into a target `<target>`.
To retrieve the resource from your code, first link the `tinyembed::tinyembed` library to your target and include the header `<tinyembed.h>`.
Then use the `TINYEMBED_DATA(<symbol>)` macro to retrieve a pointer to the binary data and the `TINYEMBED_SIZE(<symbol>)` macro to retrieve the size of the data.

## Note
All resources added via this library are converted to a text file that is parsed by the compiler. This is fine for small resources but could be slow and memory-consuming for large files. To embed a large file into your binary, use [Windows resource files](https://learn.microsoft.com/en-us/cpp/windows/resource-files-visual-studio) or exploit the [ld's capability to turn any file into an object](https://stackoverflow.com/a/4158997).

## License
See [LICENSE](LICENSE) for license and copyright information.
