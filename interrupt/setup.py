from distutils.core import setup, Extension

setup(name = 'BBoe',
      ext_modules = [Extension('bboe', ['./src/pyc/interrupt.c'])])

