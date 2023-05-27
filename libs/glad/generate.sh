#!/bin/bash

# Build glad:
# python -m venv venv
# source venv/bin/activate
# python setup.py build
# python setup.py install

glad --api="gl:compatibility=4.6" --extensions="" --out-path libs/glad-out c
