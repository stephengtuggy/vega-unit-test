#include <iostream>
#include <boost/smart_ptr/intrusive_ref_counter.hpp>
#include <boost/smart_ptr/intrusive_ptr.hpp>
#include <boost/smart_ptr/shared_ptr.hpp>

class Unit : public boost::intrusive_ref_counter<Unit, boost::thread_safe_counter> {
public:
    using IntrusiveUnitRefCounter = boost::intrusive_ref_counter<Unit, boost::thread_safe_counter>;

};

using UnitRawPtr = Unit *;
using UnitIntrusivePtr = boost::intrusive_ptr<Unit>;
using UnitSharedPtr = boost::shared_ptr<Unit>;
using UnitWeakPtr = boost::weak_ptr<Unit>;

using UnitPtr = UnitRawPtr;
using UnitParentPtr = UnitWeakPtr;
using UnitPtrForPy = UnitRawPtr;

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
