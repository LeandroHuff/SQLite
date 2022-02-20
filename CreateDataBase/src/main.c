/*
 ============================================================================
 Name        : CreateDataBase.c
 Author      : Leandro Daniel Huff
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "sql3.h"

int main(void)
{
	db_t db;
	db_t *pdb = &db;

	db_setName(pdb, "SQL_Database.db");

	printf("Create SQLite Database: %s ...\n", db_getName(pdb));

	if( db_open(pdb) != SQLITE_OK)
	{
		(void)db_errmsg(pdb);
		return(EXIT_FAILURE);
	}

	puts("Successful!");

	if (db_close(pdb) != SQLITE_OK)
	{
		(void)db_errmsg(pdb);
		return(EXIT_FAILURE);
	}

	return EXIT_SUCCESS;
}
