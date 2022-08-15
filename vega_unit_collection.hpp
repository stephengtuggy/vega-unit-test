//
// Created by StephenTuggy on 8/15/2022.
//

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

namespace VegaStrike {

//    class Unit;
    struct UnitSequenced {};
    struct UnitIdentity {};
    struct UnitFlightgroup {};

    using namespace boost;
    using namespace boost::multi_index;

    typedef multi_index_container<
            boost::shared_ptr<Unit>,
            indexed_by<
                    sequenced<tag<UnitSequenced>>,
                    ordered_unique<tag<UnitIdentity>, identity<Unit>>>,
                    ordered_unique<tag<UnitFlightgroup>,
                            composite_key<Unit,
                                    const_mem_fun<Unit, std::string, &Unit::getFlightgroupName>,
                                    const_mem_fun<Unit, int32_t, &Unit::getFlightgroupSubNumber>
                            >,
                            composite_key_compare<std::less<std::string>, std::less<int32_t>>
            >
    > UnitContainer;

}
#endif //VEGA_UNIT_TEST_VEGA_UNIT_COLLECTION_HPP
