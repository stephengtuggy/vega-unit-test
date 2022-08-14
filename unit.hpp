//
// Created by StephenTuggy on 8/14/2022.
//

#ifndef VEGA_UNIT_TEST_UNIT_HPP
#define VEGA_UNIT_TEST_UNIT_HPP

#include <string>
#include <cstdint>
#include <iostream>
#include <boost/smart_ptr/intrusive_ref_counter.hpp>
#include <boost/smart_ptr/intrusive_ptr.hpp>
#include <boost/smart_ptr/shared_ptr.hpp>
#include <utility>
#include "vega_intrusive_ptr.hpp"

namespace VegaUnit {

    class Unit : public boost::intrusive_ref_counter<Unit, boost::thread_safe_counter> {
    protected:
        bool killed{false};

        std::string flightgroup_name;
        int32_t flightgroup_member_number{};

        inline bool isKilled() const {
            std::cout << "isKilled called. Value: " << killed << std::endl;
            return killed;
        }

        inline void setKilled(bool new_value) {
            std::cout << "setKilled called with new_value: " << new_value << std::endl;
            killed = new_value;
        }

    public:
        using IntrusiveUnitRefCounter = boost::intrusive_ref_counter<Unit, boost::thread_safe_counter>;

        inline Unit() {
            std::cout << "No-arg Unit constructor called" << std::endl;
            isKilled();
        }

        inline Unit(std::string flightgroup_name, int32_t flightgroup_member_number) : flightgroup_name(
                std::move(flightgroup_name)), flightgroup_member_number(flightgroup_member_number) {
            std::cout << "Two-arg Unit constructor called" << std::endl;
            isKilled();
        }

        inline Unit(Unit const & rhs) : IntrusiveUnitRefCounter(rhs), flightgroup_name(rhs.flightgroup_name), flightgroup_member_number(rhs.flightgroup_member_number) {
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
            if (use_count() == 0) {
                setKilled(true);
            }
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

    };

    using UnitRawPtr = Unit *;
    using UnitIntrusivePtr = boost::intrusive_ptr<Unit>;
    using UnitSharedPtr = boost::shared_ptr<Unit>;
    using UnitWeakPtr = boost::weak_ptr<Unit>;

    using UnitPtr = UnitSharedPtr;
    using UnitParentPtr = UnitWeakPtr;
    using UnitPtrForPy = UnitRawPtr;

    inline std::ostream & operator<<(std::ostream& os, const Unit& unit) {
        os << unit.getFlightgroupName() << ' ' << unit.getFlightgroupMemberNumber();
        return os;
    }

    inline std::ostream & operator<<(std::ostream& os, const UnitSharedPtr& unit) {
        os << unit->getFlightgroupName() << ' ' << unit->getFlightgroupMemberNumber();
        return os;
    }

}

#endif //VEGA_UNIT_TEST_UNIT_HPP
