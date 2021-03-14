#pragma once

#include <vector>
#include <iostream>
#include <iomanip>
#include <chrono>

namespace tiktok {
   std::vector<std::chrono::high_resolution_clock::time_point> t0s;
   std::chrono::high_resolution_clock::time_point t1;

   /** starts time measurement **/
   void tik() {
      t0s.push_back( std::chrono::high_resolution_clock::now() );
   }

   /** stops time measurement and returns the elapsed time in ms **/
   double tok() {
      if(t0s.size() > 0) {
         t1 = std::chrono::high_resolution_clock::now();
         std::chrono::high_resolution_clock::time_point t0 = t0s[t0s.size()-1];
         t0s.pop_back();
         double duration = ( (double) std::chrono::duration_cast<std::chrono::nanoseconds>(t1-t0).count() )*1E-6;
         return duration;
      } else {
         return -1;
      }
   }

   /** stops time measurement and prints it out. Also returns the measured time in ms **/
   double tok(std::string jobname, std::string jobdescription) {
      double duration = tok();
      if(duration < 0) {
         std::cout << std::setw(10) << jobname << " | " << std::setw(15) << jobdescription << " | " << " INVALID: tok() without tik() before" << std::endl;
      } else {
         int printed=0;
         for(int i=0; i<t0s.size(); i++) {
            std::cout << ">";
            printed++;
         }
         std::cout << std::setw(10-printed) << jobname << " | " << std::setw(15) << jobdescription << " | " /*<< std::scientific*/ << std::setprecision(6) << std::setw(10) << duration << " ms" << std::endl;
      }
      return duration;
   }
}