// Copyright (c) 2022 Stephen G. Tuggy
//
// This file is part of Vega Test.
//
// Vega Test is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// Vega Test is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with Vega Test. If not, see <https://www.gnu.org/licenses/>.

#ifndef VEGA_UNIT_TEST_UNIT_HPP
#define VEGA_UNIT_TEST_UNIT_HPP

#include <string>
#include <cstdint>
#include <iostream>
#include <utility>
#include "flightgroup_member.hpp"
#include "can_be_parent.hpp"
#include "can_be_owner.hpp"

namespace VegaStrike {

    class Universe;

    class Unit : public FlightgroupMember,
            public CanBeParent,
            public CanBeOwner {
    protected:
        bool killed{false};

//        std::string flightgroup_name;
//        int32_t flightgroup_member_number{};

        bool isKilled() const;

        friend class Universe;

    public:
        // Copy constructor -- forbidden
        inline Unit(Unit const & rhs) = delete; // : FlightgroupMember(rhs.getFlightgroupName(), rhs.getFlightgroupSubNumber()), killed(false) {
////            std::cout << "Unit copy constructor called" << std::endl;
//            isKilled();
//        }

        // Move constructor
        inline Unit(Unit&& rhs) = default;

        inline Unit & operator=(Unit const & rhs) = delete; //{
////            std::cout << "Unit operator= called" << std::endl;
//            flightgroup_name = rhs.flightgroup_name;
//            flightgroup_member_number = rhs.flightgroup_member_number;
//            return *this;
//        }

        ~Unit() override;

        Unit() = delete;

        virtual void kill();

        std::string getFlightgroupName() const override {
            return flightgroup_name_;
        }

        int32_t getFlightgroupMemberNumber() const {
            return flightgroup_sub_number_;
        }

        int32_t getFlightgroupSubNumber() const override {
            return flightgroup_sub_number_;
        }

        bool operator<(const Unit& other_unit) const;

        inline Unit(std::string flightgroup_name, int32_t flightgroup_sub_number) : FlightgroupMember(std::move(flightgroup_name), flightgroup_sub_number), killed(false) {
            std::cout << "Two-arg Unit constructor called" << std::endl;
            isKilled();
        }
    };

    inline std::ostream & operator<<(std::ostream& os, const Unit& unit) {
        os << unit.getFlightgroupName() << '-' << unit.getFlightgroupSubNumber();
        return os;
    }

    struct CompareByFlightgroup {
        bool operator()(Unit const & unit, std::string flightgroup_name, int32_t flightgroup_number) {
            if (unit.getFlightgroupName() < flightgroup_name) {
                return true;
            } else if (unit.getFlightgroupName() > flightgroup_name) {
                return false;
            } else {
                return unit.getFlightgroupSubNumber() < flightgroup_number;
            }
        }

        bool operator()(std::string flightgroup_name, int32_t flightgroup_number, Unit const & unit) {
            if (flightgroup_name < unit.getFlightgroupName()) {
                return true;
            } else if (flightgroup_name > unit.getFlightgroupName()) {
                return false;
            } else {
                return flightgroup_number < unit.getFlightgroupSubNumber();
            }
        }

        bool operator()(Unit & unit, std::string flightgroup_name, int32_t flightgroup_number) {
            if (unit.getFlightgroupName() < flightgroup_name) {
                return true;
            } else if (unit.getFlightgroupName() > flightgroup_name) {
                return false;
            } else {
                return unit.getFlightgroupSubNumber() < flightgroup_number;
            }
        }

        bool operator()(std::string flightgroup_name, int32_t flightgroup_number, Unit & unit) {
            if (flightgroup_name < unit.getFlightgroupName()) {
                return true;
            } else if (flightgroup_name > unit.getFlightgroupName()) {
                return false;
            } else {
                return flightgroup_number < unit.getFlightgroupSubNumber();
            }
        }
    };

}

#endif //VEGA_UNIT_TEST_UNIT_HPP
