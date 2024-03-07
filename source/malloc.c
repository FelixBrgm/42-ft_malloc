#include "malloc.h"

t_storage storage = {
    .zones = NULL,
    .capacity = 0,
    .page_size = 0,
    .block_sizes = BLOCK_SIZES,
};

void *malloc(size_t size)
{
    if (storage.page_size == 0)
        storage.page_size = getpagesize();

    if (size == 0)
        return (NULL);

    for (size_t i = 0; i < BLOCK_SIZES_LEN; i++)
    {
        const uint16_t block_size = storage.block_sizes[i];

        if (size <= block_size)
        {
            const void *res = get_memory(size, block_size);
            if (res != NULL)
                return (res);
            // add another zone like that
            return (get_memory(size, block_size));
        }
    }

    // if (size <= TINY_ALLOC_SIZE)
    // {
    //     void *res = get_tiny_mem(size);
    //     if (res != NULL)
    //         return (res);
    //     printf("NEW ZONE\n");
    //     add_zone(size);
    //     res = get_tiny_mem(size);
    //     return (res);
    // }
    // else if (size <= SMALL_ALLOC_SIZE)
    // {
    //     // void *res = get_small_mem(size);
    //     // if (res == NULL)
    //     //     add_zone(size);
    //     // return (get_small_mem(size));
    // }
    // else
    // {
    //     if (add_zone(size))
    //         return (NULL);
    //     return (get_large_mem(size));
    // }

    return NULL;
}

void free(void *ptr)
{
    if (ptr == NULL)
        return;
    // is null

    // existing

    // what type
}

void *alloc(size_t size)
{
    size_t *ptr = mmap(NULL, size, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
    if (ptr == MAP_FAILED)
        return NULL;
    return ptr;
}

void dealloc(void *ptr, size_t size)
{
    if (ptr != NULL && size > 0)
    {
        munmap(ptr, size);
    }
}