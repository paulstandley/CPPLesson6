#ifndef CPPLESSON_6
#define CPPLESSON_6

void string_view_hello();
std::string_view ask_for_name();
void ownership_issues();

void print_implicitly_convert_string_view(std::string s);
void implicitly_convert_string_view();

void converting_string_view_c_style_string();
void string_data();
void incomplete_implementation();

void ponter_address_operator();
void reassign_pointer();

void bang(int*&);
void crash();
void size_of_pointer();
void null_pointers();

void print(int x);
void print(int *x);
void call_print();
void doSomething(std::nullptr_t ptr);

void array_decay_to_address();
void dereference_array_to_get_value_of_first_element();
void print_size_of1(int* array);
void print_size_of2(int array[]);
void passing_fixed_arrays_to_functions();

void change_array(int* ptr);
void print_change_array();

void pointer_arithmetic();
bool isVowel(char ch);
void pointer_iterate_array();

void pointer_to_symbolic_constant();
const char* get_pointer_to_array();

void dynamic_memory_allocation();
void dangling_pointer();



#endif // !CPPLESSON_6

