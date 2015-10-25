#ifndef __RECOMMENDENGINE_H__
#define __RECOMMENDENGINE_H__

#include "Book.h"

class RecommendEngine
{
public:
    virtual ~RecommendEngine();
    virtual std::shared_ptr<Book> filter(const BookList &bookList) const = 0;

    // Engine Control Functions
    virtual const std::string &setEngineParameter(
        const std::string &key, const std::string &value) = 0;
    virtual const std::string &getEngineParameter(const std::string &key) const = 0;
    virtual const std::string &getEngineName() const = 0;
    virtual void start() = 0;
    virtual void stop() = 0;
    virtual void reload() = 0;
    virtual void restart() = 0;
    virtual void loadConfig(const std::string &path) = 0;

    static std::shared_ptr<RecommendEngine> create();
};

#endif
