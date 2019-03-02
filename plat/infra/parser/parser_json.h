/*******************************************************
# Copyright (C) For free.
# All rights reserved.
# ******************************************************
# Author       : Ronghua Gao
# Last modified: 2019-01-21 03:34
# Email        : grh4542681@163.com
# Filename     : parser_json.h
# Description  : Parser json header. base on rapidjson
* ******************************************************/
#ifndef __PERSER_JSON_H__
#define __PERSER_JSON_H__

#include <vector>
#include <map>
#include <time.h>

#include "parser_return.h"
#include "mempool.h"
#include "thread_rw_lock.h"
#include "rapidjson/document.h"
#include "rapidjson/pointer.h"

#define MAXJSONFILESIZE (1024*1024)

namespace parser {

typedef enum class _JsonType : int {
    STRING = 1,
    INT,
    DOUBLE,
    BOOL,
    ARRAY,
    OBJECT,
    ONULL,
}JsonType;

class ParserJson;
class ParserJsonObject {
public:
    ParserJsonObject();
    ParserJsonObject(ParserJson*, rapidjson::Value*);
    ParserJsonObject(const parser::ParserJsonObject&);
    ParserJsonObject(const parser::ParserJsonObject&&);
    ~ParserJsonObject();

    bool isAvailable();
    bool hasError();
    ParserRet getLastRet();

    bool isString();
    bool isInt();
    bool isLong();
    bool isDouble();
    bool isNull();
    bool isBool();
    bool isArray();
    bool isObject();
    
    ParserRet getString(char* cache, unsigned int cache_size, struct timespec* overtime = NULL);
    ParserRet getInt(int* cache, struct timespec* overtime = NULL);
    ParserRet getLong(long* cache, struct timespec* overtime = NULL);
    ParserRet getDouble(double* cache, struct timespec* overtime = NULL);
    ParserRet getBool(bool* cache, struct timespec* overtime = NULL);
    ParserRet getArray(std::vector<ParserJsonObject>* cache, struct timespec* overtime = NULL);
    ParserRet getObject(std::map<std::string, ParserJsonObject>* cache, struct timespec* overtime = NULL);

    ParserJsonObject& setString(char* cache, unsigned int cache_size, struct timespec* overtime = NULL);
    ParserJsonObject& setInt(int cache, struct timespec* overtime = NULL);
    ParserJsonObject& setLong(long cache, struct timespec* overtime = NULL);
    ParserJsonObject& setDouble(double cache, struct timespec* overtime = NULL);
    ParserJsonObject& setNull(struct timespec* overtime = NULL);
    ParserJsonObject& setBool(bool cache, struct timespec* overtime = NULL);
    ParserJsonObject& setArray(struct timespec* overtime = NULL);
    ParserJsonObject& setObject(struct timespec* overtime = NULL);

    ParserRet arraySize(unsigned int* size, struct timespec* overtime = NULL);
    ParserJsonObject& arrayPush(const char* value, struct timespec* overtime = NULL);
    ParserJsonObject& arrayPush(const char* value, unsigned int len, struct timespec* overtime = NULL);
    ParserJsonObject& arrayPush(int value, struct timespec* overtime = NULL);
    ParserJsonObject& arrayPush(long value, struct timespec* overtime = NULL);
    ParserJsonObject& arrayPush(double value, struct timespec* overtime = NULL);
    ParserJsonObject& arrayPush(bool value, struct timespec* overtime = NULL);
    ParserJsonObject& arrayPush(JsonType type, unsigned int size,  struct timespec* overtime = NULL);
    ParserJsonObject& arrayPush(ParserJsonObject&& jsontree, struct timespec* overtime = NULL);
    ParserJsonObject& arrayPush(ParserJsonObject& jsontree, struct timespec* overtime = NULL);

    ParserJsonObject& arrayPop(struct timespec* overtime = NULL);
    ParserJsonObject& arrayClear(struct timespec* overtime = NULL);

    bool hasObject(const char* key, struct timespec* overtime = NULL);
    ParserRet objectSize(unsigned int* size, struct timespec* overtime = NULL);
    ParserJsonObject& objectAdd(const char* key, const char* value, struct timespec* overtime = NULL);
    ParserJsonObject& objectAdd(const char* key, const char* value, unsigned int len, struct timespec* overtime = NULL);
    ParserJsonObject& objectAdd(const char* key, int value, struct timespec* overtime = NULL);
    ParserJsonObject& objectAdd(const char* key, long value, struct timespec* overtime = NULL);
    ParserJsonObject& objectAdd(const char* key, double value, struct timespec* overtime = NULL);
    ParserJsonObject& objectAdd(const char* key, bool value, struct timespec* overtime = NULL);
    ParserJsonObject& objectAdd(const char* key, JsonType type, struct timespec* overtime = NULL);
    ParserJsonObject& objectAdd(const char* key, ParserJsonObject&& jsontree, struct timespec* overtime = NULL);
    ParserJsonObject& objectAdd(const char* key, ParserJsonObject& jsontree, struct timespec* overtime = NULL);

    ParserJsonObject& objectDel(const char* key, struct timespec* overtime = NULL);
    ParserJsonObject& objectClear(struct timespec* overtime = NULL);

    ParserJsonObject& Vfind(const char* path);
    ParserJsonObject& Hfind(const char* path);

    ParserJsonObject operator[](int index);
    ParserJsonObject operator[](const char* name);
    ParserJsonObject& operator=(const ParserJsonObject& other);
    ParserJsonObject& operator=(const ParserJsonObject&& other);
private:
    bool init_flag_;
    rapidjson::Value* rpj_value_;
    ParserJson* pj_center_;
    ParserRet last_ret_;

private:
    void _setret(ParserRet ret) {
        this->last_ret_ = ret;
    }
};

class ParserJson {
public:
    friend class ParserJsonObject;

public:
    ParserJsonObject root;

public:
    ParserJson();
    ~ParserJson();

    ParserRet ParserJsonFile(const char* filename);
    ParserRet ParserJsonString(const char* jsonstring);
    ParserRet StorageJsonFile(const char* filename);
    ParserRet StorageJsonString(const char* jsonstring, unsigned int len);

    void setThreadSafe(bool flag);
    bool getThreadSafe();

    void setNonBlock(bool flag);
    bool getNonBlock();

    ParserRet RLock(struct timespec* overtime);
    ParserRet WLock(struct timespec* overtime);
    ParserRet UnLock();

    ParserJsonObject find(const char* path);
private:
    bool init_flag_;
    bool thread_safe_flag_;
    pub::MemPool* mempool_;
    thread::ThreadRWLock rwlock_;

    rapidjson::Document doc_;
};

}//namespace parser end

#endif