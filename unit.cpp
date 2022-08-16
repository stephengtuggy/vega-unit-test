//
// Created by StephenTuggy on 8/15/2022.
//

#include "unit.hpp"

bool VegaStrike::Unit::isKilled() const {
//            std::cout << "isKilled called. Value: " << killed << std::endl;
    return killed;
}

VegaStrike::Unit::~Unit() {
//            std::cout << "Unit destructor called" << std::endl;
}

void VegaStrike::Unit::kill() {
//            std::cout << "kill called" << std::endl;
    killed = true;
}

bool VegaStrike::Unit::operator<(const VegaStrike::Unit &other_unit) const {
    const std::string &this_fg_name = this->getFlightgroupName();
    const std::string &other_fg_name = other_unit.getFlightgroupName();
    if (this_fg_name < other_fg_name) {
        return true;
    } else if (this_fg_name > other_fg_name) {
        return false;
    } else {
        return (this->getFlightgroupSubNumber() < other_unit.getFlightgroupSubNumber());
    }
}
