from distutils.core import setup, Extension

setup(
    ext_modules=[Extension("_add", ["./src/c/add.c","./src/pyc/_add.c"])],
    include_dirs=["./src/include"],
)

