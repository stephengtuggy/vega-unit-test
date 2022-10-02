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
