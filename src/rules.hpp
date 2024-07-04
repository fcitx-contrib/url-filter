#ifndef URL_FILTER_RULES_H
#define URL_FILTER_RULES_H

#include <regex>
#include <string>
#include <utility>
#include <vector>

namespace url_filter {

class Rule {
  public:
    Rule(std::string pattern, std::vector<std::string> rules,
         std::vector<std::string> rawRules, std::vector<std::string> exceptions,
         std::vector<std::string> redirects)
        : pattern(pattern), rules(rules), rawRules(rawRules),
          exceptions(exceptions), redirects(redirects) {}

    std::pair<std::string, bool> transform(const std::string &url) const {
        if (!std::regex_match(url, pattern)) {
            return {"", false};
        }
        return {"", false};
    }

  private:
    std::regex pattern;
    std::vector<std::string> rules;
    std::vector<std::string> rawRules;
    std::vector<std::string> exceptions;
    std::vector<std::string> redirects;
};

extern std::vector<Rule> rules;
} // namespace url_filter
#endif
