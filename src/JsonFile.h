#ifndef __JSON_FILE__
#define __JSON_FILE__

#include "json.h"
#include <fstream>
#include "BookStore.h"

class JsonFile
{
private:
    JsonFile() {};
    JsonFile(const JsonFile&) {};
    ~JsonFile() {}
    nlohmann::json readFile(std::string path);

public:
    static JsonFile& getInstance()
    {
        static JsonFile instance;
        return instance;
    }
    void readData(std::string path, BookStore& dst);
};

#endif