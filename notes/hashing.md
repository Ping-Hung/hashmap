# Hashing
## Hash Function
|input (**_key_**)|output (**_hash_**)|
|:---:|:---:|
|raw information|unique hash of a certain length|

- Mapping from a large input domain to a fixed finite range, using <mark>all
  information</mark> the input provides to generate the output (_hash_)
- The result (_hash_) must satisfy **hash properties**

## Hash Properties
### Core Properties
1. **Determinism**: same input → same hash
2. **Uniformlly Distributed**: keys are spread evenly across buckets
3. **Fast Computation**: $O(1)$ time complexity.
4. **Low Collision Probability**(in practice)
### Advanced Properties
1. **Avalanche Effect/Property**: if input $i_1$ and $i_2$ are closed to each
   other, their hashes $h_1$ and $h_2$ resides at 2 distinct locations far
   apart from each other in the hash table.

## Multiplicative Hashing
For any key,
1. Multiply it with a (non-integer) constant `A`.
2. Take its **fraction part**.
3. Expand it to table/map size.
(Reference to Prof. Koh's 368 slides)

# System Level Hashing
## ChatGPT Example
```c
    static inline u16 hash_int64(i64 key)
    {
        u64 x = (u64)key;
        x *= 11400714819323198485ull;   // 2^64 / golden ratio
        return (u16)(x >> (64 - 15));
    }
```
## Knowledge Required (Backing Knowledge)
**Computer architecture + number theory + systems**
- Fixed-width integers
- _Modular arithmetic_ in _rings_
- Overflow semantics
- Bit extraction reasoning
- How CPUs implement multiply

