#ifndef URL_FILTER_RULES_H
#define URL_FILTER_RULES_H

#include <algorithm>
#include <regex>
#include <utility>
#include <vector>

namespace url_filter {

std::string decodeURL(const std::string &url);

std::vector<std::regex> compileRules(const std::vector<std::string> &rules);

static auto generic = std::regex("(?:&amp;|[/?#&])$rule=[^&]*");

// https://github.com/fcitx5-android/fcitx5-android/blob/ea2d5c8a439a4bc400ae976c5ded278f39c5ce12/plugin/clipboard-filter/src/main/java/org/fcitx/fcitx5/android/plugin/clipboard_filter/ClearURLs.kt
class Rule {
  public:
    Rule(std::string pattern, std::vector<std::string> rules,
         std::vector<std::string> rawRules, std::vector<std::string> exceptions,
         std::vector<std::string> redirects)
        : pattern(pattern), rules(compileRules(rules)),
          rawRules(compileRules(rawRules)),
          exceptions(compileRules(exceptions)),
          redirects(compileRules(redirects)) {}

    std::pair<std::string, bool> transform(const std::string &url) const {
        if (!std::regex_match(url, pattern)) {
            return {"", false};
        }
        for (const auto &exception : exceptions) {
            if (std::regex_match(url, exception)) {
                return {"", false};
            }
        }
        for (const auto &redirect : redirects) {
            if (std::regex_match(url, redirect)) {
                return {"", true};
            }
        }
        return {"", false};
    }

  private:
    std::regex pattern;
    std::vector<std::regex> rules;
    std::vector<std::regex> rawRules;
    std::vector<std::regex> exceptions;
    std::vector<std::regex> redirects;
};

extern std::vector<Rule> rules;
} // namespace url_filter
#endif
