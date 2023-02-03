/*

FONYA BRANDONE
ICTU20223150
fonya.brandone@ictuniversity.edu.cm
SOFTWARE ENGINEERING
FALL 2022 Examination - INTRO. TO MOBILE APP
			--Section B-- Database Access Level API:
*/

#ifndef DATABASE_API
#define DATABASE_API

//Importing C++ Macros to be used:
#include<iostream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

enum DatabaseType{
	//SQL Database Type Options:
    MySql_db,
    Sqlite_db,
    PostGreSql_db
};

enum DataTypes{
    Integer,
    Text
};

enum DatabaseConstraint{
    primary_key,
    foreign_key,
    not_null,
    auto_increment
};

enum DataQuery{
	//CRUD Data query types:
    CREATE,
    SELECT,
    UPDATE,
    DELETE
};

class DB{
        protected:
            string name;
            string  uri;
            DatabaseType  DB_type;
        public:
        	//Atuallizing virtual class methods to zero:
            virtual string get_uri() = 0;
            virtual string get_name() = 0;
            virtual DatabaseType get_DB_type() = 0;
            
            //Actualizing Database class level - query methods 
            virtual int32_t create() = 0;
            virtual int32_t drop() = 0;
};

class Fields{
        protected:
        	//Fields or Columns class attributes and methods
            string Fname;
            DataTypes  FType;
            virtual DataTypes get_type()=0;
            //Create statements to create new db column or field:
            virtual string get_create_stmt_sql()=0;
        public:
            virtual string get_name()=0;
            virtual char get_text()=0;
            virtual int get_int()=0;
            virtual string get_string()=0;
};

class DB_Table{
        protected:
            string name;
            vector<Fields> field;
            virtual string get_description_sql()=0;
            virtual string get_create_stmt_sql()=0;
            virtual string get_drop_stmt_sql()=0;
        public:
            virtual string get_name()=0;
            virtual int32_t create() = 0;
            virtual int32_t drop() = 0;
};

class DB_Query{
        protected:
            string db_name;
            string tbl_name;
            string  sql_stmt;
            DataQuery  Query_type;
            virtual string get_sql_stmt() = 0;
        public:
            virtual string get_db_name() = 0;
            virtual string get_tbl_name() = 0;
            virtual DataQuery get_type() = 0;
            virtual int32_t execute() = 0;
};
#endif //DATABASE_API
