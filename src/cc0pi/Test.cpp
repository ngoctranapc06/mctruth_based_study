#include "Test.hpp"

#include <boost/log/trivial.hpp>
#include <boost/filesystem.hpp>

Test::Test() = default;

void Test::test(){
  BOOST_LOG_TRIVIAL(info) << "Test";
}

