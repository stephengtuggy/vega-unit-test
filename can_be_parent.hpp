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

#ifndef VEGA_UNIT_TEST_CAN_BE_PARENT_HPP
#define VEGA_UNIT_TEST_CAN_BE_PARENT_HPP

#include "vega_unit_collection.hpp"

namespace VegaStrike {

    class CanBeParent {
    protected:
        FgMemberCollection children_{};

    public:
        // Default constructor
        CanBeParent() = default;
        // Copy constructor -- forbidden
        CanBeParent(CanBeParent const & rhs) = delete;
        // Move constructor
        CanBeParent(CanBeParent && rhs) = default;
        // Destructor
        virtual ~CanBeParent() = default;
        CanBeParent& operator=(CanBeParent const & rhs) = delete;

        virtual FgMemberCollection &getChildren();
    };

} // VegaStrike

#endif //VEGA_UNIT_TEST_CAN_BE_PARENT_HPP
