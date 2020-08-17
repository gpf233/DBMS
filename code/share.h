#pragma once
enum Type { TYPE_INT, TYPE_CHAR };
struct Fieldsdef {
    char* field;
    enum Type type;
    int length;
    struct Fieldsdef* next_fdef;
};
struct Createsql {
    char* table;
    struct Fieldsdef* fdef;
};
struct Strings {
    char* string;
    struct Strings* next_string;
};
struct Stringss {
    struct Strings* strings;
    struct Stringss* next_strings;
};
struct Insertsql {
    char* table;
    struct Strings* column;
    struct Stringss* tuples;
};
struct Conditions {
    struct Conditions* left;
    struct Conditions* right;
    char cmp;  // 'a', 'o', '<', '>', '=', '!'
    int type;      // 0是字段，1是字符串，2是整数
    char* value;   //根据type存放字段名、字符串或整数
    char* table;   // NULL或表名
};
struct Deletesql {
    char* table;
    struct Conditions* conditions;
};
struct KVs {
    char* key;
    char* value;
    struct KVs* next_kv;
};
struct Updatesql {
    char* table;
    struct KVs* kvs;
    struct Conditions* conditions;
};
struct Selectedfields {
    char* table;
    char* field;
    struct Selectedfields* next_sf;
};
struct Selectsql {
    struct Selectedfields* sf;
    struct Strings* st;
    struct Conditions* conditions;
};
