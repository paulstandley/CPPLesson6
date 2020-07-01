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
/*
void dynamically_allocate_arrays_of_variables();

int get_number_for_array();
std::string get_names_from_user(int num);
void print_user_names(std::string* name, int num);

int get_number_for_array();
std::string get_names_from_user(int num);
void print_user_names(std::string* name, int num);
void make_dynamic_array();
void pointer_to_const();
*/
void references_to_non_const_values();

std::string ref_tester(std::string& test_string);
void print_ref_tester();

void print_elements(int(&arr)[4]);
void using_references_to_pass_c_style_arrays_to_functions();

void const_ref();
void const_function(const int& ref);
void print_it(const int& x);
void print_const_function();
void member_selection_with_pointersand_references();

void for_each_loops();
void for_each_loops_and_the_auto_keyword();
void for_each_loops_and_non_arrays();
std::string quiz_get_name_string();
void quiz_array_for_each();

//void void_pointer();
//void print_void_pointer_value(void* ptr, enum class type);
//void void_pointer_value();

void pointer_to_pointer_c();
void pointers();
void array_of_poniters();

void std_array();
void size_and_sorting(const std::array<double, 5>& myArray);
void display_std_array();


#endif // !CPPLESSON_6

