/*
1. C语言实现哈希表
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct dictEntry {
    void *key;
    void *val;
    struct dictEntry *next;
} dictEntry;

typedef struct dict {
    dictEntry **table;
    unsigned long size;
    unsigned long sizemask;
    unsigned long used;
    void *privdata;
} dict;

static int dictAdd(dict *ht, void *key, void *val);
static int dictDelete(dict *ht, const void *key);

/* Add an element to the target hash table */
static int dictAdd(dict *ht, void *key, void *val) {
    dictEntry *dictEntry_ = (dictEntry *)malloc(sizeof(dictEntry));
    dictEntry_->key = key;
    dictEntry_->val = val;
    dictEntry_->next = NULL;
    int t = rand() % ht->size;

    if (ht->table[t]->next) {
        dictEntry_->next = ht->table[t]->next;
        ht->table[t] = dictEntry_;
    } else {
        ht->table[t] = dictEntry_;
    }
    return 1;
}

static int dictGet(dict *ht, void *key, void *val) {}
#define N 10

int main() {
    dict *dict_ = (dict *)malloc(sizeof(dict));
    dict_->size = N;
    int i;
    dict_->table = (dictEntry **)malloc(N * sizeof(dictEntry *));
    dictEntry *dictEntry_;
    for (i = 0; i < dict_->size; i++) {
        // 虚拟头节点
        dictEntry_ = (dictEntry *)malloc(sizeof(dictEntry));
        dictEntry_->next = NULL;
        dict_->table[i] = dictEntry_;
    }
    int key = 100;
    int value = 200;
    dictAdd(dict_, (void *)key, (void *)value);

    return 0;
}
