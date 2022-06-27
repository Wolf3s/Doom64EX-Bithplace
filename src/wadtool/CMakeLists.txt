##------------------------------------------------------------------------------
##
## Doom64EX-Plus CMake configuration
##
## LICENSE:
##
## Copyright(C) 2016 Zohar Malamant
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
## Sources
##

set(SOURCES
  main.c
  )

##------------------------------------------------------------------------------
## Build target
##

add_executable(wadtool ${SOURCES})

# Generate doom64ex-plus.wad
add_custom_target(doom64expluswad
  DEPENDS wadtool
  COMMAND wadtool "${CMAKE_SOURCE_DIR}/data/kex" "${CMAKE_BINARY_DIR}/doom64ex-plus.wad"
  )

##------------------------------------------------------------------------------
## Install target
##

# Install doom64ex-plus.wad
if (NOT WIN32)
  install(FILES ${CMAKE_CURRENT_BINARY_DIR}/doom64ex-plus.wad DESTINATION share/games/doom64ex-plus)
endif ()