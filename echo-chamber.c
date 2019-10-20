/*
 * Copyright 2019 Jan Klötzke
 *
 * SPDX-License-Identifier: MIT
 */

#include <stdio.h>
#include <stdlib.h>

#include <echo.h>

static struct echo echo;

static void msg_print(const char *msg)
{
	printf("%s", msg);
}

int main(void)
{
	int ch;

	if (echo_init(&echo, msg_print) != 0) {
		fprintf(stderr, "Error initializing echo library!\n");
		return EXIT_FAILURE;
	}

	printf("Type some characters and press enter...\n");
	while ((ch = getchar()) != EOF) {
		if (ch == '\n')
			ch = '\r';
		echo_putchar(&echo, ch);
	}

	return EXIT_SUCCESS;
}
