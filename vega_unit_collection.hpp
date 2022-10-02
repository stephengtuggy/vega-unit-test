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

#ifndef VEGA_UNIT_TEST_VEGA_UNIT_COLLECTION_HPP
#define VEGA_UNIT_TEST_VEGA_UNIT_COLLECTION_HPP

#include <boost/multi_index_container.hpp>
#include <boost/multi_index/sequenced_index.hpp>
#include <boost/multi_index/ordered_index.hpp>
#include <boost/multi_index/identity.hpp>
#include <boost/multi_index/composite_key.hpp>
#include <boost/multi_index/mem_fun.hpp>
//#include <boost/smart_ptr/make_shared.hpp>
#include <boost/smart_ptr/shared_ptr.hpp>
#include <utility>
#include "flightgroup_member.hpp"

namespace VegaStrike {

//    class Unit;
    struct FgMemberSequenced {};
    struct FgMemberByIdentity {};
    struct FgMemberByFlightgroup {};

    using boost::multi_index_container;
    using namespace boost::multi_index;

    typedef multi_index_container<
            boost::shared_ptr<FlightgroupMember>,
            indexed_by<
                    sequenced<tag<FgMemberSequenced>>,
                    ordered_unique<tag<FgMemberByIdentity>, identity<FlightgroupMember>>,
                    ordered_unique<tag<FgMemberByFlightgroup>,
                            composite_key<FlightgroupMember,
                                    const_mem_fun<FlightgroupMember, std::string, &FlightgroupMember::getFlightgroupName>,
                                    const_mem_fun<FlightgroupMember, int32_t, &FlightgroupMember::getFlightgroupSubNumber>
                            >,
                            composite_key_compare<std::less<std::string>, std::less<int32_t>>
                    >
            >
    > FgMemberCollection;
    typedef FgMemberCollection::index<FgMemberSequenced>::type BySequence;

}
#endif //VEGA_UNIT_TEST_VEGA_UNIT_COLLECTION_HPP
