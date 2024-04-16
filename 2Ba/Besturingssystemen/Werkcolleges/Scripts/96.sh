#!/bin/bash

declare -A group_name_id
declare -A user_name_group

IFS=:

while read -r group_name password gid user_list rest; do
    group_name_id[$gid]=$group_name
done < /etc/group

while read -r user_name password uid gid rest; do
    if [ "${group_name_id[$gid]}" ]; then
        group_name="${group_name_id[$gid]}"
        user_name_group["$group_name"]+="$user_name "
    fi
done < /etc/passwd

for group_name in "${!user_name_group[@]}"; do
    echo "$group_name: ${user_name_group[$group_name]}"
done
