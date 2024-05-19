#pragma once

struct Utils {
  static bool is_number(const std::string& str) {
      if (str.empty()) return false;
      auto iter { str.begin() };
      if (str.front() == '-') {
        if (str.size() > 1) ++iter; // neg number
        else return false;          // only -
      }
      return all_of(iter, str.end(), ::isdigit);
    }
};