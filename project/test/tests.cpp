#include "gtest/gtest.h"

extern "C" {
    #include "read_write.h"
    #include "task_structure.h"
}

TEST(Test_file, write) {
    char filename[] = "test.bin";
    ASSERT_EQ(write_file(1, filename, "-c"), 0);
}

TEST(Test_file, add) {
    char filename[] = "test.bin";
    ASSERT_EQ(write_file(1, filename, "-a"), 0);
}

TEST(Test_file, wrong_filename) {
    char filename[] = "";
    ASSERT_EQ(write_file(1, filename, "-a"), FAILED_FILE_OPENNING);
}

TEST(Teat_file, empty_file) {
    char filename[] = "notest.bin";
    TaskList_t* structure = NULL;
    structure = read_file(filename);
    ASSERT_EQ(print_task(structure), PRINT_ERROR);
}

TEST(Test_add, null_elem) {
    Task* elem = NULL;
    TaskList_t* head = NULL;
    ASSERT_EQ(add_elem(elem, head), NULL);
}

TEST(Test_print, null_head) {
    TaskList_t* head = NULL;
    ASSERT_EQ(print_task(head), PRINT_ERROR);
}

TEST(Test_struct, null_initialise) {
    ASSERT_EQ(initialise(NULL), NULL);
}
