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

TEST(Test_file, empty_file) {
    char filename[] = "notest.bin";
    TaskList_t* structure = nullptr;
    structure = read_file(filename);
    ASSERT_EQ(print_task(structure), PRINT_ERROR);
}


TEST(Test_print, print_null) {
    TaskList_t* head = nullptr;
    ASSERT_EQ(print_task(head), PRINT_ERROR);
}

TEST(Test_task, initialise_task_null) {
    TaskList_t* head = nullptr;
    head = initialise(nullptr);
    ASSERT_EQ(head, nullptr);
}

TEST(Test_task, add_elem_null) {
    Task* elem = nullptr;
    TaskList_t* head = nullptr;
    ASSERT_EQ(add_elem(elem, head), nullptr);
}



TEST(Test_task, read_file) {
    TaskList_t* head = nullptr;
    char filename[] = "test.bin";
    head = read_file(filename);
    ASSERT_NE(head, nullptr);
    freopen("got.txt", "w", stdout);
    ASSERT_EQ(print_task(head), 0);
    clear(head);
    fclose(stdout);
}