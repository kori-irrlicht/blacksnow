dnl Process this file with autoconf to produce a configure script.

AC_PREREQ(2.59)
AC_INIT(BlackSnow, 1.0)

AM_GNU_GETTEXT([external])
AM_GNU_GETTEXT_VERSION(0.19)

AC_CANONICAL_SYSTEM
AM_INIT_AUTOMAKE()

AC_PROG_CC

  dnl Check for SDL
  SDL_VERSION=2.0.4
  AM_PATH_SDL2($SDL_VERSION,
            :,
            AC_MSG_ERROR([*** SDL version $SDL_VERSION not found!])
  )
  CFLAGS="$CFLAGS $SDL_CFLAGS -std=c11"
  LIBS="$LIBS $SDL_LIBS"

AC_MSG_CHECKING(whether compiler understands -Wall)
old_CFLAGS="$CFLAGS"
CFLAGS="$CFLAGS -Wall"
AC_COMPILE_IFELSE([AC_LANG_PROGRAM([],[])],
  AC_MSG_RESULT(yes),
    AC_MSG_RESULT(no)
      CFLAGS="$old_CFLAGS")

AC_CONFIG_FILES(Makefile assets/Makefile src/Makefile po/Makefile.in)
AC_OUTPUT

