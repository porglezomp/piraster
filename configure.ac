#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.69])
AC_INIT([piraster], [0.1], [bugs.adventurous@gmail.com])
AC_CONFIG_AUX_DIR([build-aux])
AM_INIT_AUTOMAKE([-Wall -Werror foreign subdir-objects])
AC_CONFIG_SRCDIR([src/])
AC_CONFIG_HEADERS([config.h])

AC_SUBST([libname], [piraster])

# Checks for programs.
AC_PROG_CXX
AC_PROG_CC
AC_PROG_RANLIB
AM_PROG_AR

# Checks for libraries.
AC_CHECK_LIB([SDL], [SDL_Init])

# Checks for header files.

# Checks for typedefs, structures, and compiler characteristics.

# Checks for library functions.

AC_CONFIG_FILES([Makefile
				 src/Makefile
				 test/Makefile])

AC_OUTPUT
