#include <iostream>
#include <fstream>
#include <unistd.h>

#include "adaptive_query_server_benchmark.h"

void print_usage(char *exec) {
  fprintf(stderr,
          "Usage: %s [-l len] [-z skew] [-b batch_size] [-o output-path]\n",
          exec);
}

int main(int argc, char **argv) {
  if (argc > 11) {
    print_usage(argv[0]);
    return -1;
  }

  int c;
  std::string outpath = "bench/res";
  double skew = 0.01;  // Very skewed
  int32_t len = 100;
  uint32_t batch_size = 10;
  std::string querypath = "";
  while ((c = getopt(argc, argv, "o:z:l:b:q:")) != -1) {
    switch (c) {
      case 'o':
        outpath = std::string(optarg);
        break;
      case 'z':
        skew = atof(optarg);
        break;
      case 'l':
        len = atol(optarg);
        break;
      case 'b':
        batch_size = atol(optarg);
        break;
      case 'q':
        querypath = optarg;
        break;
      default:
        outpath = "bench/res";
        skew = 1.0;
        len = 100;
        batch_size = 10;
        querypath = "";
    }
  }

  // Benchmark core functions
  std::string reqpath = outpath + "/aqs-bench.req";
  std::string respath = outpath + "/aqs-bench.res";
  AdaptiveQueryServerBenchmark aqs_bench(reqpath, respath, skew, len,
                                         querypath);
  for (int32_t i = -1; i < 10; i++) {
    aqs_bench.DeleteLayer(i);
    aqs_bench.MeasureSearchGetThroughput();
  }

  return 0;
}
