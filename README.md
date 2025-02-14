

```c
typedef enum {
    MIN,
    MID,
    MAX
} Position;

typedef enum {
    A,
    B
} Stack;

typedef struct s_lst {
    int value;
    int index;
    t_lst next;
    Position curr_pos;
    // current len of chunk being split?
} t_lst;

typedef struct s_chunk {
    int lower_limit;
    int upper_limit;
    // don't actually have to know it's 'position' 
    // -> we just need to know on which stack it is, because it will always be at the top;
    Stack stack_id;
} t_chunk;

typedef struct s_chunks {
    t_chunk min;    
    t_chunk mid;    
    t_chunk max;    
} t_chunks;

typedef struct s_mst {
    t_lst *a;
    t_lst *b;
    t_lst *ops;
    // t_chunk chunks;
} t_mst;

/*
 * mst: master structure, with pointers to the two stacks + metadata
 * node: pointer to the specific node we want to change
 * pos: end position we want (eg. MIN)
 */
void    move_node_between_positions(mt *mst, lst *node, Position pos);

/*
 * chunk_to_sort: contains the required info to know which chunk to sort and how
    * ie. which Stack (A or B),  
 */
void    split_chunk(t_mst *mt, t_chunk *chunk_to_sort);

void    recursive_chunk_sort(t_mst *mst, t_chunk *chunk_to_sort);
```
