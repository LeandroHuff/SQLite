/**
 * @file	sql3.h
 * @date	10 de fev. de 2022
 * @author	Leandro - leandrohuff@programmer.net
 */

#ifndef SQL3_H_
#define SQL3_H_

#include <stdint.h>
#include <stddef.h>
#include <sqlite3.h>

/**
 * @struct st_db
 * @brief Database structure to aggregate sqlite3 variables into a unique and
 *        concise structure to be used as a defined user type.
 */
typedef struct st_db
{
	char    *name;	/*!< Pointer to database name. */
	sqlite3 *hnd;	  /*!< Pointer to sqlite3 address structure. */
	int     rc;		  /*!< Hold last sqlite execution result. */
} db_t;				    /*!< SQLite3 database structure type. */

/**!
 *******************************************************************************
 * SQLite3 database functions to:
 * Constructors:
 * 	  Open
 * Destructors:
 * 		Close
 * Resources:
 *		Set db file's name
 *		Get db file's name
 * Errors:
 * 		Get error messages
 *******************************************************************************
*/


/**
 * @brief Open a database file or create one if it doesn't exist.
 * @param db Pointer to database structure db_t*.
 * @return SQLITE_OK    Successful,
 *         SQLITE_ERROR For any kind of database error, require specific treatment.
 */
int db_open(db_t *db);


/**
 * @fn int db_close(db_t *db)
 * @brief Close database handler.
 * @param db Pointer to database structure db_t*.
 * @return SQLITE_OK    Successful,
 *         SQLITE_ERROR For any kind of database error, require specific treatment.
 */
int db_close(db_t *db);


/**
 * @fn int db_setName(db_t *db, char *name)
 * @brief Setup the database name into the database structure.
 * @param db Pointer to database structure db_t*.
 * @param name Pointer to database name.
 * @return SQLITE_OK    Successful,
 *         SQLITE_ERROR For any kind of database error, require specific treatment.
 */
int db_setName(db_t *db, char *name);


/**
 * @fn const char *db_getName(db_t *db)
 * @brief Get the database name from the database structure.
 * @param db Pointer to database structure db_t*.
 * @return String char pointer to database name.
 *         NULL   For any kind of database error, require specific treatment.
 */
const char* db_getName(db_t *db);


/**
 * @fn const char *db_getErrorMsg(db_t *db)
 * @brief Get the last sqlite3 operation error message.
 * @param db Pointer to database structure db_t*.
 * @return String String char pointer to database error message.
 *         NULL   For any kind of database error, require specific treatment.
 */
const char* db_getErrorMsg(db_t *db);


/**
 * @fn int db_getErrorCode(db_t *db)
 * @brief Get the Result and Error Codes - defined in sqlite3.h.
 * @param *db Pointer to database structure db_t*.
 * @return int SQLite error code.
 *          -1 Function parameter error.
 */
int db_getErrorCode(db_t *db);


/**
 * @fn int db_getExtendedErrorCode(db_t *db)
 * @brief Get the Result and Extended Result Code - defined in sqlite3.h.
 * @param *db Pointer to database structure db_t*.
 * @return int Extended SQLite error code.
 *          -1 Function parameter error.
 */
int db_getExtendedErrorCode(db_t *db);


/**
 * @fn const char *db_getErrStr(int)
 * @brief Get the string message from SQLite error code.
 * @param int SQLite error code.
 * @return char* Error message according to error code.
 */
const char* db_getErrStr(int);


/**!
 *******************************************************************************
 * SQLite3 tables functions to:
 * Create
 * Delete
 * Modify
 * Set db tables's name
 * Get db tables's name
 *******************************************************************************
*/


#endif /* SQL3_H_ */
