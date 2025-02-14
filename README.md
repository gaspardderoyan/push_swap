

```c
typedef enum {
    MIN,
    MID,
    MAX
} Position;

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
} t_chunk;

typedef struct s_mst {
    t_lst *a;
    t_lst *b;
    t_lst *ops;
    t_chunk chunk;
} t_mst;

/*
 * mst: master structure, with pointers to the two stacks + metadata
 * node: pointer to the specific node we want to change
 * pos: end position we want (eg. MIN)
 */
void    move_node_between_positions(mt *mst, lst *node, Position pos);
```
