#ifndef LAYERED_SAMPLED_ISA_HPP
#define	LAYERED_SAMPLED_ISA_HPP

#include "layered_sampled_array.h"

class LayeredSampledISA : public LayeredSampledArray {
 public:
  LayeredSampledISA(uint32_t target_sampling_rate, uint32_t base_sampling_rate,
                    NPA *npa, ArrayStream& sa_stream, uint64_t sa_n,
                    SuccinctAllocator &s_allocator);

  LayeredSampledISA(uint32_t target_sampling_rate, uint32_t base_sampling_rate,
                    NPA *npa, ArrayInput& sa_array, uint64_t sa_n,
                    SuccinctAllocator &s_allocator);

  LayeredSampledISA(uint32_t target_sampling_rate, uint32_t base_sampling_rate,
                    NPA *npa, SuccinctAllocator &s_allocator);

  // Access element at index i
  uint64_t operator[](uint64_t i);

  size_t ReconstructLayer(uint32_t layer_id);

 protected:
  void SampleLayered(ArrayStream& sa_stream, uint64_t n);
  void SampleLayeredInMem(ArrayInput& sa_array, uint64_t n);
  NPA *npa;
};

#endif	/* LAYERED_SAMPLED_ISA_HPP */

