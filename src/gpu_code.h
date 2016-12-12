#ifndef H_GPUCODE
#define H_GPUCODE

#include "memutil.h"

#include <etnaviv_drmif.h>
#include <stdint.h>

#define GPU_CODE(x) {x, ARRAY_SIZE(x), NULL}
struct gpu_code {
    const uint32_t *code;
    unsigned size;
    struct etna_bo *bo; /* Cached bo */
};

/* Create a new gpu_code */
extern struct gpu_code *gpu_code_new(const uint32_t *codein, size_t size_uints);

/* Allocate a bo with this GPU code for ICACHE */
extern void gpu_code_alloc_bo(struct gpu_code *code, struct etna_device *dev);

/* Destroy associated bo */
extern void gpu_code_destroy_bo(struct gpu_code *code);

/* Destroy a gpu_code */
void gpu_code_destroy(struct gpu_code *code);

#endif
