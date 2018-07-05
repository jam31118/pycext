from setuptools import setup, Extension, find_packages
from numpy.distutils.misc_util import get_numpy_include_dirs

ext_modules = [
    Extension("cu", ["./obj/_add.cc"])
]

