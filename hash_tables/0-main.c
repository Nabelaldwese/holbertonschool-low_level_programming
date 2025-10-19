/* tests/0-main.c */
#include <stdlib.h>
#include <stdio.h>
#include "hash_tables.h"

/**
 * main - check the code for task 0
 *
 * Return: Always EXIT_SUCCESS.
 */
int main(void)
{
	hash_table_t *ht;

	ht = hash_table_create(1024);
	printf("%p\n", (void *)ht);

	/* حتى لا يشتكي Valgrind من تسريبات */
	hash_table_delete(ht);

	return (EXIT_SUCCESS);
}

