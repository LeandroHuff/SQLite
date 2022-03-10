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
  int result;
	db_t db;
	db_t *pdb = &db;

	db_setName(pdb, "SQL_Database.db");
	fprintf(stdout,"Creating/Opening SQLite Database: %s ...\n", db_getName(pdb));

  if( db_updateDatabaseVersion(pdb) != SQLITE_OK)
  {
    fprintf(stdout, "SQLite update database version error!\n");
  }

  fprintf(stdout, "SQLite library version: %d.%d.%d\n", pdb->version.major, pdb->version.minor, pdb->version.build);

	if( db_open(pdb) != SQLITE_OK)
	{
	  fprintf(stderr, "SQLite error message: %s\n", db_getErrorMsg(pdb));
		return(EXIT_FAILURE);
	}

	fprintf(stdout, "Create/Open SQLite database result message: %s\n", db_getErrorMsg(pdb));

	/** Put your sql code here ******/

	if (db_createTable( pdb, "owner", "Id INTEGER PRIMARY KEY, Name TEXT") != SQLITE_OK)
	{
    fprintf(stderr, "SQLite error message: %s\n", db_getErrorMsg(pdb));
	}
	else
	{
	  fprintf(stdout, "SQLite message: %s\n", db_getErrorMsg(pdb));
	}

  /********/

	fprintf(stdout, "Closing SQLite Database...");

	result = db_close(pdb);

	if (result != SQLITE_OK)
	{
	  fprintf(stderr,"SQLite error message: %s\n", db_getErrorMsg(pdb));
		return(EXIT_FAILURE);
	}

	fprintf(stdout,"Close SQLite database successful.\n");

	return EXIT_SUCCESS;
}
