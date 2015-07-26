#ifndef REGEX_PLANNER_H
#define REGEX_PLANNER_H

#include "succinct_core.h"

class RegExPlanner {
 public:
  RegExPlanner(SuccinctCore *s_file, RegEx *re) {
    this->s_core = s_file;
    this->re = re;
  }

  virtual ~RegExPlanner() {
    // Do nothing
  }

  virtual RegEx* plan() = 0;

 protected:
  SuccinctCore *s_core;
  RegEx *re;
};

class NaiveRegExPlanner : public RegExPlanner {
 public:
  NaiveRegExPlanner(SuccinctCore *s_core, RegEx *re)
      : RegExPlanner(s_core, re) {
  }

  // Does no cost estimation
  virtual RegEx* plan() {
    return re;
  }
};

#endif
