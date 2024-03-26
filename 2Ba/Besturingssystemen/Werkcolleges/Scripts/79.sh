#!/bin/bash

x=/usr/bin/tail

y=${x##*/}

dir=${x%$y}