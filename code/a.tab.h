typedef union {
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
} YYSTYPE;
#define	ID	257
#define	STRING	258
#define	NUMBER	259
#define	CREATE	260
#define	TABLE	261
#define	CHAR	262
#define	INT	263
#define	SELECT	264
#define	FROM	265
#define	WHERE	266
#define	INSERT	267
#define	INTO	268
#define	VALUES	269
#define	DELETE	270
#define	UPDATE	271
#define	SET	272
#define	DATABASE	273
#define	DATABASES	274
#define	USE	275
#define	SHOW	276
#define	TABLES	277
#define	DROP	278
#define	EXIT	279
#define	OR	280
#define	AND	281


extern YYSTYPE yylval;
