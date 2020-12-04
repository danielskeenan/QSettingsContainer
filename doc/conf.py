# Configuration file for the Sphinx documentation builder.
#
# This file only contains a selection of the most common options. For a full
# list see the documentation:
# https://www.sphinx-doc.org/en/master/usage/configuration.html
import json
import re
import subprocess
from pathlib import Path
from datetime import date


def conan_info() -> dict:
    conanfile_path = Path(__file__).parent / '..'
    result = subprocess.run(['conan', 'inspect', str(conanfile_path)], check=True, capture_output=True, text=True)
    info = {}
    pattern = re.compile(r'^(?P<key>.+): (?P<value>.+)$')
    for line in result.stdout.splitlines():
        data = pattern.match(line)
        if not data:
            continue
        info[data.group('key')] = data.group('value')

    return info


# -- Path setup --------------------------------------------------------------

# If extensions (or modules to document with autodoc) are in another directory,
# add these directories to sys.path here. If the directory is relative to the
# documentation root, use os.path.abspath to make it absolute, like shown here.
#
# import os
# import sys
# sys.path.insert(0, os.path.abspath('.'))


# -- Project information -----------------------------------------------------

conanfile = conan_info()
project = conanfile['name']
copyright = '{year}, {author}'.format(year=date.today().year, author=conanfile['author'])
author = conanfile['author']

# The full version, including alpha/beta/rc tags
release = conanfile['version']

# -- General configuration ---------------------------------------------------

# Add any Sphinx extension module names here, as strings. They can be
# extensions coming with Sphinx (named 'sphinx.ext.*') or your custom
# ones.
extensions = [
]

# Add any paths that contain templates here, relative to this directory.
templates_path = ['_templates']

# List of patterns, relative to source directory, that match files and
# directories to ignore when looking for source files.
# This pattern also affects html_static_path and html_extra_path.
exclude_patterns = ['_build', 'Thumbs.db', '.DS_Store']

primary_domain = 'cpp'

# -- Options for HTML output -------------------------------------------------

# The theme to use for HTML and HTML Help pages.  See the documentation for
# a list of builtin themes.
#
html_theme = 'nature'

# Add any paths that contain custom static files (such as style sheets) here,
# relative to this directory. They are copied after the builtin static files,
# so a file named "default.css" will overwrite the builtin "default.css".
html_static_path = ['_static']
