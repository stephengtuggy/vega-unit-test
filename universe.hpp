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

    typedef UnitContainer::index_iterator<UnitSequenced> UnitSequencedIterator;
    typedef const UnitContainer::index_const_iterator<UnitSequenced> UnitConstSequencedIterator;

    // Forward declarations
    class Universe;
    static Universe& getUniverse();

    class Universe {
    private:
        UnitContainer all_live_units{};
        UnitContainer all_dying_units{};

        friend Universe& getUniverse();

        Universe() = default;

        inline virtual ~Universe() = default;

    public:
        Universe(Universe const & rhs) = delete;
        Universe & operator=(Universe const & rhs) = delete;

        inline UnitContainer const & getAllLiveUnits() const {
            return all_live_units;
        }

        inline UnitContainer const & getAllDyingUnits() const {
            return all_dying_units;
        }

        inline Unit & createUnit(std::string flightgroup_name, int32_t flightgroup_member_number) {
            boost::shared_ptr<Unit> new_unit = boost::make_shared<Unit>(std::move(flightgroup_name), flightgroup_member_number);
            all_live_units.get<0>().insert(*new_unit);
            return *new_unit;
        }

        inline void killUnit(Unit & unitToKill) {
            unitToKill.kill();
            all_dying_units.get<0>().insert(unitToKill);
            all_live_units.get<0>().erase(unitToKill);
        }
    };

    static Universe& getUniverse() {
        static Universe kUniverseSingleton{};
        return kUniverseSingleton;
    }

} // VegaStrike

#endif //VEGA_UNIT_TEST_UNIVERSE_HPP
