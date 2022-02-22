/*
 * sql3.h
 *
 *  Created on: 10 de fev. de 2022
 *      Author: leandro
 */

#ifndef SQL3_H_
#define SQL3_H_

#include <sqlite3.h>

typedef struct st_db
{
	char    *name;
	sqlite3 *hnd;
	int     rc;
} db_t;

/**
 * @brief Open a database file or create one if it doesn't exist.
 * @param *db Pointer to database structure db_t*.
 * @return SQLITE_OK    Successful,
 *         SQLITE_ERROR Any error.
 */
int db_open(db_t *db);

int db_errmsg(db_t *db);
int db_close(db_t *db);
int db_setName(db_t *db, char *name);
const char *db_getName(db_t *db);

#endif /* SQL3_H_ */
