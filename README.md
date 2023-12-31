Doom64EX-Plus
========

Doom64EX-Plus is a reverse-engineering project aimed to recreate Doom64 as close as possible with additional modding features.

**NOTE for Linux users:** As of Feb. 24, 2016, the save data is located in `$XDG_DATA_HOME/doom64ex-plus` (typically `~/.local/share/doom64ex-plus`) and not in `~/.doom64ex-plus`. The files can be safely moved to their new home.

## Dependencies

* SDL2
* SDL2_net
* zlib
* libpng
* FluidSynth

## Compiling

### Linux and MSYS (Windows)

Clone this repo

    $ git clone https://github.com/atsb/Doom64EX-Plus

Create a new directory inside the repo root where compilation will take place

    $ mkdir Doom64EX-Plus/temp
    $ cd Doom64EX-Plus/temp

Run cmake and make

    $ cmake .. && make
	
(For MSYS)

     $ cmake .. -G "MSYS Makefiles" && make
	 
Install doom64ex-plus

    # make install

## Usage

### Linux

Doom64EX-Plus needs the Doom 64 data to be present in any of the following directories:

* The directory in which `doom64ex-plus` resides
* `$XDG_DATA_HOME/doom64ex-plus` (eg. `~/.local/share/doom64ex-plus`)
* `/usr/local/share/games/doom64ex-plus`
* `/usr/local/share/doom64ex-plus`
* `/usr/share/games/doom64ex-plus`
* `/usr/share/doom64ex-plus`

The data files are:

* `doom64ex-plus.wad` (Generated by cmake)
* `doom64.wad`
* `doomsnd.sf2`

To generate the two latter files, acquire a Doom64 ROM and run:

    $ WadGen.exe (in the wadgen directory) and select your Doom64 ROM.

This will generate the required files and place them in `$XDG_DATA_DIR/doom64ex-plus`.

After this you can play.

    $ doom64ex-plus
