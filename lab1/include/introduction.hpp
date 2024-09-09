/* Introduction class.
 * @file
 * @date 2021-09-04
 * @author Anonymous
 */

#ifndef __INTRODUCTION_HPP__
#define __INTRODUCTION_HPP__

#include <string>

//{
class introduction
{
public:
    std::string_view name() const
    {
        return "Stanislav"
    }

    std::string_view surename() const
    {
        return "Seleznev"
    }

    std::string fullname() const
    {
        return "Seleznev Stanislav"
    }

private:
};
//}

#endif // __INTRODUCTION_HPP__
