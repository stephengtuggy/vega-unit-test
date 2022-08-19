//
// Created by StephenTuggy on 8/14/2022.
//

#ifndef VEGA_UNIT_TEST_UNIVERSE_HPP
#define VEGA_UNIT_TEST_UNIVERSE_HPP

#include <boost/multi_index_container.hpp>
#include <boost/multi_index/sequenced_index.hpp>
#include <boost/multi_index/ordered_index.hpp>
#include <boost/multi_index/identity.hpp>
#include <boost/multi_index/composite_key.hpp>
#include <boost/multi_index/mem_fun.hpp>
#include <boost/smart_ptr/make_shared.hpp>
#include <boost/smart_ptr/shared_ptr.hpp>
#include <utility>
#include "vega_unit_collection.hpp"
#include "unit.hpp"

namespace VegaStrike {

    using namespace boost;
    using namespace boost::multi_index;

    typedef FgMemberCollection::index_iterator<FgMemberSequenced>::type UnitSequencedIterator;
    typedef const FgMemberCollection::index_const_iterator<FgMemberSequenced>::type UnitConstSequencedIterator;
    typedef FgMemberCollection::index_iterator<FgMemberByIdentity>::type UnitByIDIterator;
    typedef const FgMemberCollection::index_const_iterator<FgMemberByIdentity>::type UnitByIDConstIterator;
    typedef FgMemberCollection::index_iterator<FgMemberByFlightgroup>::type UnitByFlightgroupIterator;
    typedef const FgMemberCollection::index_const_iterator<FgMemberByFlightgroup>::type UnitByFlightgroupConstIterator;

    // Forward declarations
    class Universe;
    static Universe& getUniverse();

    class Universe {
    private:
        FgMemberCollection all_live_units{};
        FgMemberCollection all_dying_units{};

        friend Universe& getUniverse();

        Universe() = default;

        inline virtual ~Universe() = default;

    public:
        Universe(Universe const & rhs) = delete;
        Universe & operator=(Universe const & rhs) = delete;

        inline FgMemberCollection const & getAllLiveUnits() const {
            return all_live_units;
        }

        inline FgMemberCollection const & getAllDyingUnits() const {
            return all_dying_units;
        }

        inline boost::shared_ptr<Unit> createUnit(std::string flightgroup_name, int32_t flightgroup_member_number) {
            boost::shared_ptr<Unit> new_unit = boost::make_shared<Unit>(std::move(flightgroup_name), flightgroup_member_number);
            boost::shared_ptr<FlightgroupMember> fg_member = boost::dynamic_pointer_cast<FlightgroupMember>(new_unit);
            all_live_units.get<FgMemberSequenced>().push_back(fg_member);
            return new_unit;
        }

        inline void killUnit(boost::shared_ptr<Unit> unit_to_kill) {
            boost::shared_ptr<FlightgroupMember> fg_member = boost::dynamic_pointer_cast<FlightgroupMember>(unit_to_kill);
            all_dying_units.get<FgMemberSequenced>().push_back(fg_member);
            all_live_units.get<FgMemberByFlightgroup>().erase(all_live_units.get<FgMemberByFlightgroup>().find(std::make_tuple(fg_member->getFlightgroupName(), fg_member->getFlightgroupSubNumber())));
            unit_to_kill->kill();
        }

        inline void killAllUnits() {
            all_dying_units.get<FgMemberSequenced>().merge(all_live_units.get<FgMemberSequenced>());
            all_live_units.clear();
            for (auto & each_unit : all_dying_units.get<FgMemberSequenced>()) {
                boost::dynamic_pointer_cast<Unit>(each_unit)->kill();
            }
        }

//        inline void killUnit(const std::string& flightgroup_name, const int32_t flightgroup_sub_number) {
//
//        }

//        inline void killUnit(UnitByFlightgroupIterator unit_to_kill) {
//            unit_to_kill->->kill();
//        }

//        inline UnitByFlightgroupConstIterator & findUnitByFlightgroupID(const std::string& flightgroup_name, const int32_t flightgroup_sub_number) {
//            return all_live_units.get<FgMemberByFlightgroup>().find(std::make_tuple(flightgroup_name, flightgroup_sub_number));
//        }
    };

    static Universe& getUniverse() {
        static Universe kUniverseSingleton{};
        return kUniverseSingleton;
    }

} // VegaStrike

#endif //VEGA_UNIT_TEST_UNIVERSE_HPP
