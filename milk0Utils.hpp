/** \file milk0Utils.hpp
  * \brief Useful tools for milk 0.
  * \author Jared R. Males (jaredmales@gmail.com)
  *
  * History:
  * - 2018-12-27 created by JRM
  */

#ifndef milk0Utils_hpp
#define milk0Utils_hpp

#include <iostream>
#include <string>
#include <chrono>
#include <thread>

namespace milk0 
{

/// Sleep for a specified period in seconds.
inline
void sleep( unsigned sec /**< [in] the number of seconds to sleep. */)
{
   std::this_thread::sleep_for(std::chrono::seconds(sec));
}

/// Sleep for a specified period in microseconds.
inline
void microsleep( unsigned usec /**< [in] the number of microseconds to sleep. */)
{
   std::this_thread::sleep_for(std::chrono::microseconds(usec));
}

/// Get the current time, as double precision seconds since the epoch
/** 
  * \returns the time since the epoch.
  */ 
inline
double get_curr_time()
{
   struct timespec tsp;
   clock_gettime(CLOCK_REALTIME, &tsp);

   return ((double)tsp.tv_sec) + ((double)tsp.tv_nsec)/1e9;
}

/// Report an error to the user using stderr.
inline 
void reportError( const std::string & argv0, ///< [in] the name of the application reporting the error
                  const std::string & msg,   ///< [in] the error message
                  const std::string & file,  ///< [in] the file where the error occurred
                  int line                   ///< [in] the line number at which the error occurred.
                )
{
   std::cerr << argv0  <<": " << msg << "\n";
   std::cerr << "  at " << file << " line " << line << "\n"; 
}

} //namespace milk0 

#endif //milkZeroUtils_hpp