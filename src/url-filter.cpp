#include "url-filter.hpp"
#include "rules.hpp"

namespace url_filter {
std::pair<std::string, bool> filterTrackingParameters(const std::string &url) {
    for (const auto &rule : url_filter::rules) {
        auto result = rule.transform(url);
        if (result.second) {
            return result;
        }
    }
    return {"", false};
}
} // namespace url_filter
