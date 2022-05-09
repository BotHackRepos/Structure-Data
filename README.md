# Structure-Data
create list:
List *ptr = newlist(SIZE);
forange:
for (int i = 0;i < size(ptr);++i) {
  // *element(ptr, i);
}
print:
VOID print(ptr);
push_back:
VOID
push_back(ptr, NUMBER);
push_front:
VOID
push_front(ptr,NUMBER);
search:
LIST*
search(ptr, NUMBER);
sort:
VOID
sort_vstavk_binary(ptr);
free:
VOID
Free(ptr);
getnode:
LIST*
getnode(ptr, INDEX);
search_count:
INT
search_count(ptr, INDEX);
is_empty:
BOOL
is_empty(ptr);
and mor...
