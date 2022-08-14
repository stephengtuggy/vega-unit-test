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

        Unit(const Unit &) = delete;

        Unit &operator=(const Unit &) = delete;

        inline Unit() {
            std::cout << "No-arg Unit constructor called" << std::endl;
            isKilled();
        }

        inline Unit(std::string flightgroup_name, int32_t flightgroup_member_number) : flightgroup_name(
                std::move(flightgroup_name)), flightgroup_member_number(flightgroup_member_number) {
            std::cout << "Two-arg Unit constructor called" << std::endl;
            isKilled();
        }

        inline virtual ~Unit() {
            std::cout << "Unit destructor called" << std::endl;
            setKilled(true);
        }

        inline std::string getFlightgroupName() const {
            return flightgroup_name;
        }

        inline int32_t getFlightgroupMemberNumber() const {
            return flightgroup_member_number;
        }

    };

    using UnitRawPtr = Unit *;
    using UnitIntrusivePtr = boost::intrusive_ptr<Unit>;
    using UnitSharedPtr = boost::shared_ptr<Unit>;
    using UnitWeakPtr = boost::weak_ptr<Unit>;

    using UnitPtr = UnitSharedPtr;
    using UnitParentPtr = UnitWeakPtr;
    using UnitPtrForPy = UnitRawPtr;

}

#endif //VEGA_UNIT_TEST_UNIT_HPP
