#ifndef HASH_MAP_H
#define HASH_MAP_H

#include <stdint.h>

#define HASH_MAP_CREATE(map, iter) \
	struct hash_map *map = hash_map_create(); \
	struct hash_map_iter *iter = hash_map_iter_create(map);
#define HASH_MAP_DESTROY(map, iter) \
	hash_map_iter_destroy(iter); \
	hash_map_destroy(map);
#define HASH_MAP_INSERT(map, key, val) hash_map_insert(map, key, (void *)(val))
#define HASH_MAP_AT(map, key, val) hash_map_at(map, key, (void *)&(val))
#define HASH_MAP_FOR_EACH(iter, key_ptr, val_ptr) \
	for (; hash_map_iter_next(iter, &(key_ptr), (void *)&(val_ptr)); )

struct hash_map *hash_map_create(void);
void hash_map_destroy(struct hash_map *map);
void hash_map_insert(struct hash_map *map, char *key, void *val);
int64_t hash_map_at(struct hash_map *map, char *key, void **val);
uint64_t hash_map_length(struct hash_map *map);
uint64_t hash_map_capacity(struct hash_map *map);
struct hash_map_iter *hash_map_iter_create(struct hash_map *map);
void hash_map_iter_destroy(struct hash_map_iter *iter);
int hash_map_iter_next(struct hash_map_iter *iter, char **key, void **val);

#endif
