%{
#include "func.h"
#include "share.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char* currentdatabase = NULL;
struct Fieldsdef* lastfield = NULL;
struct Strings* laststring = NULL;
struct Stringss* laststrings = NULL;
struct KVs* lastkv = NULL;
struct Selectedfields* lastsf = NULL;
%}

%union {
    char char_var;
    char* string;
    int int_var;
    struct Fieldsdef* fieldsdef_var;
    struct Createsql* createsql_var;
    struct Strings* strings_var;
    struct Stringss* stringss_var;
    struct Insertsql* insertsql_var;
    struct Deletesql* deletesql_var;
    struct Selectedfields* sf_var;
    struct Conditions* cons_var;
    struct KVs* kvs_var;
    struct Updatesql* updatesql_var;
    struct Selectsql* selectsql_var;
}
%token<string> ID, STRING
%token<int_var> NUMBER
%token<int_var> CREATE, TABLE, CHAR, INT, SELECT, FROM, WHERE, INSERT, INTO, VALUES, DELETE, UPDATE, SET, DATABASE, DATABASES, USE, SHOW, TABLES, DROP, EXIT
%type<int_var> statements, statement
%type<string> createdatabase, usedatabase, dropdatabase, droptable
%type<fieldsdef_var> fieldsdef, field_type, type
%type<createsql_var> createsql
%type<strings_var> column, columns, value, values, table, tables
%type<stringss_var> tuple, tuples
%type<insertsql_var> insertsql
%type<char_var> comp_op
%type<deletesql_var> deletesql
%type<sf_var> table_field, table_fields, fields_star
%type<cons_var> condition, conditions, comp_left, comp_right
%type<kvs_var> assignment, assignments
%type<updatesql_var> updatesql
%type<selectsql_var> selectsql;

%left OR
%left AND

%%
statements: statements statement | statement
statement: createdatabase {
    createdatabasefunc($1);
    free($1);
}
| showdatabases {
    showdatabasesfunc();
}
| usedatabase {
    usedatabasefunc($1);
    free($1);
}
| dropdatabase {
    dropdatabasefunc($1);
    free($1);
}
| createsql {
    createsqlfunc($1);
    free($1->table);
    while ($1->fdef->next_fdef) {
        struct Fieldsdef *temp = $1->fdef->next_fdef;
        $1->fdef->next_fdef = $1->fdef->next_fdef->next_fdef;
        //printf("释放字段%s空间。\n", temp->field);
        free(temp->field);
        free(temp);
    }
    //printf("释放字段头节点空间。\n");
    free($1->fdef);
    //printf("删除表%s。\n", $1->table);
    free($1);
    //printf("空间清理完毕。\n");
}
| showtables {
    showtablesfunc();
}
| droptable {
    droptablefunc($1);
    free($1);
}
| insertsql {
    //printf("insertsql -> statement\n");
    insertsqlfunc($1);
    free($1->table);
    while ($1->column->next_string) {
        struct Strings* temp = $1->column->next_string;
        $1->column->next_string = $1->column->next_string->next_string;
        free(temp);
    }
    free($1->column);
    while ($1->tuples->next_strings) {
        struct Stringss* temp = $1->tuples->next_strings;
        $1->tuples->next_strings = $1->tuples->next_strings->next_strings;
        while (temp->strings->next_string) {
            struct Strings* tmp = temp->strings->next_string;
            temp->strings->next_string = temp->strings->next_string->next_string;
            free(tmp);
        }
        free(temp);
    }
    free($1->tuples);
    free($1);
}
| deletesql {
    deletesqlfunc($1);
    free($1->table);
    myfree($1->conditions);
    free($1);
}
| updatesql {
    updatesqlfunc($1);
    free($1->table);
    struct KVs* cur = $1->kvs;
    while (cur->next_kv) {
        struct KVs* temp = cur->next_kv;
        cur->next_kv = cur->next_kv->next_kv;
        free(temp->key);
        free(temp->value);
        free(temp);
    }
    free(cur->next_kv);
    myfree($1->conditions);
    free($1);
}
| selectsql {
    //printf("识别select语句\n");
    selectsqlfunc($1);
    struct Selectedfields* cur = $1->sf;
    /*if (!cur) {
        while (cur->next_sf) {
            struct Selectedfields* temp = cur->next_sf;
            cur->next_sf = cur->next_sf->next_sf;
            free(temp->table);
            free(temp->field);
        }
        free(cur);
    }*/
    struct Strings* curr = $1->st;
    while (curr->next_string) {
        struct Strings* temp = curr->next_string;
        curr->next_string = curr->next_string->next_string;
        free(temp->string);
    }
    free(curr);
    myfree($1->conditions);
}
| exit {
    printf("bye bye~\n");
    return 0;
}

createdatabase: CREATE DATABASE ID ';' {
    $$ = $3;
}

showdatabases: SHOW DATABASES ';' {

}

usedatabase: USE ID ';' {
    $$ = $2
}

dropdatabase: DROP DATABASE ID ';' {
    $$ = $3
}

createsql: CREATE TABLE ID '(' fieldsdef ')' ';' {
    $$ = (struct Createsql *) malloc(sizeof(struct Createsql));
    $$->table = $3;
    $$->fdef = $5;
}
fieldsdef: fieldsdef ',' field_type {
    lastfield->next_fdef = $3;
    lastfield = $3;
}
| field_type {
    $$ = (struct Fieldsdef *) malloc(sizeof(struct Fieldsdef));//headnode
    $$->next_fdef = $1;
    lastfield = $1;
}
field_type: ID type {
    $$ = $2;
    $$->field = $1;
    $$->next_fdef = NULL;
}
type: CHAR '(' NUMBER ')' {
    $$ = (struct Fieldsdef *) malloc(sizeof(struct Fieldsdef));
    $$->type = TYPE_CHAR;
    $$->length = $3;
}
| INT {
    $$ = (struct Fieldsdef *) malloc(sizeof(struct Fieldsdef));
    $$->type = TYPE_INT;
    $$->length = 0;
}

showtables: SHOW TABLES ';' {

}

droptable: DROP TABLE ID ';' {
    $$ = $3;
}

insertsql: INSERT INTO ID VALUES tuples ';' {
    //printf("INSERT INTO ID VALUES tuples; -> insertsql\n");
    $$ = (struct Insertsql*)malloc(sizeof(struct Insertsql));
    $$->table = $3;
    $$->column = (struct Strings*)malloc(sizeof(struct Strings));
    $$->column->next_string = NULL;
    $$->tuples = $5;
}
| INSERT INTO ID '(' columns ')' VALUES tuples ';' {
    //printf("INSERT INTO ID (columns) VALUES tuples; -> insertsql\n");
    $$ = (struct Insertsql*)malloc(sizeof(struct Insertsql));
    $$->table = $3;
    $$->column = $5;
    $$->tuples = $8;
}
tuples: tuples ',' tuple {
    //printf("tuples, tuple -> tuples\n");
    laststrings->next_strings = $3;
    laststrings = $3;
}
| tuple {
    //printf("tuple -> tuples\n");
    $$ = (struct Stringss *) malloc(sizeof(struct Stringss));//headnode
    $$->next_strings = $1;
    laststrings = $1;
}
tuple: '(' values ')' {
    //printf("(values) -> tuple\n");
    $$ = (struct Stringss *) malloc(sizeof(struct Stringss));
    $$->strings = $2;
    $$->next_strings = NULL;
}
values: values ',' value {
    //printf("values, value -> values\n");
    laststring->next_string = $3;
    laststring = $3;
}
| value {
    //printf("value -> values\n");
    $$ = (struct Strings *) malloc(sizeof(struct Strings));//headnode
    $$->next_string = $1;
    laststring = $1;
}
value: NUMBER {
    //printf("NUMBER -> value\n");
    $$ = (struct Strings *) malloc(sizeof(struct Strings));
    char buffer[1024];
    $$->string = strdup(itoa($1, buffer, 10));
    $$->next_string = NULL;
}
| STRING {
    //printf("STRING -> value\n");
    $$ = (struct Strings *) malloc(sizeof(struct Strings));
    $$->string = $1;
    $$->next_string = NULL;
}
columns: columns ',' column {
    //printf("columns, column -> columns\n");
    laststring->next_string = $3;
    laststring = $3;
}
| column {
    //printf("column -> columns\n");
    $$ = (struct Strings *) malloc(sizeof(struct Strings));//headnode
    $$->next_string = $1;
    laststring = $1;
}
column: ID {
    //printf("ID -> column\n");
    $$ = (struct Strings *) malloc(sizeof(struct Strings));
    $$->string = $1;
    $$->next_string = NULL;
}

deletesql: DELETE FROM ID ';' {
    $$ = (struct Deletesql*)malloc(sizeof(struct Deletesql));
    $$->table = $3;
    $$->conditions = NULL;
}
| DELETE FROM ID WHERE conditions ';' {
    $$ = (struct Deletesql*)malloc(sizeof(struct Deletesql));
    $$->table = $3;
    $$->conditions = $5;
}
conditions: condition {
    $$ = $1;
}
| '(' conditions ')' {
    $$ = $2;
}
| conditions AND conditions {
    $$ = (struct Conditions*)malloc(sizeof(struct Conditions));
    $$->left = $1;
    $$->cmp = 'a';
    $$->right = $3;
    $$->table = NULL;
    $$->value = NULL;
}
| conditions OR conditions {
    $$ = (struct Conditions*)malloc(sizeof(struct Conditions));
    $$->left = $1;
    $$->cmp = 'o';
    $$->right = $3;
    $$->table = NULL;
    $$->value = NULL;
}
condition: comp_left comp_op comp_right {
    $$ = (struct Conditions*)malloc(sizeof(struct Conditions));
    $$->left = $1;
    $$->cmp = $2;
    $$->right = $3;
    $$->table = NULL;
    $$->value = NULL;
    $1->left = NULL;
    $1->right = NULL;
    $3->left = NULL;
    $3->right = NULL;
}
comp_left: table_field {
    $$ = (struct Conditions*)malloc(sizeof(struct Conditions));
    $$->type = 0;
    $$->value = $1->field;
    $$->table = $1->table;
    free($1);
}
comp_right: table_field {
    $$ = (struct Conditions*)malloc(sizeof(struct Conditions));
    $$->type = 0;
    $$->value = $1->field;
    $$->table = $1->table;
    free($1);
}
| NUMBER {
    $$ = (struct Conditions*)malloc(sizeof(struct Conditions));
    char buffer[1024];
    $$->type = 2;
    $$->value = strdup(itoa($1, buffer, 10));
    $$->table = NULL;
}
| STRING {
    $$ = (struct Conditions*)malloc(sizeof(struct Conditions));
    $$->type = 1;
    $$->value = $1;
    $$->table = NULL;
}
comp_op: '<' {
    $$ = '<';
}
| '>' {
    $$ = '>';
}
| '=' {
    $$ = '=';
}
| '!''=' {
    $$ = '!';
}
table_field: ID {
    $$ = (struct Selectedfields*)malloc(sizeof(struct Selectedfields));
    $$->field = $1;
    $$->table = NULL;
    $$->next_sf = NULL;
}
| ID '.' ID {
    $$ = (struct Selectedfields*)malloc(sizeof(struct Selectedfields));
    $$->field = $3;
    $$->table = $1;
    $$->next_sf = NULL;
}

updatesql: UPDATE ID SET assignments ';' {
    $$ = (struct Updatesql*)malloc(sizeof(struct Updatesql));
    $$->table = $2;
    $$->kvs = $4;
    $$->conditions = NULL;
}
| UPDATE ID SET assignments WHERE conditions ';' {
    $$ = (struct Updatesql*)malloc(sizeof(struct Updatesql));
    $$->table = $2;
    $$->kvs = $4;
    $$->conditions = $6;
}
assignments: assignments ',' assignment {
    lastkv->next_kv = $3;
    lastkv = $3;
}
| assignment {
    $$ = (struct KVs*)malloc(sizeof(struct KVs));//headnode
    $$->next_kv = $1;
    lastkv = $1;
}
assignment: ID '=' NUMBER {
    $$ = (struct KVs*)malloc(sizeof(struct KVs));
    char buffer[1024];
    $$->key = $1;
    $$->value = strdup(itoa($3, buffer, 10));
    $$->next_kv = NULL;
}
| ID '=' STRING {
    $$ = (struct KVs*)malloc(sizeof(struct KVs));
    $$->key = $1;
    $$->value = $3;
    $$->next_kv = NULL;
}

selectsql: SELECT fields_star FROM tables ';' {
    //printf("SELECT fields_star FROM tables; -> selectsql\n");
    $$ = (struct Selectsql*)malloc(sizeof(struct Selectsql));
    $$->sf = $2;
    $$->st = $4;
    $$->conditions = NULL;
}
| SELECT fields_star FROM tables WHERE conditions ';'{
    //printf("SELECT fields_star FROM tables WHERE conditions; -> selectsql\n");
    $$ = (struct Selectsql*)malloc(sizeof(struct Selectsql));
    $$->sf = $2;
    $$->st = $4;
    $$->conditions = $6;
}
fields_star: table_fields {
    //printf("table_fields -> fields_star\n");
    $$ = $1;
}
| '*' {
    //printf("* -> fields_star\n");
    $$ = NULL;
}
table_fields: table_fields ',' table_field {
    //printf("table_fields, table_field -> table_fields\n");
    lastsf->next_sf = $3;
    lastsf = $3;
}
| table_field {
    //printf("table_field -> table_fields\n");
    $$ = (struct Selectedfields*)malloc(sizeof(struct Selectedfields));
    $$->next_sf = $1;
    lastsf = $1;
}
tables: tables ',' table {
    //printf("tables, table -> tables\n");
    laststring->next_string = $3;
    laststring = $3;
}
| table {
    //printf("table -> tables\n");
    $$ = (struct Strings*)malloc(sizeof(struct Strings));
    $$->next_string = $1;
    laststring = $1;
}
table: ID {
    //printf("ID -> table\n");
    $$ = (struct Strings*)malloc(sizeof(struct Strings));
    $$->string = $1;
    $$->next_string = NULL;
}
exit: EXIT ';' {

}

%%
void yyerror(char *msg) {
    printf("error msg: %s.", msg);
}
int main() {
    return yyparse();
}
