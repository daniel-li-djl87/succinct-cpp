#include <iostream>
#include <fstream>
#include <unistd.h>

#include "AdaptiveQueryServerBenchmark.hpp"

void print_usage(char *exec) {
    fprintf(stderr, "Usage: %s [-l len] [-z skew] [-o output-path]\n", exec);
}

int main(int argc, char **argv) {
    if(argc > 7) {
        print_usage(argv[0]);
        return -1;
    }

    int c;
    std::string outpath = "benchmark/res";
    double skew = 1.0;  // Pure uniform
    int32_t len = 100;
    uint32_t batch_size = 10;
    while((c = getopt(argc, argv, "o:z:l:")) != -1) {
        switch(c) {
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
        default:
            outpath = "benchmark/res";
            skew = 1.0;
            len = 100;
            batch_size = 10;
        }
    }

    // Benchmark core functions
    std::string reqpath = outpath + "/aqs-bench.req";
    std::string respath = outpath + "/aqs-bench.res";
    AdaptiveQueryServerBenchmark aqs_bench(reqpath, respath, skew, len);
    for(int32_t i = -1; i < 10; i++) {
        aqs_bench.delete_layer(i);
        aqs_bench.measure_throughput();
        aqs_bench.measure_throughput_batch(batch_size);
    }

    return 0;
}
