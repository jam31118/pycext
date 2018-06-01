from distutils.core import setup, Extension

setup(
    ext_modules=[Extension("_add", ["./src/_add.c","./src/add.c"])],
    include_dirs=["./src"],
)

