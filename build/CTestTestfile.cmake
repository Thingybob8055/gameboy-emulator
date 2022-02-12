# CMake generated Testfile for 
# Source directory: /home/akshay/projects/gbemu/code
# Build directory: /home/akshay/projects/gbemu/code/build
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(check_gbe "/home/akshay/projects/gbemu/code/build/tests/check_gbe")
set_tests_properties(check_gbe PROPERTIES  _BACKTRACE_TRIPLES "/home/akshay/projects/gbemu/code/CMakeLists.txt;96;add_test;/home/akshay/projects/gbemu/code/CMakeLists.txt;0;")
subdirs("lib")
subdirs("gbemu")
subdirs("tests")
