// Copyright (C) 2001-2003
// William E. Kempf
//
//  Distributed under the Boost Software License, Version 1.0. (See
//  accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)

#include <boost/chrono.hpp> // chrono::seconds
#include <boost/thread.hpp> // this_thread::sleep_for
#include <iostream>

struct thread_alarm {
  thread_alarm(int secs) : m_secs(secs) {}
  void operator()() {
    boost::chrono::seconds duration(m_secs);
    boost::this_thread::sleep_for(duration);
    std::cout << "alarm sounded..." << std::endl;
  }

  int m_secs;
};

int main(/*** int argc, char* argv[] ***/) {
  int secs = 3;
  std::cout << "setting alarm for " << secs << " seconds..." << std::endl;
  thread_alarm alarm(secs);
  boost::thread thread(alarm);
  thread.join();

  return 0;
}
