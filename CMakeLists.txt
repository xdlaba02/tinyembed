cmake_minimum_required(VERSION 3.19)

project(tinyembed VERSION 1.0.0)

add_executable(tinyembedder "tinyembedder.cc")

add_library(tinyembed INTERFACE "tinyembed.h")

set_target_properties(tinyembed PROPERTIES PUBLIC_HEADER "tinyembed.h")

include(GNUInstallDirs)

set(CMAKE_INSTALL_CMAKEDIR "${CMAKE_INSTALL_LIBDIR}/cmake/tinyembed")

target_include_directories(tinyembed
	INTERFACE
		$<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
		$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
)

install(
	TARGETS
		tinyembedder
		tinyembed
	EXPORT tinyembed-export
)

install(
	EXPORT tinyembed-export
	FILE tinyembedTargets.cmake
	NAMESPACE tinyembed::
	DESTINATION ${CMAKE_INSTALL_CMAKEDIR}
)

include(CMakePackageConfigHelpers)

write_basic_package_version_file(
  ${CMAKE_CURRENT_BINARY_DIR}/tinyembedConfigVersion.cmake
  COMPATIBILITY SameMajorVersion
)

configure_package_config_file(
	tinyembedConfig.cmake.in
  ${CMAKE_CURRENT_BINARY_DIR}/tinyembedConfig.cmake
  INSTALL_DESTINATION ${CMAKE_INSTALL_CMAKEDIR}
)

install(
	FILES
	  ${CMAKE_CURRENT_SOURCE_DIR}/tinyembedMacros.cmake
	  ${CMAKE_CURRENT_BINARY_DIR}/tinyembedConfig.cmake
		${CMAKE_CURRENT_BINARY_DIR}/tinyembedConfigVersion.cmake
	DESTINATION ${CMAKE_INSTALL_CMAKEDIR}
)
