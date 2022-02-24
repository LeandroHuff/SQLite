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

	printf("Creating/Opening SQLite Database: %s ...\n", db_getName(pdb));

	if( db_open(pdb) != SQLITE_OK)
	{
		printf("SQLite error message:%s\n", db_getErrorMsg(pdb));
		return(EXIT_FAILURE);
	}

	printf("Create/Open SQLite database result message:%s\n", db_getErrorMsg(pdb));

	puts("Closing SQLite Database...");

	if (db_close(pdb) != SQLITE_OK)
	{
	  printf("SQLite error message:%s\n", db_getErrorMsg(pdb));
		return(EXIT_FAILURE);
	}

	printf("Close SQLite database rc:%d\tresult:%d\tmessage:%s\n",
	    pdb->rc,
	    db_getExtendedErrorCode(pdb),
	    db_getErrStr(db_getExtendedErrorCode(pdb)));

	return EXIT_SUCCESS;
}
