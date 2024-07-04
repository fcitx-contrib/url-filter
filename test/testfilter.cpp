#include "../src/url-filter.hpp"
#include <cassert>

void test_dummy() {
    assert((filterTrackingParameters("dummy") == std::make_pair("", false)));
}

int main() { test_dummy(); }
