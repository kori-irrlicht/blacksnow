/*
 ============================================================================
 Name        : BlackSnow.c
 Author      : koridevel
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "gettext.h"
#define _(String) gettext (String)

int main(void) {

	setlocale (LC_ALL, "");
	bindtextdomain (PACKAGE, LOCALEDIR);
	textdomain (PACKAGE);

	puts(_("Hello World")); /* prints Hello World */
	return EXIT_SUCCESS;
}
