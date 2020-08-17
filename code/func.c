#include <ctype.h>
#include <direct.h>
#include <io.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "share.h"
extern char* currentdatabase;
int removeDir(const char* dirPath) {
    struct _finddata_t fb;
    char path[1024];
    strcpy(path, dirPath);
    strcat(path, "/*");
    long handle = _findfirst(path, &fb);
    if (handle != 0) {
        while (!_findnext(handle, &fb)) {
            if (strcmp(fb.name, "..")) {
                memset(path, 0, sizeof(path));
                strcpy(path, dirPath);
                strcat(path, "/");
                strcat(path, fb.name);
                //属性值为16，则说明是文件夹，迭代
                if (fb.attrib == 16) {
                    removeDir(path);
                }
                //非文件夹的文件，直接删除。对文件属性值的情况没做详细调查，可能还有其他情况。
                else {
                    remove(path);
                }
            }
        }
        _findclose(handle);
    }
    return rmdir(dirPath);
}
void createdatabasefunc(char* database) {
    char buffer[1024];
    getcwd(buffer, 1024);
    strcat(buffer, "\\");
    strcat(buffer, database);
    if (!access(buffer, 0)) {
        printf("创建失败，数据库%s已经存在。\n", database);
    } else {
        if (!mkdir(buffer)) {
            printf("数据库%s创建成功。\n", database);
        } else {
            printf("数据库%s创建失败。\n", database);
        }
    }
}
void showdatabasesfunc() {
    char buffer[1024];
    getcwd(buffer, 1024);
    struct _finddata_t fb;
    strcat(buffer, "/*");
    long handle = _findfirst(buffer, &fb);
    if (handle != 0) {
        while (!_findnext(handle, &fb)) {
            if (strcmp(fb.name, "..")) {
                if (fb.attrib == 16) {
                    printf("%s\n", fb.name);
                }
            }
        }
        _findclose(handle);
    }
}
void usedatabasefunc(char* database) {
    char buffer[1024];
    getcwd(buffer, 1024);
    strcat(buffer, "\\");
    strcat(buffer, database);
    if (!access(buffer, 0)) {
        printf("切换到数据库%s。\n", database);
        free(currentdatabase);
        currentdatabase = strdup(database);
    } else {
        printf("数据库%s不存在。\n", database);
    }
}
void dropdatabasefunc(char* database) {
    char buffer[1024];
    getcwd(buffer, 1024);
    strcat(buffer, "\\");
    strcat(buffer, database);
    if (!access(buffer, 0)) {
        if (!removeDir(buffer)) {
            printf("数据库%s删除成功。\n", database);
        } else {
            printf("数据库%s删除失败。\n", database);
        }
    } else {
        printf("数据库%s不存在。\n", database);
    }
}
void createsqlfunc(struct Createsql* createsql) {
    if (!currentdatabase) {
        printf("尚未选择使用的数据库。\n");
        return;
    }
    char buffer[1024];
    getcwd(buffer, 1024);
    strcat(buffer, "\\");
    strcat(buffer, currentdatabase);
    strcat(buffer, "\\");
    strcat(buffer, createsql->table);
    if (!access(buffer, 0)) {
        printf("表%s已存在。\n", createsql->table);
        return;
    }
    FILE* fp = fopen(buffer, "w");
    fclose(fp);
    strcat(buffer, "_def");
    fp = fopen(buffer, "w");
    fprintf(fp, "%s\n", createsql->table);
    struct Fieldsdef* cur = createsql->fdef;
    while (cur->next_fdef) {
        fprintf(fp, "%s %d %d\n", cur->next_fdef->field, cur->next_fdef->type,
                cur->next_fdef->length);
        cur = cur->next_fdef;
    }
    fclose(fp);
    printf("表%s创建成功。\n", createsql->table);
}
void showtablesfunc() {
    if (!currentdatabase) {
        printf("尚未选择使用的数据库。\n");
        return;
    }
    char buffer[1024];
    getcwd(buffer, 1024);
    strcat(buffer, "\\");
    strcat(buffer, currentdatabase);
    struct _finddata_t fb;
    strcat(buffer, "/*");
    long handle = _findfirst(buffer, &fb);
    if (handle != 0) {
        while (!_findnext(handle, &fb)) {
            if (strcmp(fb.name, "..")) {
                int length = strlen(fb.name);
                if (length > 4 && fb.name[length - 4] == '_' &&
                    fb.name[length - 3] == 'd' && fb.name[length - 2] == 'e' &&
                    fb.name[length - 1] == 'f') {
                    continue;
                }
                if (fb.attrib == 16) {
                    continue;
                }
                printf("%s\n", fb.name);
            }
        }
        _findclose(handle);
    }
}
void droptablefunc(char* table) {
    if (!currentdatabase) {
        printf("尚未选择使用的数据库。\n");
        return;
    }
    char buffer[1024];
    getcwd(buffer, 1024);
    strcat(buffer, "\\");
    strcat(buffer, currentdatabase);
    strcat(buffer, "\\");
    strcat(buffer, table);
    if (!access(buffer, 0)) {
        char def[1024];
        strcpy(def, buffer);
        strcat(def, "_def");
        if (!remove(buffer) && !remove(def)) {
            printf("表%s删除成功。\n", table);
        } else {
            printf("表%s删除失败。\n", table);
        }
    } else {
        printf("表%s不存在。\n", table);
    }
}
void insertsqlfunc(struct Insertsql* insertsql) {
    if (!currentdatabase) {
        printf("尚未选择使用的数据库。\n");
        return;
    }
    char buffer[1024];
    getcwd(buffer, 1024);
    strcat(buffer, "\\");
    strcat(buffer, currentdatabase);
    strcat(buffer, "\\");
    strcat(buffer, insertsql->table);
    char def[1024];
    strcpy(def, buffer);
    strcat(def, "_def");
    if (!access(def, 0)) {
        FILE* fp = fopen(def, "r");
        fscanf(fp, "%*s");
        int colnum = 0;
        char colname[20][128];
        int coltype[20];
        int collen[20];
        while (fscanf(fp, "%s%d%d", colname[colnum], &coltype[colnum],
                      &collen[colnum]) != EOF) {
            colnum++;
        }
        fclose(fp);
        if (!insertsql->column->next_string) {
            struct Strings* cur = insertsql->column;
            for (int i = 0; i < colnum; i++) {
                struct Strings* newnode =
                    (struct Strings*)malloc(sizeof(struct Strings));
                newnode->string = strdup(colname[i]);
                newnode->next_string = NULL;
                cur->next_string = newnode;
                cur = newnode;
            }
        }
        int index[20];
        int colcnt = 0;
        struct Strings* current = insertsql->column;
        for (int i = 0; i < 20 && current->next_string; i++) {
            int j;
            for (j = 0; j < colnum; j++) {
                if (!strcmp(colname[j], current->next_string->string)) {
                    index[i] = j;
                    break;
                }
            }
            if (j == colnum) {
                printf("表%s没有%s列。\n", insertsql->table,
                       current->next_string->string);
                return;
            }
            current = current->next_string;
            colcnt++;
        }
        int tuplenum = 0;
        char sorted[20][20][128];
        memset(sorted, 0, sizeof(sorted));
        struct Stringss* cur = insertsql->tuples;
        for (int i = 0; cur->next_strings; i++) {
            struct Strings* curr = cur->next_strings->strings;
            int j;
            for (j = 0; j < colcnt && curr->next_string; j++) {
                if (isdigit(curr->next_string->string[0]) &&
                        coltype[index[j]] == 1 ||
                    !isdigit(curr->next_string->string[0]) &&
                        coltype[index[j]] == 0) {
                    printf("类型不匹配。\n");
                    return;
                }
                if (!isdigit(curr->next_string->string[0]) &&
                    strlen(curr->next_string->string) - 2 > collen[index[j]]) {
                    printf("char超出规定长度。\n");
                    return;
                }
                strcpy(sorted[i][index[j]], curr->next_string->string);
                curr = curr->next_string;
            }
            if (j != colcnt || curr->next_string) {
                printf("元素个数不匹配。\n");
                return;
            }
            cur = cur->next_strings;
            tuplenum++;
        }
        fp = fopen(buffer, "a");
        for (int i = 0; i < tuplenum; i++) {
            for (int j = 0; j < colnum; j++) {
                fprintf(fp, "%s`", sorted[i][j]);
            }
            fprintf(fp, "\n");
        }
        fclose(fp);
        printf("插入了%d行数据。\n", tuplenum);
    } else {
        printf("表%s不存在。\n", insertsql->table);
    }
}
void deletesqlfunc(struct Deletesql* deletesql) {
    if (!currentdatabase) {
        printf("尚未选择使用的数据库。\n");
        return;
    }
    char buffer[1024];
    getcwd(buffer, 1024);
    strcat(buffer, "\\");
    strcat(buffer, currentdatabase);
    strcat(buffer, "\\");
    strcat(buffer, deletesql->table);
    char def[1024];
    strcpy(def, buffer);
    strcat(def, "_def");
    if (access(buffer, 0)) {
        printf("表%s不存在。\n", deletesql->table);
    }

    FILE* fp = fopen(def, "r");
    fscanf(fp, "%*s");
    int colnum = 0;
    char colname[20][128];
    int coltype[20];
    int collen[20];
    while (fscanf(fp, "%s%d%d", colname[colnum], &coltype[colnum],
                  &collen[colnum]) != EOF) {
        colnum++;
    }
    fclose(fp);
    char info[100][20][128];
    int infonum = 0;
    fp = fopen(buffer, "r");
    for (int i = 0; 1; i++) {
        for (int j = 0; j < colnum; j++) {
            if (fscanf(fp, "%[^`]", info[i][j]) == EOF) {
                goto label;
            }
            fgetc(fp);
        }
        while (fgetc(fp) != '\n')
            ;
        infonum++;
    }
label:
    fclose(fp);
    /*for (int i = 0; i < infonum; i++) {
        for (int j = 0; j < colnum; j++) {
            printf("%s ", info[i][j]);
        }
        printf("\n");
    }*/
    int infoflag[100];
    for (int i = 0; i < infonum; i++) {
        if (!deletesql->conditions) {
            infoflag[i] = 1;
            continue;
        }
        // printf("第%d行\n", i);
        struct Conditions* cmpstack[100];
        int cmplen = 0;
        struct Conditions* constack[100];
        int conlen = 0;
        int boolstack[100];
        int boollen = 0;
        cmpstack[cmplen++] = deletesql->conditions;
        // printf("%c入符号栈\n", cmpstack[cmplen - 1]->cmp);
        constack[conlen++] = deletesql->conditions->left;
        constack[conlen++] = deletesql->conditions->right;
        int cnt = 0;
        while (1) {
            // printf("step %d\n", cnt++);
            while (1) {
                if (cmplen == 0) {
                    break;
                }
                if ((cmpstack[cmplen - 1]->cmp == 'a' ||
                     cmpstack[cmplen - 1]->cmp == 'o') &&
                    boollen >= 2) {
                    char cmp = cmpstack[cmplen-- - 1]->cmp;
                    int rb = boolstack[boollen-- - 1];
                    int lb = boolstack[boollen-- - 1];
                    boolstack[boollen++] = cmp == 'a' ? lb && rb : lb || rb;
                    // printf("处理%d%c%d，结果为%d\n", lb, cmp, rb,
                    //        boolstack[boollen - 1]);
                } else if (cmpstack[cmplen - 1]->cmp == '!') {
                    cmplen--;
                    char field[128];
                    char value[128];
                    strcpy(value, constack[conlen-- - 1]->value);
                    strcpy(field, constack[conlen-- - 1]->value);
                    // printf("处理%s != %s\n", field, value);
                    int index = -1;
                    for (int k = 0; k < colnum; k++) {
                        if (!strcmp(field, colname[k])) {
                            index = k;
                            break;
                        }
                    }
                    // printf("%s的index: %d, 对应的值: %s\n", field, index,
                    //        info[i][index]);
                    if (index == -1) {
                        printf("列%s不存在。\n", field);
                        return;
                    }
                    int fieldtype = coltype[index];
                    if (fieldtype == 0) {
                        boolstack[boollen++] =
                            atoi(info[i][index]) != atoi(value);
                    } else {
                        boolstack[boollen++] =
                            strcmp(info[i][index], value) != 0;
                    }
                    // printf("逻辑结果：%d\n", boolstack[boollen - 1]);
                } else if (cmpstack[cmplen - 1]->cmp == '=') {
                    cmplen--;
                    char field[128];
                    char value[128];
                    strcpy(value, constack[conlen-- - 1]->value);
                    strcpy(field, constack[conlen-- - 1]->value);
                    // printf("处理%s == %s\n", field, value);
                    int index = -1;
                    for (int k = 0; k < colnum; k++) {
                        if (!strcmp(field, colname[k])) {
                            index = k;
                            break;
                        }
                    }
                    // printf("%s的index: %d, 对应的值: %s\n", field, index,
                    //        info[i][index]);
                    if (index == -1) {
                        printf("列%s不存在。\n", field);
                        return;
                    }
                    int fieldtype = coltype[index];
                    if (fieldtype == 0) {
                        boolstack[boollen++] =
                            atoi(info[i][index]) == atoi(value);
                    } else {
                        boolstack[boollen++] =
                            strcmp(info[i][index], value) == 0;
                    }
                    // printf("逻辑结果：%d\n", boolstack[boollen - 1]);
                } else if (cmpstack[cmplen - 1]->cmp == '>') {
                    cmplen--;
                    char field[128];
                    char value[128];
                    strcpy(value, constack[conlen-- - 1]->value);
                    strcpy(field, constack[conlen-- - 1]->value);
                    // printf("处理%s > %s\n", field, value);
                    int index = -1;
                    for (int k = 0; k < colnum; k++) {
                        if (!strcmp(field, colname[k])) {
                            index = k;
                            break;
                        }
                    }
                    // printf("%s的index: %d, 对应的值: %s\n", field, index,
                    //        info[i][index]);
                    if (index == -1) {
                        printf("列%s不存在。\n", field);
                        return;
                    }
                    int fieldtype = coltype[index];
                    if (fieldtype == 0) {
                        boolstack[boollen++] =
                            atoi(info[i][index]) > atoi(value);
                    } else {
                        printf("类型不匹配。\n");
                        return;
                    }
                    // printf("逻辑结果：%d\n", boolstack[boollen - 1]);
                } else if (cmpstack[cmplen - 1]->cmp == '<') {
                    cmplen--;
                    char field[128];
                    char value[128];
                    strcpy(value, constack[conlen-- - 1]->value);
                    strcpy(field, constack[conlen-- - 1]->value);
                    // printf("处理%s!=%s\n", field, value);
                    int index = -1;
                    for (int k = 0; k < colnum; k++) {
                        if (!strcmp(field, colname[k])) {
                            index = k;
                            break;
                        }
                    }
                    // printf("%s的index: %d, 对应的值: %s\n", field, index,
                    //        info[i][index]);
                    if (index == -1) {
                        printf("列%s不存在。\n", field);
                        return;
                    }
                    int fieldtype = coltype[index];
                    if (fieldtype == 0) {
                        boolstack[boollen++] =
                            atoi(info[i][index]) < atoi(value);
                    } else {
                        printf("类型不匹配。\n");
                        return;
                    }
                    // printf("逻辑结果：%d\n", boolstack[boollen - 1]);
                } else {
                    break;
                }
            }
            // printf("%d %d %d\n", cmplen, conlen, boollen);
            if (boollen == 1 && cmplen == 0 && conlen == 0) {
                // printf("退出\n");
                break;
            }
            cmpstack[cmplen++] = constack[conlen-- - 1];
            // printf("%c入符号栈\n", cmpstack[cmplen - 1]->cmp);
            cmpstack[cmplen++] = constack[conlen-- - 1];
            // printf("%c入符号栈\n", cmpstack[cmplen - 1]->cmp);
            constack[conlen++] = cmpstack[cmplen - 2]->left;
            constack[conlen++] = cmpstack[cmplen - 2]->right;
            constack[conlen++] = cmpstack[cmplen - 1]->left;
            constack[conlen++] = cmpstack[cmplen - 1]->right;
        }
        // printf("where判断结果:%d\n", boolstack[boollen - 1]);
        infoflag[i] = boolstack[0];
    }
    fp = fopen(buffer, "w");
    int cnt = 0;
    for (int i = 0; i < infonum; i++) {
        if (infoflag[i]) {
            cnt++;
            continue;
        }
        for (int j = 0; j < colnum; j++) {
            fprintf(fp, "%s`", info[i][j]);
        }
        fprintf(fp, "\n");
    }
    fclose(fp);
    printf("删除了%d行数据。\n", cnt);
}
void myfree(struct Conditions* cons) {
    if (cons == NULL) {
        return;
    }
    free(cons->table);
    free(cons->value);
    myfree(cons->left);
    myfree(cons->right);
    free(cons);
}
void updatesqlfunc(struct Updatesql* updatesql) {
    if (!currentdatabase) {
        printf("尚未选择使用的数据库。\n");
        return;
    }
    char buffer[1024];
    getcwd(buffer, 1024);
    strcat(buffer, "\\");
    strcat(buffer, currentdatabase);
    strcat(buffer, "\\");
    strcat(buffer, updatesql->table);
    char def[1024];
    strcpy(def, buffer);
    strcat(def, "_def");
    if (access(buffer, 0)) {
        printf("表%s不存在。\n", updatesql->table);
    }

    FILE* fp = fopen(def, "r");
    fscanf(fp, "%*s");
    int colnum = 0;
    char colname[20][128];
    int coltype[20];
    int collen[20];
    while (fscanf(fp, "%s%d%d", colname[colnum], &coltype[colnum],
                  &collen[colnum]) != EOF) {
        colnum++;
    }
    fclose(fp);
    char info[100][20][128];
    int infonum = 0;
    fp = fopen(buffer, "r");
    for (int i = 0; 1; i++) {
        for (int j = 0; j < colnum; j++) {
            if (fscanf(fp, "%[^`]", info[i][j]) == EOF) {
                goto label;
            }
            fgetc(fp);
        }
        while (fgetc(fp) != '\n')
            ;
        infonum++;
    }
label:
    fclose(fp);
    /*for (int i = 0; i < infonum; i++) {
        for (int j = 0; j < colnum; j++) {
            printf("%s ", info[i][j]);
        }
        printf("\n");
    }*/
    int infoflag[100];
    for (int i = 0; i < infonum; i++) {
        if (!updatesql->conditions) {
            infoflag[i] = 1;
            continue;
        }
        // printf("第%d行\n", i);
        struct Conditions* cmpstack[100];
        int cmplen = 0;
        struct Conditions* constack[100];
        int conlen = 0;
        int boolstack[100];
        int boollen = 0;
        cmpstack[cmplen++] = updatesql->conditions;
        // printf("%c入符号栈\n", cmpstack[cmplen - 1]->cmp);
        constack[conlen++] = updatesql->conditions->left;
        constack[conlen++] = updatesql->conditions->right;
        int cnt = 0;
        while (1) {
            // printf("step %d\n", cnt++);
            while (1) {
                if (cmplen == 0) {
                    break;
                }
                if ((cmpstack[cmplen - 1]->cmp == 'a' ||
                     cmpstack[cmplen - 1]->cmp == 'o') &&
                    boollen >= 2) {
                    char cmp = cmpstack[cmplen-- - 1]->cmp;
                    int rb = boolstack[boollen-- - 1];
                    int lb = boolstack[boollen-- - 1];
                    boolstack[boollen++] = cmp == 'a' ? lb && rb : lb || rb;
                    // printf("处理%d%c%d，结果为%d\n", lb, cmp, rb,
                    //        boolstack[boollen - 1]);
                } else if (cmpstack[cmplen - 1]->cmp == '!') {
                    cmplen--;
                    char field[128];
                    char value[128];
                    strcpy(value, constack[conlen-- - 1]->value);
                    strcpy(field, constack[conlen-- - 1]->value);
                    // printf("处理%s != %s\n", field, value);
                    int index = -1;
                    for (int k = 0; k < colnum; k++) {
                        if (!strcmp(field, colname[k])) {
                            index = k;
                            break;
                        }
                    }
                    // printf("%s的index: %d, 对应的值: %s\n", field, index,
                    //        info[i][index]);
                    if (index == -1) {
                        printf("列%s不存在。\n", field);
                        return;
                    }
                    int fieldtype = coltype[index];
                    if (fieldtype == 0) {
                        boolstack[boollen++] =
                            atoi(info[i][index]) != atoi(value);
                    } else {
                        boolstack[boollen++] =
                            strcmp(info[i][index], value) != 0;
                    }
                    // printf("逻辑结果：%d\n", boolstack[boollen - 1]);
                } else if (cmpstack[cmplen - 1]->cmp == '=') {
                    cmplen--;
                    char field[128];
                    char value[128];
                    strcpy(value, constack[conlen-- - 1]->value);
                    strcpy(field, constack[conlen-- - 1]->value);
                    // printf("处理%s == %s\n", field, value);
                    int index = -1;
                    for (int k = 0; k < colnum; k++) {
                        if (!strcmp(field, colname[k])) {
                            index = k;
                            break;
                        }
                    }
                    // printf("%s的index: %d, 对应的值: %s\n", field, index,
                    //        info[i][index]);
                    if (index == -1) {
                        printf("列%s不存在。\n", field);
                        return;
                    }
                    int fieldtype = coltype[index];
                    if (fieldtype == 0) {
                        boolstack[boollen++] =
                            atoi(info[i][index]) == atoi(value);
                    } else {
                        boolstack[boollen++] =
                            strcmp(info[i][index], value) == 0;
                    }
                    // printf("逻辑结果：%d\n", boolstack[boollen - 1]);
                } else if (cmpstack[cmplen - 1]->cmp == '>') {
                    cmplen--;
                    char field[128];
                    char value[128];
                    strcpy(value, constack[conlen-- - 1]->value);
                    strcpy(field, constack[conlen-- - 1]->value);
                    // printf("处理%s > %s\n", field, value);
                    int index = -1;
                    for (int k = 0; k < colnum; k++) {
                        if (!strcmp(field, colname[k])) {
                            index = k;
                            break;
                        }
                    }
                    // printf("%s的index: %d, 对应的值: %s\n", field, index,
                    //        info[i][index]);
                    if (index == -1) {
                        printf("列%s不存在。\n", field);
                        return;
                    }
                    int fieldtype = coltype[index];
                    if (fieldtype == 0) {
                        boolstack[boollen++] =
                            atoi(info[i][index]) > atoi(value);
                    } else {
                        printf("类型不匹配。\n");
                        return;
                    }
                    // printf("逻辑结果：%d\n", boolstack[boollen - 1]);
                } else if (cmpstack[cmplen - 1]->cmp == '<') {
                    cmplen--;
                    char field[128];
                    char value[128];
                    strcpy(value, constack[conlen-- - 1]->value);
                    strcpy(field, constack[conlen-- - 1]->value);
                    // printf("处理%s!=%s\n", field, value);
                    int index = -1;
                    for (int k = 0; k < colnum; k++) {
                        if (!strcmp(field, colname[k])) {
                            index = k;
                            break;
                        }
                    }
                    // printf("%s的index: %d, 对应的值: %s\n", field, index,
                    //        info[i][index]);
                    if (index == -1) {
                        printf("列%s不存在。\n", field);
                        return;
                    }
                    int fieldtype = coltype[index];
                    if (fieldtype == 0) {
                        boolstack[boollen++] =
                            atoi(info[i][index]) < atoi(value);
                    } else {
                        printf("类型不匹配。\n");
                        return;
                    }
                    // printf("逻辑结果：%d\n", boolstack[boollen - 1]);
                } else {
                    break;
                }
            }
            // printf("%d %d %d\n", cmplen, conlen, boollen);
            if (boollen == 1 && cmplen == 0 && conlen == 0) {
                // printf("退出\n");
                break;
            }
            cmpstack[cmplen++] = constack[conlen-- - 1];
            // printf("%c入符号栈\n", cmpstack[cmplen - 1]->cmp);
            cmpstack[cmplen++] = constack[conlen-- - 1];
            // printf("%c入符号栈\n", cmpstack[cmplen - 1]->cmp);
            constack[conlen++] = cmpstack[cmplen - 2]->left;
            constack[conlen++] = cmpstack[cmplen - 2]->right;
            constack[conlen++] = cmpstack[cmplen - 1]->left;
            constack[conlen++] = cmpstack[cmplen - 1]->right;
        }
        // printf("where判断结果:%d\n", boolstack[boollen - 1]);
        infoflag[i] = boolstack[0];
    }
    int columnflag[20];
    char columninfo[20][128];
    memset(columnflag, 0, sizeof(columnflag));
    struct KVs* cur = updatesql->kvs;
    while (cur->next_kv) {
        int i = 0;
        for (i = 0; i < colnum; i++) {
            if (!strcmp(cur->next_kv->key, colname[i])) {
                if (coltype[i] == 1 && isdigit(cur->next_kv->value[0]) ||
                    coltype[i] == 0 && !isdigit(cur->next_kv->value[0])) {
                    printf("类型不匹配。\n");
                    break;
                }
                if (coltype[i] == 1 &&
                    strlen(cur->next_kv->value) - 2 > collen[i]) {
                    printf("char超出规定长度。\n");
                }
                columnflag[i] = 1;
                strcpy(columninfo[i], cur->next_kv->value);
                break;
            }
        }
        if (i == colnum) {
            printf("列%s不存在。\n", cur->next_kv->key);
            return;
        }
        cur = cur->next_kv;
    }
    fp = fopen(buffer, "w");
    int cnt = 0;
    for (int i = 0; i < infonum; i++) {
        if (infoflag[i]) {
            for (int j = 0; j < colnum; j++) {
                if (columnflag[j]) {
                    fprintf(fp, "%s`", columninfo[j]);
                } else {
                    fprintf(fp, "%s`", info[i][j]);
                }
            }
            cnt++;
        } else {
            for (int j = 0; j < colnum; j++) {
                fprintf(fp, "%s`", info[i][j]);
            }
        }
        fprintf(fp, "\n");
    }
    fclose(fp);
    printf("更新了%d行数据。\n", cnt);
}
void selectsqlfunc(struct Selectsql* selectsql) {
    if (!currentdatabase) {
        printf("尚未选择使用的数据库。\n");
        return;
    }
    if (selectsql->st->next_string->next_string) {
        printf("多表连接查询尚未实现。\n");
        return;
    }
    char buffer[1024];
    getcwd(buffer, 1024);
    strcat(buffer, "\\");
    strcat(buffer, currentdatabase);
    strcat(buffer, "\\");
    strcat(buffer, selectsql->st->next_string->string);
    char def[1024];
    strcpy(def, buffer);
    strcat(def, "_def");
    if (access(buffer, 0)) {
        printf("表%s不存在。\n", selectsql->st->next_string->string);
    }

    FILE* fp = fopen(def, "r");
    fscanf(fp, "%*s");
    int colnum = 0;
    char colname[20][128];
    int coltype[20];
    int collen[20];
    while (fscanf(fp, "%s%d%d", colname[colnum], &coltype[colnum],
                  &collen[colnum]) != EOF) {
        colnum++;
    }
    fclose(fp);
    char info[100][20][128];
    int infonum = 0;
    fp = fopen(buffer, "r");
    for (int i = 0; 1; i++) {
        for (int j = 0; j < colnum; j++) {
            if (fscanf(fp, "%[^`]", info[i][j]) == EOF) {
                goto label;
            }
            fgetc(fp);
        }
        while (fgetc(fp) != '\n')
            ;
        infonum++;
    }
label:
    fclose(fp);
    /*for (int i = 0; i < infonum; i++) {
        for (int j = 0; j < colnum; j++) {
            printf("%s ", info[i][j]);
        }
        printf("\n");
    }*/
    int infoflag[100];
    for (int i = 0; i < infonum; i++) {
        if (!selectsql->conditions) {
            infoflag[i] = 1;
            continue;
        }
        // printf("第%d行\n", i);
        struct Conditions* cmpstack[100];
        int cmplen = 0;
        struct Conditions* constack[100];
        int conlen = 0;
        int boolstack[100];
        int boollen = 0;
        cmpstack[cmplen++] = selectsql->conditions;
        // printf("%c入符号栈\n", cmpstack[cmplen - 1]->cmp);
        constack[conlen++] = selectsql->conditions->left;
        constack[conlen++] = selectsql->conditions->right;
        int cnt = 0;
        while (1) {
            // printf("step %d\n", cnt++);
            while (1) {
                if (cmplen == 0) {
                    break;
                }
                if ((cmpstack[cmplen - 1]->cmp == 'a' ||
                     cmpstack[cmplen - 1]->cmp == 'o') &&
                    boollen >= 2) {
                    char cmp = cmpstack[cmplen-- - 1]->cmp;
                    int rb = boolstack[boollen-- - 1];
                    int lb = boolstack[boollen-- - 1];
                    boolstack[boollen++] = cmp == 'a' ? lb && rb : lb || rb;
                    // printf("处理%d%c%d，结果为%d\n", lb, cmp, rb,
                    //        boolstack[boollen - 1]);
                } else if (cmpstack[cmplen - 1]->cmp == '!') {
                    cmplen--;
                    char field[128];
                    char value[128];
                    strcpy(value, constack[conlen-- - 1]->value);
                    strcpy(field, constack[conlen-- - 1]->value);
                    // printf("处理%s != %s\n", field, value);
                    int index = -1;
                    for (int k = 0; k < colnum; k++) {
                        if (!strcmp(field, colname[k])) {
                            index = k;
                            break;
                        }
                    }
                    // printf("%s的index: %d, 对应的值: %s\n", field, index,
                    //        info[i][index]);
                    if (index == -1) {
                        printf("列%s不存在。\n", field);
                        return;
                    }
                    int fieldtype = coltype[index];
                    if (fieldtype == 0) {
                        boolstack[boollen++] =
                            atoi(info[i][index]) != atoi(value);
                    } else {
                        boolstack[boollen++] =
                            strcmp(info[i][index], value) != 0;
                    }
                    // printf("逻辑结果：%d\n", boolstack[boollen - 1]);
                } else if (cmpstack[cmplen - 1]->cmp == '=') {
                    cmplen--;
                    char field[128];
                    char value[128];
                    strcpy(value, constack[conlen-- - 1]->value);
                    strcpy(field, constack[conlen-- - 1]->value);
                    // printf("处理%s == %s\n", field, value);
                    int index = -1;
                    for (int k = 0; k < colnum; k++) {
                        if (!strcmp(field, colname[k])) {
                            index = k;
                            break;
                        }
                    }
                    // printf("%s的index: %d, 对应的值: %s\n", field, index,
                    //        info[i][index]);
                    if (index == -1) {
                        printf("列%s不存在。\n", field);
                        return;
                    }
                    int fieldtype = coltype[index];
                    if (fieldtype == 0) {
                        boolstack[boollen++] =
                            atoi(info[i][index]) == atoi(value);
                    } else {
                        boolstack[boollen++] =
                            strcmp(info[i][index], value) == 0;
                    }
                    // printf("逻辑结果：%d\n", boolstack[boollen - 1]);
                } else if (cmpstack[cmplen - 1]->cmp == '>') {
                    cmplen--;
                    char field[128];
                    char value[128];
                    strcpy(value, constack[conlen-- - 1]->value);
                    strcpy(field, constack[conlen-- - 1]->value);
                    // printf("处理%s > %s\n", field, value);
                    int index = -1;
                    for (int k = 0; k < colnum; k++) {
                        if (!strcmp(field, colname[k])) {
                            index = k;
                            break;
                        }
                    }
                    // printf("%s的index: %d, 对应的值: %s\n", field, index,
                    //        info[i][index]);
                    if (index == -1) {
                        printf("列%s不存在。\n", field);
                        return;
                    }
                    int fieldtype = coltype[index];
                    if (fieldtype == 0) {
                        boolstack[boollen++] =
                            atoi(info[i][index]) > atoi(value);
                    } else {
                        printf("类型不匹配。\n");
                        return;
                    }
                    // printf("逻辑结果：%d\n", boolstack[boollen - 1]);
                } else if (cmpstack[cmplen - 1]->cmp == '<') {
                    cmplen--;
                    char field[128];
                    char value[128];
                    strcpy(value, constack[conlen-- - 1]->value);
                    strcpy(field, constack[conlen-- - 1]->value);
                    // printf("处理%s!=%s\n", field, value);
                    int index = -1;
                    for (int k = 0; k < colnum; k++) {
                        if (!strcmp(field, colname[k])) {
                            index = k;
                            break;
                        }
                    }
                    // printf("%s的index: %d, 对应的值: %s\n", field, index,
                    //        info[i][index]);
                    if (index == -1) {
                        printf("列%s不存在。\n", field);
                        return;
                    }
                    int fieldtype = coltype[index];
                    if (fieldtype == 0) {
                        boolstack[boollen++] =
                            atoi(info[i][index]) < atoi(value);
                    } else {
                        printf("类型不匹配。\n");
                        return;
                    }
                    // printf("逻辑结果：%d\n", boolstack[boollen - 1]);
                } else {
                    break;
                }
            }
            // printf("%d %d %d\n", cmplen, conlen, boollen);
            if (boollen == 1 && cmplen == 0 && conlen == 0) {
                // printf("退出\n");
                break;
            }
            cmpstack[cmplen++] = constack[conlen-- - 1];
            // printf("%c入符号栈\n", cmpstack[cmplen - 1]->cmp);
            cmpstack[cmplen++] = constack[conlen-- - 1];
            // printf("%c入符号栈\n", cmpstack[cmplen - 1]->cmp);
            constack[conlen++] = cmpstack[cmplen - 2]->left;
            constack[conlen++] = cmpstack[cmplen - 2]->right;
            constack[conlen++] = cmpstack[cmplen - 1]->left;
            constack[conlen++] = cmpstack[cmplen - 1]->right;
        }
        // printf("where判断结果:%d\n", boolstack[boollen - 1]);
        infoflag[i] = boolstack[0];
    }
    // int columnflag[20];
    // memset(columnflag, 0, sizeof(columnflag));
    int index[20];
    int colcnt = 0;
    struct Selectedfields* current = selectsql->sf;
    if (!current) {
        for (int i = 0; i < colnum; i++) {
            index[i] = i;
            colcnt = colnum;
        }
    } else {
        for (int i = 0; i < 20 && current->next_sf; i++) {
            int j;
            for (j = 0; j < colnum; j++) {
                if (!strcmp(colname[j], current->next_sf->field)) {
                    index[i] = j;
                    break;
                }
            }
            if (j == colnum) {
                printf("表%s没有%s列。\n", selectsql->st->next_string->string,
                       current->next_sf->field);
                return;
            }
            current = current->next_sf;
            colcnt++;
        }
    }
    int cnt = 0;
    for (int i = 0; i < colcnt; i++) {
        printf("%s\t", colname[index[i]]);
    }
    printf("\n");
    for (int i = 0; i < infonum; i++) {
        if (infoflag[i]) {
            for (int j = 0; j < colcnt; j++) {
                printf("%s\t", info[i][index[j]]);
            }
            cnt++;
            printf("\n");
        }
    }
    printf("查找到了%d行数据。\n", cnt);
}