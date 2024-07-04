#include "../src/url-filter.hpp"
#include <cassert>

void test_dummy() {
    assert(url_filter::filterTrackingParameters("dummy") == "dummy");
}

void test_exception() {
    assert(url_filter::filterTrackingParameters(
               "https://www.google.com/mail/u/?ved=0") ==
           "https://www.google.com/mail/u/");
    assert(url_filter::filterTrackingParameters(
               "https://mail.google.com/mail/u/?ved=0") ==
           "https://mail.google.com/mail/u/?ved=0");
}

int main() {
    test_dummy();
    test_exception();
}
