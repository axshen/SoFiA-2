# Makefile for the compilation of SoFiA 2
#
# Usage examples:
#   make                               for GCC or Clang without OpenMP
#   make OMP=-fopenmp                  for GCC or Clang with OpenMP
#   make CC=icc OPT=-O3 OMP=-openmp    for Intel C Compiler with OpenMP (not tested)
#   make clean                         remove object files after compilation


SRC = src/Array_dbl.c \
      src/Array_siz.c \
      src/Catalog.c \
      src/common.c \
      src/DataCube.c \
      src/Flagger.c \
      src/Header.c \
      src/LinkerPar.c \
      src/Map.c \
      src/Matrix.c \
      src/Parameter.c \
      src/Path.c \
      src/Source.c \
      src/Stack.c \
      src/statistics_dbl.c \
      src/statistics_flt.c \
      src/String.c \
      src/Table.c \
      src/WCS.c

OBJ = $(SRC:.c=.o)

# OPENMP = -fopenmp
OMP     =
OPT     = --std=c99 --pedantic -Wall -Wextra -Wshadow -Wno-unknown-pragmas -Wno-unused-function -Wfatal-errors -O3
LIBS    = -lm -lwcs
CC      = gcc
CFLAGS += $(OPT) $(OMP)

all:	sofia

sofia:	$(OBJ)
	$(CC) $(CFLAGS) -o sofia sofia.c $(OBJ) $(LIBS)

clean:
	rm -rf $(OBJ)
