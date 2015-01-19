#ifndef SUCCINCT_H
#define SUCCINCT_H

#include <cstdint>
#include <string>
#include <cstring>
#include <vector>

#include "succinct/SuccinctCore.hpp"

class SuccinctShard : public SuccinctCore {
private:
    std::string input_datafile;
    std::string succinct_datafile;

    std::vector<int64_t> keys;
    std::vector<int64_t> value_offsets;
    BitMap *invalid_offsets;

    uint32_t id;

public:
    static const int64_t MAX_KEYS = 1L << 32;

    SuccinctShard(uint32_t id, std::string datafile, uint32_t num_keys, bool construct = true,
            uint32_t isa_sampling_rate = 32, uint32_t npa_sampling_rate = 128);

    std::string name();

    size_t num_keys();

    /*
     * Random access into the Succinct file with the specified offset
     * and length
     */
    void get(std::string& result, int64_t key);

private:
    int64_t get_value_offset_pos(const int64_t key);

};

#endif
