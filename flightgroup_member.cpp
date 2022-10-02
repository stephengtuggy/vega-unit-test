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

#include "flightgroup_member.hpp"

namespace VegaStrike {
//    FlightgroupMember &FlightgroupMember::operator=(FlightgroupMember& initializer) {
//        return <#initializer#>;
//    }

    std::string FlightgroupMember::getFlightgroupName() const {
        return flightgroup_name_;
    }

    int32_t FlightgroupMember::getFlightgroupSubNumber() const {
        return flightgroup_sub_number_;
    }

    bool FlightgroupMember::operator<(FlightgroupMember &other) const {
        const std::string &this_flightgroup_name = this->getFlightgroupName();
        const std::string &other_flightgroup_name = other.getFlightgroupName();
        if (this_flightgroup_name < other_flightgroup_name) {
            return true;
        } else if (this_flightgroup_name > other_flightgroup_name) {
            return false;
        } else {
            return this->getFlightgroupSubNumber() < other.getFlightgroupSubNumber();
        }
    }

    bool FlightgroupMember::operator<(const FlightgroupMember &other) const {
        const std::string &this_flightgroup_name = this->getFlightgroupName();
        const std::string &other_flightgroup_name = other.getFlightgroupName();
        if (this_flightgroup_name < other_flightgroup_name) {
            return true;
        } else if (this_flightgroup_name > other_flightgroup_name) {
            return false;
        } else {
            return this->getFlightgroupSubNumber() < other.getFlightgroupSubNumber();
        }
    }

//    FlightgroupMember::FlightgroupMember(const boost::shared_ptr<FlightgroupMember> sharedPtr) : {
//
//    }
} // VegaStrike