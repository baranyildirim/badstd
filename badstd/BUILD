load("@rules_cc//cc:defs.bzl", "cc_library", "cc_test")

cc_library(
    name = "badstd",
    srcs = [
        "instance_counter.cc",
    ],
    hdrs = [
        "fib_tree.h",
        "instance_counter.h",
        "ip.h",
        "shared_ptr.h",
        "stlout.h",
        "string.h",
        "topological_sort.h",
        "unique_ptr.h",
    ],
    visibility = ["//visibility:public"],
)

cc_test(
    name = "badstd_test",
    srcs = [
        "tests/fib_tree_test.cpp",
        "tests/shared_ptr_test.cpp",
        "tests/split_test.cpp",
        "tests/topological_sort_test.cpp",
    ],
    deps = [
        ":badstd",
        "@googletest//:gtest",
        "@googletest//:gtest_main",
    ],
)
