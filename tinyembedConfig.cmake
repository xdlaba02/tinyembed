cmake_minimum_required(VERSION 3.19)

if (NOT TARGET tinyembed::tinyembed)
  add_subdirectory("${CMAKE_CURRENT_LIST_DIR}" "${CMAKE_BINARY_DIR}/tinyembed/")
  add_executable(tinyembed::tinyembedder ALIAS tinyembedder)
  add_library(tinyembed::tinyembed ALIAS tinyembed)
  include("${CMAKE_CURRENT_LIST_DIR}/tinyembedMacros.cmake")
endif()
