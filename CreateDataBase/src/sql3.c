/*
 * sql3.c
 *
 *  Created on: 10 de fev. de 2022
 *      Author: leandro
 */

#include <stdio.h>
#include "sql3.h"

int db_open(db_t *db)
{
	int rc = SQLITE_ERROR;
	if((db == NULL) || (db->name == NULL))
	{
		return rc;
	}
	rc = sqlite3_open(db->name, &db->hnd);
	db->rc = rc;
	return rc;
}

int db_errmsg(db_t *db)
{
	if((db == NULL) || (db->hnd == NULL) || (db->name == NULL))
	{
		return SQLITE_ERROR;
	}
	printf("Database %s error: %s\n", db->name, sqlite3_errmsg(db->hnd));
	return SQLITE_OK;
}

int db_close(db_t *db)
{
	int rc = SQLITE_ERROR;
	if((db == NULL) || (db->hnd == NULL))
	{
		return rc;
	}
	rc = sqlite3_close(db->hnd);
	db->rc = rc;
	return rc;
}

int db_setName(db_t *db, char *name)
{
	if((db == NULL) || (name == NULL))
	{
		return SQLITE_ERROR;
	}
	db->name = name;
	db->rc = SQLITE_OK;
	return SQLITE_OK;
}

const char *db_getName(db_t *db)
{
	if(db == NULL)
	{
		return NULL;
	}
	return db->name;
}
