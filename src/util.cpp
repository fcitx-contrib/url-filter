#include <regex>
#include <sstream>

namespace url_filter {

// https://developer.android.com/reference/java/net/URLDecoder
std::string urlDecode(const std::string &url) {
    std::ostringstream decoded;
    decoded << std::hex;

    auto hexValue = [](char c) {
        if (c >= '0' && c <= '9') {
            return c - '0';
        }
        if (c >= 'a' && c <= 'f') {
            return c - 'a' + 10;
        }
        if (c >= 'A' && c <= 'F') {
            return c - 'A' + 10;
        }
        return -1;
    };

    for (auto it = url.begin(); it != url.end(); ++it) {
        char c = *it;
        if (c == '%') {
            if (std::distance(it, url.end()) >= 3) {
                int high = hexValue(*(it + 1));
                int low = hexValue(*(it + 2));
                if (high >= 0 && low >= 0) {
                    decoded << static_cast<char>((high << 4) | low);
                    std::advance(it, 2);
                    continue;
                }
            }
            // Preserve malformed or incomplete escapes as literal text.
            decoded << c;
        } else if (c == '+') {
            decoded << ' ';
        } else {
            decoded << c;
        }
    }

    return decoded.str();
}

std::string decodeURL(const std::string &url) {
    auto temp = std::regex_replace(url, std::regex("\\+"), "%2B");
    return std::regex_replace(urlDecode(temp), std::regex("%2B"), "+");
}

std::vector<std::regex> compileRules(const std::vector<std::string> &rules) {
    std::vector<std::regex> compiledRules;
    compiledRules.reserve(rules.size());
    std::transform(rules.begin(), rules.end(),
                   std::back_inserter(compiledRules),
                   [](const std::string &rule) { return std::regex(rule); });
    return compiledRules;
}
} // namespace url_filter
