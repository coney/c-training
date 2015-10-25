#ifndef _PARKINGREPORT_H_INCLUDED_
#define _PARKINGREPORT_H_INCLUDED_

#include "IReportable.h"

class TextParkingReport : public IReportable {
public:
    ::std::string toString() {
        return result_.str();
    }

    virtual void report(const ParkingLot &parkingLot, const size_t level)  {
        printLevelDashes(level);
        result_ << "ParkingLot(" << parkingLot.getUsage() << "/"
            << parkingLot.getCapacity() << ")" << std::endl;
    }

    virtual void report(const ParkingBoy &boy, const size_t level)  {
        printLevelDashes(level);
        result_ << "ParkingBoy" << std::endl;

    }

    virtual void report(const ParkingManager &manager, const size_t level)  {
        printLevelDashes(level);
        result_ << "ParkingManager" << std::endl;
    }

private:
    void printLevelDashes(const size_t level) {
        result_ << ::std::string(level * 2, '-');
    }
    ::std::stringstream result_;

};

#include <stack>

class XMLParkingReport : public IReportable {
    typedef ::std::pair< ::std::string, size_t> TagLevel;
    typedef ::std::stack<TagLevel> CloseTags;
public:
    ::std::string toString() {
        closeTag(0);
        return result_.str();
    }

    virtual void report(const ParkingLot &parkingLot, const size_t level) {
        result_ << "<ParkingLot>\n"
            << "<Count>" << parkingLot.getUsage() << "</Count>\n"
            << "<Capacity>" << parkingLot.getCapacity() << "</Capacity>\n"
            << "</ParkingLot>\n";
    }

    virtual void report(const ParkingBoy &boy, const size_t level) {
        closeTag(level);
        result_ << "<ParkingBoy>" << std::endl;
        disclosedTags_.push(::std::make_pair("</ParkingBoy>", level));
    }

    virtual void report(const ParkingManager &manager, const size_t level) {
        closeTag(level);
        result_ << "<ParkingManager>" << std::endl;
        disclosedTags_.push(::std::make_pair("</ParkingManager>", level));
    }

private:

    void closeTag(const size_t level) {
        while (!disclosedTags_.empty()) {
            const TagLevel &tag = disclosedTags_.top();
            if (level <= tag.second) {
                result_ << tag.first << std::endl;
            } else {
                break;
            }
            disclosedTags_.pop();
        }
    }
    ::std::stringstream result_;

    CloseTags disclosedTags_;
};


#endif // _PARKINGREPORT_H_INCLUDED_
