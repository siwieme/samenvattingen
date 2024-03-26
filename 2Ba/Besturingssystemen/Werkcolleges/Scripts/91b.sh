#!/bin/bash

IFS=: read -a array < <(grep ^.*:x:$1: /etc/passwd)

echo ${array[0]}