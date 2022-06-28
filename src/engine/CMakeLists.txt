##------------------------------------------------------------------------------
##
## Doom64EX CMake configuration
##
## LICENSE:
##
## Copyright(C) 2014-2016 Zohar Malamant, 2022 Gibbon
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

set(SOURCE_ROOT_DIR "${CMAKE_SOURCE_DIR}/src/engine")

##------------------------------------------------------------------------------
## Set up external dependencies
##

# kexlib
add_include_directories("${CMAKE_SOURCE_DIR}/include/kexlib")
add_link_libraries(kexlib)

# SDL2
find_package(SDL2 REQUIRED)
add_include_directories(${SDL2_INCLUDE_DIRS})
add_link_libraries(${SDL2_LIBRARIES})

# SDL2_Net
find_package(SDL2_net REQUIRED)
add_include_directories(${SDL2_NET_INCLUDE_DIRS})
add_link_libraries(${SDL2_NET_LIBRARIES})

# zlib
find_package(ZLIB REQUIRED)

# libpng
find_package(PNG REQUIRED)
add_include_directories(${PNG_INCLUDE_DIRS})
add_link_libraries(${PNG_LIBRARIES})

# FluidSynth
find_package(FluidSynth REQUIRED)
add_include_directories(${FLUIDSYNTH_INCLUDE_DIR})
add_link_libraries(${FLUIDSYNTH_LIBRARIES})

# OpenGL
find_package(OpenGL REQUIRED)
add_include_directories(${OPENGL_INCLUDE_DIRS})
add_link_libraries(${OPENGL_LIBRARIES})

##------------------------------------------------------------------------------
## Configure "version.h"
##

set(VERSION_MAJOR 3)
set(VERSION_MINOR 2)
set(VERSION_PATCH 0)
set(VERSION_GIT true)

##------------------------------------------------------------------------------
## Platform-specific sources
##

if (WIN32)

set(WIN32_GAME_SOURCE_FILES
i_cpu.c win32/doom64ex-plus.rc)

else ()

set(POSIX_GAME_SOURCE_FILES
i_cpu_posix.c)

  add_link_libraries(m) # math lib
endif ()

##------------------------------------------------------------------------------
## Sources
##

set(GAME_SOURCE_FILES
am_draw.c am_map.c info.c md5.c tables.c
con_console.c con_cvar.c d_devstat.c d_main.c
d_net.c f_finale.c in_stuff.c 
g_actions.c g_demo.c g_game.c g_settings.c
wi_stuff.c m_cheat.c m_fixed.c m_keys.c m_menu.c m_misc.c m_password.c
m_random.c m_shift.c net_client.c net_common.c net_dedicated.c
net_io.c net_loop.c net_packet.c net_query.c net_sdl.c net_server.c net_structrw.c
dgl.c gl_draw.c gl_main.c gl_texture.c 
sc_main.c p_ceilng.c p_doors.c p_enemy.c
p_floor.c p_inter.c p_lights.c p_macros.c p_map.c p_maputl.c p_mobj.c
p_plats.c p_pspr.c p_saveg.c p_setup.c p_sight.c p_spec.c p_switch.c p_telept.c
p_tick.c p_user.c r_bsp.c r_clipper.c r_drawlist.c r_lights.c r_main.c
r_scene.c r_sky.c r_things.c r_wipe.c s_sound.c st_stuff.c i_audio.c
i_main.c i_png.c i_system.c i_video.c w_file.c w_merge.c w_wad.c
wadgen/deflate-N64.c wadgen/files.c wadgen/gfx.c  wadgen/level.c
wadgen/mem.c wadgen/png.c wadgen/rom.c wadgen/sndfont.c
wadgen/sound.c wadgen/sprite.c wadgen/texture.c wadgen/wad.c
wadgen/wadgen.c z_zone.c)

if (WIN32)

set(SOURCE_FILES ${GAME_SOURCE_FILES} ${WIN32_GAME_SOURCE_FILES})

else ()

set(SOURCE_FILES ${GAME_SOURCE_FILES} ${POSIX_GAME_SOURCE_FILES})

endif ()

##------------------------------------------------------------------------------
## Build target
##

add_executable(doom64ex-plus MACOSX_BUNDLE ${SOURCE_FILES})
target_include_directories(doom64ex-plus PRIVATE ${INCLUDES})
target_link_libraries(doom64ex-plus ${LIBRARIES})
add_dependencies(doom64ex-plus doom64expluswad)


##------------------------------------------------------------------------------
## Install target
##

if (NOT WIN32)
  install(PROGRAMS ${CMAKE_CURRENT_BINARY_DIR}/doom64ex-plus DESTINATION bin)
endif ()