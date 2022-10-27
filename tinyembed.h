#pragma once

#include <stdint.h>

#define TINYEMBED_DATA(SYMBOL) []{ extern char   _tinyembed_##SYMBOL[];      return _tinyembed_##SYMBOL;        }()
#define TINYEMBED_SIZE(SYMBOL) []{ extern size_t _tinyembed_##SYMBOL##_size; return _tinyembed_##SYMBOL##_size; }()
