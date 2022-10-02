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

#ifndef VEGA_UNIT_TEST_FLIGHTGROUP_MEMBER_HPP
#define VEGA_UNIT_TEST_FLIGHTGROUP_MEMBER_HPP

#include <string>
#include <cstdint>
#include <utility>
#include <iostream>
#include <boost/shared_ptr.hpp>

namespace VegaStrike {

    class FlightgroupMember {
    protected:
        std::string flightgroup_name_{};
        int32_t flightgroup_sub_number_{};
    public:
        // Default constructor -- forbidden
        inline FlightgroupMember() = delete;
        // Copy constructor -- forbidden
        FlightgroupMember(FlightgroupMember const & rhs) = delete; //: flightgroup_name_(rhs.flightgroup_name_), flightgroup_sub_number_(rhs.flightgroup_sub_number_) {}
        // Move constructor
        FlightgroupMember(FlightgroupMember&& rhs) = default;
        // Main constructor
        inline FlightgroupMember(std::string flightgroup_name, int32_t flightgroup_sub_number) : flightgroup_name_(std::move(flightgroup_name)), flightgroup_sub_number_(flightgroup_sub_number) {}
        virtual ~FlightgroupMember() = default;

        FlightgroupMember& operator=(FlightgroupMember& initializer) = delete;
        virtual bool operator<(FlightgroupMember& other) const;
        virtual bool operator<(FlightgroupMember const& other) const;

        virtual std::string getFlightgroupName() const;
        virtual int32_t getFlightgroupSubNumber() const;

//        explicit FlightgroupMember(const boost::shared_ptr<FlightgroupMember> sharedPtr);
    };

    inline std::ostream & operator<<(std::ostream& os, boost::shared_ptr<FlightgroupMember> flightgroup_member) {
        os << flightgroup_member->getFlightgroupName() << '-' << flightgroup_member->getFlightgroupSubNumber();
        return os;
    }

} // VegaStrike

#endif //VEGA_UNIT_TEST_FLIGHTGROUP_MEMBER_HPP
