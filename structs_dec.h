#ifndef STRUCTS_DEC
#define STRUCTS_DEC

struct htab {
    size_t size;
    size_t arr_size;
    //Array of pointers to items (heads of linear lists)
    //Flexible array member
    struct htab_item** items;
};

struct htab_item {
    htab_key_t key;
    htab_value_t data;
    struct htab_item* next;
};

#endif