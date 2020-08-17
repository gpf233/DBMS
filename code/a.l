%{
#include "a.tab.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
%}
word [a-zA-Z0-9_]
words {word}+
digit [0-9]
digits {digit}+
optional_fraction (\.{digits})?
optional_exponent (E[+-]?{digits})?

%%
CREATE {
    //printf("识别keyword:%s,长度为%d\n", yytext, yyleng);
    return CREATE;
}
TABLE {
    //printf("识别keyword:%s,长度为%d\n", yytext, yyleng);
    return TABLE;
}
CHAR {
    //printf("识别keyword:%s,长度为%d\n", yytext, yyleng);
    return CHAR;
}
INT {
    //printf("识别keyword:%s,长度为%d\n", yytext, yyleng);
    return INT;
}
SELECT {
    //printf("识别keyword:%s,长度为%d\n", yytext, yyleng);
    return SELECT;
}
FROM {
    //printf("识别keyword:%s,长度为%d\n", yytext, yyleng);
    return FROM;
}
WHERE {
    //printf("识别keyword:%s,长度为%d\n", yytext, yyleng);
    return WHERE;
}
INSERT {
    //printf("识别keyword:%s,长度为%d\n", yytext, yyleng);
    return INSERT;
}
INTO {
    //printf("识别keyword:%s,长度为%d\n", yytext, yyleng);
    return INTO;
}
VALUES {
    //printf("识别keyword:%s,长度为%d\n", yytext, yyleng);
    return VALUES;
}
DELETE {
    //printf("识别keyword:%s,长度为%d\n", yytext, yyleng);
    return DELETE;
}
UPDATE {
    //printf("识别keyword:%s,长度为%d\n", yytext, yyleng);
    return UPDATE;
}
SET {
    //printf("识别keyword:%s,长度为%d\n", yytext, yyleng);
    return SET;
}
DATABASE {
    //printf("识别keyword:%s,长度为%d\n", yytext, yyleng);
    return DATABASE;
}
DATABASES {
    //printf("识别keyword:%s,长度为%d\n", yytext, yyleng);
    return DATABASES;
}
USE {
    //printf("识别keyword:%s,长度为%d\n", yytext, yyleng);
    return USE;
}
SHOW {
    //printf("识别keyword:%s,长度为%d\n", yytext, yyleng);
    return SHOW;
}
TABLES {
    //printf("识别keyword:%s,长度为%d\n", yytext, yyleng);
    return TABLES;
}
DROP {
    //printf("识别keyword:%s,长度为%d\n", yytext, yyleng);
    return DROP;
}
EXIT {
    //printf("识别keyword:%s,长度为%d\n", yytext, yyleng);
    return EXIT;
}
AND {
    return AND;
}
OR {
    return OR;
}
[A-Za-z_]{word}* {
    //printf("识别标识符:%s,长度为%d\n", yytext, yyleng);
    yylval.string = strdup(yytext);
    return ID;
}
{digits}{optional_fraction}{optional_exponent} {
    //printf("识别数字:%s,长度为%d\n", yytext, yyleng);
    yylval.int_var = atoi(yytext);
    return NUMBER;
}
\'[^']*\' {
    //printf("识别字符串:%s,长度为%d\n", yytext, yyleng);
    yylval.string = strdup(yytext);
    return STRING;
}
\! |
\= |
\> |
\< |
\* |
\; |
\( |
\) |
\, {
    //printf("识别单字符:%s,长度为%d\n", yytext, yyleng);
    return yytext[0];
}
[ \r\n\t\v\f] {
    
}

%%
// int main() {
//     //printf("词法分析成功，返回记号类别为%d\n", yylex());
//     return 0;
// }

int yywrap() {
    return 1;
}
