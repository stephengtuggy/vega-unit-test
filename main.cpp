#include <iostream>
#include <boost/smart_ptr/intrusive_ref_counter.hpp>
#include <boost/smart_ptr/intrusive_ptr.hpp>
#include <boost/smart_ptr/shared_ptr.hpp>
#include "vega_intrusive_ptr.hpp"
#include "unit.hpp"
//#include <boost/smart_ptr/make_shared_object.hpp>

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
