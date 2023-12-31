##------------------------------------------------------------------------------
##
## Doom64EX CMake configuration
##
## LICENSE:
##
## Copyright(C) 2014-2016 Zohar Malamant
##
## This program is free software; you can redistribute it and/or
## modify it under the terms of the GNU General Public License
## as published by the Free Software Foundation; either version 2
## of the License, or (at your option) any later version.
##
## This program is distributed in the hope that it will be useful,
## but WITHOUT ANY WARRANTY; without even the implied warranty of
## MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
## GNU General Public License for more details.
##
## You should have received a copy of the GNU General Public License
## along with this program; if not, write to the Free Software
## Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA
## 02111-1307, USA.
##

##------------------------------------------------------------------------------
## CMake functions
##

##------------------------------------------------------------------------------
## Sources
##

# We're lazy, so add all C files
file(GLOB_RECURSE SOURCES "${CMAKE_SOURCE_DIR}/src/kexlib/*.c")

##------------------------------------------------------------------------------
## Build target
##

add_library(kexlib STATIC ${SOURCES})
target_include_directories(kexlib PRIVATE "${CMAKE_SOURCE_DIR}/include/kexlib")
target_link_libraries(kexlib m)

##------------------------------------------------------------------------------
## Build tests
##

if (TESTING)
  find_package(GTest REQUIRED)

  file(GLOB_RECURSE TEST_SOURCES "${CMAKE_SOURCE_DIR}/test/kexlib/*.cc")

  add_executable(kexlib_test ${TEST_SOURCES})
  target_include_directories(kexlib_test PRIVATE "${CMAKE_SOURCE_DIR}/include/kexlib" ${GTEST_INCLUDE_DIRS})
  target_link_libraries(kexlib_test kexlib ${GTEST_BOTH_LIBRARIES})

  add_test(AllTestsInKexlib COMMAND kexlib_test)
endif()