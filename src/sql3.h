/**
 * @file	sql3.h
 * @date	10 de fev. de 2022
 * @author	Leandro - leandrohuff@programmer.net
 */

#ifndef SQL3_H_
#define SQL3_H_

#include <sqlite3.h>

/**
 * @struct st_db
 * @brief Database structure to aggregate sqlite3 variables into a unique and
 *        concise structure to be used as a defined user type.
 */
typedef struct st_db
{
	char    *name;	/*!< Pointer to database name. */
	sqlite3 *hnd;	/*!< Pointer to sqlite3 address structure. */
	int     rc;		/*!< Hold last sqlite execution result. */
} db_t;				/*!< SQLite3 database structure type. */

/**
 * @brief Open a database file or create one if it doesn't exist.
 * @param db Pointer to database structure db_t*.
 * @return SQLITE_OK    Successful,
 *         SQLITE_ERROR Any error.
 */
int db_open(db_t *db);

/**
 * @fn int db_errmsg(db_t *db)
 * @brief Print the last sqlite3 operation error message.
 * @param db Pointer to database structure db_t*.
 * @return SQLITE_OK    Successful,
 *         SQLITE_ERROR Any error.
 */
int db_errmsg(db_t *db);

/**
 * @fn int db_close(db_t *db)
 * @brief Close database handler.
 * @param db Pointer to database structure db_t*.
 * @return SQLITE_OK    Successful,
 *         SQLITE_ERROR Any error.
 */
int db_close(db_t *db);

/**
 * @fn int db_setName(db_t *db, char *name)
 * @brief Setup the database name into the database structure.
 * @param db Pointer to database structure db_t*.
 * @param name Pointer to database name.
 * @return SQLITE_OK    Successful,
 *         SQLITE_ERROR Any error.
 */
int db_setName(db_t *db, char *name);

/**
 * @fn const char *db_getName(db_t *db)
 * @brief Get the database name from the database structure.
 * @param db Pointer to database structure db_t*.
 * @return String char pointer to database name.
 */
const char *db_getName(db_t *db);

#endif /* SQL3_H_ */
