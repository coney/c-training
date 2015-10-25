#include "RecommendEngine.h"

RecommendEngine::~RecommendEngine()
{
}

class RecommendEngineImpl : public RecommendEngine {

    virtual std::shared_ptr<Book> filter(const BookList &bookList) const
    {
        std::shared_ptr<Book> target;
        for (BookList::const_iterator it = bookList.begin();
            it != bookList.end(); ++it) {
            if (!target || (*it)->price() > target->price()) {
                target = *it;
            }
        }
        return target;
    }

    virtual const std::string & setEngineParameter(const std::string &key, const std::string &value)
    {
        throw std::logic_error("The method or operation is not implemented.");
    }

    virtual const std::string & getEngineParameter(const std::string &key) const
    {
        throw std::logic_error("The method or operation is not implemented.");
    }

    virtual const std::string & getEngineName() const
    {
        throw std::logic_error("The method or operation is not implemented.");
    }

    virtual void start()
    {
        throw std::logic_error("The method or operation is not implemented.");
    }

    virtual void stop()
    {
        throw std::logic_error("The method or operation is not implemented.");
    }

    virtual void reload()
    {
        throw std::logic_error("The method or operation is not implemented.");
    }

    virtual void restart()
    {
        throw std::logic_error("The method or operation is not implemented.");
    }

    virtual void loadConfig(const std::string &path)
    {
        throw std::logic_error("The method or operation is not implemented.");
    }

};

std::shared_ptr<RecommendEngine> RecommendEngine::create()
{
    return std::make_shared<RecommendEngineImpl>();
}
