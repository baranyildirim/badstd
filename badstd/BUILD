load("@rules_cc//cc:defs.bzl", "cc_library", "cc_test")

cc_library(
    name = "badstd",
    hdrs = [
        "unique_ptr.h",
        "shared_ptr.h",
        "stlout.h",
        "topological_sort.h",
        "instance_counter.h"
    ],
    srcs = [
        "instance_counter.cc"
    ],
    visibility = ["//visibility:public"],
)

cc_test(
    name = "badstd_test",
    srcs = [
        "tests/topological_sort_test.cpp",
        "tests/shared_ptr_test.cpp"
    ],
    deps = [
        ":badstd",
        "@googletest//:gtest",
        "@googletest//:gtest_main" 
    ],
)