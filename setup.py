from distutils.core import setup, Extension
import numpy.distutils.misc_util

#src_list = [
#    "./src/pyc/_add.c",
#    "./src/c/add.c",
##    "./src/pyc/_array_add.c",
##    "./src/c/array_add.c",
#]

ext_modules = [
    Extension("_array_info", ["./src/pyc/_array_info.c"]),
    Extension("_add", [
        "./src/pyc/_add.c",
        "./src/c/add.c"])
]

setup(
    ext_modules=ext_modules,
    include_dirs=["./src/include"]+numpy.distutils.misc_util.get_numpy_include_dirs(),
)

