//
// Created by StephenTuggy on 8/15/2022.
//

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