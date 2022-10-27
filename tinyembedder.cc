#include <iostream>
#include <fstream>
#include <iomanip>

int main(int argc, char *argv[]) {
  try {
    if (argc != 3) {
      throw std::runtime_error("wrong number of arguments");
    }

    std::ifstream in(argv[2]);

    if (!in) {
      throw std::runtime_error("unable to open input file");
    }

    std::ofstream out(std::string(argv[1]) + ".c");

    if (!out) {
      throw std::runtime_error("unable to open output file");
    }

    out << "#include <stdlib.h>\n\n";
    out << "char _tinyembed_" << argv[1] << "[] = {";

    const int symbols_per_line = 10;

    int i = symbols_per_line;
    for (int c = in.get(); in; c = in.get()) {
      if (i == symbols_per_line) {
        out << "\n\t";
        i = 0;
      }

      out << "0x" << std::hex << std::setw(2) << std::setfill('0') << c << ", ";

      i++;
    }

    out << "\n};\n\n";
    out << "size_t _tinyembed_" << argv[1] << "_size = sizeof(_tinyembed_" << argv[1] << ");\n";
  }
  catch (const std::runtime_error &e) {
    std::cerr << "Error: " << e.what() << "!\n";
    std::cerr << "Usage: " << argv[0] << " <symbol> <file>\n";

    return 1;
  }

  return 0;
}
