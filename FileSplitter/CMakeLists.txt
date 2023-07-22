add_executable (FileSplitter "FileSplitter.cpp" "FileSplitter.h" )

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET FileSplitter PROPERTY CXX_STANDARD 20)
endif()
