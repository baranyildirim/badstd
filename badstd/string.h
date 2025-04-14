#pragma once

#include <regex>
#include <string>

inline void remove_common_prefix(std::string& first, std::string& second) {
  int i = 0;
  while (i < first.size() && i < second.size() && first[i] == second[i]) {
    ++i;
  }
  first = std::string{std::next(first.begin(), i), first.end()};
  second = std::string{std::next(second.begin(), i), second.end()};
}

template <class C>
inline C split(const std::string& str, const char delim) {
  std::regex delimiter{std::string{delim}};
  return C(std::sregex_token_iterator(str.begin(), str.end(), delimiter, -1),
           {});
}

template <class C>
inline C split(const std::string& str, const std::string& delim) {
  std::regex delimiter{delim};
  std::sregex_token_iterator first{str.begin(), str.end(), delimiter, -1}, last;
  return C(first, last);
}

template <class C>
inline C strtok_split(std::string str, std::string delim) {
  char* token = strtok(str.data(), delim.data());
  C container{};
  while (token != nullptr) {
    container.push_back(token);
    token = strtok(nullptr, delim.data());
  }
  return container;
}