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

#ifndef VEGA_UNIT_TEST_CAN_BE_OWNER_HPP
#define VEGA_UNIT_TEST_CAN_BE_OWNER_HPP

#include "vega_unit_collection.hpp"

namespace VegaStrike {

    class CanBeOwner {
    protected:
        FgMemberCollection stuff_i_own_{};

    public:
        // Default constructor
        CanBeOwner() = default;
        // Copy constructor -- forbidden
        CanBeOwner(CanBeOwner const & rhs) = delete;
        // Move constructor
        CanBeOwner(CanBeOwner && rhs) = default;
        // Destructor
        virtual ~CanBeOwner() = default;
        CanBeOwner& operator=(CanBeOwner const & rhs) = delete;

        virtual FgMemberCollection& getOwned();
    };

} // VegaStrike

#endif //VEGA_UNIT_TEST_CAN_BE_OWNER_HPP
