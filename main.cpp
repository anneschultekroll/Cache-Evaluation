#include <iostream>
#include <stdlib.h>
#include <chrono>

/**
    Abgabe Blatt 10 Cache Messen
    Niklas Rausch, Anne Schulte-Kroll und Wolf Weber
**/

int main(int argc, char** argv) {
   long N=100; // Number of Elements
   long k=1; // Iterations
   char* bytes; // ByteArray

   if(argc != 3) {
      std::cout << "Syntax: program <int:iterations> <int:ByteCount>" << std::endl;
      return 1;
   } else {
      k = atoi(argv[1]);
      N = atoi(argv[2]);
   }
   // std::cout << k << std::endl;
   // std::cout << N << std::endl;

   bytes = (char*) malloc(N*sizeof(char));
   for(long i=0; i<N; i++) {
      bytes[i] = 0;
   }

   auto starttime = std::chrono::high_resolution_clock::now();
   for(long ki=0; ki<k; ki++) {
      for(long i=0; i<N; i++) {
         bytes[i] = bytes[i]+10;
      }
   }
   auto endtime = std::chrono::high_resolution_clock::now();

   double dur = (N*k)/((double) std::chrono::duration_cast<std::chrono::nanoseconds>(endtime-starttime).count());
   // Ausgabe im Format (Bytes N);(Read/Write speed Bytes/Nanosecond = GB/Second)
   std::cout << N << ";" << dur << std::endl;

   free(bytes);

   return  0;
}