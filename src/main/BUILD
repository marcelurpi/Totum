cc_binary(
    name = "totum",
    srcs = ["totum.cc"],
    deps = ["//src/lib:libraries"],
    copts = [
        "-Wall", "-Wextra", "-Wshadow", "-Wnon-virtual-dtor",
        "-Wold-style-cast", "-Wcast-align", "-Wunused", "-Woverloaded-virtual",
        "-Wpedantic", "-Wconversion", "-Wsign-conversion",
        "-Wmisleading-indentation", "-Wduplicated-cond",
        "-Wduplicated-branches", "-Wlogical-op", "-Wnull-dereference",
        "-Wuseless-cast", "-Wdouble-promotion", "-Wformat=2", "-Weffc++"
    ],
)
