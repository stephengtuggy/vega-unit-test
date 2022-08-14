//
// Created by StephenTuggy on 8/14/2022.
//

#ifndef VEGA_UNIT_TEST_UNIT_HPP
#define VEGA_UNIT_TEST_UNIT_HPP

#include <string>
#include <cstdint>
#include <iostream>
#include <utility>

namespace VegaStrike {

    class Universe;

    class Unit {
    protected:
        bool killed{false};

        std::string flightgroup_name;
        int32_t flightgroup_member_number{};

        inline bool isKilled() const {
            std::cout << "isKilled called. Value: " << killed << std::endl;
            return killed;
        }

        friend class Universe;

    public:
        inline Unit(Unit const & rhs) : flightgroup_name(rhs.flightgroup_name), flightgroup_member_number(rhs.flightgroup_member_number) {
            std::cout << "Unit copy constructor called" << std::endl;
            isKilled();
        }

        inline Unit & operator=(Unit const & rhs) {
            std::cout << "Unit operator= called" << std::endl;
            flightgroup_name = rhs.flightgroup_name;
            flightgroup_member_number = rhs.flightgroup_member_number;
            return *this;
        }

        inline virtual ~Unit() {
            std::cout << "Unit destructor called" << std::endl;
        }

        Unit() = delete;

        inline virtual void kill() {
            std::cout << "kill called" << std::endl;
            killed = true;
        }

        inline std::string getFlightgroupName() const {
            return flightgroup_name;
        }

        inline int32_t getFlightgroupMemberNumber() const {
            return flightgroup_member_number;
        }

        inline bool operator<(const Unit& other_unit) const {
            if (this->flightgroup_name < other_unit.flightgroup_name) {
                return true;
            } else if (this->flightgroup_name > other_unit.flightgroup_name) {
                return false;
            } else {
                return (this->flightgroup_member_number < other_unit.flightgroup_member_number);
            }
        }

        inline Unit(std::string flightgroup_name, int32_t flightgroup_member_number) : flightgroup_name(
                std::move(flightgroup_name)), flightgroup_member_number(flightgroup_member_number) {
            std::cout << "Two-arg Unit constructor called" << std::endl;
            isKilled();
        }
    };

    inline std::ostream & operator<<(std::ostream& os, const Unit& unit) {
        os << unit.getFlightgroupName() << ' ' << unit.getFlightgroupMemberNumber();
        return os;
    }

    struct CompareByFlightgroup {
        bool operator()(Unit const & unit, std::string flightgroup_name, int32_t flightgroup_number) {
            if (unit.getFlightgroupName() < flightgroup_name) {
                return true;
            } else if (unit.getFlightgroupName() > flightgroup_name) {
                return false;
            } else {
                return unit.getFlightgroupMemberNumber() < flightgroup_number;
            }
        }

        bool operator()(std::string flightgroup_name, int32_t flightgroup_number, Unit const & unit) {
            if (flightgroup_name < unit.getFlightgroupName()) {
                return true;
            } else if (flightgroup_name > unit.getFlightgroupName()) {
                return false;
            } else {
                return flightgroup_number < unit.getFlightgroupMemberNumber();
            }
        }

        bool operator()(Unit & unit, std::string flightgroup_name, int32_t flightgroup_number) {
            if (unit.getFlightgroupName() < flightgroup_name) {
                return true;
            } else if (unit.getFlightgroupName() > flightgroup_name) {
                return false;
            } else {
                return unit.getFlightgroupMemberNumber() < flightgroup_number;
            }
        }

        bool operator()(std::string flightgroup_name, int32_t flightgroup_number, Unit & unit) {
            if (flightgroup_name < unit.getFlightgroupName()) {
                return true;
            } else if (flightgroup_name > unit.getFlightgroupName()) {
                return false;
            } else {
                return flightgroup_number < unit.getFlightgroupMemberNumber();
            }
        }
    };

}

#endif //VEGA_UNIT_TEST_UNIT_HPP
