# Hash Map + Arena Allocator Project Roadmap

## Phase 1 -- Hash Function Fundamentals

-  [ ] Implement 64-bit integer hashing using multiplicative hashing.
-  [ ] Implement string hashing with bit shifts and multiplication.
-  [ ] Study avalanche effect (flip 1 bit → many output bits change).
-  [ ] Write tests to measure collision rate and distribution quality.

------------------------------------------------------------------------

## Phase 2 -- Linear (Bump) Arena Allocator

-  [ ] Allocate a large memory block upfront.
-  [ ] Implement bump pointer allocation.
-  [ ] Add alignment support (8/16-byte alignment).
-  [ ] Implement `reset()` to reuse memory.
-  [ ] Benchmark against malloc/free.

------------------------------------------------------------------------

## Phase 3 -- Open Addressing Hash Table

-  [ ] Use power-of-two capacity.
-  [ ] Replace modulo with bit masking: `index = hash & (capacity - 1)`.
-  [ ] Implement linear probing.
-  [ ] Support insert, find, delete (with tombstones).
-  [ ] Track load factor and probe counts.

------------------------------------------------------------------------

## Phase 4 -- Upgrade to Robin Hood Hashing

-  [ ] Track probe distance.
-  [ ] On collision, swap entries if incoming element has larger probe
   distance.
-   Measure:
    -  [ ] Average probe distance
    -  [ ] Max probe distance
    -  [ ] Variance of probe distance
-   [ ] Compare with plain linear probing.

------------------------------------------------------------------------

## Phase 5 -- Resizing & Rehashing

-   [ ] Trigger resize at load factor threshold (e.g., 0.75).
-   [ ] Rehash into new larger table.
-   [ ] Benchmark performance before and after resizing.

------------------------------------------------------------------------

## Phase 6 -- Probabilistic Analysis Experiments

Measure empirically: 
- Expected probe length vs load factor. 
- Distribution of displacement distances. 
- Collision frequency. 
- Performance degradation as load → 1.

Plot results and compare against theoretical expectations.

------------------------------------------------------------------------

## Optional Advanced Extensions

-   SIMD-based hash mixing.
-   Cache-line aware layout optimization.
-   Custom object pool for entries.
-   Benchmark vs std::unordered_map.
-   Implement Bloom filter using same hash primitives.

------------------------------------------------------------------------

## Final Goal

Understand: - Multiplicative hashing behavior - Load factor tradeoffs -
Clustering phenomena - Memory layout & cache locality - Basic
probabilistic analysis of hashing
