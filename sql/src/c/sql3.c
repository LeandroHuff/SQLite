/*
 *******************************************************************************
 * sql3.c
 *
 *  Created on: 10 de fev. de 2022
 *      Author: leandro
 *******************************************************************************
 */

#include <stdio.h>
#include "sql3.h"

/*
 *******************************************************************************
 * SQLite3 database functions to:
 *  Open
 *  Close
 *  Set db file's name
 *  Get db file's name
 *  Get error messages
 *******************************************************************************
 */

/*
 *******************************************************************************
 * Description:
 *  Get the SQLite library version number.
 *
 *  Parameters:
 *    None
 *
 *  Return:
 *    SQLite version number.
 *******************************************************************************
 */
int db_getLibVersion(void)
{
  return sqlite3_libversion_number();
}

int db_updateDatabaseVersion( db_t *db )
{
	int result = SQLITE_ERROR;
	int version = db_getLibVersion();
	
	if (version > 0)
	{
		db->version.build = (version % 1000);
		db->version.minor = ((version / 1000) % 1000);
		db->version.major = (version / 1000000);
		result = SQLITE_OK;
	}
	
	return (result);
}

db_version_t *db_getDatabaseVersion( db_t *db )
{
	return (&db->version);
}

/*
 *******************************************************************************
 * Description:
 *  Open a database file or create one if it doesn't exist.
 *
 *  Parameters:
 *    *db           Pointer to database structure db_t*.
 *
 *  Return:
 *    SQLITE_OK     Successful
 *    SQLITE_ERROR  Or any other kind of database error code,
 *                  require a specific treatment for each one.
 *******************************************************************************
 */
int db_open(db_t *db)
{
  int rc = SQLITE_ERROR;
  if ((db == NULL) || (db->name == NULL))
  {
    return rc;
  }
  rc = sqlite3_open(db->name, &db->hnd);
  db->rc = rc;
  return rc;
}

/*
 *******************************************************************************
 * Description:
 *  Close database handler.
 *
 *  Parameters:
 *    *db           Pointer to database structure db_t*.
 *
 *  Return:
 *    SQLITE_OK     Successful
 *    SQLITE_ERROR  Or any other kind of database error code,
 *                  require a specific treatment for each one.
 *******************************************************************************
 */
int db_close(db_t *db)
{
  int rc = SQLITE_ERROR;
  if ((db == NULL) || (db->hnd == NULL))
  {
    return rc;
  }
  rc = sqlite3_close(db->hnd);
  db->rc = rc;
  return rc;
}

/*
 *******************************************************************************
 * Description:
 *  Setup the database name into the database structure.
 *
 *  Parameters:
 *    *db           Pointer to database structure db_t*.
 *    *name         Pointer to database name.
 *
 *  Return:
 *    SQLITE_OK     Successful
 *    SQLITE_ERROR  Or any other kind of database error code,
 *                  require a specific treatment for each one.
 *******************************************************************************
 */
int db_setName(db_t *db, char *name)
{
  if ((db == NULL) || (name == NULL))
  {
    return SQLITE_ERROR;
  }
  db->name = name;
  db->rc = SQLITE_OK;
  return SQLITE_OK;
}

/*
 *******************************************************************************
 * Description:
 *  Get the database name from the database structure.
 *
 *  Parameters:
 *    *db           Pointer to database structure db_t*.
 *
 *  Return:
 *    String Address  String char pointer to database name.
 *    NULL            For any kind of database error.
 *******************************************************************************
 */
const char* db_getName(db_t *db)
{
  if (db == NULL)
  {
    return NULL;
  }
  return db->name;
}

/*
 *******************************************************************************
 * Description:
 *  Get the last sqlite3 operation error message.
 *
 *  Parameters:
 *    *db           Pointer to database structure db_t*.
 *
 *  Return:
 *    String Address  String char pointer to database error message.
 *    NULL            For any kind of database error.
 *******************************************************************************
 */
const char* db_getErrorMsg(db_t *db)
{
  if ((db == NULL) || (db->hnd == NULL))
  {
    return NULL;
  }
  return sqlite3_errmsg(db->hnd);
}

/*
 ********************************************************************************
 * Description:
 *  Get the Result and Error Codes - defined in sqlite3.h.
 *
 *  Parameters:
 *    *db           Pointer to database structure db_t*.
 *
 *  Return:
 *     -1           Function parameter error.
 *    int           SQLite error code.
 *
 *
 *  Primary Result Code List:
 *
 *    SQLITE_OK           0   Successful result
 *    SQLITE_ERROR        1   Generic error
 *    SQLITE_INTERNAL     2   Internal logic error in SQLite
 *    SQLITE_PERM         3   Access permission denied
 *    SQLITE_ABORT        4   Callback routine requested an abort
 *    SQLITE_BUSY         5   The database file is locked
 *    SQLITE_LOCKED       6   A table in the database is locked
 *    SQLITE_NOMEM        7   A malloc() failed
 *    SQLITE_READONLY     8   Attempt to write a readonly database
 *    SQLITE_INTERRUPT    9   Operation terminated by sqlite3_interrupt()
 *    SQLITE_IOERR       10   Some kind of disk I/O error occurred
 *    SQLITE_CORRUPT     11   The database disk image is malformed
 *    SQLITE_NOTFOUND    12   Unknown opcode in sqlite3_file_control()
 *    SQLITE_FULL        13   Insertion failed because database is full
 *    SQLITE_CANTOPEN    14   Unable to open the database file
 *    SQLITE_PROTOCOL    15   Database lock protocol error
 *    SQLITE_EMPTY       16   Internal use only
 *    SQLITE_SCHEMA      17   The database schema changed
 *    SQLITE_TOOBIG      18   String or BLOB exceeds size limit
 *    SQLITE_CONSTRAINT  19   Abort due to constraint violation
 *    SQLITE_MISMATCH    20   Data type mismatch
 *    SQLITE_MISUSE      21   Library used incorrectly
 *    SQLITE_NOLFS       22   Uses OS features not supported on host
 *    SQLITE_AUTH        23   Authorization denied
 *    SQLITE_FORMAT      24   Not used
 *    SQLITE_RANGE       25   2nd parameter to sqlite3_bind out of range
 *    SQLITE_NOTADB      26   File opened that is not a database file
 *    SQLITE_NOTICE      27   Notifications from sqlite3_log()
 *    SQLITE_WARNING     28   Warnings from sqlite3_log()
 *    SQLITE_ROW         100  sqlite3_step() has another row ready
 *    SQLITE_DONE        101  sqlite3_step() has finished executing
 *******************************************************************************
 */
int db_getErrorCode(db_t *db)
{
  if ((db == NULL) || (db->hnd == NULL))
  {
    return (-1);
  }
  return sqlite3_errcode(db->hnd);
}

/*
 *******************************************************************************
 * Description:
 *  Get the Result and Extended Result Code - defined in sqlite3.h.
 *
 *  Parameters:
 *    *db           Pointer to database structure db_t*.
 *
 *  Return:
 *     -1           Function parameter error.
 *    int           SQLite extended error code.
 *
 *
 *  Extended Result Code List:
 *
 *    SQLITE_ERROR_MISSING_COLLSEQ   (SQLITE_ERROR      | ( 1<<8))
 *    SQLITE_ERROR_RETRY             (SQLITE_ERROR      | ( 2<<8))
 *    SQLITE_ERROR_SNAPSHOT          (SQLITE_ERROR      | ( 3<<8))
 *    SQLITE_IOERR_READ              (SQLITE_IOERR      | ( 1<<8))
 *    SQLITE_IOERR_SHORT_READ        (SQLITE_IOERR      | ( 2<<8))
 *    SQLITE_IOERR_WRITE             (SQLITE_IOERR      | ( 3<<8))
 *    SQLITE_IOERR_FSYNC             (SQLITE_IOERR      | ( 4<<8))
 *    SQLITE_IOERR_DIR_FSYNC         (SQLITE_IOERR      | ( 5<<8))
 *    SQLITE_IOERR_TRUNCATE          (SQLITE_IOERR      | ( 6<<8))
 *    SQLITE_IOERR_FSTAT             (SQLITE_IOERR      | ( 7<<8))
 *    SQLITE_IOERR_UNLOCK            (SQLITE_IOERR      | ( 8<<8))
 *    SQLITE_IOERR_RDLOCK            (SQLITE_IOERR      | ( 9<<8))
 *    SQLITE_IOERR_DELETE            (SQLITE_IOERR      | (10<<8))
 *    SQLITE_IOERR_BLOCKED           (SQLITE_IOERR      | (11<<8))
 *    SQLITE_IOERR_NOMEM             (SQLITE_IOERR      | (12<<8))
 *    SQLITE_IOERR_ACCESS            (SQLITE_IOERR      | (13<<8))
 *    SQLITE_IOERR_CHECKRESERVEDLOCK (SQLITE_IOERR      | (14<<8))
 *    SQLITE_IOERR_LOCK              (SQLITE_IOERR      | (15<<8))
 *    SQLITE_IOERR_CLOSE             (SQLITE_IOERR      | (16<<8))
 *    SQLITE_IOERR_DIR_CLOSE         (SQLITE_IOERR      | (17<<8))
 *    SQLITE_IOERR_SHMOPEN           (SQLITE_IOERR      | (18<<8))
 *    SQLITE_IOERR_SHMSIZE           (SQLITE_IOERR      | (19<<8))
 *    SQLITE_IOERR_SHMLOCK           (SQLITE_IOERR      | (20<<8))
 *    SQLITE_IOERR_SHMMAP            (SQLITE_IOERR      | (21<<8))
 *    SQLITE_IOERR_SEEK              (SQLITE_IOERR      | (22<<8))
 *    SQLITE_IOERR_DELETE_NOENT      (SQLITE_IOERR      | (23<<8))
 *    SQLITE_IOERR_MMAP              (SQLITE_IOERR      | (24<<8))
 *    SQLITE_IOERR_GETTEMPPATH       (SQLITE_IOERR      | (25<<8))
 *    SQLITE_IOERR_CONVPATH          (SQLITE_IOERR      | (26<<8))
 *    SQLITE_IOERR_VNODE             (SQLITE_IOERR      | (27<<8))
 *    SQLITE_IOERR_AUTH              (SQLITE_IOERR      | (28<<8))
 *    SQLITE_IOERR_BEGIN_ATOMIC      (SQLITE_IOERR      | (29<<8))
 *    SQLITE_IOERR_COMMIT_ATOMIC     (SQLITE_IOERR      | (30<<8))
 *    SQLITE_IOERR_ROLLBACK_ATOMIC   (SQLITE_IOERR      | (31<<8))
 *    SQLITE_IOERR_DATA              (SQLITE_IOERR      | (32<<8))
 *    SQLITE_IOERR_CORRUPTFS         (SQLITE_IOERR      | (33<<8))
 *    SQLITE_LOCKED_SHAREDCACHE      (SQLITE_LOCKED     | ( 1<<8))
 *    SQLITE_LOCKED_VTAB             (SQLITE_LOCKED     | ( 2<<8))
 *    SQLITE_BUSY_RECOVERY           (SQLITE_BUSY       | ( 1<<8))
 *    SQLITE_BUSY_SNAPSHOT           (SQLITE_BUSY       | ( 2<<8))
 *    SQLITE_BUSY_TIMEOUT            (SQLITE_BUSY       | ( 3<<8))
 *    SQLITE_CANTOPEN_NOTEMPDIR      (SQLITE_CANTOPEN   | ( 1<<8))
 *    SQLITE_CANTOPEN_ISDIR          (SQLITE_CANTOPEN   | ( 2<<8))
 *    SQLITE_CANTOPEN_FULLPATH       (SQLITE_CANTOPEN   | ( 3<<8))
 *    SQLITE_CANTOPEN_CONVPATH       (SQLITE_CANTOPEN   | ( 4<<8))
 *    SQLITE_CANTOPEN_DIRTYWAL       (SQLITE_CANTOPEN   | ( 5<<8)) - Not Used
 *    SQLITE_CANTOPEN_SYMLINK        (SQLITE_CANTOPEN   | ( 6<<8))
 *    SQLITE_CORRUPT_VTAB            (SQLITE_CORRUPT    | ( 1<<8))
 *    SQLITE_CORRUPT_SEQUENCE        (SQLITE_CORRUPT    | ( 2<<8))
 *    SQLITE_CORRUPT_INDEX           (SQLITE_CORRUPT    | ( 3<<8))
 *    SQLITE_READONLY_RECOVERY       (SQLITE_READONLY   | ( 1<<8))
 *    SQLITE_READONLY_CANTLOCK       (SQLITE_READONLY   | ( 2<<8))
 *    SQLITE_READONLY_ROLLBACK       (SQLITE_READONLY   | ( 3<<8))
 *    SQLITE_READONLY_DBMOVED        (SQLITE_READONLY   | ( 4<<8))
 *    SQLITE_READONLY_CANTINIT       (SQLITE_READONLY   | ( 5<<8))
 *    SQLITE_READONLY_DIRECTORY      (SQLITE_READONLY   | ( 6<<8))
 *    SQLITE_ABORT_ROLLBACK          (SQLITE_ABORT      | ( 2<<8))
 *    SQLITE_CONSTRAINT_CHECK        (SQLITE_CONSTRAINT | ( 1<<8))
 *    SQLITE_CONSTRAINT_COMMITHOOK   (SQLITE_CONSTRAINT | ( 2<<8))
 *    SQLITE_CONSTRAINT_FOREIGNKEY   (SQLITE_CONSTRAINT | ( 3<<8))
 *    SQLITE_CONSTRAINT_FUNCTION     (SQLITE_CONSTRAINT | ( 4<<8))
 *    SQLITE_CONSTRAINT_NOTNULL      (SQLITE_CONSTRAINT | ( 5<<8))
 *    SQLITE_CONSTRAINT_PRIMARYKEY   (SQLITE_CONSTRAINT | ( 6<<8))
 *    SQLITE_CONSTRAINT_TRIGGER      (SQLITE_CONSTRAINT | ( 7<<8))
 *    SQLITE_CONSTRAINT_UNIQUE       (SQLITE_CONSTRAINT | ( 8<<8))
 *    SQLITE_CONSTRAINT_VTAB         (SQLITE_CONSTRAINT | ( 9<<8))
 *    SQLITE_CONSTRAINT_ROWID        (SQLITE_CONSTRAINT | (10<<8))
 *    SQLITE_CONSTRAINT_PINNED       (SQLITE_CONSTRAINT | (11<<8))
 *    SQLITE_CONSTRAINT_DATATYPE     (SQLITE_CONSTRAINT | (12<<8))
 *    SQLITE_NOTICE_RECOVER_WAL      (SQLITE_NOTICE     | ( 1<<8))
 *    SQLITE_NOTICE_RECOVER_ROLLBACK (SQLITE_NOTICE     | ( 2<<8))
 *    SQLITE_WARNING_AUTOINDEX       (SQLITE_WARNING    | ( 1<<8))
 *    SQLITE_AUTH_USER               (SQLITE_AUTH       | ( 1<<8))
 *    SQLITE_OK_LOAD_PERMANENTLY     (SQLITE_OK         | ( 1<<8))
 *    SQLITE_OK_SYMLINK              (SQLITE_OK         | ( 2<<8)) - internal use only
 *******************************************************************************
 */
int db_getExtendedErrorCode(db_t *db)
{
  if ((db == NULL) || (db->hnd == NULL))
  {
    return (-1);
  }
  return sqlite3_extended_errcode(db->hnd);
}

/*
 *******************************************************************************
 * Description:
 *    Get the string message from SQLite error code.
 *
 * Parameters:
 *    err     SQLite error code.
 *
 * Return:
 *    char*   Pointer to error message string according to error code.
 *******************************************************************************
 */
const char* db_getErrStr(int err)
{
  return sqlite3_errstr(err);
}

/*
 *******************************************************************************
 * SQLite3 tables functions to:
 *  Create
 *  Modify/Update
 *  Delete
 *  Set db tables's name
 *  Get db tables's name
 *******************************************************************************
 */
int db_createTable( db_t *db, char *table, char *schema)
{
  int result = -1;

  /* check paramters */
  if( (    db == NULL) ||
      ( table == NULL) ||
      (schema == NULL) )
  {
    return result;
  }

  /* reserve a memory buffer */
  char text[256] = {0};
  char *sql_error = NULL;

  /* store the SQL command into memory buffer */
  int len = snprintf(text, sizeof(text), "CREATE TABLE %s(%s);", table, schema );

  /* check how many char could be stored into memory buffer,
   * if less then needed, return an error to the caller. */
  if (len >= sizeof(text))
  {
    return result;
  }

  result = sqlite3_exec(db->hnd, text, 0, 0, &sql_error);
  db->rc = result;
  sqlite3_free(sql_error);

  return result;
}

