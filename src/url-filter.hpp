#ifndef URL_FILTER_H
#define URL_FILTER_H

#include <string>
#include <utility>

// <result, isFiltered>
std::pair<std::string, bool> filterTrackingParameters(const std::string &url);

#endif
