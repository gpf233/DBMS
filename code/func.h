#pragma once
#include "share.h"
void yyerror(char* msg);
int yylex();
void createdatabasefunc(char* database);
void showdatabasesfunc();
void usedatabasefunc(char* database);
void dropdatabasefunc(char* database);
void createsqlfunc(struct Createsql* createsql);
void showtablesfunc();
void droptablefunc(char* table);
void insertsqlfunc(struct Insertsql* insertsql);
void deletesqlfunc(struct Deletesql* deletesql);
void myfree(struct Conditions* cons);
void updatesqlfunc(struct Updatesql* updatesql);
void selectsqlfunc(struct Selectsql* selectsql);
