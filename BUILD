load("@hedron_compile_commands//:refresh_compile_commands.bzl", "refresh_compile_commands")

package(default_visibility = ["//visibility:public"])

licenses(["notice"])  # MIT

# Expose license for external usage through bazel.
exports_files([
    "AUTHORS",
    "LICENSE",
])

refresh_compile_commands(
    name = "refresh_compile_commands",
    # Specify the targets of interest.
    # For example, specify a dict of targets and any flags required to build.
    targets = {
        "//llqa:llqa": "--cxxopt='-std=c++17'",
        "//cmd:main": "--cxxopt='-std=c++17'",
    },
    # No need to add flags already in .bazelrc. They're automatically picked up.
    # If you don't need flags, a list of targets is also okay, as is a single target string.
    # Wildcard patterns, like //... for everything, *are* allowed here, just like a build.
    # As are additional targets (+) and subtractions (-), like in bazel query https://docs.bazel.build/versions/main/query.html#expressions
    # And if you're working on a header-only library, specify a test or binary target that compiles it.
)
