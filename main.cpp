#include <iostream>
#include <boost/smart_ptr/intrusive_ref_counter.hpp>
#include <boost/smart_ptr/intrusive_ptr.hpp>
#include <boost/smart_ptr/shared_ptr.hpp>
#include "vega_intrusive_ptr.hpp"
//#include <boost/smart_ptr/make_shared_object.hpp>

class Unit : public boost::intrusive_ref_counter<Unit, boost::thread_safe_counter> {
protected:
    bool killed{false};
    inline bool isKilled() const {
        std::cout << "isKilled called. Value: " << killed << std::endl;
        return killed;
    }
    inline void setKilled(bool new_value) {
        std::cout << "setKilled called with new_value: " << new_value << std::endl;
        killed = new_value;
    }
public:
    using IntrusiveUnitRefCounter = boost::intrusive_ref_counter<Unit, boost::thread_safe_counter>;

    Unit(const Unit &) = delete;

    Unit &operator=(const Unit &) = delete;

    Unit() {
        std::cout << "No-arg Unit constructor called" << std::endl;
        isKilled();
    }

    ~Unit() {
        std::cout << "Unit destructor called" << std::endl;
        setKilled(true);
    }

    // The following don't work for some reason
//    inline void Ref() {
//        std::cout << "Unit::Ref() called" << std::endl;
//        intrusive_ptr_add_ref(this);
//        isKilled();
//    }
//
//    inline void UnRef() {
//        std::cout << "Unit::UnRef() called" << std::endl;
//        intrusive_ptr_release(this);
////        isKilled();
//    }

};

using UnitRawPtr = Unit *;
using UnitIntrusivePtr = boost::intrusive_ptr<Unit>;
using UnitSharedPtr = boost::shared_ptr<Unit>;
using UnitWeakPtr = boost::weak_ptr<Unit>;

using UnitPtr = UnitSharedPtr;
using UnitParentPtr = UnitWeakPtr;
using UnitPtrForPy = UnitRawPtr;

int main() {
    std::cout << "Entering main()" << std::endl;
    UnitSharedPtr unitSharedPtr = make_shared_from_intrusive(new Unit());
    std::cout << "reference count: " << unitSharedPtr.use_count() << std::endl;
//    unitSharedPtr->Ref();
//    std::cout << "reference count: " << unitSharedPtr.use_count() << std::endl;
//    unitSharedPtr->UnRef();
//    std::cout << "reference count: " << unitSharedPtr.use_count() << std::endl;
    UnitSharedPtr anotherPtr = unitSharedPtr; // NOLINT(performance-unnecessary-copy-initialization)
    std::cout << "reference count: " << unitSharedPtr.use_count() << std::endl;
//    anotherPtr->Ref();
//    std::cout << "reference count: " << unitSharedPtr.use_count() << std::endl;
//    anotherPtr->UnRef();
//    std::cout << "reference count: " << unitSharedPtr.use_count() << std::endl;
    anotherPtr.reset();
    std::cout << "reference count: " << unitSharedPtr.use_count() << std::endl;
    std::cout << "Exiting main()" << std::endl;
    return 0;
}
