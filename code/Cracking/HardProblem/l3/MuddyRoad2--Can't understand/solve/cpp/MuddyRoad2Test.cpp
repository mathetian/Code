#define BOOST_TEST_DYN_LINK 
#define BOOST_TEST_MODULE MyTest
#include <boost/test/unit_test.hpp> 
#include "MuddyRoad2.cpp" 

BOOST_AUTO_TEST_CASE (test_theCount) {
    BOOST_CHECK_EQUAL(0, 0);
}
