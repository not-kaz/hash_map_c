# hash_map_c

THIS DOESNT WORK YET!

Naive and portable implementation of a hash map written in ANSI C99, using the FNV1a hash function.</br>
Made as an exercise and for personal use in hobby projects.

Collisions are handled with linear probing, for the simplicity and locality(?).</br>
No removal implemented yet, will see if it's necessary.

Several helper macros included to reduce verbosity, however, they are not necessary to use.
Some macros obscure the code for the sake of readability; casts and variable declarations.
I personally prefer the using the functions, as they show clear intent.


```
VERBOSE VERSION:
#include "hash_map.h"

#include <stdio.h>

int main(void)
{
	struct hash_map *map;
	struct hash_map_iter *iter;
	int res;
	char *key;
	void *val;

	/* Create map and associated iterator. */
	map = hash_map_create();
	if (!map) {
		return 1;
	}
	iter = hash_map_iter_create(map);
	if (!iter) {
		return 1;
	}
	/* Insert key and value pairs. */
	/* intptr_t casts are here to prevent the compiler from screaming at us. */
	hash_map_insert(map, "a", (void *)(intptr_t)(1));
	hash_map_insert(map, "b", (void *)(intptr_t)(2));
	hash_map_insert(map, "c", (void *)(intptr_t)(3));
	hash_map_insert(map, "d", (void *)(intptr_t)(4));
	/* Access value from map via key. */
	res = hash_map_at(map, "c", (void *)&(val));
	if (!res) {
		return 1;
	}
	fprintf("%d\n", val);
	hash_map_destroy(map);
	return 0;
}
```

```
MACRO VERSION:
#include "hash_map.h"

#include <stdio.h>

int main(void)
{
	char *key;
	void *val;
	
	/* Create map and associated iterator. */
	HASH_MAP_CREATE(map, iter);
	/* Insert key and value pairs. */
	HASH_MAP_INSERT(map, "a", 1);
	HASH_MAP_INSERT(map, "b", 2);
	HASH_MAP_INSERT(map, "c", 3);
	HASH_MAP_INSERT(map, "d", 4);
	/* Access value from map via key. */
	HASH_MAP_AT(map, "c", val);
	fprintf(stdout, "%d\n", val); /* prints 3 */
	/* Access each map entry and store key and value pairs into pointers. */
	HASH_MAP_FOR_EACH(iter, key, val) {
		fprintf(stdout, "%s:%d\n", key, val);
	}
	HASH_MAP_DESTROY(map, iter);
}
