from distutils.core import setup, Extension
import numpy.distutils.misc_util

bcm_ext = Extension("_bcm", ["_bcm.cpp", "bcm.cpp"])

setup(
    name='CA BCM Utility',
    version = '0.1',
    ext_modules=[bcm_ext],
    include_dirs=numpy.distutils.misc_util.get_numpy_include_dirs(),
)
