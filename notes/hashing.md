# Hashing
## Hash Function
|input|output|
|:---:|:---:|
|raw information|unique hash of a certain length|

- Mapping from a large input domain to a fixed finite range, using all
  information input provides to generate the output (_hash_)
- The result (_hash_) must satisfy:
    1. **Determinism**: same input → same hash
    2. **Uniformlly Distributed**: keys are spread evenly across buckets
    3. **Fast Computation**: $O(1)$ time complexity.
    4. **Low Collision Probability**(in practice)


# Multiplicative Hashing
