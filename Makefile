# -------------------------
#  CPU Utilisation Monitor
# -------------------------
#  Makefile
# --------
#  Copyright (c) 2015 Citrix
#
#  This program is free software: you can redistribute it and/or modify
#  it under the terms of the GNU General Public License as published by
#  the Free Software Foundation, version 2 of the License only.
#
#  This program is distributed in the hope that it will be useful,
#  but WITHOUT ANY WARRANTY; without even the implied warranty of
#  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
#  GNU General Public License for more details.
#
#  You should have received a copy of the GNU General Public License
#  along with this program.  If not, see <http://www.gnu.org/licenses/>.
#
# Please read the README file.

all: cumd

cumd: cumd.c cumd.h
	gcc -o cumd cumd.c -lrt # -DDEBUG

example: example.c cumd.h
	gcc -o example example.c -lrt

.PHONY: clean
clean:
	rm -f example cumd
